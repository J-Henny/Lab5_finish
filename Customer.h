#ifndef CSCI2421_CUSTOMER_H
#define CSCI2421_CUSTOMER_H

/**
 * Represents a customer waiting in line to make a purchase.
 */
class Customer {
private:
    int queueStartTime;     /**Time index when the customer got into the queue*/
    int serviceStartTime;   /**Time index when the customer moved to the cashier*/
    int unloadTime;         /**How long would it take to process all the customer's products at a cashier.*/

public:
    Customer(int time, int unload);

    void setServiceStartTime(int aValue);

    /**s
     * @return serviceStartTime - queueStartTime
     */
    int getWaitTime() const;

    /**
     * When the customer reaches the cashier, starts unloding the products for unloadTime.
     * This decreases the remaining unloadTime as time progresses.
     */
    void unload();

    /**
     * Check if the customer still have "work" to do
     * @return  true if all products were unloaded and the purchase is complete.
     */
    bool isCompleted() const;
};

#include "Customer.cpp"

#endif //CSCI2421_CUSTOMER_H
