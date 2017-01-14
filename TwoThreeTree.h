

#ifndef _TWO_THREE_TREE
#define _TWO_THREE_TREE

#include "TriNode.h"

template<class T>
class TwoThreeTree{
private:
	TriNode<T>* rootPtr = nullptr;

protected:
	void inorder(void visit(T&), TriNode<T>* triNodePtr){
		if(triNodePtr->isLeaf()){
			T smallItem = triNodePtr->getSmallItem();
			T largeItem = triNodePtr->getLargeItem();
			visit(smallItem);
			visit(largeItem);
		}
	}
public:
	TwoThreeTree(){};

};

#endif