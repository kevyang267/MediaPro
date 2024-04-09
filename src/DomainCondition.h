#ifndef DOMAINCONDITION_H
  #define DOMAINCONDITION_H

#include <memory>
#include <string>
#include <vector>

#include <QDateTime>

#include "Song.h"
#include "Tag.h"

// TODO enum for types.


namespace MediaPro {

class DomainCondition {

private:
  int type;

  std::string str;
  int duration;
  QDateTime date;
  std::shared_ptr<Tag> tag;

public:
  DomainCondition();
  ~DomainCondition();

  bool isValidSong(std::shared_ptr<Song> song);
};

}

#endif
