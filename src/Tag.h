
#ifndef TAG_H
  #define TAG_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <QColor>

#include "Song.h"


namespace MediaPro {

class Tag {

private:
  std::string name;
  QColor colour;
  std::map<std::string, std::shared_ptr<Song>> taggedSongs;

public:
  Tag();
  ~Tag();

  bool addSong(std::shared_ptr<Song> song);
  bool removeSong(std::string key);
  std::vector<std::shared_ptr<Song>> songs();

  void setName(std::string newName);
  void setColour(QColor newColour);

  std::string getName();
  QColor getColour();
};

}

#endif // TAG_H