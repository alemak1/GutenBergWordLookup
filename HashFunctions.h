

#ifndef _HASH_FUNCTIONS_H
#define _HASH_FUNCTIONS_H

#include <functional>
#include <map>

using namespace std;
using namespace std::placeholders;

/**	The hash function converts the string into an n-bit binary number by multiplying the ASCII-equivalent value for each character
by (2^k) where  k >= 0 and k <= n, where n is the number of characters in the string.  The first character occupies the 0's place
in the n-bit binary number, the second character the 1's place, the third character the 2's place, and so on.  Horner's rule
is used to simplify the computation, and the modulo operator is applied recursively to the result of multiplying the sum of the integer
equivalent and the result of the previous iteration of the same expression

**/


int hashFunc(const string& example_str, size_t table_size){
	int prev_int = 0;

	for(const auto& ch: example_str){
		int int_ch = static_cast<int>(ch);
		prev_int = (int_ch + prev_int)*32 % table_size;
	};

	return prev_int;
};


/** The bind() function from the standard library is used to generate callable objects based on different hash table sizes;
The hash table size parameter is set to a fixed value by the bind function to generate a callable object that can 
serve as a hash function.

The average size of the linked chain (alpha) held in each location in the hash table is n/tableSize, where n = total number of words;

For the case where 100,000 words must be stored in the dictionary, the average size of the linked chain in each hash table
location for a table that store 1,000 words would be 100;  The alpha value (i.e. average length of each chain) is given for 
different tableSizes corresponding the the hash functions below.

**/

//alpha = 100,000/500 = 200
auto hashFnc501 = bind(hashFunc,_1, 501);

//alpha = 100,000/1000 = 100
auto hashFnc1001 = bind(hashFunc,_1,1001);

//alpha = 100,000/2000 = 50
auto hashFnc2001 = bind(hashFunc,_1,2001);

//alpha = 100,000/3000 = 33
auto hashFnc3001 = bind(hashFunc,_1,3001);

//alpha = 100,000/10,000 = 10
auto hashFnc10001 = bind(hashFunc,_1,10001);

map<int,function<int(string)>> hashFunctionTable = {
	{501, hashFnc501}, 
	{1001, hashFnc1001},
	{2001,hashFnc2001},
	{3001,hashFnc3001},
	{10001,hashFnc10001},
	{20001,bind(hashFunc,_1,20001)}

};

#endif