
#ifndef _HASHED_ENTRY_H
#define _HASHED_ENTRY_H

#include "Entry.h"

using namespace std;

template<class K, class V>
class HashedEntry: public Entry<K,V>{
private:
	HashedEntry<K,V>* nextPtr;
public:
	HashedEntry(K searchKey): Entry<K,V>(searchKey){};
	HashedEntry(V newEntry, K searchKey): Entry<K,V>(newEntry,searchKey){};
	HashedEntry(V newEntry, K searchKey, Entry<K,V>* nextEntryPtr): Entry<K,V>(newEntry,searchKey),nextPtr(nextPtr){};

	void setNext(HashedEntry<K,V>* nextEntryPtr){
		nextPtr = nextEntryPtr;
	}

	HashedEntry<K,V>* getNext() const{
		return nextPtr;
	}

};

#endif