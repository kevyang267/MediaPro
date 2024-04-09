#ifndef QUEUE_H
  #define QUEUE_H

#include <memory>
#include <vector>

#include "Song.h"
#include "OrderRule.h"


namespace MediaPro {

class Queue {

private:
  std::vector<std::shared_ptr<Song>> queue;
  int index;

  std::vector<std::shared_ptr<OrderRule>> orderRules;
  std::vector<std::shared_ptr<Song>> songSet;

public:
  Queue();
  ~Queue();

  void refresh();
  std::shared_ptr<Song> pop();
  std::vector<std::shared_ptr<Song>> list();

  void setRules(std::vector<std::shared_ptr<OrderRule>> rules);
  void setSongSet(std::vector<std::shared_ptr<Song>> songs);
};

}

#endif