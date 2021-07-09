#include "random"

/**********************************************************************************************************************/
SupermarketSimulator::SupermarketSimulator() : SupermarketSimulator(0, 0) {}

/**********************************************************************************************************************/
SupermarketSimulator::SupermarketSimulator(int maxIterations, int cashierQty) :
        waitingCustomers(make_unique<LinkedQueue<shared_ptr<Customer>>>()),
        servedCustomers(make_unique<LinkedList<shared_ptr<Customer>>>()),
        cashiers(make_unique<LinkedList<shared_ptr<Cashier>>>()),
        maxIterations(maxIterations),
        averageWaitTime(0),
        currentTime(1) {
    for (int i = 0; i < cashierQty; i++) { /**Create cashiers*/
        this->cashiers->insert(i + 1, make_shared<Cashier>(i + 1));
    }
}

/**********************************************************************************************************************/
void SupermarketSimulator::runSimulation() {
    /**TODO: implement runSimulation -- see sequence diagram and hints*/
    /**
     * for each time step
     *      generate random customers
     *      processCustomers
     *      increment currentTime one timeStep
     */
     for(int i = 0; i < maxIterations; i++){
         generateCustomers();
         processCustomers();
     }


    // Todo: Your code here

    /**
     * Process remaining waiting customers
     * (increments time every after each process)
     */




    // Todo: Your code here

    /**
     * Calculates average time:
     *  sum all the served customers wait time
     *  avg is the sum / the total number of served customers. -- make sure to cast to double (real division)
     */

    // Todo: Your code here

}

/**********************************************************************************************************************/
double SupermarketSimulator::getAverageWaitingTime() const {
    return this->averageWaitTime;
}

/**===================================================================================================================*/
/****                                   PRIVATE                                                                    ****/
/**===================================================================================================================*/
void SupermarketSimulator::processCustomers() {
    /**TODO: implement processCustomers -- see sequence diagram and hints*/
    shared_ptr<Cashier> aCashier = nullptr;
    shared_ptr<Customer> aCustomer = nullptr;
    /**
     * for each cashier
     *  get i-th cashier
     *  if cashier is free
     *      if there are customers waiting
     *          get the first customer and remove it from the queue
     *          add the customer to the served list.
     *          send the it to the cashier
     *          set the customer service start time to the current time
     *  else
     *      run the cashier for this time step.
     */
    // Todo: Your code here -- Review
    int cashierCount = cashiers->getLength(); /** Used to iterate through cashiers. */
    for(int i = 1; i < cashierCount+1; i++) {
        shared_ptr<Cashier> currentCashier = cashiers->getEntry(i); /** Getting ith cashier*/
        if(!currentCashier->isBusy()) {
            aCashier = currentCashier;
            if(!waitingCustomers->isEmpty()){ /** If we have a customer */
                aCustomer = waitingCustomers->peekFront();
                aCashier->setCustomer(aCustomer);
                servedCustomers->insert(this->servedCustomers->getLength()+1, aCustomer);
                waitingCustomers->dequeue();
                aCustomer->setServiceStartTime(currentTime);
            }
        }
        else {
            currentCashier->run();
        }
    }
    currentTime++;




}

/**********************************************************************************************************************/
void SupermarketSimulator::generateCustomers() {
    random_device rd1, rd2;             //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd1()), gen2(rd2());    //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> distAddCustomer(0.0, 1.0),
                                distUnloadTime(10.0, 50.0),
                                distQtyCustomers(1.0, 3.0);

    if (distAddCustomer(gen) >= 0.5) {
        int qty = static_cast<int>(distQtyCustomers(gen2));
        for (int i=0; i<qty; i++) {
            /**Generate a new customer and add it to the queue*/
            int unloadUnits = static_cast<int>(distUnloadTime(gen2));
            shared_ptr<Customer> aCustomer = make_shared<Customer>(this->currentTime, unloadUnits);
            this->waitingCustomers->enqueue(aCustomer);
        }
    }
}

/**********************************************************************************************************************/
int SupermarketSimulator::getServedCustomerQuantity() const {
    return this->servedCustomers->getLength();
}
