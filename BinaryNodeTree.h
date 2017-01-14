
#ifndef _BINARY_NODE_TREE_H
#define _BINARY_NODE_TREE_H

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "Exceptions.h"

using namespace std;

template <class T>
class BinaryNodeTree: BinaryTreeInterface<T>{ //public BinaryTreeInterface<T>{
private:
	BinaryNode<T>* rootPtr;

protected:
	/** Protected Helper Utility Methods
	**/

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

	 


	BinaryNode<T>* balancedAdd(BinaryNode<T>* subtreePtr, BinaryNode<T>* newNodePtr){

		if(subtreePtr == nullptr){
			return newNodePtr;
		}else{
			BinaryNode<T>* leftPtr = subtreePtr->getLeftChildPtr();
			BinaryNode<T>* rightPtr = subtreePtr->getRightChildPtr();

			if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr)){
				rightPtr = balancedAdd(rightPtr,newNodePtr);
				subtreePtr->setRightChildPtr(rightPtr);
			}else{
				leftPtr = balancedAdd(leftPtr,newNodePtr);
				subtreePtr->setLeftChildPtr(leftPtr);
			}

			return subtreePtr;
		}

	}


	BinaryNode<T>* getFirstLeafParent(BinaryNode<T>* subTreePtr){

		if(subTreePtr != nullptr){
				BinaryNode<T>* leftPtr = subTreePtr->getLeftChildPtr();
				BinaryNode<T>* rightPtr = subTreePtr->getRightChildPtr();

				if(!leftPtr->isLeaf() && !rightPtr->isLeaf()){
					if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr)){
						return getFirstLeafParent(leftPtr);
					}else{
						return getFirstLeafParent(rightPtr);
					}
				}else{
					if(leftPtr->isLeaf() || rightPtr->isLeaf()){
						return subTreePtr;
					}

				}

			}
		

		return subTreePtr;

	}

	BinaryNode<T>* moveValuesUpTree(BinaryNode<T>* subTreePtr){

		T item = subTreePtr->getItem();

		if(subTreePtr != nullptr && !subTreePtr->isLeaf()){

			BinaryNode<T>* leafParentPtr = getFirstLeafParent(subTreePtr);


			BinaryNode<T>* rightPtr = leafParentPtr->getRightChildPtr();
			BinaryNode<T>* leftPtr = leafParentPtr->getLeftChildPtr();

			if(leftPtr != nullptr && leftPtr->isLeaf()){
				item = leftPtr->getItem();
				leafParentPtr->setLeftChildPtr(nullptr);
				delete leftPtr;
				leftPtr = nullptr;
			}

			if(rightPtr != nullptr && rightPtr->isLeaf()){
				item = rightPtr->getItem();
				leafParentPtr->setRightChildPtr(nullptr);
				delete rightPtr;
				rightPtr = nullptr;
			}

			
			
		}

		subTreePtr->setItem(item);

		return subTreePtr;
	}


	BinaryNode<T>* getParentNode(BinaryNode<T>* subTreePtr, BinaryNode<T>* searchedNodePtr){

		BinaryNode<T>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<T>* rightPtr = subTreePtr->getRightChildPtr();
		T searchedItem = searchedNodePtr->getItem();

		if(subTreePtr != nullptr){
			if(leftPtr != nullptr && leftPtr->getItem() == searchedItem){
				return subTreePtr;
			}

			if(rightPtr != nullptr && rightPtr->getItem() == searchedItem){
				return subTreePtr;
			}

			if(leftPtr != nullptr && !leftPtr->isLeaf()){
				return getParentNode(leftPtr,searchedNodePtr);
			}

			if(rightPtr != nullptr && !rightPtr->isLeaf()){
				return getParentNode(rightPtr,searchedNodePtr);
			}

			return nullptr;
		}

		return nullptr;
	}


	BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target) throw(NotFoundException){


		BinaryNode<T>* nodeToRemove = findNode(subTreePtr,target,false);

		if(nodeToRemove == nullptr){
			throw NotFoundException("The value to be removed could not be found");
		}



		BinaryNode<T>* parentNodePtr = getParentNode(rootPtr, nodeToRemove);


		if(parentNodePtr == nullptr){
			nodeToRemove = moveValuesUpTree(nodeToRemove);
			return nodeToRemove;
		}

		BinaryNode<T>* leftChildPtr = parentNodePtr->getLeftChildPtr();
		BinaryNode<T>* rightChildPtr = parentNodePtr->getRightChildPtr();


		bool inLeftBranch = leftChildPtr != nullptr && leftChildPtr->getItem() == nodeToRemove->getItem();
		bool inRightBranch = rightChildPtr != nullptr && rightChildPtr->getItem() == nodeToRemove->getItem();


			if(nodeToRemove->isLeaf()){
				
				if(inLeftBranch){
					parentNodePtr->setLeftChildPtr(nullptr);
					
				}

				if(inRightBranch){
					parentNodePtr->setRightChildPtr(nullptr);
			
				}

				delete nodeToRemove;
				nodeToRemove = nullptr;

			}else{

				nodeToRemove = moveValuesUpTree(nodeToRemove);


				if(inLeftBranch){
					parentNodePtr->setLeftChildPtr(nodeToRemove);
					
				}

				if(inRightBranch){
					parentNodePtr->setRightChildPtr(nodeToRemove);
			
				}
			}
		

		return subTreePtr;
	}


	BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target, bool success) const{

	
		if(treePtr == nullptr && !success){
			return nullptr;
		}else if(success){
			return treePtr;
		}else{
			T item = treePtr->getItem();

			if(item == target){
				return findNode(treePtr,target,true);
			}else{


				BinaryNode<T>* leftPtr = findNode(treePtr->getLeftChildPtr(), target, false);
				BinaryNode<T>* rightPtr = findNode(treePtr->getRightChildPtr(),target,false);

				if(leftPtr == nullptr && rightPtr == nullptr){
					return nullptr;
				}else{

					if(rightPtr != nullptr){
						return findNode(rightPtr,target,false);
					}

					if(leftPtr != nullptr){
						return findNode(leftPtr,target,false);
					}
				}





			}
		}

		return treePtr;
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
	BinaryNodeTree(): rootPtr(nullptr){};
	BinaryNodeTree(const T& rootItem){
		rootPtr = new BinaryNode<T>(rootItem, nullptr, nullptr);
	}

	BinaryNodeTree(const T& rootItem,  const BinaryNodeTree<T>* leftTreePtr,  const BinaryNodeTree<T>* rightTreePtr){
		rootPtr = new BinaryNode<T>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
	}


	BinaryNodeTree(const BinaryNodeTree<T>& treePtr){
		rootPtr = copyTree(treePtr.rootPtr);
	}

	virtual ~BinaryNodeTree(){
		destroyTree(rootPtr);
	}

	/** Public BinaryTreeInterface Methods Sections
	**/
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

		virtual bool add(const T& newData){
			BinaryNode<T>* newNodePtr = new BinaryNode<T>(newData,nullptr,nullptr);
			rootPtr = balancedAdd(rootPtr, newNodePtr);

			return true;
		}

		// virtual bool remove(const T& data) = 0;

		virtual void clear(){
			clearTree(rootPtr);
			rootPtr = nullptr;
		}

		virtual T getEntry(const T& anEntry) const throw(NotFoundException){
			BinaryNode<T>* nodeToFind = findNode(rootPtr, anEntry, false);

			if(nodeToFind == nullptr){
				throw NotFoundException("Could not find item");
			}

			return nodeToFind->getItem();
		}


		virtual bool contains(const T& anEntry) const{
			bool result = false;
			BinaryNode<T>* nodeToFind = findNode(rootPtr,anEntry,false);

			if(nodeToFind != nullptr){
				result = true;
			}

			return result;

		}

	virtual bool remove(const T& data){

		bool result;

		try{
			BinaryNode<T>* nodeToRemove = removeValue(rootPtr,data);
			result = (nodeToRemove == nullptr) ? false:true;

		}catch(NotFoundException nfe){
			cout << endl << nfe.what() << endl;
		}



		return result;
	}



	T getParentNodeValue(T target) throw(NotFoundException){


		BinaryNode<T>* parentNodePtr = getParentNode(rootPtr,findNode(rootPtr,target,false));
		T itemForParentNode;

		if(parentNodePtr != nullptr){
			itemForParentNode = parentNodePtr->getItem();
		}else{
			throw NotFoundException("Value could not be found");
		}

		return itemForParentNode;

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

	/** Overloaded Operators Section **/

};

#endif