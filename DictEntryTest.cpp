
#include <iostream>
#include <cassert>

#include "DictEntry.h"

using namespace std;

int main(){
	DictEntry entry1("court");
	DictEntry entry2(Definitions(30),"love");
	DictEntry entry3("a feeling of strong dislike towards another person", "hatred");

	cout << "The entry is: " << entry3.getWord() << endl;
	cout << "The definition is: " << entry3.getDefinitions() << endl;

	assert(entry1.getDefinitions().isEmpty());
	assert(entry1.getWord() == "court");

	cout << entry2.getWord() << endl;
	cout << entry2.getDefinitions() << endl;

	entry2.setDefinition("a feeling of attraction towards the opposite sex");
	cout << entry2.getDefinitions() << endl;

	entry1.setDefinition("a place where legal disputes are resolved");
	entry1.addDefinition("to pursue a woman's favor or agreement, often said of a man");

	cout << entry1.getDefinitions() << endl;



	return 0;
}