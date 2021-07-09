#ifndef CSCI2421_CASHIER_H
#define CSCI2421_CASHIER_H

#include "memory"
#include "Customer.h"

using namespace std;

class Cashier {
private:
    int id;                                  /**The Cashier Id, just for reference*/
    shared_ptr<Customer> currentCustomer;    /**The current customer at the cashier*/

public:
    explicit Cashier(int anId);

    int getId() const;

    void setCustomer(shared_ptr<Customer> aCustomer) noexcept(false);

    /**
     * Runs a time step for the cashier. i.e. process the customer "work"
     */
    void run() noexcept(false);

    /**
     * @return true if there's a customer at the cashier.
     */
    bool isBusy() const;

};

#include "Cashier.cpp"

#endif //CSCI2421_CASHIER_H
