
#ifndef _ARRAY_DICTIONARY_H
#define _ARRAY_DICTIONARY_H

#include <algorithm>

#include "DictionaryInteface.h"
#include "DictEntry.h"
#include "Definitions.h"

class ArrayDictionary: public DictionaryInterface<string, Definitions>{
private:
	static const int DEFAULT_CAPACITY = 21;
	DictEntry* items;
	int itemCount;
	int maxItems;

public:
	ArrayDictionary(){
		items = new DictEntry[DEFAULT_CAPACITY];
		itemCount = 0;
		maxItems = DEFAULT_CAPACITY;
	}


	 bool isEmpty() const{
	 	return itemCount == 0;
	 };


	int getNumberOfItems() const{
		return itemCount;
	};


 	bool add(const string& word, const Definitions& newItem){
 		bool ableToInsert = (itemCount < maxItems);

 		if(ableToInsert){

 			int index = itemCount;

 			while((index > 0) && word < items[index-1].getWord()){
 				items[index] = items[index-1];
 				--index;
 			}

 			items[index] = DictEntry(word, newItem);
 			itemCount++;

 		}

 		return ableToInsert;
 	}

 	bool add(const string& word, const string& newDefinition){
 		return add(word, Definitions(newDefinition));
 	}

	 bool remove(const string& word){

		bool canRemove = itemCount > 0;

			if(canRemove){
			
			int index = 0;

				for_each(items, items+itemCount,[&index](const string& searchString){
					if(searchString == word){
						return;
					}

					++index;
					});

				if(index == itemCount){
					itemCount--;
				}else{

					for(int i = index; i < itemCount-1; i++){
						items[index] = items[index+1];
					}
					itemCount--;

			}

		return canRemove;

	}
}

	 void clear(){
		DictEntry* oldArray = items;

		items = new DictEntry[DEFAULT_CAPACITY];
		copy(oldArray, oldArray + itemCount, items);

		maxItems = DEFAULT_CAPACITY;
		itemCount = 0;
		delete [] oldArray;
	}

	 Definitions getItem(const string& searchWord) const throw(NotFoundException){

		Definitions searchDefinition;

		for_each(items, items + itemCount, [&searchDefinition,&searchWord](const string& someString){
			if(someString == searchWord){
				searchDefinition = items->getDefinitions();
			}
		});

		return searchDefinition;
	}

	string getDefinitions(const word& searchWord) const throw(NotFoundException){
		return string(getItem(searchWord));
	}
	
	bool contains(const string& word) const{
		bool result = false;
		for_each(items, items + itemCount,[&result,&word](const string& dictWord){
			if(word == dictWord){
				result = true;
			}
		});

		return result;
	}
	 
	void traverse(void visit(Definitions&)) const{
		for(int i = 0; i < itemCount; i++){
			visit(items[i].getDefinitions());
		}
	}

	void traverse(void visit(string&)){
		Definitions currentDefinition;
		for(int i = 0; i < itemCount; i++){
			currentDefinition = items[i].getDefinitions();
			for(int j = 0; j < currentDefinition.numberOfDefinitions(); j++){
				visit(currentDefinition[j]);
			}
		}
	}

};

#endif