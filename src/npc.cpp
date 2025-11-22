#include "npc.h"
#include "dragon.h"
#include "frog.h"
#include "knight.h"
#include <sstream>

NPC::NPC(const std::string& name, double x, double y) 
    : name(name), x(x), y(y), alive(true) {}

std::string NPC::getName() const {
    return name;
}

double NPC::getX() const {
    return x;
}

double NPC::getY() const {
    return y;
}

bool NPC::isAlive() const {
    return alive;
}

void NPC::kill() {
    alive = false;
}

double NPC::distanceTo(const NPC& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

void NPC::save(std::ostream& os) const {
    os << getType() << " " << name << " " << x << " " << y << "\n";
}

std::shared_ptr<NPC> NPC::load(std::istream& is) {
    std::string type, name;
    double x, y;
    
    if (!(is >> type >> name >> x >> y)) {
        return nullptr;
    }
    
    if (type == "Dragon") {
        return std::make_shared<Dragon>(name, x, y);
    } else if (type == "Frog") {
        return std::make_shared<Frog>(name, x, y);
    } else if (type == "Knight") {
        return std::make_shared<Knight>(name, x, y);
    }
    
    return nullptr;
}
