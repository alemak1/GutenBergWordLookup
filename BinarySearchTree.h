

#ifndef _BINARY_SEARCH_H
#define _BINARY_SEARCH_H

#include <algorithm>
#include <functional>

#include "Exceptions.h"
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"

using namespace std;

template<class T>
class BinarySearchTree: BinaryTreeInterface<T>{
private:
	BinaryNode<T>* rootPtr;

protected:
	BinaryNode<T>* copyTree(BinaryNode<T>* treePtr) const{
		BinaryNode<T>* newTreePtr = nullptr;

		if(treePtr != nullptr){
			newTreePtr = new BinaryNode<T>(treePtr->getItem(),nullptr,nullptr);
			newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
			newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));

		}

		return newTreePtr;
	}

	void destroyTree(BinaryNode<T>* treePtr){

		if(treePtr != nullptr){
			destroyTree(treePtr->getLeftChildPtr());
			destroyTree(treePtr->getRightChildPtr());
			delete treePtr;
		}else{
			BinaryNode<T>* nodeToDelete = treePtr;
			treePtr = nullptr;
			delete nodeToDelete;
		}
	}

	void clearTree(BinaryNode<T>* treePtr){

		if(treePtr != nullptr){
				clearTree(treePtr->getLeftChildPtr());
				clearTree(treePtr->getRightChildPtr());
				delete treePtr;
		}
	
	}

	int getHeightHelper(BinaryNode<T>* subtreePtr) const{
		if(subtreePtr == nullptr){
			return 0;
		}else{
			return 1 + max(getHeightHelper(subtreePtr->getLeftChildPtr()),getHeightHelper(subtreePtr->getRightChildPtr()));
		}
	}

	int getNumberOfNodesHelper(BinaryNode<T>* subtreePtr) const{

		BinaryNode<T>* leftChildPtr = subtreePtr->getLeftChildPtr();
		BinaryNode<T>* rightChildPtr = subtreePtr->getRightChildPtr();

		if(subtreePtr == nullptr){
			return 1;
		}else if(leftChildPtr != nullptr && rightChildPtr != nullptr){
			return 1 + getNumberOfNodesHelper(leftChildPtr) + getNumberOfNodesHelper(rightChildPtr);
		}else{

				if(leftChildPtr == nullptr && rightChildPtr == nullptr){
					return 1;
				}

				if(leftChildPtr != nullptr){
					return 1 + getNumberOfNodesHelper(leftChildPtr);
				}

				if(rightChildPtr != nullptr){
					return 1 + getNumberOfNodesHelper(rightChildPtr);
				}
		}

		return 0;
	}





	BinaryNode<T>* insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr){


		if(subTreePtr == nullptr){
			return newNodePtr;
		}else if(subTreePtr->getItem() > newNodePtr->getItem()){
			BinaryNode<T>* tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
			subTreePtr->setLeftChildPtr(tempPtr);
		}else{
			BinaryNode<T>* tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
			subTreePtr->setRightChildPtr(tempPtr);
		}

		return subTreePtr;

	}

	BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success){
		if(subTreePtr == nullptr){
			success = false;
			return nullptr;
		}else if(subTreePtr->getItem() == target){
			subTreePtr = removeNode(subTreePtr);
			success = true;
			return subTreePtr;
		}else if(subTreePtr->getItem() > target){
			BinaryNode<T>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(),target,success);
			subTreePtr->setLeftChildPtr(tempPtr);
			return subTreePtr;
		}else{
			BinaryNode<T>* tempPtr = removeValue(subTreePtr->getRightChildPtr(),target,success);
			subTreePtr->setRightChildPtr(tempPtr);
			return subTreePtr;
		}
	}

	BinaryNode<T>* removeNode(BinaryNode<T>* subTreePtr){
		bool hasOnlyLeftChild = subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() == nullptr;
		bool hasOnlyRightChild = subTreePtr->getRightChildPtr() != nullptr && subTreePtr->getLeftChildPtr() == nullptr;

		if(subTreePtr->isLeaf()){
			delete subTreePtr;
			subTreePtr = nullptr;
			return subTreePtr;
		}else if(hasOnlyLeftChild || hasOnlyRightChild){

			BinaryNode<T>* nodeToConnectPtr = nullptr;

			if(hasOnlyLeftChild){
				nodeToConnectPtr = subTreePtr->getLeftChildPtr();
			}else{
				nodeToConnectPtr = subTreePtr->getRightChildPtr();
			}

			delete nodeToConnectPtr;
			nodeToConnectPtr = nullptr;

			return nodeToConnectPtr;

		}else{
			T newNodeValue;
			BinaryNode<T>* tempPtr = removeLeftmostNode(subTreePtr->getRightChildPtr(), newNodeValue);
			subTreePtr->setRightChildPtr(tempPtr);
			subTreePtr->setItem(newNodeValue);
			return subTreePtr;
		}
	}

	BinaryNode<T>* removeLeftmostNode(BinaryNode<T>* nodePtr, T& inorderSuccessor){

		if(nodePtr->getLeftChildPtr() == nullptr){
			inorderSuccessor = nodePtr->getItem();
			return removeNode(nodePtr);
		}else{
			return removeLeftmostNode(nodePtr->getLeftChildPtr(),inorderSuccessor);
		}
	}

	BinaryNode<T>* findNode(BinaryNode<T>* subTreePtr, const T& target){

		if(subTreePtr == nullptr){
			return nullptr;
		}else if(subTreePtr->getItem() == target){
			return subTreePtr;
		}else if(target < subTreePtr->getItem()){
			return findNode(subTreePtr->getLeftChildPtr(),target);
		}else{
			return findNode(subTreePtr->getRightChildPtr(),target);
		}


	}

	//perform an inorder traverse, visit function is applied to data item if the data item of the current node is greater
		//than the lower bound and lower the the upper bound
	void inorderWithBounds(void visit(T&), BinaryNode<T>* treePtr, const T& lowerBound, const T& upperBound) const{
		if(treePtr != nullptr){
			inorderWithBounds(visit, treePtr->getLeftChildPtr(),lowerBound,upperBound);
			T item = treePtr->getItem();
			if(item > lowerBound && item < upperBound){
				visit(item);
			}
			inorderWithBounds(visit,treePtr->getRightChildPtr(), lowerBound,upperBound);
		}
	}

	

	void inorder(void visit(T&), BinaryNode<T>* treePtr) const{
		if(treePtr != nullptr){
			inorder(visit, treePtr->getLeftChildPtr());
			T item = treePtr->getItem();
			visit(item);
			inorder(visit,treePtr->getRightChildPtr());
		}
	}


	void preorder(void visit(T&), BinaryNode<T>* treePtr) const{
		if(treePtr != nullptr){
			 preorder(visit,treePtr->getLeftChildPtr());
			 preorder(visit,treePtr->getRightChildPtr());
			T item = treePtr->getItem();
			visit(item);
		}
	}

	void postorder(void visit(T&), BinaryNode<T>* treePtr) const{
		if(treePtr != nullptr){
			T item = treePtr->getItem();
			visit(item);
			 postorder(visit, treePtr->getLeftChildPtr());
			 postorder(visit,treePtr->getRightChildPtr());
		}
	}


