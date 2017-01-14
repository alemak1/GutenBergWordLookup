

#ifndef _TRI_NODE
#define _TRI_NODE

#include "Exceptions.h"

template<class T>
class TriNode{
private:
	T smallItem; //enforce value initialization of the dataItems
	T largeItem; //enforce value initialization of the dataItems
	TriNode<T>* leftChildPtr = nullptr;
	TriNode<T>* midChildPtr = nullptr;
	TriNode<T>* rightChildPtr = nullptr;
public:
	// TriNode(): leftChildPtr(nullptr),midChildPtr(nullptr),rightChildPtr(nullptr){};

	//Constructors for which data items are initialized only
	// TriNode(const T& anItem): smallItem(anItem){};
	// TriNode( const T& aSmallItem,  const T& aLargeItem): smallItem(aSmallItem),largeItem(aLargeItem){
	// 	if(aSmallItem > aLargeItem){
	// 		throw InvalidInputException("The smaller item must be smaller in value than the larger item.");
	// 	};
	// };

	//Three-Node Constructors
	// TriNode(TriNode<T>* leftPtr, TriNode<T>* midPtr, TriNode<T>* rightPtr): leftChildPtr(leftPtr),midChildPtr(midPtr),rightChildPtr(rightPtr){};

	// TriNode( const T& anItem, TriNode<T>* leftPtr, TriNode<T>* midPtr, TriNode<T>* rightPtr): smallItem(anItem),
	// 	leftChildPtr(leftPtr),midChildPtr(midPtr),rightChildPtr(rightPtr){};

	TriNode(const T& aSmallItem, const T& aLargeItem, TriNode<T>* leftPtr, TriNode<T>* midPtr, TriNode<T>* rightPtr): 
		smallItem(aSmallItem), largeItem(aLargeItem), leftChildPtr(leftPtr),midChildPtr(midPtr),rightChildPtr(rightPtr){
			if(aSmallItem > aLargeItem){
				throw InvalidInputException("The smaller data item must be smaller in value than the larger data item");
			};

		};

	//Two-Node Constructor
	TriNode(const T& aSmallItem, TriNode<T>* leftPtr, TriNode<T>* midPtr): 
		smallItem(aSmallItem), leftChildPtr(leftPtr),midChildPtr(midPtr){};

	// TriNode(TriNode<T>* leftPtr, TriNode<T>* midPtr): leftChildPtr(leftPtr),midChildPtr(midPtr){};



	bool isLeaf() const{
		return leftChildPtr == nullptr && midChildPtr == nullptr && rightChildPtr == nullptr;
	}

	bool isTwoNode() const{
		bool condition1 = leftChildPtr == nullptr && midChildPtr != nullptr && rightChildPtr != nullptr;
		bool condition2 = leftChildPtr != nullptr && midChildPtr != nullptr && rightChildPtr == nullptr;
		bool condition3 = leftChildPtr != nullptr && midChildPtr == nullptr && rightChildPtr != nullptr;

		return condition3 || condition2 || condition1;
	}

	bool isThreeNode() const{
		return leftChildPtr != nullptr && midChildPtr != nullptr && rightChildPtr != nullptr;
	}

	T getSmallItem() const{
		return smallItem;
	}

	T getLargeItem() const{
		return largeItem;
	}


	void setSmallItem(const T& newSmallItem){
		smallItem = newSmallItem;
	}

	void setLargeItem(const T& newLargeItem){
		largeItem = newLargeItem;
	}

	TriNode<T>* getLeftChildPtr() const{
		return leftChildPtr;
	}

	TriNode<T>* getMidChildPtr() const{
		return midChildPtr;
	}

	TriNode<T>* getRightChildPtr() const{
		return rightChildPtr;
	}

	void setLeftChildPtr(const T& newLeftChildPtr) const{
		leftChildPtr = newLeftChildPtr;
	}

	void setMidChildPtr(const T& newMidChildPtr) const{
		midChildPtr = newMidChildPtr;
	}

	void setRightChildPtr(const T& newRightChildPtr) const{
		rightChildPtr = newRightChildPtr;
	}
		

};


#endif