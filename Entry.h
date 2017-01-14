


#ifndef _ENTRY_H
#define _ENTRY_H

#include <string>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "Definitions.h"

using namespace std;

template<class KeyType, class ItemType>
class Entry{
private:
	ItemType item;
	KeyType searchKey;
protected:
	void setKey(const KeyType& newSearchKey){
		searchKey = newSearchKey;
	}
public:
	Entry(KeyType newSearchKey): searchKey(newSearchKey){};
	Entry(ItemType newEntry, KeyType newSearchKey): item(newEntry),searchKey(newSearchKey){};

	ItemType getItem() const{
		return item;
	}

	KeyType getKey() const{
		return searchKey;
	}

	void setItem(const ItemType& newEntry){
		item = newEntry;
	}

	bool operator==(const Entry<KeyType,ItemType>& rhs) const{
		return searchKey == rhs.searchKey;
	}

	bool operator!=(const Entry<KeyType,ItemType>& rhs) const{
		return !(*this == rhs);
	}

	bool operator<(const Entry<KeyType,ItemType>& rhs) const{
		return searchKey < rhs.searchKey;
	}

	bool operator>(const Entry<KeyType,ItemType>& rhs) const{
		return searchKey > rhs.searchKey;
	}

	template<class K,class V>
	friend ostream& operator<<(ostream& os, const Entry<K,V>& anEntry);
};

	template<class K,class V>
	ostream& operator<<(ostream& os, const Entry<K,V>& anEntry){
		os << "Key: " << anEntry.searchKey << ", " << "Item: " << anEntry.item;
		return os;
	}

#endif