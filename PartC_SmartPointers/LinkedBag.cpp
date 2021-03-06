//  LinkedBag.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <cstddef>
#include "Node.h"
#include "LinkedBag.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//
using namespace std;
template<typename ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}

template<typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;

	if (origChainPtr == nullptr) {
		headPtr = nullptr; 
	}
	else {
<<<<<<< HEAD
		shared_ptr<ItemType> headptr {headPtr->setItem(origChainPtr->getItem())};
=======
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
>>>>>>> 2a46b3db71acdf75ec3b3d97e8043475b5725c2c


		shared_ptr<ItemType> newChainPtr = headPtr; 
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != nullptr)
		{
			ItemType nextItem = origChainPtr->getItem();
<<<<<<< HEAD
			unique_ptr<ItemType> newNodePtr {nextItem}
=======
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
>>>>>>> 2a46b3db71acdf75ec3b3d97e8043475b5725c2c
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		} 

		newChainPtr->setNext(nullptr);
	}
}
 
template<typename ItemType>
LinkedBag<ItemType>::~LinkedBag() {
	clear();
} 

template<typename ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

template<typename ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
<<<<<<< HEAD
	unique_ptr<ItemType> nextNodePtr {newEntry};
=======
	auto nextNodePtr{make_unique<Node<ItemType>>(newEntry)};
>>>>>>> 2a46b3db71acdf75ec3b3d97e8043475b5725c2c
	nextNodePtr->setNext(headPtr);  
	headPtr=nextNodePtr.release();
	itemCount++;
	return true;
}


template<typename ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
	std::vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;

	while ((curPtr != nullptr) && (counter < itemCount)) {
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}

	return bagContents;
}

template<typename ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
	auto entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

	if (canRemoveItem) {
		entryNodePtr->setItem(headPtr->getItem());
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	}

	return canRemoveItem;
}

template<typename ItemType>
void LinkedBag<ItemType>::clear() {
	Node<ItemType>* nodeToDeletePtr = headPtr;

	while (headPtr != nullptr) {
		headPtr = headPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	}

	itemCount = 0;
} 

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;

	while ((curPtr != nullptr) && (counter < itemCount)) {
		if (anEntry == curPtr->getItem()) {
			frequency++;
		} 
		counter++;
		curPtr = curPtr->getNext();
	}

	return frequency;
}

template<typename ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
	return (getPointerTo(anEntry) != nullptr);
}

template<typename ItemType>
unique_ptr<Node<ItemType>> LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {
	bool found = false;
	auto curPtr{make_unique<Node<ItemType>>(*headPtr)};

	while (!found && (curPtr != nullptr)) {
		if (anEntry == curPtr->getItem()) {
			found = true;
		}
		else {
			curPtr = make_unique<Node<ItemType>>(*curPtr->getNext());
		}
	}
	return curPtr;
} 