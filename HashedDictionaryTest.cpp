#include <iostream>
#include <functional>
#include <cassert>

#include "HashedDictionary.h"
#include "HashFunctions.h"

using namespace std;

// int performCalculation(int(*fnc)(int,int)){
// 	int operand1 = 10;
// 	int operand2 = 20;

// 	return fnc(operand1,operand2);
// }

// int addNumbers(int op1, int op2){
// 	return op1 + op2;
// }

int main(){


	function<int(string)> hashFunction = hashFnc501;
	function<int(string)> fnc1001 = hashFunctionTable[1001];
	function<int(string)> fnc2001 = hashFunctionTable[2001];


	HashedDictionary<string,string> wordDictionary;
	assert(wordDictionary.isEmpty());
	assert(wordDictionary.getNumberOfItems() == 0);
	wordDictionary.setHashFunction(fnc2001);

	assert(wordDictionary.getHashFunction()("love") == fnc2001("love"));
	assert(wordDictionary.getHashFunction()("justice") == fnc2001("justice"));

	HashedDictionary<string,string> wordDictionary2(501,hashFnc501);
	assert(wordDictionary2.getHashFunction()("love") == hashFnc501("love"));
	assert(wordDictionary2.getHashFunction()("justice") == hashFnc501("justice"));

	assert(wordDictionary2.add("love","a positive feeling of attraction towards the opposite sex"));
	assert(wordDictionary2.add("hate","a feeling of strong dislike towards another person or thing"));
	assert(wordDictionary2.add("build","to construct or make"));
	assert(wordDictionary2.add("install","to set up or arrange in such a way that something functions or works as intended"));
	assert(wordDictionary2.add("dog","man's best friend"));
	assert(wordDictionary2.getNumberOfItems() == 5);

	try{
		cout << wordDictionary2.getItem("dog") << endl;
		cout << wordDictionary2.getItem("love") << endl;
	}catch(NotFoundException nfe){
		cout << nfe.what() << endl;
	}

	// assert(wordDictionary2.contains("dog"));

	// assert(wordDictionary2.remove("dog"));
	// assert(wordDictionary2.remove("love"));
	// assert(wordDictionary2.getNumberOfItems() == 3);


	// int(*fnc1)(int,int) = nullptr;
	// fnc1 = addNumbers;
	// function<int(int,int)> fnc(nullptr);
	// fnc = addNumbers;

	// cout << performCalculation(fnc1) << endl;


	return 0;
}