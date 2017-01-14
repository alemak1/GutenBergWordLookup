

#ifndef _DICTIONARY_INTEFACE_H
#define _DICTIONARY_INTEFACE_H

#include <stdexcept>
#include <string>

#include "Exceptions.h"

using namespace std;



template<class KeyType, class ItemType>
class DictionaryInterface{
public:
	virtual bool isEmpty() const = 0;
	virtual int getNumberOfItems() const = 0;
	virtual bool add(const KeyType& searchKey, const ItemType& newItem) = 0;
	virtual bool remove(const KeyType& searchKey) = 0;
	virtual void clear() = 0;
	virtual ItemType getItem(const KeyType& searchKey) const throw(NotFoundException) = 0;
	virtual bool contains(const KeyType& searchKey) const = 0;
	virtual void traverse(void visit(ItemType&)) const = 0;

};

#endif