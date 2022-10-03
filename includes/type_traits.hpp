#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	/***********************************************/
	/******         INTEGRAL_CONSTANT          *****/
	/***********************************************/
	template <typename T, T v>
	struct integral_constant
	{
		/******************************************/
		/******         MEMBER TYPES          *****/
		/******************************************/
		typedef T					value_type;
		typedef integral_constant	type;
		
		/******************************************/
		/******        MEMBER CONSTANT        *****/
		/******************************************/
		static const T 				value = v;

		/******************************************/
		/******       MEMBER FUNCTIONS        *****/
		/******************************************/
		operator	value_type() const { return this->value; }
	};

	/****************************************/
	/******         IS_INTEGRAL         *****/
	/****************************************/
	template <typename T> struct is_integral : public ft::integral_constant<bool, false> {};
	template <> struct is_integral<bool> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<signed char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<short int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned short int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<long int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<long long int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long long int> : public ft::integral_constant<bool, true> {};

	/****************************************/
	/******          ENABLE_IF          *****/
	/****************************************/
	template <bool B, typename T = void> struct enable_if {};
	
	template <typename T>
	struct enable_if<true, T>
	{
		/******************************************/
		/******         MEMBER TYPES          *****/
		/******************************************/
		typedef T type;
	};

	/****************************************/
	/******        REMOVE_CONST         *****/
	/****************************************/
	template<typename T> struct remove_const { typedef T type; };
	template<typename T> struct remove_const <const T> { typedef T type; };
}

#endif