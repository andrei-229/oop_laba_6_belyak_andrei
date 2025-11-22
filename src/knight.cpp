#include "knight.h"
#include "visitor.h"

Knight::Knight(const std::string& name, double x, double y) 
    : NPC(name, x, y) {}

std::string Knight::getType() const {
    return "Knight";
}

void Knight::accept(Visitor& visitor) {
    visitor.visit(*this);
}
