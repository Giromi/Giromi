//DISPLAY 15.13 More Inheritance with Virtual Functions
//Program to illustrate use of a virtual function
//to defeat the slicing problem.

#include <string>
#include <iostream>
using namespace std;

class Pet
{
public:
    virtual void print();
    string name;
};

class Dog : public Pet
{
public:
    void print();        //Keyword virtual not needed, but put
                         //here for clarity. (It is also good style!)
    string breed;
};

class CuteDog : public Dog {
public:
    void print();
    string color;
};

void CuteDog::print() {
    cout << "name: " << name << endl;
    cout << "breed: " << breed << endl;
    cout << "color: " << color << endl;
}


void Dog::print()
{
    cout << "name: " << name << endl;
    cout << "breed: " << breed << endl;
}

void Pet::print()

{
    cout << "name: " << endl;//Note no breed mentioned
}

int main()
{
    Dog vDog;
    Pet vPet;



    vDog.name = "Tiny";
    vDog.breed = "Great Dane";
    vPet = vDog;


    //vPet.breed; is illegal since class Pet has no member named breed

    vPet.print(); // What gets printed?
    Dog *pDog;
    pDog = new Dog;
    pDog->name = "Tiny";
    pDog->breed = "Great Dane";

    Pet *pPet;
    pPet = pDog;
    pPet->print(); // These two print the same output:
    pDog->print(); // name: Tiny breed: Great Dane

    Pet& rPet = vDog;
    rPet.print(); // These two print the same output:
    vDog.print(); // name: Tiny breed: Great Dane
                  //
    Pet& rPet2 = *pDog;
    rPet2.print(); // These two print the same output:
    pDog->print(); // name: Tiny breed: Great Dane

    CuteDog vCuteDog;
    Pet& rPet3 = vCuteDog;
    CuteDog *pCuteDog;
    pCuteDog = &vCuteDog;
    pCuteDog->name = "Hell";
    pCuteDog->breed = "what the fxxx";
    pCuteDog->color = "red";
    rPet3.print(); // These two print the same output:
    vCuteDog.print(); // name: Tiny breed: Great Dane


    //The following, which accesses member variables directly
    //rather than via virtual functions, would produce an error:
    //cout << "name: " << pPet->name << "  breed: "
    //     << pPet->breed << endl;
    //generates an error message: 'class Pet' has no member
    //named 'breed' .
    //See Pitfall section "Not Using Virtual Member Functions"
    //for more discussion on this.

    return 0;
}
