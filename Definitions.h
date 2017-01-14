


#ifndef _DEFINITIONS_H
#define _DEFINITIONS_H

#include <string>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;


class Definitions{
private:
	const static int DEFAULT_CAPACITY = 10;
	int currentCapacity = DEFAULT_CAPACITY;
	int itemCount = 0;
	string* definitionItems;
public:


	Definitions(){
		definitionItems = new string[currentCapacity];
	}

	Definitions(int newCapacity){
		currentCapacity = newCapacity;
		definitionItems = new string[newCapacity];
	}

	Definitions(const string& newDefinition){
		definitionItems = new string[currentCapacity];
		appendDefinition(newDefinition);
	}

	int getCurrentCapacity() const{
		return currentCapacity;
	}

	bool hasDefinitions(){
		return itemCount > 0;
	}

	bool isEmpty(){
		return itemCount == 0;
	}

	int numberOfDefinitions() const{
		return itemCount;
	}

	void appendDefinition(string newDefinition){
		if(itemCount== currentCapacity){
			string* oldItemsArray = definitionItems;

			currentCapacity *= 2;
			definitionItems = new string[currentCapacity];

			for(int i = 0; i < itemCount; i++){
				definitionItems[i] = oldItemsArray[i];
			}

			delete [] oldItemsArray;

		}

		definitionItems[itemCount] = newDefinition;
		++itemCount;


	}

	void popDefinition(){

		--itemCount;

		if(itemCount == DEFAULT_CAPACITY){
			string* oldItemsArray = definitionItems;

			currentCapacity /= 2;
			definitionItems = new string[currentCapacity];

			for(int i = 0; i < itemCount; i++){
				definitionItems[i] = oldItemsArray[i];
			}

			delete [] oldItemsArray;
		}
	}

	void showDefinitions(ostream& os){
		int cnt = 0;
		for_each(definitionItems,definitionItems+itemCount,[&cnt, &os](const string& def){
			os << cnt << ": " << def << endl;
			cnt++;
		});
	}



	string& operator[](size_t index){
		if(index > itemCount){
			throw out_of_range("Invalid index: out of range");
		}
		return definitionItems[index];
	}

	const string& operator[](size_t index) const{
		if(index > itemCount){
			throw out_of_range("Invalid index: out of range");
		}

		return definitionItems[index];
	}


	Definitions& operator=(const Definitions& rhs){
		string* oldArray = definitionItems;

		definitionItems = new string[rhs.currentCapacity];

		for(int i = 0; i < rhs.itemCount; i++){
			appendDefinition(rhs.definitionItems[i]);
		}

		delete [] oldArray;

		return *this;
	};

	Definitions& operator=(const string& newDefinition){

		appendDefinition(newDefinition);

		return *this;	
	};

	Definitions& operator+=(const string& newDefinition){
		appendDefinition(newDefinition);

		return *this;
	}

	Definitions& operator+=(const Definitions& newDefinition){
		for(int i = 0; i < newDefinition.itemCount; i++){
			appendDefinition(newDefinition.definitionItems[i]);
		}

		return *this;
	}


	operator string(){
		string str = "";

		for(int i = 0; i < itemCount; i++){
			str.append(to_string(i+1));
			str.append(". ");
			str.append(definitionItems[i]);
			str.append(" ");
		}

		return str;
	}

	friend ostream& operator<<(ostream& os, const Definitions& aDefinition);
	friend Definitions operator+(const Definitions& lhs, const Definitions& rhs);
	friend bool operator==(const Definitions& lhs, const Definitions& rhs);
	friend bool operator!=(const Definitions& lhs, const Definitions& rhs);
};

 	bool operator==(const Definitions& lhs, const Definitions& rhs){
 		bool result = true;

 		if(lhs.itemCount != rhs.itemCount){
 			result = false;
 		}else{
 			for(int i = 0; i < lhs.itemCount; i++){
 				if(lhs.definitionItems[i] != rhs.definitionItems[i]){
 					result = false;
 				}
 			}
 		}

 		return result;
 	};

	bool operator!=(const Definitions& lhs, const Definitions& rhs){
		return !(lhs == rhs);
	};




Definitions operator+(const Definitions& lhs, const Definitions& rhs){
	int newCapacity;
	int newItemCount = lhs.itemCount + rhs.itemCount;

	if(newItemCount < lhs.getCurrentCapacity()){
		newCapacity = lhs.getCurrentCapacity();
	}else if(newItemCount < rhs.getCurrentCapacity()){
		newCapacity = rhs.getCurrentCapacity();
	}else{
		newCapacity = lhs.getCurrentCapacity() + rhs.getCurrentCapacity();
	}

	
	Definitions newDefArray(newCapacity);

	for(int i = 0; i < lhs.itemCount; i++){
		newDefArray.appendDefinition(lhs.definitionItems[i]);
	}

	for(int i = 0; i < rhs.itemCount; i++){
		newDefArray.appendDefinition(rhs.definitionItems[i]);
	}

	return newDefArray;
};


	ostream& operator<<(ostream& os, const Definitions& aDefinition){

		int cnt = 0;

		for_each(aDefinition.definitionItems, aDefinition.definitionItems + aDefinition.itemCount, [&cnt,&os](const string& def){
			os << cnt << ": " << def << endl;
			++cnt;
		});

		return os;
	};


#endif