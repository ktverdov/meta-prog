#pragma once

#include "TypeList.h"


class EmptyType {};


template < class TList, 
			template <class AtomicType, class Base> class Unit, 
			class Root = EmptyType
				>
class GenLinearHierarchy;


template < class T1, 
			class T2, 
			template <class, class> class Unit, 
			class Root
				>
class GenLinearHierarchy<TypeList<T1, T2>, Unit, Root> 
	: public Unit<T1, GenLinearHierarchy<T2, Unit, Root>> {};


template <class AtomicType,
			template <class, class> class Unit, 
			class Root
				>
class GenLinearHierarchy<TypeList<AtomicType>, Unit, Root> 
	: public Unit<AtomicType, Root> {};


// template <template <typename, typename> typename Unit, typename Root>
// class GenLinearHierarchy<NullType , Unit, Root>
// 		: public Root {};