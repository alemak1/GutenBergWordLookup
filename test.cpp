
#include <iostream>
#include <string>
#include <cassert>

#include "BinaryNode.h"

using namespace std;

int main(){
	BinaryNode<int> bnode1;
	BinaryNode<int> bnode2(10);

	BinaryNode<int>* bnodePtr1 = &bnode1;
	BinaryNode<int>* bnodePtr2 = &bnode2;

	BinaryNode<int> bnode3(23, bnodePtr1, bnodePtr2);

	assert(bnode3.getItem() == 23);
	assert(bnode3.getRightChildPtr()->getItem() == 10);
	assert(bnode3.getLeftChildPtr()->isLeaf());
	assert(bnode3.getRightChildPtr()->isLeaf());
	assert(!bnode3.isLeaf());

	BinaryNode<string>* bnodePtrA = new BinaryNode<string>();

	bnodePtrA->setItem("Love");
	bnodePtrA->setLeftChildPtr(new BinaryNode<string>("Justice"));
	bnodePtrA->setRightChildPtr(new BinaryNode<string>("Truth"));

	cout << "The data value of BinaryNodePtr A is 'Love': " << bnodePtrA->getItem() << endl;
	cout << "The data value of BinaryNodePtr A's left child is 'Justice': " << (bnodePtrA->getLeftChildPtr())->getItem() << endl;
	cout << "The data value of BinaryNodePtr A's right child is 'Truth': " << (bnodePtrA->getRightChildPtr())->getItem() << endl;

	cout << "BinaryNodePtr A is a leaf should be 'false': " << bnodePtrA->isLeaf() << endl;
	cout << "BinaryNodePtr A's left child is a leaf is 'true': " << bnodePtrA->getLeftChildPtr()->isLeaf() << endl;
	cout << "BinaryNodePtr A's right child is a leaf is also 'true': " << bnodePtrA->getRightChildPtr()->isLeaf() << endl;


	return 0;
}