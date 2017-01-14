


#ifndef _ENTRY_H
#define _ENTRY_H

#include <string>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "Definitions.h"

using namespace std;


class DictEntry{
private:
	string word;
	Definitions definitions;
protected:
	void setWord(const string& newWord){
		word = newWord;
	}
public:
	DictEntry(const string& newWord){
		definitions = *(new Definitions());
		word = newWord;
		};

	DictEntry(const string& definition_str, const string& newWord){
		word = newWord;
		definitions = Definitions(definition_str);
	}

	DictEntry(Definitions newDefinitions, string newWord):word(newWord),definitions(newDefinitions){};
	
	Definitions getDefinitions() const{
		return definitions;
	}

	string getWord() const{
		return word;
	}

	void setDefinition(const Definitions& newDefinitions){
		definitions = definitions;
	}

	void setDefinition(const string& newDefinition){
		definitions = newDefinition;
	}

	void setDefinitions(const Definitions& newDefinitions){
		definitions = definitions;
	}

	void setDefinitions(const string& newDefinition){
		definitions = newDefinition;
	}

	void addDefinition(const string& newDefinition){
		definitions += newDefinition;
	}

	void addDefinition(const Definitions& newDefinition){
		definitions += newDefinition;
	}

	void addDefinitions(const string& newDefinition){
		definitions += newDefinition;
	}

	void addDefinitions(const Definitions& newDefinition){
		definitions += newDefinition;
	}



	friend bool operator==(const DictEntry& lhs, const DictEntry& rhs);
	friend bool operator<(const DictEntry& lhs, const DictEntry& rhs);


};

#endif