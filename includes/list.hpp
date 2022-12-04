#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <memory>
# include <limits>
# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	/********************************************************/
	/******             LIST CLASS TEMPLATE             *****/
	/********************************************************/
	template <class T, class Allocator = std::allocator<T> >
	class list
	{
		/*********************************************/
		/******         STRUCT LIST NODE         *****/
		/*********************************************/
	private:
		struct node
		{
			T		content;
			node*	next;
			node*	prev;
		};

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

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/
	private:
		allocator_type			_allocator;
		size_type				_size;			
		node*					_beginList;
		node*					_endList;
		std::allocator<node>	_allocatorNode;

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/
	public:
		list()
		{
			this->_allocator = allocator_type();
			this->_size = 0;
			this->_beginList = NULL;
			this->_endList = NULL;
		}

		explicit	list(const allocator_type& allocator)
		{
			this->_allocator = allocator;
			this->_size = 0;
			this->_beginList = NULL;
			this->_endList = NULL;
		}

		explicit	list(size_type count, const value_type& value = value_type(), const allocator_type& allocator = allocator_type())
		{
			this->_allocator = allocator;
			this->_size = count;
			this->_beginList = NULL;
			this->_endList = NULL;
			for (size_type i = 0; i < count; ++i)
				this->_addNodeToEnd(this->_createNode(value));
		}

		template <class InputIt >
		list(InputIt first, InputIt last, const allocator_type& allocator = allocator_type())
		{
			this->_allocator = allocator;
			
		}

		~list() { this->clear(); }

		/*********************************************/
		/******          ELEMENT ACCESS          *****/
		/*********************************************/
		reference		front() { return this->_beginList->content; }
		const_reference	front() const { return this->_beginList->content; }
		reference		back() { return this->_endList->content; }
		const_reference	back() const { return this->_endList->content; }

		/*********************************************/
		/******            CAPACITY              *****/
		/*********************************************/
		bool		empty() const { return this->_size == 0; }
		size_type	size() const { return this->_size; }
		size_type	max_size() const { return std::min(this->_allocator.max_size(), std::numeric_limits<size_type>::max()); }

		/*********************************************/
		/******            MODIFIERS             *****/
		/*********************************************/
		void	clear()
		{
			node*	tmp = this->_beginList;
			node*	del = tmp;

			while (tmp)
			{
				tmp = tmp->next;
				this->_deleteNode(del);
				del = tmp;
			}
			this->_beginList = NULL;
			this->_endList = NULL;
			this->_size = 0;
		}

		void	push_back(const value_type& value)
		{
			this->_addNodeToEnd(this->_createNode(value));
			++this->_size;
		}

		void	push_front(const value_type& value)
		{
			this->_addNodeToBegin(this->_createNode(value));
			++this->_size;
		}

		/*********************************************/
		/******          NODES FUNCTIONS         *****/
		/*********************************************/
	private:
		node*	_createNode(value_type value)
		{
			node*	newNode = this->_allocatorNode.allocate(1);
			this->_allocator.construct(&newNode->content, value);
			newNode->next = NULL;
			newNode->prev = NULL;
			return newNode;
		}

		void	_addNodeToBegin(node* newNode)
		{
			if (this->_beginList)
			{
				newNode->next = this->_beginList;
				this->_beginList->prev = newNode;
				this->_beginList = newNode;
			}
			else
			{
				this->_beginList = newNode;
				this->_endList = newNode;
			}
		}

		void	_addNodeToEnd(node* newNode)
		{
			node*	last = this->_lastNode(this->_beginList);

			if (last)
			{
				last->next = newNode;
				newNode->prev = last;
				this->_endList = newNode;
			}
			else
			{
				this->_beginList = newNode;
				this->_endList = newNode;
			}
		}

		node*	_lastNode(node* beginList)
		{
			node*	last = beginList;

			while (last && last->next)
				last = last->next;
			return last;
		}

		void	_deleteNode(node* delNode)
		{
			this->_allocator.destroy(&delNode->content);
			this->_allocatorNode.deallocate(delNode, 1);
		}
	};
}

#endif