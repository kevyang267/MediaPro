
#include "Queue.h"

#include <memory>
#include <vector>

#include "Song.h"
#include "OrderRule.h"


namespace MediaPro {

Queue::Queue() {

}

Queue::~Queue() {

}

void Queue::refresh() { // TODO make new queue from current order rules and song set.
  queue = songSet;
  index = 0;
}

std::shared_ptr<Song> Queue::pop() {
  auto& ret = queue[index];
  index = (index + 1) % queue.size();

  return ret;
}

std::vector<std::shared_ptr<Song>> Queue::list() {
  return queue;
}

void Queue::setRules(std::vector<std::shared_ptr<OrderRule>> rules) {
  orderRules = rules;
  refresh();
}

void Queue::setSongSet(std::vector<std::shared_ptr<Song>> songs) {
  this->songSet = songs;
}

}
