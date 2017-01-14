
#ifndef _HASHED_DICTIONARY_H
#define _HASHED_DICTIONARY_H

#include <string>
#include <functional>

#include "Entry.h"
#include "HashedEntry.h"
#include "Exceptions.h"
#include "DictionaryInteface.h"

using namespace std;

template<class K, class V>
class HashedDictionary{
private:
	static const int DEFAULT_SIZE = 101;
	HashedEntry<K,V>** hashTable;
	int itemCount;
	int hashTableSize;
	function<int(string)> hashFunction;
	//int(*hashFunction)(string);

public:
	HashedDictionary(){
		hashTable = new HashedEntry<K,V>*[DEFAULT_SIZE];
		itemCount = 0;
		hashTableSize = DEFAULT_SIZE;
		hashFunction = nullptr;
	};

	HashedDictionary(int userHashTableSize, function<int(string)> func){
		hashTable = new HashedEntry<K,V>*[userHashTableSize];
		hashTableSize = userHashTableSize;
		itemCount = 0;
		hashFunction = func;
	}

	void setHashFunction(function<int(string)>func){
		hashFunction = func;
	}

	function<int(string)> getHashFunction() const{
		return hashFunction;
	}

	bool isEmpty() const{
		return itemCount == 0;
	}

	int getNumberOfItems() const{
		return itemCount;
	}

	// void clear(){
	// 	HashedEntry<K,V>** oldHashTable = hashTable;
	// 	hashTable = new HashedEntry<K,V>**[hashTableSize];
	// 	delete [] oldHashTable;
	// }

	bool add(const V& newEntry, const K& searchKey){

		HashedEntry<K,V>* entryToAddPtr = new HashedEntry<K,V>(newEntry,searchKey);

		int itemHashIndex = hashFunction(searchKey);

		if(hashTable[itemHashIndex] == nullptr){
			hashTable[itemHashIndex] = entryToAddPtr;
		}else{
			entryToAddPtr->setNext(hashTable[itemHashIndex]);
			hashTable[itemHashIndex] = entryToAddPtr;
		}

		itemCount++;
		return true;
	}


	bool remove(const K& searchKey){
		bool itemFound = false;

		int itemHashIndex = hashFunction(searchKey);

		if(searchKey == hashTable[itemHashIndex]->getKey()){
			cout << "Found key at headptr of hashTable index..." << endl;
			HashedEntry<K,V>* entryToRemovePtr = hashTable[itemHashIndex];

			hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
			delete entryToRemovePtr;
			entryToRemovePtr = nullptr;
			itemFound = true;
			itemCount--;

		}else{
			cout << "Search for item further along the separated chain in hashTable index..." << endl;
			HashedEntry<K,V>* prevPtr = hashTable[itemHashIndex];
			HashedEntry<K,V>* crtPtr = prevPtr->getNext();

			while((crtPtr != nullptr) && !itemFound){
				if(searchKey == crtPtr->getKey()){
					if(crtPtr->getNext() != nullptr){
						prevPtr->setNext(crtPtr->getNext());
					}else{
						prevPtr->setNext(nullptr);
					}

					delete crtPtr;
					crtPtr = nullptr;
					itemFound = true;
					itemCount--;
				}else{
					prevPtr = crtPtr;
					crtPtr = crtPtr->getNext();
				}
			}
		}

		return itemFound;
	}


	bool contains(const K& searchKey){
		bool itemFound = false;

		int itemHashIndex = hashFunction(searchKey);

		HashedEntry<K,V>* prevPtr = hashTable[itemHashIndex];

		if(searchKey == prevPtr->getKey()){
			itemFound = true;
		}else{
			HashedEntry<K,V>* crtPtr = prevPtr->getNext();

			while((crtPtr != nullptr) && !itemFound){
				if(searchKey == crtPtr->getKey()){
					if(crtPtr->getNext() == nullptr){
						prevPtr->setNext(nullptr);
					}else{
						prevPtr->setNext(crtPtr->getNext());
					}
		
					delete crtPtr;
					crtPtr = nullptr;	


					itemFound = true;
				}else{
					prevPtr = crtPtr;
					crtPtr = crtPtr->getNext();
				}
			}
		}

		return itemFound;
	}



	V getItem(const K& searchKey) throw(NotFoundException){
		cout << "Starting function..." << endl;
		bool itemFound = false;

		int itemHashIndex = hashFunction(searchKey);

		cout << "Hash index obtained... " << endl;
		HashedEntry<K,V>* prevPtr = hashTable[itemHashIndex];
		HashedEntry<K,V>* crtPtr = nullptr;

		cout << "prevPtr and crtPtr's already set..." << endl;

		if(searchKey == prevPtr->getKey()){
			cout << "Search key equals headptr at hashTableIndex location..." << endl;
			return prevPtr->getItem();
		}else{
			cout << "Entering loop to traverse separate chain..." << endl;
			crtPtr = prevPtr->getNext();

			while((crtPtr != nullptr) && !itemFound){
				if(crtPtr->getKey() == searchKey){
					itemFound = true;
				}else{
					prevPtr = crtPtr;
					crtPtr = crtPtr->getNext();
				}
			}
		}

		if(crtPtr == nullptr && !itemFound){
			throw NotFoundException("Item was not found");
		}

		V item = crtPtr->getItem();
		prevPtr->setNext(crtPtr->getNext());
		delete crtPtr;
		crtPtr = nullptr;

		return item;

	}

	// void traverse(void(*visit)(V)){
	// 	for(int i = 0; i < itemCount; i++){
	// 		HashedEntry<K,V>* crtPtr = hashTable[i];

	// 		while(crtPtr != nullptr){
	// 			V item = crPtr->getItem();
	// 			visit(item);
	// 			crtPtr = crtPtr->getNext();
	// 		}
	// 	}
	// }
};

#endif