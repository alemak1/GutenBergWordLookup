
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

bool isWord(const string& aString){
	bool isWord = true;
	for(const auto& ch: aString){
		if(isalpha(ch) && islower(ch)){
			isWord = false;
		}
	}

	return isWord;
}

void printVec(const vector<string>& defVec){
	ostream_iterator<string> out_iter(cout,"\n");
	copy(defVec.begin(),defVec.end(), out_iter);
}

//For file-size where n is even
// BinaryNode<Entry<string,string>>* readFullTree(int n){
// 	if(n > 0){
// 		BinaryNode<Entry<string,sring>>* treePtr;




// 		return treePtr;
// 	}else{
// 		return nullptr;
// 	}

// 	return nullptr;
// }


class FileReader{
private:
	const int BEGINNING_LINE_NUMBER = 58;
	string file_name;
	fstream data_file;
	string input_line;
	Entry<string,string>* newEntryPtr;
	vector<string> definitions;
	string current_word = string("");
	string previous_word = string("");
	BinaryNode<Entry<string,string>>* mainTreePtr = new BinaryNode<Entry<string,string>>();
	int line_counter = 0;

	void open_file() throw(FileNotFound){
		data_file.open();

		if(!data_file.is_open()){
			throw FileNotFound("The specified file either could not be opened or could not be found");
		}
	}

	void increment_counter(){
		line_counter++;
	}
	
	void reset_line_counter(){
		line_counter = 0;
	}

	void verify_file_open(){
		try{
			if(!data_file.is_open()){
				throw FileNotOpened("The data either has not been opened yet or is already closed");
			}
		}catch(FileNotOpened fno){
			cout << fn.what() << endl;
		}
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

public:
	FileReader(const string& user_file_name):file_name(user_file_name){};



	void open(){
		try{
			open_file();
		}catch(FileNotFound fnf, ostream& os = cout){
			os << fnf.what() << endl;
		}
	}


	void close(){
		data_file.close();
	}


	void run(){
		verify_file_open();



	}

	void getEntry(BinaryNode<Entry<string,string>>* aTreePtr, int numberOfEntries){
		verify_file_open();
		while(getline(data_file,input_line)){
			if(isWord(input_line)){
				newEntryPtr = new Entry<string,string>(input_line);
				current_word = input_line;
			}

			if((newEntryPtr->getKey()).empty()){
				throw WordNotSet("No word set for this entry");
			}else{
				if(current_word != prev_word){
					definitions.push_back(input_line);
				}
			}

			increment_counter();
		}

		string def_str = accumulate(definitions.begin(),definitions.end(),string(""));
		newEntryPtr->setItem(def_str);

		aTreePtr->setItem(*newEntryPtr);

		newEntryPtr = nullptr;
		definitions.clear();
		prev_word = current_word;

	}


	void getAllEntries(int numberOfEntries, BinaryNode<Entry<string,sring>>* aTreePtr){
		//replace hard-coded value for nubmerOfEntries with variable that can be update dynamically
		
		if(numberOfEntries > 0){

			getEntry(aTreePtr, numberOfEntries);

			BinaryNode<Entry<string,string>>* leftPtr = aTreePtr->getLeftChildPtr();
			BinaryNode<Entry<string,string>>* rightPtr = aTreePtr->getRightChildPtr();

			getAllEntries(leftPtr, numberOfEntries/2);
			leftPtr = aTreePtr->setLeftChildPtr(leftPtr);

			getAllEntries(rightPtr, nubmerOfEntries/2);
			rightPtr = aTreePtr->setRighChildPtr(rightPtr);
		}
	}


	void loadBinarySearchTree(){
		int totalNumberOfEntries = getNumberOfEntries();
		getAllEntries(totalNumberOfEntries, mainTreePtr);
	}

	void skip_to_line_number(int line_number){
		verify_file_open();
		while(getline(data_file,input_line) && line_counter < line_number){
			increment_counter();
		}
	}


	int getNumberOfEntries(){
		verify_file_open();
		skip_to_line_number(BEGINNING_LINE_NUMBER);

		int numWords = 0;

		while(getline(data_file,input_line)){
			if(isWord(input_line)){
				numWords++;
			}
		}


		return numWords;

	}



}



int main(){


	try{
		string input_line;
		string def_str = string("");
		string current_word = string("");
		string prev_word = current_word;

		fstream data_file("main_words.txt");

		vector<string> words;
		vector<string> definitions;


		vector<Entry<string,string>*> entry_vec;
		entry_vec.clear();
		Entry<string,string>* newEntryPtr = new Entry<string,string>(string(""));

		int cnt = 0;
		string temp_str = string("");


		if(data_file.is_open()){

			while(getline(data_file, input_line)){
				if(cnt > 158){
					if(isWord(input_line)){

						current_word = input_line;
						
						if(cnt == 0){
							prev_word = current_word;
						}



						if(current_word != prev_word && !definitions.empty()){

							string def_str = accumulate(definitions.begin(),definitions.end(),string(""));
							newEntryPtr->setItem(def_str);
							entry_vec.push_back(newEntryPtr);

							newEntryPtr = nullptr;
						}

						definitions.clear();

						newEntryPtr = new Entry<string,string>(input_line);
						prev_word = input_line;


					}else{			
						if(current_word == prev_word){
							definitions.push_back(input_line);
						}
					}
				}

				
				cnt++;
			}

			for_each(entry_vec.begin(),entry_vec.end(),[](Entry<string,string>* entryPtr){
				string word = string("");
				word.append(entryPtr->getKey());

				if(!word.empty()){
					cout << "WORD: " << entryPtr->getKey() << endl;
					cout << "DEFINITION: " << entryPtr->getItem() << endl;
				}
			});


			cout << "Number of word entries stored: " << entry_vec.size() << endl;


		}else{
			throw FileNotFound("file either could not be located or opened");
		}
	}catch(FileNotFound fnf){
		cout << fnf.what() << endl;
	}




	return 0;
}