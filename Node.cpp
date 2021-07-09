
#include "Node.h"
#include <cstddef>

/**********************************************************************************************************************/
template<class ItemType>
Node<ItemType>::Node() {} // end default constructor

/**********************************************************************************************************************/
template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem) : item(anItem) {} // end constructor

/**********************************************************************************************************************/
template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem, shared_ptr<Node<ItemType>> nextNodePtr)
        : item(anItem), next(nextNodePtr) {} // end constructor

/**********************************************************************************************************************/
template<class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem) {
    item = anItem;
}

/**********************************************************************************************************************/
template<class ItemType>
void Node<ItemType>::setNext(shared_ptr<Node<ItemType>> nextNodePtr) {
    next = nextNodePtr;
}

/**********************************************************************************************************************/
template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

/**********************************************************************************************************************/
template<class ItemType>
shared_ptr<Node<ItemType>> Node<ItemType>::getNext() const {
    return next;
}
