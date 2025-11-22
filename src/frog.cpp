#include "frog.h"
#include "visitor.h"

Frog::Frog(const std::string& name, double x, double y) 
    : NPC(name, x, y) {}

std::string Frog::getType() const {
    return "Frog";
}

void Frog::accept(Visitor& visitor) {
    visitor.visit(*this);
}
