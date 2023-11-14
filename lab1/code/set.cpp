#include "set.hpp"

#include <algorithm>  //std::swap

/*
* std::size_t is defined in the C++ standard library
Expand
message.txt
4 KB
﻿
DubG
dubg1
#include "set.hpp"

#include <algorithm>  //std::swap

/*
* std::size_t is defined in the C++ standard library
* std::size_t is an unsigned integer type that can store the maximum size of any possible object
* sizes are non-negative integers -- i.e. unsigned integer type
*/

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ************************************ */

// Default constructor
Set::Set() : head{ new Node{} }, counter{ 0 } {  // create the dummy node
}

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {
    insert(head, x);
    /*Node* newNode = new Node;
    newNode->value = x;
    newNode->next = nullptr;
    counter++;
    head->next = newNode;*/



}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() {
    /*
    * Sorting a vector cannot used here
    * std::sort and std::unique cannot be used
    */
    // ADD CODE
    Node* temp = nullptr;
    for (int i = 0; i < std::ssize(elements); i++) {
        
        
        bool isInSet = this->member(elements[i]);

        if (isInSet) {
            //dont add
            continue;
        }
        else {
            // Step 1: search for the first node larger than elements[i]
            // we need to stop teh node before -- make ptr to point to the node before insertion point

            Node* ptr = head;

            while (ptr->next != nullptr && ptr->next->value < elements[i]) {
                ptr = ptr->next;
            }

            //STEP2: INSERT A NEW NODE STORING ELEMENTS[I] AFTER PTR
            /*Node* newNode = new Node(elements[i], nullptr);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ++counter;*/
            insert(ptr, elements[i]);




            /*Node* newNode = new Node;
            newNode->value = elements[i];
            counter++;

            
            newNode->next = nullptr;

           
            if (temp == nullptr) {
                head->next = newNode;
            }

            else {
                temp->next = newNode;
            }

            Node* temp = newNode;*/

        }


    }
}

// copy constructor
Set::Set(const Set& rhs) : Set() {
    // ADD CODE
    Node* ptr1 = rhs.head->next;
    Node* ptr2 = head;  // pointer to last node of the list

    while (ptr1 != nullptr) {
        ptr2->next = new Node(ptr1->value, nullptr);

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    counter = rhs.counter;
}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) {
    // ADD CODE
    std::swap(head, rhs.head);
    std::swap(counter, rhs.counter);

    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    // ADD CODE
    Node* ptr = head;

    while (ptr != nullptr) {
        head = head->next;

        delete ptr;  // free memory of first node in the list
        ptr = head;
    }
    head = nullptr;
    counter = 0;
}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    // ADD CODE
    return counter;
}

// Test if set is empty
bool Set::empty() const {
    // ADD CODE
    if (counter == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Test if x is an element of the set
bool Set::member(int x) const {
    // ADD CODE
    Node* ptr = head->next;  // ptr points at 1st node, after dummy node

    while ((ptr != nullptr) &&
        (ptr->value != x)) {  // do not swap the tests, to avoid dereferencing a null pointer
        ptr = ptr->next;
    }
    if (ptr != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const {
    // ADD CODE

    if (counter == 0) {
        return true;
    }
    else {
        Node* ptr = head;
        bool subset = false;
        while (ptr != nullptr) {
            if (b.member(ptr->value)) {
                subset = true;
            }
            else {
                subset = false;
            }
            ptr = ptr->next;
        }

        return subset;  // delete, if needed
    }


}

// Return a new Set representing the union of Sets *this and b
// Repeated values are not allowed
// Implement an algorithm similar to the one in exercise 3/Set 1, but don't use vectors
Set Set::set_union(const Set& b) const {
    // ADD CODE


    return Set{};  // delete, if needed
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

std::ostream& operator<<(std::ostream& os, const Set& rhs) {
    if (rhs.empty()) {
        os << "Set is empty!";
    }
    else {
        Set::Node* ptr = rhs.head->next;
        os << "{ ";

        while (ptr != nullptr) {
            os << ptr->value << " ";
            ptr = ptr->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

// Insert a new Node after node pointed by ptr
void Set::insert(Node* ptr, int value) {
    Node* newNode = new Node(value, nullptr);
    newNode->next = ptr->next;
    ptr->next = newNode;
    ++counter;
}

