#include <iostream>
#include "TypeList.h"
#include "GenFibonacciHierarchy.h"


//testing typelist function (GetBeforeIndex, GetAfterIndex) 
//needed for GenFibonacciHierarchy
void test_typelist() {
	// using type_1 = TypeList<int, char, double, float>;
	// using type_2 = TypeList<>;
	// using type_3 = TypeList<double>;

	// using type_1_first = GetBeforeIndex<type_3, 0>::result;
	// using type_1_second = GetAfterIndex<type_1, 2>::result;

	// static_assert( std::is_same<type_1, TypeList<int, char, double, float> >{}, "!");
}

template <class T, class Base>
class Handler: public Base
{
public:
    virtual void OnEvent(T& obj){
        std::cout<<sizeof(T)<<std::endl;
    }
};

class A{
    int val;
public:
    int f1();
};

class B{
    char val;
public:
    int f2();
};

class C{
    double val;
public:
    int f3();
};

using hierarchy =  GenFibonacciHierarchy<TypeList<A, B, C>, Handler>;


int main() {
	test_typelist();	

	return 0;
}



// template <typename T>
// struct Holder {
// 	T value_;
// };

// template <typename T, typename Base>
// class EventHandler : public Base {
// 	public:
// 		virtual void OnEvent(const T&) = 0;
// };
