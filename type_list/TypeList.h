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



//-----------------PRINT-----------------------

template <typename TList>
struct Print {
	static void print() {
		std::cout << typeid(typename TList::head).name() << " ";
		Print<typename TList::tail>::print();
	}
};


template <>
struct Print<NullType> {
	static void print() {
		std::cout << std::endl;
	}	
};


template <>
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


//----------------TypeAt---------------------

template <typename TList, unsigned long index>
struct TypeAt {
	using result = NullType;
};

template <typename ...Args>
struct TypeAt<TypeList<Args... >, 0> {
	using result = typename TypeList<Args... >::head;
};

template <typename ...Args, unsigned long i>
struct TypeAt<TypeList<Args... >, i> {
	using result = typename TypeAt<typename TypeList<Args ...>::tail, i - 1>::result;
};


//-----------------------------------------
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

template <typename T, typename ...Args>
struct AppendElement<TypeList<Args...>, T > {
	using result = TypeList<Args..., T>;
};


//----------------Insert---------------------

template <typename TList, typename T, unsigned long index> struct Insert;

template <typename ...Args, typename T>
struct Insert<TypeList<Args... >, T, 0> {
	using result = typename AppendElement< T, TypeList<Args... > >::result;
};

template <typename T, unsigned long i>
struct Insert<NullType, T, i> {
	using result = T;
};

template <typename ...Args, typename T, unsigned long i>
struct Insert<TypeList<Args... >, T, i> {
	using result = typename AppendElement< typename TypeList<Args... >::head,
											typename Insert< typename TypeList<Args... >::tail, T, i - 1>::result
											>::result;
};


//----------------Remove---------------------

template <typename TList, unsigned long index> 
struct Remove {
	using result = NullType;	
};

template<typename ...Args>
struct Remove<TypeList<Args... >, 0> {
	using result = typename TypeList<Args... >::tail;
};

template<typename ...Args, unsigned long i>
struct Remove<TypeList<Args... >, i> {
	using result = typename AppendElement< typename TypeList<Args... >::head,
											typename Remove< typename TypeList<Args... >::tail, i - 1>::result
											>::result;
};


//----------------Replace--------------------

template <typename TList, typename T, unsigned long index> struct Replace;

template <typename ...Args, typename T, unsigned long i>
struct Replace<TypeList<Args... >, T, i> {
	static_assert(i < Length< TypeList<Args...> >::value, "Remove Failed");

	using result = typename Insert<typename Remove<TypeList<Args...>, i>::result, T, i
									>::result;
};



//****methods used for Hierarchy generation*****

//-----DIVIDE LIST IN TWO PARTS ON INDEX--------

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


//------------------

template <typename TListFirst, typename TListSecond> struct AppendList;

template <typename ...Args>
struct AppendList< TypeList<Args... >, NullType > {
	using result = TypeList<Args... >;
};


template <typename ...ArgsFirst, typename ...ArgsSecond>
struct AppendList< TypeList<ArgsFirst... >, TypeList<ArgsSecond... > > {
	using result = typename AppendList< typename AppendElement<TypeList<ArgsFirst... >, 
														typename TypeList<ArgsSecond... >::head >::result, 
							 	typename TypeList<ArgsSecond... >::tail >::result;
};
