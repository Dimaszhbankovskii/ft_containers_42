#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	/********************************************************/
	/******            STACK CLASS TEMPLATE             *****/
	/********************************************************/

	template < typename T, typename Container = ft::vector<T> >
	class stack
	{
		/*********************************************/
		/******           MEMBER TYPES           *****/
		/*********************************************/

	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

	private:
		container_type	_container;

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/

	public:
		explicit stack( const container_type& container = container_type()) { this->_container = container; }
		stack(const stack& src) { *this = src; }
		~stack() {}
		stack&	operator=(const stack& src)
		{
			if (this == &src)
				return *this;
			this->_container = src._container;
			return *this;
		}

		/*********************************************/
		/******          ELEMENT ACCESS          *****/
		/*********************************************/

		reference top() { return this->_container.back(); }
		const_reference top() const { return this->_container.back(); }

		/*********************************************/
		/******            CAPACITY              *****/
		/*********************************************/

		bool		empty() const { return this->_container.empty(); }
		size_type	size() const { return this->_container.size(); }

		/*********************************************/
		/******            MODIFIERS             *****/
		/*********************************************/

		void	push(const value_type& value) { this->_container.push_back(value); }
		void	pop() { this->_container.pop_back(); }

		/*******************************************************************/
		/******       NON-MEMBER FUNCTIONS - STACK CLASS TEMPLATE      *****/
		/*******************************************************************/

		friend bool	operator==( const stack& left, const stack& right) { return left._container == right._container; }
		friend bool	operator!=( const stack& left, const stack& right) { return left._container != right._container; }
		friend bool	operator<( const stack& left, const stack& right) { return left._container < right._container; }
		friend bool	operator<=( const stack& left, const stack& right) { return left._container <= right._container; }
		friend bool	operator>( const stack& left, const stack& right) { return left._container > right._container; }
		friend bool	operator>=( const stack& left, const stack& right) { return left._container >= right._container; }
	};
}

#endif