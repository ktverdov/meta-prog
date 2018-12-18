#pragma once

#include <fstream>
#include "TypeList.h"

template<typename TList>
void Write(std::ifstream &ifs, char * curr) {
	typename TList::head temp;
	ifs >> temp;
	* reinterpret_cast<typename TList::head * >(curr) = temp;
	Write<typename TList::tail>(ifs, static_cast<char * >(curr) + sizeof(typename TList::head));
}

template<>
void Write<NullType>(std::ifstream &ifs, char * curr) {}


template <typename TList>
class Reader {
	public:
		Reader(std::string input_file) : ifs(input_file, std::ifstream::in) 
		{}

		~Reader() {
			ifs.close();
		}

		void * readNextLine() {			
			char * const ptr = static_cast<char *>(std::malloc(Sizeof<TList>::value));

			Write<TList>(ifs, ptr);

			return ptr;
		}

	private:
		std::ifstream ifs;
};
