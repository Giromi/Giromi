#include <iostream>
#include <string>

// 무기 클래스 템플릿
template <typename T>
class Weapon {
public:
    Weapon(T dmg) : damage(dmg) { }

    // 무기 사용 함수
    void use() const {
        std::cout << "Dealing damage: " << damage << std::endl;
    }
private:
    T damage;
};

// 게임 캐릭터 클래스 템플릿
template <typename WeaponType>
class GameCharacter {
public:
    GameCharacter(const std::string& charName, const WeaponType& charWeapon) 
        : name(charName), weapon(charWeapon) { }

    // 캐릭터가 무기를 사용하는 함수
    void attack() const {
        std::cout << name << " attacks with ";
        weapon.use();
    }
private:
    std::string name;
    WeaponType weapon;
};

int main() {
    // 다양한 종류의 무기 생성
    Weapon<int> sword(20);
    Weapon<double> bow(15.5);
    Weapon<std::string> magicWand("Fireball");

    // 각각의 무기를 사용하는 게임 캐릭터 생성
    GameCharacter< Weapon<int> > warrior("Warrior", sword);
    GameCharacter< Weapon<double> > archer("Archer", bow);
    GameCharacter< Weapon<std::string> > wizard("Wizard", magicWand);

    // 각각의 캐릭터가 무기를 사용
    warrior.attack();
    archer.attack();
    wizard.attack();

    return 0;
}
