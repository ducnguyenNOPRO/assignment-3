#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    ListNode<T> *newPtr = new ListNode<T>(value);
    if (newPtr == nullptr)
        throw "out of memory";
    // Created a new ListNode with the passed value
    // Set newPtr->next to point to the first ListNode
    // Set the head->next to point to the newPtr.
    newPtr->next = head->next;
    head->next = newPtr;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    ListNode<T> *newNode = new ListNode<T>(value);
    // Traverse to the end of the List
    // Set the last Node->next point to a new ListNode.
    ListNode<T> *current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = newNode;
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    if (num_of_element == 0)
        return;

    // Traverse to the end of the List
    // Find the last second Node
    ListNode<T> *current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    // Store the last node in a temp
    // to deallocate the memory
    ListNode<T> *nodeToDelete = current->next;
    // Point the second last->next to null
    current->next = nullptr;
    delete nodeToDelete;
    num_of_element--;
}

template<class T>
void LinkedList<T>::pop_front() {
    if (num_of_element == 0)
        return;

    // Store first Node in a temp to deallocate memory
    // Point head->next to the second Node -> this will be the new first Node
    ListNode<T> *firstNode = head->next;
    head->next = firstNode->next;
    delete firstNode;
    num_of_element--;
}

template<class T>
void LinkedList<T>::remove(T &val) {
    if (num_of_element == 0)
        return;
    ListNode<T> *current = head;
    // Find the Node before the deleted Node
    while (current->next != nullptr){
        if (current->next->val == val){
            ListNode<T> *nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
            num_of_element--;
        }
        else{
            current = current->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    auto &other_list = (LinkedList<T> &) ot;

    // Algorithm from https://codereview.stackexchange.com/questions/123346/merging-sorted-linked-lists-c
    // Creating a new List
    ListNode<T> *dummy = new ListNode<T>();
    // Use to decide which node will be the next node (ascending mode)
    ListNode<T> *current = dummy;

    ListNode<T> *currentA = head->next;  // First node this list
    ListNode<T> *currentB = other_list.head->next;  // Fist node other list

    while(currentA != nullptr && currentB != nullptr){
        if (currentA->val <= currentB->val){
            current->next = new ListNode<T>(currentA->val);
            currentA = currentA->next;
        }else{
            current->next = new ListNode<T>(currentB->val);
            currentB = currentB->next;
        }
        current = current->next;
    }
    // Check if there is remaining node in either list
    while (currentA != nullptr){
        current->next = new ListNode<T>(currentA->val);
        current = current->next;

        currentA = currentA->next;
    }
    while (currentB != nullptr){
        current->next = new ListNode<T>(currentB->val);
        current = current->next;
        currentB = currentB->next;
    }
    // Make current point to NULL
    current = current->next;

    // Delete the old List
    ListNode<T> *toDelete = head;
    while(toDelete){
        ListNode<T>* d = toDelete;
        toDelete = toDelete->next;
        delete d;
    }

    // Point the head of old List to the new List
    head = dummy;
    num_of_element += other_list.num_of_element;
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    // Algorithm from https://www.geeksforgeeks.org/reverse-a-linked-list/
    // Initialize current, previous and next pointers
    ListNode<T>* current = head->next;  // First Node
    ListNode<T> *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head->next = prev;
}