#include <iostream>
#include <iomanip>
#include "Reader.h"
#include "TypeList.h"

using type_list = TypeList<float, int, int, bool, char, double>;


template<typename TList>
void Print(void * ptr) {
	std::cout << * static_cast<typename TList::head *>(ptr) << " ";

	Print<typename TList::tail>(static_cast<char *>(ptr) + sizeof(typename TList::head));
}

template<>
void Print<NullType>(void * ptr) {
	std::cout << std::endl;
}


int main() {
	std::string input_file = "input.txt";

	Reader<type_list> reader(input_file);

	void * first_line = reader.readNextLine();
	void * second_line = reader.readNextLine();
	void * third_line = reader.readNextLine();

	Print<type_list>(first_line);
	Print<type_list>(second_line);
	Print<type_list>(third_line);

	free(first_line);
	free(second_line);
	free(third_line);

	return 0;
}