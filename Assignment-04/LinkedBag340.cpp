//	LinkedBag340.cpp
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
    //create new node and put newEntry as data
    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(newEntry);
    //get head and iterate through link until last node is found
    Node<ItemType>* cur = headPtr;
    while(cur->getNext()!=nullptr) cur=cur->getNext();
    //set the next of the last node to the node we are adding
    cur->setNext(nextNodePtr);
    itemCount++;
    return true;
}

//gets the current size of the bag iteratively
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int count = 1;
    Node<ItemType>* cur = headPtr;
    //if head is null return 0 because bag is empty
    if(cur==nullptr) return 0;
    //iterate through all the nodes and increment count if nextNode exists
    while(cur->getNext()!=nullptr){
        count++;
        cur=cur->getNext();
    } 
    return count;

}

//gets the current size recursivly
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return getCurrentSize340RecursiveHelper(headPtr);
}

//helper for getCurrentSize340Recursive()
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* cur) const {
    //base case
    if(cur->getNext()==nullptr) {
        return 1;
    } else {
        //recursive call for the next node if it exists
        return 1 + getCurrentSize340RecursiveHelper(cur->getNext());
    }
}

//get the current size recursively without a helper
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    //static node pointer to keep track of current node in recursive call
    static Node<ItemType>* cur = headPtr;
    if(cur->getNext()!=nullptr) {
        //if next node exists do recursive call on it
        cur=cur->getNext();
        return 1 + getCurrentSize340RecursiveNoHelper();
    } else {
        //base case to return 1 if there is no next node
        return 1;
    }

}

//get the frequency of an item recursively
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& entry) const {
    Node<ItemType>* cur = headPtr;
    return getFrequencyOf340RecursiveHelper(cur, entry);
}

//helper for getFrequencyOf340()
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* cur, const ItemType& entry) const {
    //base case if there is no next node
    if(cur->getNext()==nullptr) {
        //check if item matches entry, return 1 if it does 0 otherwise
       return (cur->getItem()==entry) ? 1 : 0;
    } else {
        //recursive call if there is a next node
        if(cur->getItem()==entry) {
            //return 1 + recursive call if entry matches
            return 1+getFrequencyOf340RecursiveHelper(cur->getNext(),entry);
        } else {
            //just recusive call next node if entry doesn't match
            return getFrequencyOf340RecursiveHelper(cur->getNext(),entry);
        }
    }
}

//get the frequency of an item recursively without helper
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& entry) const {
    //create a static node pointer to iterate through nodes in recursion
    static Node<ItemType>* cur;
    //static int to keep track of the count
    static int count = 0;
    //base case reached, return count
    if (cur == nullptr) {
        return count;
    }
    else {
        //if entry matches, count++, set current node to the next one
        if (entry == cur->getItem()) {
            count++;
        }
        //if next node exists recursive call on it
        if(cur->getNext()!=nullptr) {
            cur = cur->getNext();
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