public:
/** Constructore and Destructor Section
	**/
	BinarySearchTree(): rootPtr(nullptr){};
	BinarySearchTree(const T& rootItem){
		rootPtr = new BinaryNode<T>(rootItem, nullptr, nullptr);
	}

	BinarySearchTree(const T& rootItem,  const BinarySearchTree<T>* leftTreePtr,  const BinarySearchTree<T>* rightTreePtr) throw(InvalidInputException){

		bool treeInputsNotEmpty = !leftTreePtr->isEmpty() && !rightTreePtr->isEmpty();

		if(!treeInputsNotEmpty){
			throw InvalidInputException("The two trees being used to initialize the left and right subtrees of the current binary search \
										tree must have not have nullptr's for \
											their root pointers");
		}

		if(leftTreePtr->getRootData() < rootItem && rightTreePtr->getRootData() > rootItem){
			rootPtr = new BinaryNode<T>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
		}else{
			throw InvalidInputException("The root value of the left binary search search tree must be less than the root item \
										for the current binary search tree, and the root value of the right binary search tree \
										 must be greater than the root item of the the current binary search tree");
		}
	}


	BinarySearchTree(const BinarySearchTree<T>& treePtr){
		rootPtr = copyTree(treePtr.rootPtr);
	}

	virtual ~BinarySearchTree(){
		destroyTree(rootPtr);
	}

		virtual bool isEmpty() const{
			return rootPtr == nullptr;
		}

		virtual int getHeight() const{
			return getHeightHelper(rootPtr);
		}

		virtual int getNumberOfNodes() const{
			int numNodes;

			if(rootPtr == nullptr){
				numNodes = 0;
			}else{
				numNodes = getNumberOfNodesHelper(rootPtr);
			}

			return numNodes;
		}

		virtual T getRootData() const{
			return rootPtr->getItem();
		}

		virtual void setRootData(const T& newData){
			rootPtr->setItem(newData);
		}
		
		void traverseRange(const T& lowerBound, const T& upperBound, void visit(T&)){
			inorderWithBounds(visit, rootPtr, lowerBound, upperBound);
		}

		virtual bool add(const T& newData){
			BinaryNode<T>* newNodePtr = new BinaryNode<T>(newData);
			rootPtr = insertInorder(rootPtr, newNodePtr);
			return true;
		};


		virtual bool remove(const T& data){
			bool success = false;
			rootPtr = removeValue(rootPtr, data, success);
			return success;
		}

		virtual void clear(){
			clearTree(rootPtr);
			rootPtr = nullptr;
		}

		
		virtual T getEntry(const T& anEntry) throw(NotFoundException){
			BinaryNode<T>* nodeWithItem = findNode(rootPtr, anEntry);

			if(nodeWithItem == nullptr){
				throw NotFoundException("The item you searched for could not be located");
			}

			return nodeWithItem->getItem();
		}

		virtual bool contains(const T& anEntry) {
			bool success = true;
			BinaryNode<T>* nodeWithItem = findNode(rootPtr,anEntry);

			if(nodeWithItem == nullptr){
				success = false;
			}

			return success;
		}


	/**Public Traversals Section **/

		virtual void preorderTraverse(void visit(T&)) const{
			preorder(visit, rootPtr);
		}

		virtual void inorderTraverse(void visit(T&)) const{
			inorder(visit,rootPtr);
		}

		virtual void postorderTraverse(void visit(T&))const {
			postorder(visit,rootPtr);
		}

};

#endif