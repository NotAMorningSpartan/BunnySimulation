//Tyler Kness-Miller
//BunnySimulation.h

#include "Bunny.h"
#include <vector>
#include <fstream>

class Simulation{
private:
    int getRandomNumber(int lower, int upper){
        //return 1 + ( rand() % ( 100 - 1 + 1 ) );
        //return rand() % 100;
        random_device generator;
        mt19937 mt(generator());
        uniform_int_distribution<int> dist(lower, upper);
        return dist(mt);
    }
public:
    vector<Bunny> males;
    vector<Bunny> females;
    vector<Bunny> genderXs;
    vector<Bunny> mutants;
    vector<Bunny*> bunnies;
    ofstream outfile;

    /// Creates a bunny and adds to vector. Bunny is created with all random attributes.
    void bunnyBorn(){
        Bunny bunny = Bunny();
        if(bunny.getMutant()){
            cout << "Mutant Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Mutant Bunny " << bunny.getName() << " was born!" << endl;
            mutants.push_back(bunny);
        }
        else if(bunny.getGender() == "male"){
            cout << "Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Bunny " << bunny.getName() << " was born!" << endl;
            males.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else if(bunny.getGender() == "female"){
            cout << "Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Bunny " << bunny.getName() << " was born!" << endl;
            females.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else{
            cout << "Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Bunny " << bunny.getName() << " was born!" << endl;
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
        if(bunny.getMutant()){
            cout << "Mutant Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Mutant Bunny " << bunny.getName() << " was born!" << endl;
            mutants.push_back(bunny);
        }
        else if(bunny.getGender() == "male"){
            cout << "Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Bunny " << bunny.getName() << " was born!" << endl;
            males.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else if(bunny.getGender() == "female"){
            cout << "Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Bunny " << bunny.getName() << " was born!" << endl;
            females.push_back(bunny);
            Bunny *bunny_pointer = &bunny;
            bunnies.push_back(bunny_pointer);
        }
        else{
            cout << "Bunny " << bunny.getName() << " was born!" << endl;
            outfile << "Bunny " << bunny.getName() << " was born!" << endl;
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
            //cout << "Bunny Age: " << males[i].getAge() << endl;
            bool notDead = males[i].addAgeCheck();
            if(!notDead){
                cout << "Bunny " << males[i].getName() << " has died!" << endl;
                outfile << "Bunny " << males[i].getName() << " has died!" << endl;
                males.erase(males.begin() + i);
                i = -1;
            }
            else{
                bunnies.push_back(&males[i]);
            }
        }
        for(int i = 0; i < females.size(); i++){
            //cout << "Bunny Age: " << females[i].getAge() << endl;
            bool notDead = females[i].addAgeCheck();
            if(!notDead){
                cout << "Bunny " << females[i].getName() << " has died!" << endl;
                outfile << "Bunny " << females[i].getName() << " has died!" << endl;
                females.erase(females.begin() + i);
                i = -1;
            }
            else{
                bunnies.push_back(&females[i]);
            }
        }
        for(int i = 0; i < genderXs.size(); i++){
            //cout << "Bunny Age: " << genderXs[i].getAge() << endl;
            bool notDead = genderXs[i].addAgeCheck();
            if(!notDead){
                cout << "Bunny " << genderXs[i].getName() << " has died!" << endl;
                outfile << "Bunny " << genderXs[i].getName() << " has died!" << endl;
                genderXs.erase(genderXs.begin() + i);
                i = -1;
            }
            else{
                bunnies.push_back(&genderXs[i]);
            }
        }
        for(int i = 0; i < mutants.size(); i++){
            //cout << "Bunny Age: " << mutants[i].getAge() << endl;
            bool notDead = mutants[i].addAgeCheck();
            if(!notDead){
                cout << "Mutant Bunny " << mutants[i].getName() << " has died!" << endl;
                outfile << "Mutant Bunny " << mutants[i].getName() << " has died!" << endl;
                mutants.erase(mutants.begin() + i);
                i = -1;
            }
        }
    }

    void breeding(){
        vector<Bunny> breedingMales;
        vector<Bunny> breedingFemales;
        vector<Bunny> breedingGenderX;
        for(int i = 0; i < males.size(); i++){
            //Get all bunnies that are at the appropriate age.
            if(males[i].getAge() > 1 && males[i].getAge() < 9 && !males[i].getMutant()){
                breedingMales.push_back(males[i]);
            }
        }
        for(int i = 0; i < females.size(); i++){
            if(females[i].getAge() > 1 && females[i].getAge() < 9 && !females[i].getMutant()){
                breedingFemales.push_back(females[i]);
            }
        }
        for(int i = 0; i < genderXs.size(); i++){
            if(genderXs[i].getAge() > 1 && genderXs[i].getAge() < 9 && !genderXs[i].getMutant()){
                breedingGenderX.push_back(genderXs[i]);
            }
        }



        //Find max amount of bunnies in one list, to facilitate pairs.
        int pairs = max(max(breedingMales.size(), breedingFemales.size()), breedingGenderX.size());
        //facilitate breeding. After each one has breeded, remove them.
        for(int i = 0; i < pairs; i++){
            //breeding between males and females/genderXs
            if(!breedingMales.empty()){
                if(!breedingFemales.empty()){
                    bunnyBorn(breedingMales[0].getColor(), breedingFemales[0].getColor());
                    breedingMales.erase(breedingMales.begin());
                    breedingFemales.erase(breedingFemales.begin());
                }
                else if(!breedingGenderX.empty()){
                    if(getRandomNumber(1,100) > 50){
                        bunnyBorn(breedingMales[0].getColor(), breedingGenderX[0].getColor());
                        breedingMales.erase(breedingMales.begin());
                        breedingGenderX.erase(breedingGenderX.begin());
                    }
                    else{
                        breedingMales.erase(breedingMales.begin());
                        breedingGenderX.erase(breedingGenderX.begin());
                    }
                }
            }
            //Breeding between females and males/genderXs
            if(!breedingFemales.empty()){
                if(!breedingMales.empty()){
                    bunnyBorn(breedingMales[0].getColor(), breedingFemales[0].getColor());
                    breedingMales.erase(breedingMales.begin());
                    breedingFemales.erase(breedingFemales.begin());
                }
                else if(!breedingGenderX.empty()){
                    if(getRandomNumber(1,100) > 50){
                        bunnyBorn(breedingGenderX[0].getColor(), breedingFemales[0].getColor());
                        breedingGenderX.erase(breedingGenderX.begin());
                        breedingFemales.erase(breedingFemales.begin());
                    }
                    else{
                        breedingFemales.erase(breedingFemales.begin());
                        breedingGenderX.erase(breedingGenderX.begin());
                    }
                }
            }
            //edge case. no need to keep looking if no females and males are left to breed.
            if(breedingMales.empty() && breedingFemales.empty()){
                i = pairs;
            }
        }

        //cout << "Bunnies breeding: " << to_string(breedingMales.size()) << " " << to_string(breedingFemales.size()) << " " << to_string(breedingGenderX.size()) << endl;
    }

    /// Take all bunnies that are mutants and move them out of standard vectors and into the mutant vectors.
    void moveMutants(){
        bunnies.clear();
        for(int i = 0; i < males.size(); i++){
            if(males[i].getMutant()){
                Bunny bunny = males[i];
                mutants.push_back(bunny);
                males.erase(males.begin() + i);
                i = 0;
            }
            else{
                bunnies.push_back(&males[i]);
            }
        }
        for(int i = 0; i < females.size(); i++){
            if(females[i].getMutant()){
                Bunny bunny = females[i];
                mutants.push_back(bunny);
                females.erase(females.begin() + i);
                i = 0;
            }
            else{
                bunnies.push_back(&females[i]);
            }
        }
        for(int i = 0; i < genderXs.size(); i++){
            if(genderXs[i].getMutant()){
                Bunny bunny = genderXs[i];
                mutants.push_back(bunny);
                genderXs.erase(genderXs.begin() + i);
                i = 0;
            }
            else{
                bunnies.push_back(&genderXs[i]);
            }
        }
    }

    /// Using the count of current mutants, transform bunnies into new mutants.
    void createMutants(){
        for(int i = 0; i < mutants.size(); i++){
            if(i == bunnies.size()){
                //If it reaches this point, it means there is no more mutants left to convert.
                return;
            }
            bunnies[i]->transformMutant();
        }
        moveMutants();
    }

    void runSimulation(){
        outfile = ofstream("output.txt");
        cout << "Initial Setup: " << endl;
        outfile << "Initial Setup: " << endl;
        startVector();
        int turncount = 0;
        bool endCondition = true;
        while(endCondition){
            cout << "Start of Turn " << to_string(turncount) << endl;
            outfile << "Start of Turn " << to_string(turncount) << endl;
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
            << to_string(mutants.size()) << ", Total Bunnies: " << to_string(bunnies.size() + mutants.size()) << endl;
            turncount++;

            outfile << "Turn " << to_string(turncount) << ": Males: " << to_string(males.size()) << ", Females: "
                 << to_string(females.size()) << ", GenderX's: " + to_string(genderXs.size()) + ", Mutants: "
                 << to_string(mutants.size()) << ", Total Bunnies: " << to_string(bunnies.size() + mutants.size()) << endl;
            turncount++;
        }
        outfile.close();
    }

    Simulation()= default;
};