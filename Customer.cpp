Customer::Customer(int time, int unload) : queueStartTime(time), serviceStartTime(0), unloadTime(unload) {}

void Customer::setServiceStartTime(int aValue) {
    this->serviceStartTime = aValue;
}

int Customer::getWaitTime() const {
    return this->serviceStartTime - this->queueStartTime;
}

void Customer::unload() {
    if (this->unloadTime > 0)
        this->unloadTime--;
}

bool Customer::isCompleted() const {
    return this->unloadTime <= 0;
}
