//	LinkedBagClient340.cpp
//	Created by: Duc Ta

#include "Include.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

void displayBag(const unique_ptr<LinkedBag<string>>&);

int main() {

	cout << "----- LINKED BAG 340 C++-----" << endl << endl;

	// 1. Create a bag and add initial nodes
	cout << "--->>>>> Test 1 --->>>>>" << endl;
	unique_ptr<LinkedBag<string>> bag { make_unique <LinkedBag<string>>() };
	
	// A small vector of small objects to test the bag
	vector<string> items { "#-END", "5-FIVE", "4-FOUR", "4-FOUR", "3-THREE", "2-TWO", "1-ONE", "0-ZERO", "#-BEGIN" };
	cout << " !add()...     ";
	vector<string>::const_iterator cItr;
	for (cItr = items.begin(); cItr  != items.end(); cItr++) {
		cout << *cItr << " ";
		bool success = bag->add(*cItr);
		if ( !success) {
			cout << " !add() FAILED: " << *cItr << endl;
		}
	}
	displayBag(bag);

	// 2. Remove the second node
	cout << "\n--->>>>> Test 2 --->>>>>";
	cout << "\n !removeSecondNode340()... ";
	bag->removeSecondNode340();
	cout << "\n !removeSecondNode340()... ";
	bag->removeSecondNode340();
	displayBag(bag);
	cout << "\n !removeSecondNode340()... ";
	bag->removeSecondNode340();
	cout << "\n !removeSecondNode340()... ";
	bag->removeSecondNode340();
	displayBag(bag);

	// 3. Add a node to the end of the linked list
	cout << "\n--->>>>> Test 3 --->>>>>";
	cout << "\n !addEnd340()... ";
	bag->addEnd340("9-NINE");
	cout << "\n !addEnd340()... ";
	bag->addEnd340("4-FOUR"); 
	displayBag(bag);
	cout << "\n !addEnd340()... ";
	bag->addEnd340("9-NINE");
	cout << "\n !addEnd340()... ";
	bag->addEnd340("0-ZERO");
	displayBag(bag);

	// 4. getCurrentSize() - Iterative
	cout << "\n--->>>>> Test 4 --->>>>>";
	cout << "\n !getCurrentSize340Iterative - Iterative... ";
	cout << "\n  ---> Current size: " << bag->getCurrentSize340Iterative();
	displayBag(bag);

	// 5. getCurrentSize() - Recursive
	cout << "\n--->>>>> Test 5 --->>>>>";
	cout << "\n !getCurrentSize340Recursive() - Recursive... ";
	cout << "\n  ---> Current size: " << bag->getCurrentSize340Recursive();
	displayBag(bag);
		
	// 6. getCurrentSize() - Recursive w/ no helper function
	cout << "\n--->>>>> Test 6 --->>>>>";
	cout << "\n !getCurrentSize340RecursiveNoHelper() - Recursive... ";
	cout << "\n  ---> Current size: " << bag->getCurrentSize340RecursiveNoHelper();
	displayBag(bag);
	
	// 7. getFrequencyOf() - Recursive
	cout << "\n--->>>>> Test 7 --->>>>>";

	cout << "\n !getFrequencyOf()... ";
	cout << "\n  ---> 0-ZERO:  " << bag->getFrequencyOf("0-ZERO");
	cout << "\n  ---> 1-ONE:   " << bag->getFrequencyOf("1-ONE");
	cout << "\n  ---> 2-TWO:   " << bag->getFrequencyOf("2-TWO");
	cout << "\n  ---> 4-FOUR:  " << bag->getFrequencyOf("4-FOUR");
	cout << "\n  ---> 9-NINE:  " << bag->getFrequencyOf("9-NINE");
	displayBag(bag);

	cout << "\n !getFrequencyOf340Recursive() - Recursive... ";
	cout << "\n  ---> 0-ZERO:  " << bag->getFrequencyOf340Recursive("0-ZERO");
	cout << "\n  ---> 1-ONE:   " << bag->getFrequencyOf340Recursive("1-ONE");
	cout << "\n  ---> 2-TWO:   " << bag->getFrequencyOf340Recursive("2-TWO");
	cout << "\n  ---> 4-FOUR:  " << bag->getFrequencyOf340Recursive("4-FOUR");
	cout << "\n  ---> 9-NINE:  " << bag->getFrequencyOf340Recursive("9-NINE");
	displayBag(bag);

	// 8. getFrequencyOf() - Recursive w/ no helper fuction
	cout << "\n--->>>>> Test 8 --->>>>>";
	cout << "\n !getFrequencyOf340RecursiveNoHelper() - Recursive... ";
	cout << "\n  ---> 0-ZERO:  " << bag->getFrequencyOf340RecursiveNoHelper("0-ZERO");
	cout << "\n  ---> 1-ONE:   " << bag->getFrequencyOf340RecursiveNoHelper("1-ONE");
	cout << "\n  ---> 2-TWO:   " << bag->getFrequencyOf340RecursiveNoHelper("2-TWO");
	cout << "\n  ---> 4-FOUR:  " << bag->getFrequencyOf340RecursiveNoHelper("4-FOUR");
	cout << "\n  ---> 9-NINE:  " << bag->getFrequencyOf340RecursiveNoHelper("9-NINE");
	displayBag(bag);

	// 9. Remove a random node
	cout << "\n--->>>>> Test 9 --->>>>>";
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	displayBag(bag);
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	displayBag(bag);
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	displayBag(bag);
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	cout << "\n !removeRandom340() ---> " << bag->removeRandom340();
	displayBag(bag);

	cout << endl;
	return 0;
}

// Display the current contents in the bag
void displayBag(const unique_ptr<LinkedBag<string>>& bag) {
	cout << "\n !Display bag: ";
	auto bagItems = make_unique<vector<string>>(bag->toVector());

	vector<string>::const_iterator cItr;
	for (cItr = bagItems->begin(); cItr  != bagItems->end(); cItr++) {
		cout << *cItr << " ";
	}
	
	cout << "\n  -----------> " << bagItems->size() << " item(s) total";
	cout << endl;
}