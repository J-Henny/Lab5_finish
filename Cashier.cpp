//#include "Cashier.h"

Cashier::Cashier(int anId) : id(anId), currentCustomer(nullptr){}

int Cashier::getId() const {
    return this->id;
}

void Cashier::setCustomer(shared_ptr<Customer> aCustomer) {
    if (! this->isBusy())
        this->currentCustomer = aCustomer;
    else
        throw logic_error("Invalid, cashier is busy.");
}


bool Cashier::isBusy() const {
    return this->currentCustomer != nullptr;
}

void Cashier::run() {
    if (this->currentCustomer != nullptr){
        this->currentCustomer->unload();
        if (this->currentCustomer->isCompleted())
            this->currentCustomer= nullptr;
    }
    else
        throw logic_error("No Customer at the Cashier desk.");
}

