#include <iostream>
#include <vector>
#include <string>

// 스킬 클래스 템플릿
template <typename T>
class Skill {
public:
    Skill(T damage, int initialManaCost)
        : _damage(damage), _manaCost(initialManaCost) { }
/* 
    1. Type parameter를 type으로 갖는 damage 멤버 변수를 만드세요. 
    2. int type을 갖는 manaCost 멤버 번수를 만드세요. 
    3. Skill 클래스의 constructor를 만드세요.
        - Arguments: damage, initialManaCost
*/

    // Write your code here. 
    const T& getDamage() const { return _damage; }
    const int& getManaCost() const { return _manaCost; }

private:
    T       _damage;
    int     _manaCost;
};




// 게임 캐릭터 클래스 템플릿
template <typename SkillType>
class GameCharacter {

/* 
    1. 게임 캐릭터는 name(string), health(int), mana(int), SkiilType을 타입으로 갖는 skill(위 클래스 Skill 참고)을 갖습니다. 
    2. name, mana, skill을 argument로 받아 초기화하고, health는 100으로 초기화하는 constructor를 만드세요.
*/

    // Write your code here. 
public:
    GameCharacter(const std::string& name, const int& mana, const SkillType& skill)
        : name(name), mana(mana), skill(skill), health(100) {}

    template <typename SkillTypeOpp>
    void Attack(GameCharacter<SkillTypeOpp>& opponent) {
        if (mana < skill.getManaCost()) {
            std::cout << "[INFO] Not enough mana" << std::endl << std::endl;
            return ;
        }
        if (health == 0) {
            std::cout << "[INFO] I'm already dead" << std::endl << std::endl;
            return ;
        }
        if (opponent.health == 0) {
            std::cout << "[INFO] he/she is already dead" << std::endl << std::endl;
            return ;
        }
        std::cout << name << " attacks " 
            << opponent.name  << " with " << skill.getDamage() << " damage." << std::endl;
        mana -= skill.getManaCost();
        if (opponent.health < skill.getDamage()) { opponent.health = 0; } 
        else { opponent.TakeDamage(static_cast<int>(skill.getDamage())); }
        std::cout << opponent.name << "'s remaining health: " << opponent.health << std::endl;
        std::cout << name << "'s remaining mana: " << mana << std::endl << std::endl;;
    }
    void TakeDamage(const int damage) {
        std::cout << name << " takes " << damage << " damage." << std::endl;
        health -= damage;
    }

    std::string name;
    int         health;
    int         mana;
    SkillType   skill;


/* 
    1. void Attack function을 아래 설명에 따라 만드세요. 
        - skill을 사용하는 데에 필요한 마나 이상의 마나가 남아있다면 Attack을 수행합니다. 
        - Attack 수행시 마나가 소모됩니다. 
        - Attack을 받는 상대는 TakeDamage function을 통해 데미지를 받습니다. 
        - 마나가 충분하지 않은 경우, 마나가 충분하지 않다는 메시지를 출력합니다. 

*/
    // Write your code here. 

/* 
    1. void TakeDamage function을 아래 설명에 따라 만드세요. 
        - damage를 받은 만큼 health가 감소합니다. 
*/

    // Write your code here. 








}; 


template <typename T>
int print(T& t) {
    std::cout << t << std::endl;
    return 0;
}


int main() {
    // 다양한 종류의 스킬 생성
    {
        Skill<int> sword(20, 2);
        Skill<int> bow(15, 3);
        Skill<int> magicWand(12, 4);

        // 각각의 스킬을 사용하는 게임 캐릭터 생성
        GameCharacter<Skill<int> > warrior("Warrior", 100, sword);
        GameCharacter<Skill<int> > archer("Archer", 50, bow);
        GameCharacter<Skill<int> > wizard("Wizard", 70, magicWand);

        // 각각의 캐릭터가 공격

        while (warrior.health > 0 && archer.health > 0){
            std::cout << "health of two players: " << warrior.health << " ," << archer.health << std::endl; 

            warrior.Attack(archer);
            archer.Attack(wizard);
        }
    }

/* 
What should we do to make the program run the code below?
*/
    std::cout << "==============================" << std::endl << std::endl;

    // {
    //     Skill<int> sword(20, 2);
    //     Skill<double> bow(15.5, 3);
    //     Skill<std::string> magicWand("Fireball", 4);
    //
    //     // 각각의 스킬을 사용하는 게임 캐릭터 생성
    //     GameCharacter<Skill<int> > warrior("Warrior", 100, sword);
    //     GameCharacter<Skill<double> > archer("Archer", 50, bow);
    //     GameCharacter<Skill<std::string> > wizard("Wizard", 70, magicWand);
    //
    //     // 각각의 캐릭터가 공격
    //     warrior.Attack(archer);
    //     archer.Attack(wizard);
    //     archer.Attack(wizard);
    //     archer.Attack(wizard);
    //     archer.Attack(wizard);
    //     archer.Attack(wizard);
    //     archer.Attack(wizard);
    //     archer.Attack(wizard);
    //     archer.Attack(wizard);
    //
    //     warrior.Attack(archer);
    //     warrior.Attack(archer);
    //     warrior.Attack(archer);
    //     warrior.Attack(archer);
    //     warrior.Attack(archer);
    //     warrior.Attack(archer);
    //
    //     archer.Attack(wizard);
    //
    //     // wizard.Attack(warrior);
    // }


}





