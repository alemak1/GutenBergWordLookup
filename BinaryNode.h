

#ifndef _BINARY_NODE_H
#define _BINARY_NODE_H

template<class P>
class BinaryNode{
private:
	P dataItem;
	BinaryNode<P>* leftChildPtr;
	BinaryNode<P>* rightChildPtr;
public:
	BinaryNode(): leftChildPtr(nullptr), rightChildPtr(nullptr){};

	BinaryNode(const P& someData){
		dataItem = someData;
		leftChildPtr = nullptr;
		rightChildPtr = nullptr;
	};

	BinaryNode(const P& someData, BinaryNode<P>* uLeftChildPtr, BinaryNode<P>* uRightChildPtr){
		dataItem = someData;
		leftChildPtr = uLeftChildPtr;
		rightChildPtr = uRightChildPtr;
	}

	void setItem(const P& someItem){
		dataItem = someItem;
	}
	
	P getItem() const{
		return dataItem;
	}

	bool isLeaf() const{
		return (leftChildPtr == nullptr) && (rightChildPtr == nullptr);
	}

	BinaryNode<P>* getLeftChildPtr() const{
		return leftChildPtr;
		};

	BinaryNode<P>* getRightChildPtr() const{
		return rightChildPtr;
		};

	void setLeftChildPtr(BinaryNode<P>* newLeftChildPtr){
		leftChildPtr = newLeftChildPtr;
	};

	void setRightChildPtr(BinaryNode<P>* newRightChildPtr){
		rightChildPtr = newRightChildPtr;
	};

};


#endif