#include <memory>

/**********************************************************************************************************************/
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue &aQueue) {
    auto origChainPtr = aQueue.frontPtr;  // Points to nodes in original chain

    // Using shared pointers initializes frontPtr/backPtr to nullPtr
    if (origChainPtr != nullptr) {
        // Copy first node
        frontPtr = std::make_shared<Node<ItemType>>();
        frontPtr->setItem(origChainPtr->getItem());

        // Advance original-chain pointer
        origChainPtr = origChainPtr->getNext();

        // Copy remaining nodes
        auto newChainTailPtr = frontPtr;        // Points to last node in new chain
        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            auto newNodePtr = std::make_shared<Node<ItemType>>(nextItem);

            // Link new node to end of new chain
            newChainTailPtr->setNext(newNodePtr);

            // Advance pointers
            newChainTailPtr = newChainTailPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainTailPtr->setNext(nullptr);               // Flag end of chain
        backPtr = newChainTailPtr;
    }  // end if
}

/**********************************************************************************************************************/
template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {
    //smart pointers will clean-up
    backPtr = nullptr;
    frontPtr = nullptr;
}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
    return backPtr == nullptr;
}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType &newEntry) {
    /**TODO: Check chapter 14.1.2 or lectures*/

    auto newNodePtr = make_shared<Node<ItemType>>(newEntry);
    // Insert the new node
    if (isEmpty())
        frontPtr = newNodePtr; // The queue was empty
    else
        backPtr->setNext(newNodePtr); // The queue was not empty
    backPtr = newNodePtr; // New node is at back
    return true;

}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    /**TODO: Check chapter 14.1.2 or lectures*/

    bool result = false;
    if (!isEmpty())
    {
        // Queue is not empty; remove front
        auto nodeToDeletePtr = frontPtr;
        if (frontPtr == backPtr)
        { // Special case: one node in queue
            frontPtr = nullptr;
            backPtr = nullptr;
        }
        else
            frontPtr = frontPtr->getNext();
        // Return deleted node to system
        result = true;
    } // end if
    return result;
}

/**********************************************************************************************************************/
template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
    if (isEmpty())
        throw PrecondViolatedExcep("getFront() called with empty queue.");

    // Queue is not empty; return front
    return frontPtr->getItem();
}
