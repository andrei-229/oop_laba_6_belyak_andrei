#pragma once
#include <string>
#include <memory>
#include <cmath>

class Visitor;

class NPC {
protected:
    std::string name;
    double x, y;
    bool alive;

public:
    NPC(const std::string& name, double x, double y);
    virtual ~NPC() = default;

    virtual std::string getType() const = 0;
    virtual void accept(Visitor& visitor) = 0;
    
    std::string getName() const;
    double getX() const;
    double getY() const;
    bool isAlive() const;
    void kill();
    
    double distanceTo(const NPC& other) const;
    
    virtual void save(std::ostream& os) const;
    static std::shared_ptr<NPC> load(std::istream& is);
};
