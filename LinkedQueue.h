#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include <memory>
#include "QueueInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

using namespace std;

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
private:
    /** The queue is implemented as a chain of linked nodes that has
     *  two external pointers, a head pointer for front of the queue and
     *  a tail pointer for the back of the queue. */
    shared_ptr<Node<ItemType>> backPtr;
    shared_ptr<Node<ItemType>> frontPtr;

public:
    explicit LinkedQueue() =default;

    LinkedQueue(const LinkedQueue &aQueue);

    ~LinkedQueue();

    bool isEmpty() const override;

    bool enqueue(const ItemType &newEntry) override;

    bool dequeue() override;

    /** @throw PrecondViolatedExcep if the queue is empty */
    ItemType peekFront() const noexcept(false) override;
};

#include "LinkedQueue.cpp"

#endif
