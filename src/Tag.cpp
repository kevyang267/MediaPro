
#include "Tag.h"

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <QColor>

#include "Song.h"


namespace MediaPro {

Tag::Tag() {

}

Tag::~Tag() {

}

bool Tag::addSong(std::shared_ptr<Song> song) {
  return taggedSongs.try_emplace(song->getPath(), song).second;
}

bool Tag::removeSong(std::string key) {
  if (taggedSongs.erase(key) == 0) {
    return false;
  }

  return true;
}

std::vector<std::shared_ptr<Song>> Tag::songs() {
  std::vector<std::shared_ptr<Song>> list;

  for (auto& song : taggedSongs) {
    list.push_back(song.second);
  }

  return list;
}

void Tag::setName(std::string newName) {
  name = newName;
}

void Tag::setColour(QColor newColour) {
  colour = newColour;
}

std::string Tag::getName() {
  return name;
}

QColor Tag::getColour() {
  return colour;
}

}
