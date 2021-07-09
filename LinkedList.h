#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <memory>
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

using namespace std;

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
    shared_ptr<Node<ItemType>> headPtr;/**Pointer to 1st node in the chain; (contains the 1st entry in the list)*/
    int itemCount;                          /**Current count of list items*/

    /**
     * Locates a specified node in this linked list.
     * @pre  position is the number of the desired node;
     * position >= 1 and position <= itemCount.
     * @post  The node is found and a pointer to it is returned.
     * @param position  The number of the node to locate.
     * @return  A pointer to the node at the given position.
     */
    shared_ptr<Node<ItemType>> getNodeAt(int position) const;

public:
    LinkedList();

    LinkedList(const LinkedList<ItemType> &aList);

    virtual ~LinkedList();

    bool isEmpty() const;

    int getLength() const;

    bool insert(int newPosition, const ItemType &newEntry);

    bool remove(int position);

    void clear();

    /** @throw PrecondViolatedExcep if position < 1 or position > getLength(). */
    ItemType getEntry(int position) const noexcept(false);

    /** @throw PrecondViolatedExcep if position < 1 or position > getLength(). */
    void replace(int position, const ItemType &newEntry) noexcept(false);
};

#include "LinkedList.cpp"

#endif
