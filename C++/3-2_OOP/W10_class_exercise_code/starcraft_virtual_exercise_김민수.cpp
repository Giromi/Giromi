#include <iostream>
#include <string>

class Unit {
public:
    Unit(const std::string& name) : name(name) { // class compile
        std::cout << "Unit Constructor" << std::endl; 
    }
    virtual ~Unit(void) {                               // heap 없기 때문에
        std::cout << "Unit Destructor" << std::endl;
    }

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
    ProtossUnit(void) : Unit("Empty") { }
    ProtossUnit(const std::string &name) : Unit(name) { 
        std::cout << "Process Constructor" << std::endl;
    }
    ~ProtossUnit(void) {
        std::cout << "ProtossUnit Destructor" << std::endl;
    }
                       //
    void attack(void) const {
        std::cout << getName() << " (Protoss) attacks with psionic energy." << std::endl;
    }
};

class TerranUnit : public Unit {
public:
    TerranUnit(const std::string &name) : Unit(name) { 
        std::cout << "Terran Constructor" << std::endl;
    }
    ~TerranUnit(void) {
        std::cout << "TerranUnit Destructor" << std::endl;
    }
    void attack(void) const override {
        std::cout << getName() << " (Terran) attacks with bullets and guns." << std::endl;
    }
};

class ZergUnit : public Unit {
public:
    ZergUnit(const std::string &name) : Unit(name) { 
        std::cout << "Zerg Constructor" << std::endl;
    }
    ~ZergUnit(void) {
        std::cout << "ZergUnit Destructor" << std::endl;
    }
    void attack(void) const {
        std::cout << getName() << " (Zerg) attacks with biological weapons." << std::endl;
    }
};

int main() {

    std::cout << std::endl;

    {
        std::cout << ">>> Default Test <<<" << std::endl;

        ProtossUnit zealot("Zealot");
        TerranUnit marine("Marine");
        ZergUnit zergling("Zergling");

        std::cout << "------------------" << std::endl;

        Unit* units[] = {&zealot, &marine, &zergling};


        for (Unit* unit : units) {
            unit->attack();  // Calls the appropriate attack() based on the unit's type
        }

        std::cout << "------------------" << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << ">>> Reference Test <<< " << std::endl;

        ProtossUnit zealot("Zealot");
        ProtossUnit empty;
        TerranUnit marine("Marine");
        ZergUnit zergling("Zergling");

        std::cout << "------------------" << std::endl;

        Unit unitsVal[] = {zealot, marine, zergling, empty};
        Unit (&unitsRef)[4] = unitsVal;

        // typecasting virtual 효력잃는다?
        for (Unit& unit : unitsRef) {
            unit.attack();  // Calls the appropriate attack() based on the unit's type
        }

        //
        std::cout << "------------------" << std::endl;

    }

    std::cout << std::endl;

    {
        std::cout << ">>> Upcasting stack Test <<< " << std::endl;

        Unit zealot = ProtossUnit("Zealot");
        Unit empty = ProtossUnit();
        Unit marine = TerranUnit("Marine");
        Unit zergling = ZergUnit("Zergling");

        std::cout << "------------------" << std::endl;

        Unit units[] = {zealot, empty, marine, zergling};

        // typecasting virtual 효력잃는다?
        for (Unit& unit : units) {
            unit.attack();  // Calls the appropriate attack() based on the unit's type
        }
        //
        std::cout << "------------------" << std::endl;

    }

    std::cout << std::endl;

    {
        std::cout << ">>> Upcasting Heap Test <<< " << std::endl;

        Unit* zealot = new ProtossUnit("Zealot");
        Unit* empty = new ProtossUnit();
        Unit* marine = new TerranUnit("Marine");
        Unit* zergling = new ZergUnit("Zergling");

        std::cout << "------------------" << std::endl;

        Unit unitsValArray[] = {*zealot, *empty, *marine, *zergling};
        for (Unit& unit : unitsValArray) {
            unit.attack();  // Calls the appropriate attack() based on the unit's type
        }

        Unit* unitsPtrArray[] = {zealot, empty, marine, zergling};
        for (Unit* unit : unitsPtrArray) {
            unit->attack();  // Calls the appropriate attack() based on the unit's type
        }
        //
        std::cout << "------------------" << std::endl;

        delete zealot;
        delete marine;
        delete empty;
        delete zergling;

        std::cout << "@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
        system("leaks -q a.out");
        std::cout << "@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
    }

    std::cout << "------------------" << std::endl;

    return 0;
}


/*
 *
 * Q. 출력물이 많아도 상관없는 지?
 *
 * Q. orthdox canonical form에서 대해서는 배우지 않는지?
 * A. x
 *
 * Q. virtual 소멸자를 붙이면 왜 upcasting 상황에서
 * Q. mac vs linux
 *
 */



