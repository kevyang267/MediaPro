
#include "DomainCondition.h"

#include <memory>
#include <string>
#include <vector>

#include <QDateTime>

#include "Song.h"
#include "Tag.h"


namespace MediaPro {

DomainCondition::DomainCondition() {

}

DomainCondition::~DomainCondition() {

}

bool DomainCondition::isValidSong(std::shared_ptr<Song> song) {
    return false;
}

}
