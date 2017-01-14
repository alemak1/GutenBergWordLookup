

#ifndef _BINARY_TREE_INTERFACE_H
#define _BINARY_TREE_INTERFACE_H

	#include "Exceptions.h"

	template<class T>
	class BinaryTreeInterface{
	public:
		virtual bool isEmpty() const = 0;
		virtual int getHeight() const = 0;
		virtual int getNumberOfNodes() const = 0;

		virtual T getRootData() const = 0;
		virtual void setRootData(const T& newData) = 0;

		virtual bool add(const T& newData) = 0;
		virtual bool remove(const T& data) = 0;

		virtual void clear() = 0;
		virtual T getEntry(const T& anEntry)  throw(NotFoundException) = 0;

		virtual bool contains(const T& anEntry) = 0;

		virtual void preorderTraverse(void visit(T&)) const = 0;
		virtual void inorderTraverse(void visit(T&)) const = 0;
		virtual void postorderTraverse(void visit(T&)) const = 0;
	};

#endif