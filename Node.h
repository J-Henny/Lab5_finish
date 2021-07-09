#ifndef NODE_
#define NODE_

#include <memory>

using namespace std;

template<class ItemType>
class Node {
private:
    ItemType item;                     // A data item
    shared_ptr<Node<ItemType>> next;   // Pointer to next node

public:
    explicit Node();

    explicit Node(const ItemType &anItem);

    Node(const ItemType &anItem, shared_ptr<Node<ItemType>> nextNodePtr);

    void setItem(const ItemType &anItem);

    void setNext(shared_ptr<Node<ItemType>> nextNodePtr);

    ItemType getItem() const;

    shared_ptr<Node<ItemType>> getNext() const;

};
#include "Node.cpp"

#endif