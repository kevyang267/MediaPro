#ifndef SONG_H
  #define SONG_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <QDateTime>

#include "Tag.h"


namespace MediaPro {

class Song {

private:
  std::string path;
  std::string title;
  std::string album;
  std::vector<std::string> artists;
  int length;
  QDateTime date;
  std::vector<std::shared_ptr<Tag>> tags;

public:
  Song(std::string path, std::string title, std::string album, std::vector<std::string> artists, int length, QDateTime date);
  ~Song();

  bool addTag(std::shared_ptr<Tag> tag);
  bool hasTag(std::shared_ptr<Tag> tag);
  bool removeTag(std::shared_ptr<Tag> tag);

  std::string getPath();
  std::string getTitle();
  std::string getAlbum();
  std::string getArtist();
  std::vector<std::string> getArtists();
  int getLength();
  QDateTime getDate();
  std::vector<std::shared_ptr<Tag>> getTags();
};

}

#endif
