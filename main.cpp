#include "iostream"
#include "memory"
#include "SupermarketSimulator.h"
using namespace std;

/**TODO - BEFORE YOU START: Review the uml diagrams, and inspect the classes Customer, Cashier and SupermarketSimulator.
 * This program compiles and runs, but all results are set to 0 until implemented.
 */

/**
 * Runs a single simulation for n iterations with k cashiers.
 * @param iterations number of iterations to run (i.e. time)
 * @param cashiers   number of cashiers (i.e. processors)
 */
void runSimulation(int iterations, int cashiers){
    shared_ptr<SupermarketSimulator> sim = make_shared<SupermarketSimulator>(iterations, cashiers);
    cout<< string(120,'-')<<endl;
    cout<<"Running Simulation. "<<iterations<< " with "<<cashiers<<" cashiers."<<endl;
    sim->runSimulation();
    cout<<"The Simulation ended. " << sim->getServedCustomerQuantity()<< " customers were served."<<
          "The average wait time was:" <<sim->getAverageWaitingTime()<<endl;
    cout<< string(120,'*')<<endl;
}

/**
 * Main program
 */
int main(){
    runSimulation(3000, 2);
    runSimulation(3000, 4);
    runSimulation(3000, 6);
    runSimulation(3000, 8);
    runSimulation(3000, 10);

    return 0;
}
