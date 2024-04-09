
#include "DomainRule.h"

#include <memory>
#include <string>
#include <vector>

#include "DomainCondition.h"
#include "Song.h"


namespace MediaPro {

DomainRule::DomainRule() {

}

DomainRule::~DomainRule() {

}

bool DomainRule::inSet(std::shared_ptr<Song> song) {
  return false;
}

bool DomainRule::remove(int index) {
  return false;
}

bool DomainRule::add(DomainCondition condition) {
  return false;
}

void DomainRule::setName(std::string newName) {
  name = newName;
}

std::vector<DomainCondition> DomainRule::getConditions() {
  return conditions;
}

std::string DomainRule::getName() {
  return name;
}

}
