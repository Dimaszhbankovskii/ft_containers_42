#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <memory>
# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	template <typename T>
	struct listNode
	{
		T			element;
		listNode*	next;
		listNode*	prev;
	};

	/********************************************************/
	/******            DEQUE CLASS TEMPLATE             *****/
	/********************************************************/

	template <typename T, typename Allocator = std::allocator<T> >
	class list
	{
		/*********************************************/
		/******           MEMBER TYPES           *****/
		/*********************************************/

	public:
		typedef T														value_type;
		typedef Allocator												allocator_type;
		typedef std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
		typedef typename Allocator::reference							reference;
		typedef typename Allocator::const_reference						const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef typename ft::BidirectionalIterator<value_type>			iterator;
		typedef typename ft::BidirectionalIterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef ft::listNode<value_type>								node;
		typedef node*													prtNode;
		typedef std::allocator<ft::listNode<value_type> >				node_allocator_type;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

		private:
			allocator_type		_allocator;
			node_allocator_type	_nodeAllocator;
			prtNode				_startList;
			prtNode				_endList;
			size_type			_size;

			prtNode	_newNode(value_type value, prtNode next, prtNode prev)
			{
				prtNode elem = this->_nodeAllocator.allocate(1);
				this->_allocator.construct(elem, value);
			}

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/
		public:
			list()
			{
				this->_allocator = allocator_type();
				this->_nodeAllocator = node_allocator_type();
				this->startList = NULL;
				this->endList = NULL;
				this->_size = 0;
			}

			explicit list(const allocator_type& allocator)
			{
				this->_allocator = allocator;
				this->_nodeAllocator = node_allocator_type();
				this->startList = NULL;
				this->endList = NULL;
				this->_size = 0;
			}
	};
}

#endif