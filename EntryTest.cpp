
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

#include "Entry.h"

using namespace std;

int main(){
	vector<Entry<string,string>> testEntries;
	ostream_iterator<Entry<string,string>> out_iter(cout, "\n");
	ostream_iterator<Entry<string,string>> out_iter2(cout, "\n");

	Entry<string,string> entry1("time");
	entry1.setItem("a precious commodity");
	testEntries.push_back(entry1);

	Entry<string,string> entry2("a feeling of attraction towards the opposite sex","love");
	testEntries.push_back(entry2);

	Entry<string,string> entry3("a feeling of strong dislike towards someone or something","hate");
	testEntries.push_back(entry3);

	Entry<string,string> entry4("man's best friend","dog");
	testEntries.push_back(entry4);

	Entry<string,string> entry5("a standardized means of exchange for conducting commercial transactions","money");
	testEntries.push_back(entry5);

	cout << "For entry2, key: " << entry2.getKey() << ", " << entry2.getItem() << endl;
	cout << "For entry3, key: " << entry3.getKey() << ", " << entry3.getItem() << endl;
	cout << "For entry4, key: " << entry4.getKey() << ", " << entry4.getItem() << endl;
	cout << "For entry5, key: " << entry5.getKey() << ", " << entry5.getItem() << endl;


	cout << "Before sorting the entries, .... " << endl;
	copy(testEntries.begin(), testEntries.end(), out_iter);

	sort(testEntries.begin(),testEntries.end());

	cout << "After sorting the entries, .... " << endl;
	copy(testEntries.begin(), testEntries.end(), out_iter2);





	return 0;
}