
#include <iostream>
#include <cassert>

#include "BinarySearchTree.h"

using namespace std;

int main(){

	auto fnc = [](int& someInt){
		cout << someInt << " ";
	};

	BinarySearchTree<int>* bst2 = new BinarySearchTree<int>(23);
	BinarySearchTree<int>* bst3 = new BinarySearchTree<int>(66);

	bst2->add(10);
	bst2->add(30);
	bst2->add(17);
	bst2->add(21);
	bst2->add(5);
	bst2->add(15);
	bst2->add(45);
	bst2->add(27);

	bst3->add(10);
	bst3->add(30);
	bst3->add(5);
	bst3->add(15);
	bst3->add(30);

	assert(bst3->getEntry(10) == 10);
	assert(bst3->getEntry(5) == 5);
	assert(bst3->getEntry(30) == 30);
	assert(bst3->getEntry(15) == 15);

	assert(bst3->contains(10));
	assert(bst3->contains(30));
	assert(!bst3->contains(2));

	cout << "Displaying values in BinarySearchTree 2: ";
	bst2->inorderTraverse(fnc);

	cout << "Displaying values in the range from 15 to 30: ";
	bst2->traverseRange(14,31,fnc);


	cout << endl << endl;

	cout << "After removing value 30: ";
	bst2->remove(30);
	bst2->inorderTraverse(fnc);

	cout << endl << endl;

	cout << "After removing value 5: ";
	bst2->remove(5);
	bst2->inorderTraverse(fnc);

	cout << endl;

	cout << "Displaying values in BinarySearchTree 3: ";
	bst3->inorderTraverse(fnc);

	cout << endl;


	/** Tests for Constructors
	BinarySearchTree<int>* bst1 = new BinarySearchTree<int>();
	BinarySearchTree<int>* bst2 = new BinarySearchTree<int>(23);
	BinarySearchTree<int>* bst2a = new BinarySearchTree<int>(66);

	try{
		BinarySearchTree<int>* bst3 = new BinarySearchTree<int>(50,bst2,bst2a);
		assert(!bst3->isEmpty());

		BinarySearchTree<int>* bst4 = new BinarySearchTree<int>(*bst3);
		assert(!bst4->isEmpty());


	}catch(InvalidInputException iie){
		cout << iie.what() << endl;
	}

	assert(bst1->isEmpty());
	assert(!bst2->isEmpty());
	**/

	return 0;
}