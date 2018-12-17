#include <iostream>
#include "TypeList.h"


namespace test_typeat
{
	using type = TypeList<int, char, double, float>;
	
	static_assert( std::is_same< TypeAt<type, 0>::result, int > {}, "!");
	
	static_assert( std::is_same< TypeAt<type, 2>::result, double > {}, "!");
	
	static_assert( std::is_same< TypeAt<type, 3>::result, float > {}, "!");
	
	//returning NullType when index > length
	static_assert( std::is_same< TypeAt<type, 5>::result, NullType> {}, "!");
}

namespace test_insert
{	
	using type = TypeList<int, char, double, float>;

	using type_ans_1 = TypeList<bool, int, char, double, float>;
	static_assert( std::is_same< Insert<type, bool, 0>::result, type_ans_1 > {}, "!");
	
	using type_ans_2 = TypeList<int, char, bool, double, float>;
	static_assert( std::is_same< Insert<type, bool, 2>::result, type_ans_2 > {}, "!");
	
	//index > length - push_back
	using type_ans_3 = TypeList<int, char, double, float, bool>;
	static_assert( std::is_same< Insert<type, bool, 5>::result, type_ans_3 > {}, "!");
}


namespace test_remove
{
	using type = TypeList<int, char, double, float>;

	using type_ans_1 = TypeList<char, double, float>;
	static_assert( std::is_same< Remove<type, 0>::result, type_ans_1 > {}, "!");
	
	using type_ans_2 = TypeList<int, char, float>;
	static_assert( std::is_same< Remove<type, 2>::result, type_ans_2 > {}, "!");
	
	//index > length - do nothing
	static_assert( std::is_same< Remove<type, 5>::result, type > {}, "!");
}


namespace test_replace
{
	using type = TypeList<int, char, double, float>;

	using type_ans_1 = TypeList<char, char, double, float>;
	static_assert( std::is_same< Replace<type, char, 0>::result, type_ans_1 >{}, "!");

	using type_ans_2 = TypeList<int, char, double, int>;
	static_assert( std::is_same< Replace<type, int, 3>::result, type_ans_2 > {}, "!");

	//assert then i > length
	//static_assert( std::is_same< Replace<type, float, 5>::result, type > {}, "!");

}

//testing typelist function (GetBeforeIndex, GetAfterIndex) 
//needed for GenFibonacciHierarchy
namespace test_other
{
	using type_1 = TypeList<int, char, double, float>;
	using type_2 = TypeList<>;


	using temp_0 = GetBeforeIndex<type_1, 0>::result;
	static_assert( std::is_same<temp_0, TypeList<> >{}, "!");

	using temp_1 = GetBeforeIndex<type_1, 3>::result;
	static_assert( std::is_same<temp_1, TypeList<int, char, double> >{}, "!");

	using temp_2 = GetBeforeIndex<type_1, 5>::result;
	static_assert( std::is_same<temp_2, TypeList<int, char, double, float> >{}, "!");

	using temp_3 = GetBeforeIndex<type_2, 2>::result;
	static_assert( std::is_same<temp_3, TypeList<> >{}, "!");

	//---------

	using temp_4 = GetAfterIndex<type_1, 2>::result;
	static_assert( std::is_same<temp_4, TypeList<double, float> >{}, "!");

	using temp_5 = GetAfterIndex<type_1, 4>::result;
	static_assert( std::is_same<temp_5, TypeList<> >{}, "!");

	using temp_6 = GetAfterIndex<type_1, 0>::result;
	static_assert( std::is_same<temp_6, TypeList<int, char, double, float> >{}, "!");
}


int main() {	
	return 0;
}

