
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

int main(){


	try{
		string input_line;
		

		fstream data_file("main_words.txt");
		fstream data_file2("processed_main_words.txt");
		string temp_str = string("");

		if(data_file.is_open() && data_file2.is_open()){

			while(getline(data_file, input_line)){
				temp_str = input_line;


				if(!temp_str.empty() && isalpha(temp_str[0])){
				 	data_file2 << temp_str;
				}

				

			}

		
		}else{
			throw FileNotFound("file either could not be located or opened");
		}
	}catch(FileNotFound fnf){
		cout << fnf.what() << endl;
	}




	return 0;
}