//Tyler Kness-Miller
//BunnySimulation.h

#include "Bunny.h"
#include <vector>

class Simulation{
private:

public:
    vector<Bunny> bunnies;

    /// Creates a bunny and adds to vector. Bunny is created with all random attributes.
    void bunnyBorn(){
        Bunny bunny = Bunny();
        cout << "Bunny " << bunny.getName() << " was born!" << endl;
        bunnies.push_back(bunny);
    }

    /// Creates a bunny and adds to vector. Bunny is created using color of mother and father.
    /// \param colorM The color of the mother.
    /// \param colorF The color of the father.
    void bunnyBorn(string colorM, string colorF){
        Bunny bunny = Bunny(colorM, colorF);
        cout << "Bunny " << bunny.getName() << " was born!" << endl;
        bunnies.push_back(bunny);
    }

    /// Starts the vector of bunnies by filling it with 10 new ones.
    void startVector(){
        for(int i = 0; i < 10; i++){
            bunnyBorn();
        }
    }

    void addAge(){
        for(int i = 0; i < bunnies.size(); i++){
            bool notDead = bunnies[i].addAgeCheck();
            if(!notDead){
                bunnies.erase(bunnies.begin() + i);
            }
        }
    }

    void runSimulation(){
        cout << "Initial Setup: " << endl;

    }

    Simulation(){

    }
};