
#include "OrderRule.h"

#include <memory>
#include <string>
#include <vector>

#include "DomainCondition.h"
#include "Song.h"


namespace MediaPro {

OrderRule::OrderRule() {

}

OrderRule::~OrderRule() {

}

std::vector<int> OrderRule::next(std::vector<std::shared_ptr<Song>> songs) {
    return std::vector<int>();
}

bool OrderRule::isUnique() {
    return false;
}

void OrderRule::setName(std::string newName) {
    name = newName;
}

void OrderRule::set(int t, int a) {
    type = t;
    attribute = a;
}

std::string OrderRule::getName() {
    return name;
}

int OrderRule::getType() {
    return type;
}

int OrderRule::getAttribute() {
    return attribute;
}

}
