#ifndef CSCI2421_SUPERMARKETSIMULATOR_H
#define CSCI2421_SUPERMARKETSIMULATOR_H

#include "memory"
#include "LinkedQueue.h"
#include "LinkedList.h"
#include "Customer.h"
#include "Cashier.h"

using namespace std;

class SupermarketSimulator {
private:
    unique_ptr<LinkedQueue<shared_ptr<Customer>>> waitingCustomers;  /**Waiting Customers Queue*/
    unique_ptr<LinkedList<shared_ptr<Customer>>> servedCustomers;   /**Customers that were server (historical)*/
    unique_ptr<LinkedList<shared_ptr<Cashier>>> cashiers;           /**Available processors*/
    int maxIterations;      /**max number of time steps*/
    double averageWaitTime; /**Computer averageWaitTime by a customer in the queue*/
    int currentTime;        /**The current time step*/

    /**
     * Process customers from the queue using the available cashiers
     */
    void processCustomers();
    /**
     * randomly generates n (random) customers
     */
    void generateCustomers();

public:
    explicit SupermarketSimulator();
    SupermarketSimulator(int maxIterations, int cashierQty);

    /**
     * Runs the simulation by adding random number of customers and iterate time steps while cashier process
     * the customer requests.
     */
    void runSimulation();

    ////////// Accessors //////////
    double getAverageWaitingTime() const;

    int getServedCustomerQuantity() const;
};

#include "SupermarketSimulator.cpp"

#endif
