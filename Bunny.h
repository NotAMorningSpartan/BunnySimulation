//Tyler Kness-Miller
//Bunny.h

#include <iostream>
using namespace std;

class Bunny {
private:
    string gender;
    string color;
    int age;
    string name;
    bool radioactive_mutant_vampire_bunny;

    int getRandomNumber(){
        return 1 + ( rand() % ( 100 - 1 + 1 ) );
    }

    void setGender(){
        string genders[] = {"male", "female", "genderX"};
        int ran = getRandomNumber();
        if(ran > 53) {
            gender = genders[0];
        }
        else if(ran > 6){
            gender = genders[1];
        }
        else{
            gender = genders[2];
        }
    }
    void setColor(){
        string colors[] = {"white", "brown", "black", "spotted"};
        color = colors[getRandomNumber() / 25];
    }
    void setName(){
        string names[] = {"Bob", "Mary", "Joe", "Susan", "Jimmy", "Quark", "Karen", "Kim", "Susan", "Roberto", "Juan", "Kirk", "Earl", "Liam", "Bert", "Zod", "Shepard", "Wrex", "Justin", "Dan"};
        name = names[getRandomNumber() / 5];
    }
    void setMutant(){
        int ran = getRandomNumber();
        if(ran > 96){
            radioactive_mutant_vampire_bunny = true;
        }
        else{
            radioactive_mutant_vampire_bunny = false;
        }
    }
public:
    /// Function that adds a yar to the age and checks whether the bunny will die.
    /// \return Returns false when the bunny will die.
    bool addAgeCheck(){
        age++;
        if(radioactive_mutant_vampire_bunny && age >= 50){
            cout << "Bunny " << name << " died at age " << age << endl;
            return false;
        }
        if(!radioactive_mutant_vampire_bunny && age >= 10){
            cout << "Bunny " << name << " died at age " << age << endl;
            return false;
        }
        return true;
    }
    Bunny(){
        age = 0;
        setGender();
        setColor();
        setName();
        setMutant();
    }
};