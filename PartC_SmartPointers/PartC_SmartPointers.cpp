//	PartC_SmartPointers.cpp
//	Created by: CSC340
//Contributors: Cody Huang, Faiyaz Chaudhury
//4/12/2021
#include "LinkedBag.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory>
using namespace std;
//function that replaces the content of the second node with head and deletes head
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340(){
    //puts all items into a vector
    std::vector<ItemType> v = this->toVector();
    //get the second item in the vector
    ItemType target = v[1];
    //use remove() to remove second item
    this->remove(v[1]);
    return true;
}

//function adds a new node with data = newEntry to the last node of the link
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry){
    //create a unique pointer for a new node
    auto nextNodePtr{make_unique<Node<ItemType>>(newEntry)};
    //create a raw pointer to iterate through the bag
    Node<ItemType>* cur = headPtr;
    //iterate through the bag to find the last node
    while(cur->getNext()!=nullptr) cur = cur->getNext();
    //release the smart pointer for the last node to point at then point last node at new node
    cur->setNext(nextNodePtr.release());
    //increment itemCount
    itemCount++;
    return true;
}

//gets the current size of the bag iteratively
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int count = 1;
    auto cur{make_unique<Node<ItemType>>(*headPtr)};
    //if head is null return 0 because bag is empty
    if(cur==nullptr) return 0;
    //iterate through all the nodes and increment count if nextNode exists
    while(cur->getNext()!=nullptr){
        count++;
        cur=make_unique<Node<ItemType>>(*cur->getNext());
    } 
    return count;

}

//gets the current size recursivly
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return getCurrentSize340RecursiveHelper(make_unique<Node<ItemType>>(*headPtr));
}

//helper for getCurrentSize340Recursive()
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(unique_ptr<Node<ItemType>> cur) const {
    //base case
    if(cur->getNext()==nullptr) {
        return 1;
    } else {
        return 1 + getCurrentSize340RecursiveHelper(make_unique<Node<ItemType>>(*cur->getNext()));
    }
}

//get the current size recursively without a helper
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    static auto cur{make_unique<Node<ItemType>>(*headPtr)};
    if(cur->getNext()!=nullptr) {
        cur=make_unique<Node<ItemType>>(*cur->getNext());
        return 1 + getCurrentSize340RecursiveNoHelper();
    } else {
        return 1;
    }
}

//get the frequency of an item recursively
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& entry) const {
    auto cur{make_shared<Node<ItemType>>(*headPtr)};
    return getFrequencyOf340RecursiveHelper(cur, entry);
}

//helper for getFrequencyOf340()
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(shared_ptr<Node<ItemType>> cur, const ItemType& entry) const {
    //base case if last item matches entry
    if(cur->getNext()==nullptr) {
        return (cur->getItem()==entry) ? 1 : 0;
    }else{
        if(cur->getItem()==entry) {
            return 1 + getFrequencyOf340RecursiveHelper(make_shared<Node<ItemType>>(*cur->getNext()),entry);
        } else{
            return getFrequencyOf340RecursiveHelper(make_shared<Node<ItemType>>(*cur->getNext()),entry);
        }
    }
}

//get the frequency of an item recursively without helper
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& entry) const {
    //create a static node pointer to iterate through nodes in recursion
    static auto cur{make_unique<Node<ItemType>>(*headPtr)};
    static int count = 0;
    if (cur == nullptr) {
        return count;
    }
    else {
        if (entry == cur->getItem()) {
            count++;
        }
        if(cur->getNext()!=nullptr) {
            cur = make_unique<Node<ItemType>>(*cur->getNext());
            getFrequencyOf340RecursiveNoHelper(entry);
        }
        return count;
    }
}

//remove random item from bag
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    //use toVector to put all items into a vector
    std::vector<ItemType> v = this->toVector();
    //generate a random numer between 0 and v.size
    srand((unsigned)time(NULL));
    int randomNum = rand()%v.size();
    //pick a random number in the vector and use the remove function to remove it from bag
    this->remove(v[randomNum]);
    return v[randomNum];
}