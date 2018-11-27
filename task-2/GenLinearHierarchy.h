#pragma once

#include "TypeList.h"


class EmptyType {};


template < class TList, 
			template <class AtomicType, class Base> class Unit, 
			class Root = NullType
				>
class GenLinearHierarchy;


template < class Head,
			class ...Tail, 
			template <class, class> class Unit, 
			class Root
				>
class GenLinearHierarchy<TypeList<Head, Tail... >, Unit, Root> 
	: public Unit< Head, GenLinearHierarchy< TypeList<Tail... >, Unit, Root> > {
	
	public:
		// GenLinearHierarchy() {
		// 	std::cout << "GenLinearHierarchy" << std::endl;
		// 	Print<TypeList<Head, Tail... > >::print();
		// }
};


template <class AtomicType,
			template <class, class> class Unit, 
			class Root
				>
class GenLinearHierarchy<TypeList<AtomicType>, Unit, Root> 
	: public Unit<AtomicType, Root> {};


template <template <class, class> class Unit, class Root>
class GenLinearHierarchy<NullType , Unit, Root>
		: public Root {};
