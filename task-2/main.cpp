#include <iostream>
#include "TypeList.h"
#include "GenFibonacciHierarchy.h"

//testing typelist function (GetBeforeIndex, GetAfterIndex) 
//needed for GenFibonacciHierarchy
namespace test_typelist
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


template <class T, class Base>
class EventHandler: public Base
{
public:
	virtual void OnEvent(T& obj, int eventId) {}
};

class A {};
class B {};
class C {};
class D {};
class E {};
class F {};
class G {};
class K {};
class I {};


using hierarchy = GenFibonacciHierarchy<TypeList<A, B, C, D, E, F, G, K, I>, EventHandler>;

int main() {	

	hierarchy test_obj;

	return 0;
}

