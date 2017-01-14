
#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <string>
#include <fstream>

#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include "Entry.h"


BinaryNode<Entry>* readTree(int numberOfEntries, string fileName) throw(FileNotFound){

	fstream wordFile(fileName);
	string file_line;
	BinaryNode<T>* treePtr = new BinaryNode<Entry>();

	
}

//wrap this in another function that can take filename or number of entries or even readTree function as an argument
if(wordFile.is_open()){
		while(getline(wordFile, file_line)){


		}

	}else{
		throw FileNotFound("specified file either does not exist or could not be opened");
	}

#endif