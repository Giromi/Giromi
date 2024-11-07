#include <iostream>
#include <string>

class Unit {
public:
    Unit(const std::string& name) : name(name) {}

    virtual void attack() const {
        std::cout << name << " attacks." << std::endl;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

class ProtossUnit : public Unit {
public:
    ProtossUnit(const std::string& name) : Unit(name) {}

    void attack() const override {
        std::cout << getName() << " (Protoss) attacks with psionic energy." << std::endl;
    }
};

class TerranUnit : public Unit {
public:
    TerranUnit(const std::string& name) : Unit(name) {}

    void attack() const override {
        std::cout << getName() << " (Terran) attacks with bullets and guns." << std::endl;
    }
};

class ZergUnit : public Unit {
public:
    ZergUnit(const std::string& name) : Unit(name) {}

    void attack() const override {
        std::cout << getName() << " (Zerg) attacks with biological weapons." << std::endl;
    }
};

int main() {
    ProtossUnit zealot("Zealot");
    TerranUnit marine("Marine");
    ZergUnit zergling("Zergling");

    Unit* units[] = {&zealot, &marine, &zergling};

    for (Unit* unit : units) {
        unit->attack();  // Calls the appropriate attack() based on the unit's type
    }

    return 0;
}