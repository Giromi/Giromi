#include <iostream>
#include <vector>
#include <string>

// 스킬 클래스 템플릿
template <typename T>
class Skill {
public:

/* 
    1. Type parameter를 type으로 하는 damage 멤버 변수를 만드세요. 
    2. int type을 갖는 manaCost 멤버 번수를 만드세요. 
    3. Skill 클래스의 constructor를 만드세요.
        - Arguments: damage, initialManaCost 
*/

// Write your code here. 

    T damage;
    int manaCost;

    Skill(T dmg, int initialManaCost) : damage(dmg), manaCost(initialManaCost) {}
};

// 게임 캐릭터 클래스 템플릿
template <typename SkillType>
class GameCharacter {
public:
    std::string name;
    int health;
    int mana;
    SkillType skill;

    GameCharacter<SkillType>(const std::string& charName, int initialMana, const SkillType& charSkill)
        : name(charName), health(100), mana(initialMana), skill(charSkill) {}

    // 캐릭터가 공격하는 함수
    template <typename OppType>
    void Attack(GameCharacter<OppType>& attacked) {
        std::cout << name << " attacks " << attacked.name << " with " << skill.damage << " damage." << std::endl;
        if (mana >= skill.manaCost) {
            attacked.TakeDamage(skill.damage);
            mana -= skill.manaCost;
            std::cout << name << "'s remaining mana: " << mana << std::endl;
        } else {
            std::cout << "Not enough mana!" << std::endl;
        }
    }

    // 캐릭터가 피해를 받는 함수
    void TakeDamage(int amount) {
        std::cout << name << " takes " << amount << " damage." << std::endl;
        health -= amount;
        std::cout << name << "'s" << "remaining health: " << health << std::endl << std::endl;
    }
};

int main() {
    // 다양한 종류의 스킬 생성
    //
    {
        Skill<int> sword(20, 2);
        Skill<int> bow(15, 3);
        Skill<int> magicWand(12, 4);

        // 각각의 스킬을 사용하는 게임 캐릭터 생성
        GameCharacter<Skill<int>> warrior("Warrior", 100, sword);
        GameCharacter<Skill<int>> archer("Archer", 50, bow);
        GameCharacter<Skill<int>> wizard("Wizard", 70, magicWand);

        // 각각의 캐릭터가 공격

        while (warrior.health > 0 && archer.health > 0){
            warrior.Attack(archer);
            archer.Attack(wizard);
        }
    }
    //
    // }
/* 
What should we do to make the program run the code below?
*/

    Skill<int> sword(20, 2);
    Skill<double> bow(15.5, 3);
    Skill<std::string> magicWand("Fireball", 4);

    // 각각의 스킬을 사용하는 게임 캐릭터 생성
    GameCharacter<Skill<int>> warrior("Warrior", 100, sword);
    GameCharacter<Skill<double>> archer("Archer", 50, bow);
    GameCharacter<Skill<std::string>> wizard("Wizard", 70, magicWand);

    // 각각의 캐릭터가 공격
    warrior.Attack(archer);
    archer.Attack(wizard);
}
