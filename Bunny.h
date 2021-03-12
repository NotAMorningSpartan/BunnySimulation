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

    static int getRandomNumber(){
        //return 1 + ( rand() % ( 100 - 1 + 1 ) );
        return rand() % 100;
    }

    /// Set the gender of a bunny.
    void setGender() {
        string genders[] = {"male", "female", "genderX"};
        int ran = getRandomNumber();
        if (ran > 53) {
            gender = genders[0];
        } else if (ran > 6) {
            gender = genders[1];
        } else {
            gender = genders[2];
        }
    }

    /// Overloaded method that sets the color of the bunny. Color is chosen randomly between mother and father.
    /// \param colorM The color of the mother.
    /// \param colorF The color of the father.
    void setColor(string colorM, string colorF){
        int ran = getRandomNumber();
        if(ran > 50){
            color = colorM;
        }
        else{
            color = colorF;
        }
    }

    /// Overloaded method that sets the color of the bunny. Color is chosen randomly from list of all available options.
    void setColor(){
        string colors[] = {"white", "brown", "black", "spotted"};
        color = colors[getRandomNumber() / 25];
    }
    void setName(){
        string names[] = {"Bob", "Mary", "Joe", "Susan", "Jimmy", "Quark", "Karen", "Kim", "Susan", "Roberto", "Juan", "Kirk", "Earl", "Liam", "Bert", "Zod", "Shepard", "Wrex", "Justin", "Dan", "Jonah"};
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
    /// Function that adds a year to the age and checks whether the bunny will die.
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

    string getColor(){
        return color;
    }
    bool getMutant(){
        return radioactive_mutant_vampire_bunny;
    }
    string getGender(){
        return gender;
    }
    string getName(){
        return name;
    }

    /// Constructor for the Bunny class. Used when the color is not known. All attributes are randomly assigned according to project directions.
    Bunny(){
        age = 0;
        setGender();
        setColor();
        setName();
        setMutant();
    }

    /// Constructor for the Bunny class. Used when the color of the father and mother are known.
    /// \param colorM The color of the mother.
    /// \param colorF The color of the father.
    Bunny(string colorM, string colorF){
        age = 0;
        setGender();
        setColor(colorM, colorF);
        setName();
        setMutant();
    }
};