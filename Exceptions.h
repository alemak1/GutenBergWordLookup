

#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

	#include <stdexcept>
	#include <string>
	

	using namespace std;

	class NotFoundException: public logic_error{
		public:
			NotFoundException(const string& message): logic_error("Entry not found: " + message){};
	};

	class InvalidInputException: public logic_error{
		public:
			InvalidInputException(const string& message): logic_error("Invalid input:" + message){};
	};

	class FileNotFound: public logic_error{
		public:
			FileNotFound(const string& message): logic_error("File Not Found:" + message){};
	};

	class FileNotOpened: public logic_error{
		public:
			FileNotOpened(const string& message): logic_error("File has not yet been opened:" + message){};
	};

	class WordNotSet: public logic_error{
		public:
			WordNotSet(const string& message): logic_error("File has not yet been opened:" + message){};
	};


#endif