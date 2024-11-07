#include <iostream>
#include <stdexcept>

class NoMineral{};

class Unit {
public:
    Unit(const std::string& race) : race(race) {}

    virtual void createUnit() {
        if (minerals < 10) {
            throw NoMineral();
        }
        minerals -= 10;
        std::cout << "A " << race << " unit has been created. Remaining minerals: " << minerals << std::endl;
    }

    int getMinerals() const {
        return minerals;
    }

protected:
    int minerals = 100;
    std::string race;
};

class ZergUnit : public Unit {
public:
    ZergUnit() : Unit("Zerg") {}
};

class ProtossUnit : public Unit {
public:
    ProtossUnit() : Unit("Protoss") {}
};

class TerranUnit : public Unit {
public:
    TerranUnit() : Unit("Terran") {}
};

void randomCreateUnit(Unit& zerg, Unit& terran, Unit& protoss) {
    int randomValue = rand() % 3;  // Generate a random number between 0 and 2

    switch (randomValue) {
        case 0:
            zerg.createUnit();
            break;
        case 1:
            terran.createUnit();
            break;
        case 2:
            protoss.createUnit();
            break;
    }
}


int main() {
    try {
        srand(static_cast<unsigned>(time(0)));  // Seed for random number generation

        ZergUnit zergUnit;
        ProtossUnit protossUnit;
        TerranUnit terranUnit;

        // Trying to create a unit with not enough minerals
        for (int i = 0; i < 31; ++i) {
        randomCreateUnit(zergUnit, terranUnit, protossUnit);
        }
        
    } catch (NoMineral) {
        std::cerr << "Exception caught: Not enough Minerals!" << std::endl;
    }

    return 0;
}

