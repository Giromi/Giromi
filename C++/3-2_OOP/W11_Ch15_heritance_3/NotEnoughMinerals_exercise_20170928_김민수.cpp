#include <iostream>
#include <stdexcept>

enum e_const { COST_Z = 10, COST_T = 10, COST_P = 10 };

class Unit {
public:
    Unit(const std::string& race) : race(race) {};

    virtual void createUnit(void) {
        throw NotChoiceRace();
    };

    class NotEnoughMinerals : public std::exception {
    public:
        NotEnoughMinerals(const std::string& race) {
            msg = "Not enough minerals! (" + race + ")";
        };
        const char* what(void) const noexcept { return msg.c_str(); };
    private:
        std::string msg;
   };

    class NotChoiceRace : public std::exception {
    public:
        const char* what(void) const noexcept override {
            return "Not yet choice race";
        };
    };

    /* not need due to protected */
    const unsigned int getMinerals() { return mineral; }

protected:
    void isPossibleCreateUnit(const unsigned int cost) {
        if (mineral < cost) {
            throw NotEnoughMinerals(race);
        }
    };
    void printCreateMessage(void) {
        std::cout << "A " << race << " unit has been created. "
            << "Remaining minerals: " << mineral << std::endl;
    };

    unsigned int mineral = 100;
    const std::string race;
};

    /*
    1. virtual function인 createUnit()을 만드세요. 
        - createUnit()은 unit을 create하는 함수입니다. 
        - 하나의 unit을 만들 때마다 10의 mineral을 소모하게 됩니다. 
        - unit이 성공적으로 만들어진 경우에는 unit이 성공적으로 만들어졌다는 메세지와 함께 남은 mineral을 출력합니다. 
        - 만약 보유한 mineral이 10보다 적을 경우에는 예외처리를 해서 Mineral이 없다는 메시지를 띄우세요. 
    
    2.  mineral variable을 protected로 만드세요. 
        - mineral은 모든 종족이 동일하게 100씩 갖고 게임이 시작됩니다. 
        - mineral variable을 protected로 만듦으로써 Unit class를 상속할 모든 class들은 동일한 양의 mineral을 상속하게 됩니다. 
    
    3. race variable을 protected로 만드세요. 
        - 모든 종족은 각자의 종족 이름을 갖고 있습니다. 
        - 이 특성을 자식 class들이 동일하게 상속할 수 있도록 protected로 만드세요. 

    4. protected로 만들어진 변수들을 사용할 때에 getter function이 필요한지 확인하세요. (e.g., getMinerals())
    */

class ZergUnit : public Unit {
public:
    ZergUnit(void) : Unit("Zerg"), cost_z(COST_Z) { };
    /*
    ZergUnit class의 constructor를 작성하세요. 
    (Hint: race) 
    */
   // Write your code here. 
    void createUnit() {
        isPossibleCreateUnit(cost_z);
        mineral -= cost_z;
        printCreateMessage();
    }
private:
    const unsigned int cost_z;

};

class ProtossUnit : public Unit {
public:
    ProtossUnit(void) : Unit("Protoss"), cost_p(COST_P) { };
    /*
    ProtossUnit class의 constructor를 작성하세요. 
    (Hint: race) 
    */
   // Write your code here. 
    void createUnit() {
        isPossibleCreateUnit(cost_p);
        mineral -= cost_p;
        printCreateMessage();
    }
private:
    const unsigned int cost_p;
};

class TerranUnit : public Unit {
public:
    TerranUnit(void) : Unit("Terran"), cost_t(COST_T) { };
    /*
    TerranUnit class의 constructor를 작성하세요. 
    (Hint: race) 
    */
   
    void createUnit() {
        isPossibleCreateUnit(cost_t);
        mineral -= cost_t;
        printCreateMessage();
    }
private:
    const unsigned int cost_t;
};


// Function to randomly choose a unit and call its createUnit() function
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

        Unit unit("Hello"); //안봐도 비디오 default 없고, 인자들어간 생성자가 있겠구나

        ZergUnit zergUnit;
        ProtossUnit protossUnit;
        TerranUnit terranUnit;

        /* unit.createUnit(); 예외 필요 */
        unit.createUnit(); //? -> 논리에 의해서 막아놔야함
        zergUnit.createUnit();
        terranUnit.createUnit();
        protossUnit.createUnit();

        // Trying to create a unit with not enough minerals
        for (int i = 0; i < 50; ++i) {
            randomCreateUnit(zergUnit, terranUnit, protossUnit);
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

