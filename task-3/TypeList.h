#pragma once


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

//---------

template <typename TList>
struct Sizeof {
	constexpr static auto value = Sizeof<typename TList::tail>::value + 
									sizeof(typename TList::head);
};

template <>
struct Sizeof <NullType> {
	constexpr static auto value = 0;
};
