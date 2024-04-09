
#include "LibraryManager.h"

#include <map>
#include <memory>
#include <string>

#include <nlohmann/json.hpp>

#include "DirectoryManager.h"
#include "Tag.h"


namespace MediaPro {

LibraryManager::LibraryManager(std::string path) : dirManager(path) {
  auto library = dirManager.getLibrary();

  for (auto& tag : library->at("tags")) {
    tags.emplace(tag["name"], std::make_shared<Tag>(tag["name"], tag["colour"]));
  }

  for (auto& song : library->at("songs")) {
    std::shared_ptr<Song> ptr = std::make_shared<Song>(
      song, song["title"], song["album"], song["artists"], song["length"], song["date"]);

    for (std::string tag : song["tags"]) {
      ptr->addTag(tags[tag]);
    }

    songs.emplace(song, ptr);
  }

  for (auto& domain : library->at("domainRules")) {
    // TODO construct domain rules.
  }

  for (auto& order : library->at("orderRules")) {
    // TODO construct order rules.
  }
}

LibraryManager::~LibraryManager() {
  // TODO update the shared ptr json to reflect current state.
}

void LibraryManager::update() {
  // TODO update the songSet and orderRules of the queue.

  queue->setSongSet(search(""));
  queue->refresh();
}

std::vector<std::shared_ptr<Song>> LibraryManager::search(std::string key, int category = 0) {
  std::vector<std::shared_ptr<Song>> list;

  if (key == "") {
    for (auto& song : songs) {
      list.push_back(song.second);
    }

    return list;
  }

  // TODO implement search

  return list;
}

std::shared_ptr<Queue> LibraryManager::getQueue() {
  return queue;
}

std::shared_ptr<Tag> LibraryManager::getTag(std::string key) {
  return tags[key];
}

std::shared_ptr<Song> LibraryManager::getSong(std::string key) {
  return songs[key];
}

std::shared_ptr<DomainRule> LibraryManager::getDomainRule(std::string key) {
  return domainRules[key];
}

std::shared_ptr<OrderRule> LibraryManager::getOrderRule(std::string key) {
  return orderRules[key];
}

bool LibraryManager::addTag(std::shared_ptr<Tag> tag) {
  return tags.try_emplace(tag->getName(), tag).second;
}

bool LibraryManager::addDomainRule(std::shared_ptr<DomainRule> rule) {
  return domainRules.try_emplace(rule->getName(), rule).second;
}

bool LibraryManager::addOrderRule(std::shared_ptr<OrderRule> rule) {
  return orderRules.try_emplace(rule->getName(), rule).second;
}

bool LibraryManager::editTag(std::string key, std::shared_ptr<Tag> tag) {
  if (removeTag(key)) {
    return false;
  }

  return addTag(tag);
}

bool LibraryManager::editDomainRule(std::string key, std::shared_ptr<DomainRule> rule) {
  if (removeDomainRule(key)) {
    return false;
  }

  return addDomainRule(rule);
}

bool LibraryManager::editOrderRule(std::string key, std::shared_ptr<OrderRule> rule) {
  if (removeOrderRule(key)) {
    return false;
  }

  return addOrderRule(rule);
}

bool LibraryManager::removeTag(std::string key) {
  if (tags.erase(key) == 0) {
    return false;
  }

  update();

  return true;
}

bool LibraryManager::removeDomainRule(std::string key) {
  if (domainRules.erase(key) == 0) {
    return false;
  }

  update();

  return true;
}

bool LibraryManager::removeOrderRule(std::string key) {
  if (orderRules.erase(key) == 0) {
    return false;
  }

  update();

  return true;
}

}
