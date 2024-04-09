
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <QDateTime>

#include "Tag.h"


using namespace MediaPro;

Song::Song(std::string path, std::string title, std::string album, std::vector<std::string> artists, int length, QDateTime date) :
    path(path),
    title(title),
    album(album),
    artists(artists),
    length(length),
    date(date) {

}

Song::~Song() {

}

bool Song::addTag(std::shared_ptr<Tag> tag) {
  if (hasTag(tag)) {
    return false;
  }

  tags.emplace_back(tag);

  return true;
}

bool Song::hasTag(std::shared_ptr<Tag> tag) {
  for (auto t = tags.begin(); t != tags.end(); t++) {
    if ((*t)->getName() == tag->getName()) {
      return true;
    }
  }

  return false;
}

bool Song::removeTag(std::shared_ptr<Tag> tag) {
  for (auto t = tags.begin(); t != tags.end(); t++) {
    if ((*t)->getName() == tag->getName()) {
      tags.erase(t);
      return true;
    }
  }

  return false;
}

std::string Song::getPath() {
  return path;
}

std::string Song::getTitle() {
  return title;
}

std::string Song::getAlbum() {
  return album;
}

std::string Song::getArtist() {
  return artists[0];
}

std::vector<std::string> Song::getArtists() {
  return artists;
}

int Song::getLength() {
  return length;
}

QDateTime Song::getDate() {
  return date;
}

std::vector<std::shared_ptr<Tag>> Song::getTags() {
  return tags;
}
