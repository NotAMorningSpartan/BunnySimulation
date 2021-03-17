//Tyler Kness-Miller
//BunnySimulation.h

#include "Bunny.h"
#include <vector>

class Simulation{
private:

public:
    vector<Bunny> males;
    vector<Bunny> females;
    vector<Bunny> genderXs;
    vector<Bunny> mutants;
    vector<Bunny*> bunnies;

    /// Creates a bunny and adds to vector. Bunny is created with all random attributes.
    void bunnyBorn(){
        Bunny bunny = Bunny();
        cout << "Bunny " << bunny.getName() << " was born!" << endl;
        if(bunny.getMutant()){
            mutants.push_back(bunny);
        }
        else if(bunny.getGender() == "male"){
            males.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else if(bunny.getGender() == "female"){
            females.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else{
            genderXs.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
    }

    /// Creates a bunny and adds to vector. Bunny is created using color of mother and father.
    /// \param colorM The color of the mother.
    /// \param colorF The color of the father.
    void bunnyBorn(string colorM, string colorF){
        Bunny bunny = Bunny(colorM, colorF);
        cout << "Bunny " << bunny.getName() << " was born!" << endl;
        if(bunny.getMutant()){
            mutants.push_back(bunny);
        }
        else if(bunny.getGender() == "male"){
            males.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else if(bunny.getGender() == "female"){
            females.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else{
            genderXs.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
    }

    /// Starts the vector of bunnies by filling it with 10 new ones.
    void startVector(){
        for(int i = 0; i < 10; i++){
            bunnyBorn();
        }
    }

    /// Adds a year of age to all bunny vectors and handles deletion when necessary.
    void addAge(){
        bunnies = vector<Bunny*>();
        for(int i = 0; i < males.size(); i++){
            cout << "Bunny Age: " << males[i].getAge() << endl;
            bool notDead = males[i].addAgeCheck();
            if(!notDead){
                males.erase(males.begin() + i);
                i = -1;
            }
            else{
                bunnies.push_back(&males[i]);
            }
        }
        for(int i = 0; i < females.size(); i++){
            cout << "Bunny Age: " << females[i].getAge() << endl;
            bool notDead = females[i].addAgeCheck();
            if(!notDead){
                females.erase(females.begin() + i);
                i = -1;
            }
            else{
                bunnies.push_back(&females[i]);
            }
        }
        for(int i = 0; i < genderXs.size(); i++){
            cout << "Bunny Age: " << genderXs[i].getAge() << endl;
            bool notDead = genderXs[i].addAgeCheck();
            if(!notDead){
                genderXs.erase(genderXs.begin() + i);
                i = -1;
            }
            else{
                bunnies.push_back(&genderXs[i]);
            }
        }
        for(int i = 0; i < mutants.size(); i++){
            cout << "Bunny Age: " << mutants[i].getAge() << endl;
            bool notDead = mutants[i].addAgeCheck();
            if(!notDead){
                mutants.erase(mutants.begin() + i);
                i = -1;
            }
        }
    }

    void shuffleBunnies(){
        for (int i = 0; i < bunnies.size(); i++)
            swap(bunnies[i],bunnies[i+rand() % bunnies.size() - i]);
    }

    void breeding(){
        vector<Bunny> breedingMales;
        vector<Bunny> breedingFemales;
        vector<Bunny> breedingGenderX;
        for(int i = 0; i < males.size(); i++){
            if(males[i].getAge() > 1 && males[i].getAge() < 9){
                breedingMales.push_back(males[i]);
            }
        }
        for(int i = 0; i < females.size(); i++){
            if(females[i].getAge() > 1 && females[i].getAge() < 9){
                breedingFemales.push_back(females[i]);
            }
        }
        for(int i = 0; i < genderXs.size(); i++){
            if(genderXs[i].getAge() > 1 && genderXs[i].getAge() < 9){
                breedingGenderX.push_back(genderXs[i]);
            }
        }
        //cout << "Bunnies breeding: " << to_string(breedingMales.size()) << " " << to_string(breedingFemales.size()) << " " << to_string(breedingGenderX.size()) << endl;
    }

    /// Take all bunnies that are mutants and move them out of standard vectors and into the mutant vectors.
    void moveMutants(){
        for(int i = 0; i < males.size(); i++){
            if(males[i].getMutant() == true){
                Bunny bunny = males[i];
                mutants.push_back(bunny);
                males.erase(males.begin() + i);
            }
        }
        for(int i = 0; i < females.size(); i++){
            if(females[i].getMutant() == true){
                Bunny bunny = females[i];
                mutants.push_back(bunny);
                females.erase(females.begin() + i);
            }
        }
        for(int i = 0; i < genderXs.size(); i++){
            if(genderXs[i].getMutant() == true){
                Bunny bunny = genderXs[i];
                mutants.push_back(bunny);
                genderXs.erase(genderXs.begin() + i);
            }
        }
    }

    /// Using the count of current mutants, transform bunnies into new mutants.
    void createMutants(){
        if(mutants.size() == bunnies.size()){
            return;
        }
        for(int i = 0; i < mutants.size(); i++){
            bunnies[i]->transformMutant();
        }
        moveMutants();
    }

    void runSimulation(){
        cout << "Initial Setup: " << endl;
        startVector();
        int turncount = 0;
        bool endCondition = true;
        while(endCondition){
            cout << "Start of Turn " << to_string(turncount) << endl;
            addAge();
            if(males.size() == 0 && females.size() == 0 && genderXs.size() == 0 && mutants.size() == 0){
                endCondition = false;
            }
            //breeding logic
            breeding();
            //mutant logic
            createMutants();

            //End of turn, display results.
            cout << "Turn " << to_string(turncount) << ": Males: " << to_string(males.size()) << ", Females: "
            << to_string(females.size()) << ", GenderX's: " + to_string(genderXs.size()) + ", Mutants: "
            << to_string(mutants.size()) << ", Total Bunnies: " << to_string(bunnies.size()) << endl;
            turncount++;
        }
    }

    Simulation()= default;
};