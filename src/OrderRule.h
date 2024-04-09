#ifndef ORDERRULE_H
  #define ORDERRULE_H

#include <memory>
#include <string>
#include <vector>

#include "DomainCondition.h"
#include "Song.h"


namespace MediaPro {

class OrderRule {

private:
  std::string name;
  int type;
  int attribute;

public:
  OrderRule();
  ~OrderRule();

  std::vector<int> next(std::vector<std::shared_ptr<Song>> songs);
  bool isUnique();

  void setName(std::string newName);
  void set(int t, int a);

  std::string getName();
  int getType();
  int getAttribute();
};

}

#endif
