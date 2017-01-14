
#include <iostream>
#include <cassert>

#include "TriNode.h"

using namespace std;

int main(){

	//Tets for constructors
	// TriNode<int>* triNode1 = new TriNode<int>();
	// TriNode<int>* triNode2 = new TriNode<int>(20);
	// TriNode<int>* triNode3 = new TriNode<int>(15,30);

	// TriNode<int>* triNode4 = new TriNode<int>(40,50, new TriNode<int>(3), new TriNode<int>(5), new TriNode<int>(7));
	// TriNode<int>* triNode5 = new TriNode<int>(70, new TriNode<int>(91), new TriNode<int>(92), new TriNode<int>(93));
	// TriNode<int>* triNode6 = new TriNode<int>(new TriNode<int>(1), new TriNode<int>(2), new TriNode<int>(3));

	// TriNode<int>* triNode7 = new TriNode<int>(new TriNode<int>(88), new TriNode<int>(89));
	// TriNode<int>* triNode8 = new TriNode<int>(67, new TriNode<int>(93), new TriNode<int>(94));

	// assert(triNode1->isLeaf());
	// assert(triNode2->isLeaf());
	// assert(triNode3->isLeaf());
	// assert(triNode3->getSmallItem() == 15);
	// assert(triNode3->getLargeItem() == 30);

	// assert(triNode4->isThreeNode());
	// assert(!triNode4->isLeaf());
	// assert(triNode5->isThreeNode());
	// assert(!triNode5->isLeaf());
	// assert(triNode6->isThreeNode());
	// assert(!triNode6->isLeaf());

	// assert(triNode7->isTwoNode());
	// assert(!triNode7->isLeaf());
	// assert(triNode8->isTwoNode());
	// assert(!triNode8->isLeaf());


	//Tests for error handling
	// try{
	// 	TriNode<int>* triNode9 = new TriNode<int>(34,12);
	// 	TriNode<int>* triNode10 = new TriNode<int>(122,100, new TriNode<int>(10), new TriNode<int>(14), new TriNode<int>(19));

	// 	cout << "For TriNode9, the small item is: " << triNode9->getSmallItem() << endl;
	// 	cout << "For TriNode9, the large item is: " << triNode9->getLargeItem() << endl;

	// 	cout << "For TriNode10, the small item is: " << triNode10->getSmallItem() << endl;
	// 	cout << "For TriNode10, the large item is: " << triNode10->getLargeItem() << endl;
	// }catch(InvalidInputException iie){
	// 	cout << iie.what() << endl;
	// }


	return 0;
}