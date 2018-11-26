#pragma once

#include "TypeList.h"
#include "GenLinearHierarchy.h"


template < class TList, 
			template <class AtomicType, class Base> class Unit,
			unsigned long prev=0,
			unsigned long curr=1
				>
class GenFibonacciHierarchy;


template < class ...Args, 
			template <class AtomicType, class Base> class Unit,
			unsigned long prev, 
			unsigned long curr
				>
class GenFibonacciHierarchy<TypeList<Args... >, Unit, prev, curr>
	: public GenLinearHierarchy< typename GetBeforeIndex<TypeList<Args... >, curr + 1>::result, 
									Unit
										>, 
	  public GenFibonacciHierarchy< typename GetAfterIndex<TypeList<Args... >, curr + 1>::result, 
									Unit, 
									curr, 
									prev + curr
										> {
	public:
		using TList = TypeList<Args... >;

		using LeftBase = GenLinearHierarchy< typename GetBeforeIndex<TList, curr + 1>::result, Unit >;
		
		using RightBase =  GenFibonacciHierarchy< typename GetAfterIndex<TList, curr + 1>::result, 
													Unit, 
													curr, 
													prev + curr
														>;
};


template < template <class AtomicType, class Base> class Unit, 
			unsigned long prev, 
			unsigned long curr
				>
class GenFibonacciHierarchy< NullType, Unit, prev, curr > {};
