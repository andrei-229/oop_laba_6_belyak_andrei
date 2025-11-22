#include "dragon.h"
#include "visitor.h"

Dragon::Dragon(const std::string& name, double x, double y) 
    : NPC(name, x, y) {}

std::string Dragon::getType() const {
    return "Dragon";
}

void Dragon::accept(Visitor& visitor) {
    visitor.visit(*this);
}
