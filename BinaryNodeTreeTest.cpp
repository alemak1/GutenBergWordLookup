
#include <iostream>
#include <string>
#include <cassert>

#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include "BinaryNodeTree.h"

using namespace std;

// void displayInt(int& someInt){
// 	cout << someInt << " ";
// }

int main(){
	
	auto f = [](int& intItem){
		cout << intItem << " ";
	};

	/** Tests for balancedAdd() and add() **/

	BinaryNodeTree<int>* level0_BinaryNodeTree = new BinaryNodeTree<int>(144);
	level0_BinaryNodeTree->add(99);
	level0_BinaryNodeTree->add(150);

	cout << "Inorder Traverse after adding (in order) 144, 99, 150: " << endl;
	level0_BinaryNodeTree->inorderTraverse(*f);
	cout << endl;

	cout << "Height of tree (should be 2): " << level0_BinaryNodeTree->getHeight() << endl;
	cout <<  "Number of nodes (should be 3): " << level0_BinaryNodeTree->getNumberOfNodes() << endl;

	level0_BinaryNodeTree->add(10);
	level0_BinaryNodeTree->add(20);

	cout << "Inorder Traverse after adding (in order) 10 and 20: " << endl;
	level0_BinaryNodeTree->inorderTraverse(*f);
	cout << endl;


	level0_BinaryNodeTree->add(30);
	level0_BinaryNodeTree->add(40);

	cout << "Height of tree (should be 3): " << level0_BinaryNodeTree->getHeight() << endl;
	cout << "Number of nodes (should be 7): " << level0_BinaryNodeTree->getNumberOfNodes() << endl;

	

	assert(level0_BinaryNodeTree->contains(10));
	assert(level0_BinaryNodeTree->contains(40));
	assert(level0_BinaryNodeTree->contains(99));
	assert(!level0_BinaryNodeTree->contains(11));
	assert(!level0_BinaryNodeTree->contains(21));
	assert(!level0_BinaryNodeTree->contains(31));

	// cout << "The result of calling contains(11) is False: " << level0_BinaryNodeTree->contains(11) << endl;
	// cout << "The result of calling contains(11) is False: " << level0_BinaryNodeTree->contains(21) << endl;
	// cout << "The result of calling contains(11) is False: " << level0_BinaryNodeTree->contains(31) << endl;

	try{
		cout << "The result of getEntry(10) is 10: " << (level0_BinaryNodeTree->getEntry(10)) << endl;
		cout << "The result of getEntry(40) is 40: " << (level0_BinaryNodeTree->getEntry(40)) << endl;
		cout << "The result of getEntry(99) is 99: " << (level0_BinaryNodeTree->getEntry(99)) << endl;

		level0_BinaryNodeTree->getEntry(11);

	}catch(NotFoundException nte){
		cout << nte.what() << endl;
	}


	level0_BinaryNodeTree->inorderTraverse(*f);
	cout << endl;

	// try{
	// 	cout << "The parent node value of 99 is: " << level0_BinaryNodeTree->getParentNodeValue(99) << endl;
	// 	cout << "The parent node value of 150 is: " << level0_BinaryNodeTree->getParentNodeValue(150) << endl;
	// 	cout << "The parent node value of 10 is: " << level0_BinaryNodeTree->getParentNodeValue(10) << endl;
	// 	cout << "The parent node value of 30 is: " << level0_BinaryNodeTree->getParentNodeValue(30) << endl;
	// 	cout << "The parent node vaue of 40 is: " << level0_BinaryNodeTree->getParentNodeValue(40) << endl;
	// 	cout << "The parent node value of 144 is: " << level0_BinaryNodeTree->getParentNodeValue(144) << endl;

	// }catch(NotFoundException nfe){
	// 	cout << nfe.what() << endl;
	// }

	// assert(level0_BinaryNodeTree->remove(144));

	assert(level0_BinaryNodeTree->remove(40));

	cout << "After removing the 40, an inorder traverse shows the following: " << endl;

	level0_BinaryNodeTree->inorderTraverse(*f);

	cout << endl;

	assert(level0_BinaryNodeTree->remove(10));

	cout << "After removing the 10, an inorder traverse shows the following: " << endl;

	level0_BinaryNodeTree->inorderTraverse(*f);

	cout << endl;

	assert(level0_BinaryNodeTree->remove(144));

	cout << "After removing the 144, an inorder traverse shows the following: " << endl;

	level0_BinaryNodeTree->inorderTraverse(*f);

	cout << endl;

	


	/** Tests for destructor, copy constructor, getHeight(), getNumberOfNodes(), isEmpty(), clear();
	BinaryNodeTree<int>* binaryNodeTreeA1 = new BinaryNodeTree<int>(10);
	BinaryNodeTree<int>* binaryNodeTreeA2 = new BinaryNodeTree<int>(20);
	BinaryNodeTree<int>* binaryNodeTreeB1 = new BinaryNodeTree<int>(5);
	BinaryNodeTree<int>* BinaryNodeTreeB2 = new BinaryNodeTree<int>(8);

	BinaryNodeTree<int>* binaryNodeTreeC1 = new BinaryNodeTree<int>(100, binaryNodeTreeA1,binaryNodeTreeA2);
	BinaryNodeTree<int>* binaryNodeTreeC2 = new BinaryNodeTree<int>(200, binaryNodeTreeB1,BinaryNodeTreeB2);

	BinaryNodeTree<int>* binaryNodeTreeD1 = new BinaryNodeTree<int>(800, binaryNodeTreeC1, binaryNodeTreeC2);

	assert(binaryNodeTreeD1->getHeight() == 3);
	assert(binaryNodeTreeD1->getNumberOfNodes() == 7);

	BinaryNodeTree<int>* binaryNodeTreeD1_copy = new BinaryNodeTree<int>(*binaryNodeTreeD1);
	assert(binaryNodeTreeD1_copy->getHeight() == 3);
	assert(binaryNodeTreeD1_copy->getNumberOfNodes() == 7);
	binaryNodeTreeD1_copy->clear();
	assert(binaryNodeTreeD1_copy->isEmpty());
	assert(binaryNodeTreeD1_copy->getNumberOfNodes() == 0);

	BinaryNodeTree<int>* treeToDelete = binaryNodeTreeD1;
	delete treeToDelete;
	**/


	/** Tests for default constructor, isEmpty(), getNumberOfNodes(), single-parameter constructor (taking data item as
	argument only, three-parameter constructor(taking data item as well as two BinaryTree pointers as arguments), setRootData(),
	and getRootData()

	BinaryNodeTree<int> binTree1;
	assert(binTree1.getNumberOfNodes() == 0);
	assert(binTree1.isEmpty());

	BinaryNodeTree<int> binTree2(44);
	assert(binTree2.getNumberOfNodes() == 1);
	assert(!binTree2.isEmpty());

	BinaryNodeTree<int>* binTree1Ptr = &binTree1;
	BinaryNodeTree<int>* binTree2Ptr = &binTree2;

	BinaryNodeTree<int>* binTreeAPtr = new BinaryNodeTree<int>(110,binTree1Ptr,new BinaryNodeTree<int>(63));
	cout << "Number of nodes in binTreeA: " << binTreeAPtr->getNumberOfNodes() << endl;

	BinaryNodeTree<int>* binTreeBPtr = new BinaryNodeTree<int>(120,binTree2Ptr,new BinaryNodeTree<int>(64));
	cout << "Number of nodes in binTreeB: " << binTreeBPtr->getNumberOfNodes() << endl;

	BinaryNodeTree<int>* binTreeCPtr = new BinaryNodeTree<int>(130, binTreeAPtr,binTreeBPtr);
	assert(binTreeCPtr->getHeight() == 3);
	
	cout << "Number of nodes in binTree: " << binTreeCPtr->getNumberOfNodes() << endl;

	BinaryNodeTree<int>* leftNodePtr = new BinaryNodeTree<int>(33);
	BinaryNodeTree<int>* rightNodePtr = new BinaryNodeTree<int>(55);
	BinaryNodeTree<int>* newBinaryTreePtr = new BinaryNodeTree<int>(23,leftNodePtr,rightNodePtr);

	cout << "Before resetting the root value of newBinaryTreePtr: ";
	cout << newBinaryTreePtr->getRootData() << endl;
	assert(newBinaryTreePtr->getRootData() == 23);

	cout << "After resetting the root value of newBinaryTreePtr: ";
	newBinaryTreePtr->setRootData(66);
	cout << newBinaryTreePtr->getRootData() << endl;
	assert(newBinaryTreePtr->getRootData() == 66);

	cout << "The height of newBinaryTreePtr is 2: " << newBinaryTreePtr->getHeight() << endl;


	newBinaryTreePtr->clear();
	assert(newBinaryTreePtr->isEmpty());
	**/
	return 0;
}