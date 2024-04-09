#ifndef DOMAINRULE_H
  #define DOMAINRULE_H

#include <memory>
#include <string>
#include <vector>

#include "DomainCondition.h"
#include "Song.h"


namespace MediaPro {

class DomainRule {

private:
  std::string name;
  std::vector<DomainCondition> conditions;

public:
  DomainRule();
  ~DomainRule();

  bool inSet(std::shared_ptr<Song> song);

  bool remove(int index);
  bool add(DomainCondition condition);
  void setName(std::string newName);

  std::vector<DomainCondition> getConditions();
  std::string getName();
};

}

#endif
