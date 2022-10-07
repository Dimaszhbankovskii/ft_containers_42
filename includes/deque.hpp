#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <memory>
# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	/********************************************************/
	/******            DEQUE CLASS TEMPLATE             *****/
	/********************************************************/

	template <typename T, typename Allocator = std::allocator<T> >
	class deque
	{
		/*********************************************/
		/******           MEMBER TYPES           *****/
		/*********************************************/

	public:
		typedef T													value_type;
		typedef Allocator											allocator_type;
		typedef std::size_t											size_type;
		typedef std::ptrdiff_t										difference_type;
		typedef typename Allocator::reference						reference;
		typedef typename Allocator::const_reference					const_reference;
		typedef typename Allocator::pointer							pointer;
		typedef typename Allocator::const_pointer					const_pointer;
		typedef typename ft::RandomAccessIterator<value_type>		iterator;
		typedef typename ft::RandomAccessIterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

	};
}

#endif