//Tyler Kness-Miller
//CS4499 - Scientific Computing
//18 March 2021

#include "BunnySimulation.h"

int main(){
    Simulation s = Simulation();
    srand(time(0));
    s.runSimulation();
    return 0;
}