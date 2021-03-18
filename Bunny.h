//Tyler Kness-Miller
//Bunny.h

#include <iostream>
#include <random>
using namespace std;

class Bunny {
private:
    string gender;
    string color;
    int age;
    string name;
    bool radioactive_mutant_vampire_bunny;


    int getRandomNumber(int lower, int upper){
        //return 1 + ( rand() % ( 100 - 1 + 1 ) );
        //return rand() % 100;
        random_device generator;
        mt19937 mt(generator());
        uniform_int_distribution<int> dist(lower, upper);
        return dist(mt);

    }

    /// Set the gender of a bunny.
    void setGender() {
        string genders[] = {"male", "female", "genderX"};
        int ran = getRandomNumber(1,100);
        //cout << to_string(ran) << endl;
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
        int ran = getRandomNumber(1,100);
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
        color = colors[getRandomNumber(0,3)];
    }
    void setName(){
        string names[] = {"Bob", "Mary", "Joe", "Susan", "Jimmy", "Quark", "Karen", "Kim", "Susan", "Roberto", "Juan", "Kirk", "Earl", "Liam", "Bert", "Zod", "Shepard", "Wrex", "Justin", "Dan", "Jonah"};
        name = names[getRandomNumber(0,20)];
    }
    void setMutant(){
        int ran = getRandomNumber(1,100);
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
        return ageCheck();
    }
    bool ageCheck(){
        if(radioactive_mutant_vampire_bunny && age >= 50){
            return false;
        }
        if(!radioactive_mutant_vampire_bunny && age >= 10){
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
    int getAge(){
        return age;
    }
    void transformMutant(){
        radioactive_mutant_vampire_bunny = true;
    }

    /// Constructor for the Bunny class. Used when the color is not known. All attributes are randomly assigned according to project directions.
    Bunny(){
        age = 0;
        setGender();
        setColor();
        setName();
        radioactive_mutant_vampire_bunny = false;
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