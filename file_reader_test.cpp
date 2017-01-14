
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <list>
#include <iterator>
#include <vector>

#include "Exceptions.h"
#include "Entry.h"
#include "BinaryNode.h"
#include "BinarySearchTree.h"


using namespace std;


void printVec(const vector<string>& defVec){
	ostream_iterator<string> out_iter(cout,"\n");
	copy(defVec.begin(),defVec.end(), out_iter);
}

	bool isWord(const string& aString){
		bool isWord = true;
		for(const auto& ch: aString){
			if(isalpha(ch) && islower(ch)){
				isWord = false;
			}
		}

		return isWord;
	}


// class FileReader{
// private:
// 	//const int BEGINNING_LINE_NUMBER = 58;
// 	ostream& out_stream = cout;
// 	const static string file_name;
// 	fstream* data_file = new fstream(file_name);

// 	string input_line;
// 	//Entry<string,string>* newEntryPtr = nullptr;
// 	vector<string> definitions;
// 	string current_word = string("");
// 	string previous_word = string("");
// 	//BinaryNode<Entry<string,string>>* mainTreePtr = new BinaryNode<Entry<string,string>>();
// 	int line_counter = 0;

// 	void open_file() throw(FileNotFound){

// 		data_file->open(file_name,'r');

// 		try{
// 			if(!data_file->is_open()){
// 				throw FileNotFound("The specified file either could not be opened or could not be found");
// 			}
// 		}catch(FileNotFound fnf){
// 			out_stream << fnf.what() << endl;
// 		}
// 	}

// 	void increment_counter(){
// 		line_counter++;
// 	}
	
// 	void reset_line_counter(){
// 		line_counter = 0;
// 	}

// 	void verify_file_open(){
// 		try{
// 			if(!data_file->is_open()){
// 				throw FileNotOpened("The data either has not been opened yet or is already closed");
// 			}
// 		}catch(FileNotOpened fno){
// 			cout << fno.what() << endl;
// 		}
// 	}

// 	bool isWord(const string& aString){
// 		bool isWord = true;
// 		for(const auto& ch: aString){
// 			if(isalpha(ch) && islower(ch)){
// 				isWord = false;
// 			}
// 		}

// 		return isWord;
// 	}

// public:
// 	FileReader(){};



// 	void openFile(){
// 		open_file();
// 	}


// 	void close(){
// 		data_file->close();
// 	}


// 	void run(){
// 		verify_file_open();



// 	}

	// void getEntry(BinaryNode<Entry<string,string>>* aTreePtr, int numberOfEntries){
	// 	verify_file_open();
	// 	while(getline(data_file,input_line)){
	// 		if(isWord(input_line)){
	// 			newEntryPtr = new Entry<string,string>(input_line);
	// 			current_word = input_line;
	// 		}

	// 		if((newEntryPtr->getKey()).empty()){
	// 			throw WordNotSet("No word set for this entry");
	// 		}else{
	// 			if(current_word != prev_word){
	// 				definitions.push_back(input_line);
	// 			}
	// 		}

	// 		increment_counter();
	// 	}

	// 	string def_str = accumulate(definitions.begin(),definitions.end(),string(""));
	// 	newEntryPtr->setItem(def_str);

	// 	aTreePtr->setItem(*newEntryPtr);

	// 	newEntryPtr = nullptr;
	// 	definitions.clear();
	// 	prev_word = current_word;

	// }


	// void getAllEntries(int numberOfEntries, BinaryNode<Entry<string,sring>>* aTreePtr){
	// 	//replace hard-coded value for nubmerOfEntries with variable that can be update dynamically
		
	// 	if(numberOfEntries > 0){

	// 		getEntry(aTreePtr, numberOfEntries);

	// 		BinaryNode<Entry<string,string>>* leftPtr = aTreePtr->getLeftChildPtr();
	// 		BinaryNode<Entry<string,string>>* rightPtr = aTreePtr->getRightChildPtr();

	// 		getAllEntries(leftPtr, numberOfEntries/2);
	// 		leftPtr = aTreePtr->setLeftChildPtr(leftPtr);

	// 		getAllEntries(rightPtr, nubmerOfEntries/2);
	// 		rightPtr = aTreePtr->setRighChildPtr(rightPtr);
	// 	}
	// }


	// void loadBinarySearchTree(){
	// 	int totalNumberOfEntries = getNumberOfEntries();
	// 	getAllEntries(totalNumberOfEntries, mainTreePtr);
	// }

	// void skip_to_line_number(int line_number){
	// 	verify_file_open();
	// 	while(getline(*data_file,input_line)){
	// 		cout << input_line << endl;
	// 		increment_counter();
	// 		if(line_counter > line_number){
	// 			break;
	// 		}
	// 	}
	// }


	// int getNumberOfEntries(){
	// 	verify_file_open();
	// 	skip_to_line_number(BEGINNING_LINE_NUMBER);

	// 	int numWords = 0;

	// 	while(getline(data_file,input_line)){
	// 		if(isWord(input_line)){
	// 			numWords++;
	// 		}
	// 	}


	// 	return numWords;

	// }


// 	int getCurrentLineNumber() const{
// 		return line_counter;
// 	}

// };



//const string FileReader::file_name = "main_words.txt";

Entry<string,string> getNextEntry(fstream* datafile){
	string input_line;
	Entry<string,string>* newEntry;
	vector<string> definitions;

	
	while(getline(*datafile,input_line)){

		if(isWord(input_line)){
			newEntry = new Entry<string,string>(input_line);
		}else{
			definitions.push_back(input_line);
		}

		prev_word = input_line;

	}
}

BinaryNode<Entry<string,string>>* readFullTree(int numberOfEntries, BinaryNode<Entry<string,string>>* treePtr){

	treePtr = new BinaryNode<Entry<string,string>>()
}

int main(){







	return 0;
}