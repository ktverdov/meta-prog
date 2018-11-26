#pragma once

#include <iostream>
#include <typeinfo>


struct NullType {};


template <typename T=NullType, typename... U>
struct TypeList {
	using head = T;
	using tail = TypeList<U...>;
};


template <typename T>
struct TypeList<T> {
	using head = T;
	using tail = NullType;
};


//-----DIVIDE LIST IN TWO PARTS ON INDEX--------

template <typename T, typename U>
struct AppendElement {
	using result = TypeList<T, U>;
};

template <typename T>
struct AppendElement<T, NullType> {
	using result = TypeList<T>;
};

template <typename T, typename ...Args>
struct AppendElement<T, TypeList<Args...> > {
    using result = TypeList<T, Args...>;
};

//--------

template <typename TList, unsigned long index>
struct GetBeforeIndex {
	using result = typename AppendElement<typename TList::head,
											typename GetBeforeIndex<typename TList::tail, 
																	index - 1>
													::result>  
							::result;
};

//reach index or 1 -> return last element before
template <typename ...Args>
struct GetBeforeIndex<TypeList<Args... >, 1> {
	using result = TypeList<typename TypeList<Args... >::head>;
};

// for index == 0
template <typename ...Args>
struct GetBeforeIndex<TypeList<Args... >, 0> {
	using result = TypeList<>;
};

//index > len of initial TypeList -> return NullType 
template <unsigned long index>
struct GetBeforeIndex<NullType, index> {
	using result = NullType;
};

//-------

template <typename TList, unsigned long index>
struct GetAfterIndex {
	using result = typename GetAfterIndex<typename TList::tail, index - 1>::result;
};

//skipped all before index -> return remaining part
template <typename ...Args>
struct GetAfterIndex<TypeList<Args... >, 0> {
	using result = TypeList<Args... >;
};

//index > length of initial TypeList -> return empty TypeList
template <unsigned long index>
struct GetAfterIndex<NullType, index> {
	using result = TypeList<>;
};

//-----------------PRINT-----------------------

template <typename TList>
struct Print {
	static void print() {
		std::cout << typeid(typename TList::head).name() << " ";
		Print<typename TList::tail>::print();
	}
};


template<>
struct Print<NullType> {
	static void print() {
		std::cout << std::endl;
	}	
};


template<>
struct Print<TypeList<>> {
	static void print() {
		std::cout << "empty typelist" << std::endl;
	}	
};


//----------------LENGTH---------------------

template <typename TList>
struct Length {
	constexpr static auto value = Length<typename TList::tail>::value + 1;
};


template <>
struct Length<NullType> {
	constexpr static auto value = 0;
};


template <>
struct Length<TypeList<> > {
	constexpr static auto value = 0;
};
