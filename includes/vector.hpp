#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <algorithm>
# include <stdexcept>
// # include <iterator>
# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	/********************************************************/
	/******            VECTOR CLASS TEMPLATE            *****/
	/********************************************************/

	template <typename T, typename Allocator = std::allocator<T> >
	class vector
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
		typedef typename ft::iterator<value_type*>					iterator;
		typedef typename ft::iterator<const value_type*>			const_iterator;
		typedef typename ft::reverse_iterator<value_type*>			reverse_iterator;
		typedef typename ft::reverse_iterator<const value_type*>	const_reverse_iterator;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

	private:
		allocator_type	_allocator;
		pointer			_prt;
		size_type		_capacity;
		size_type		_size;

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/

	public:
		vector()
		{
			this->_allocator = allocator_type();
			this->_prt = NULL;
			this->_capacity = 0;
			this->_size = 0;
		}

		explicit vector(const allocator_type& allocator)
		{
			this->_allocator = allocator;
			this->_prt = NULL;
			this->_capacity = 0;
			this->_size = 0;
		}

		explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& allocator = allocator_type())
		{
			this->_allocator = allocator;
			this->_prt = this->_allocator.allocate(n);
			this->_capacity = n;
			this->_size = n;
			for (size_type i = 0; i < this->_size; ++i)
				this->_allocator.construct(this->_prt + i, value);
		}

		template <typename InputIt>
		vector(InputIt first, InputIt last, const allocator_type& allocator = allocator_type())
		{
			size_type	size = last - first;

			this->_allocator = allocator;
			if (size > this->max_size())
				throw std::length_error("cannot create ft::vector larger than max_size()");
			this->_prt = this->_allocator.allocate(size);
			this->_capacity = size;
			this->_size = size;
			for (size_type i = 0; i < this->_size; ++i)
				this->_allocator.construct(this->_prt + i, *(first + i));
		}

		vector(const vector& src)
		{
			this->_allocator = src._allocator;
			this->_prt = NULL;
			this->_capacity = 0;
			this->_size = 0;
			*this = src;
		}

		~vector()
		{
			this->clear();
			this->_allocator.deallocate(this->_prt, this->_capacity);
		}

		vector&	operator=(const vector& src)
		{
			if (this == &src)
				return *this;
			this->clear();
			this->_allocator.deallocate(this->_prt, this->_capacity);
			this->_allocator = src._allocator;
			this->_capacity = src._capacity;
			this->_size = src._size;
			this->_prt = this->_allocator.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; ++i)
				this->_allocator.construct(this->_prt + i, *(src._prt + i));
			return *this;
		}

		void	assign(size_type count, const value_type& value)
		{
			if (!count)
				return ;
			this->clear();
			this->reserve(count);
			this->_size = count;
			for (size_type i = 0; i < this->_size; ++i)
				this->_allocator.construct(this->_prt + i, value);
		}

		template <typename InputIt>
		typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type
		assign(InputIt first, InputIt last)
		{
			size_type	size = last - first;

			if (size > this->max_size())
				throw std::length_error("cannot create ft::vector larger than max_size()");
			this->clear();
			this->reserve(size);
			this->_size = size;
			for (size_type i = 0; i < this->_size; ++i)
				this->_allocator.construct(this->_prt + i, *(first + i));
		}

		allocator_type	get_allocator() const { return this->_allocator; }

		/*********************************************/
		/******          ELEMENT ACCESS          *****/
		/*********************************************/

		reference	at(size_type pos)
		{
			if (pos >= this->_size)
				throw std::out_of_range("vector.at()::out_of_range");
			return *(this->_prt + pos);
		}
		const_reference	at(size_type pos) const
		{
			if (pos >= this->_size)
				throw std::out_of_range("vector.at()::out_of_range");
			return *(this->_prt + pos);
		}
		reference		operator[](size_type pos) { return *(this->_prt + pos); }
		const_reference	operator[](size_type pos) const { return *(this->_prt + pos); }
		reference		front() { return *this->_prt; }
		const_reference	front() const { return *this->_prt; }
		reference		back() { return *(this->_prt + this->_size - 1); }
		const_reference	back() const { return *(this->_prt + this->_size - 1); }
		pointer			data() { return this->_prt; }
		const_pointer	data() const {return this->_prt; }

		/*********************************************/
		/******            ITERATORS             *****/
		/*********************************************/

		iterator				begin() { return iterator(this->_prt); }
		const_iterator			begin() const { return const_iterator(this->_prt); }
		iterator				end() { return iterator(this->_prt + this->_size); }
		const_iterator			end() const { return const_iterator(this->_prt + this->_size); }
		reverse_iterator		rbegin() { return reverse_iterator(this->_prt + this->_size - 1); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->_prt + this->_size - 1); }
		reverse_iterator		rend() { return reverse_iterator(this->_prt - 1); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(this->_prt - 1); }

		/*********************************************/
		/******            CAPACITY              *****/
		/*********************************************/

		bool		empty() const { return this->_size == 0; }
		size_type	size() const { return this->_size; }
		size_type	max_size() const { return std::min(this->_allocator.max_size(), std::numeric_limits<size_type>::max()); }
		void		reserve(size_type new_cap)
		{
			if (new_cap > this->_capacity)
			{
				if (new_cap > this->max_size())
					throw std::length_error("vector::reverse");
				
				pointer		new_prt = _allocator.allocate(new_cap);
				for (size_t i = 0; i < this->_size; ++i)
				{
					this->_allocator.construct(new_prt + i, *(this->_prt + i));
					this->_allocator.destroy(this->_prt + i);
				}				
				this->_allocator.deallocate(this->_prt, this->_capacity);
				this->_prt = new_prt;
				this->_capacity = new_cap;
			}
			else
				return ;
		}
		size_type	capacity() const { return this->_capacity; }

		/*********************************************/
		/******            MODIFIERS             *****/
		/*********************************************/

		void	clear()
		{
			for (size_t i = 0; i < this->_size; ++i)
				this->_allocator.destroy(this->_prt + i);
			this->_size = 0;
		}

		// iterator insert( const_iterator pos, const T& value );

		// iterator	insert(const_iterator pos, size_type count, const_reference value)
		// {
		// 	size_type	ind = pos - this->begin();
		// 	size_type	new_size = this->_size + count;
		// }
		
		// constexpr iterator insert( const_iterator pos, size_type count, const T& value );

		// template< class InputIt >
		// iterator insert( const_iterator pos, InputIt first, InputIt last );

		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );

		void	push_back(const_reference value)
		{
			if (this->_size == this->_capacity)
				(!this->_capacity) ? this->reserve(1) : this->reserve(this->_capacity * 2);
			*(this->_prt + this->_size) = value;
			++this->_size;
		}

		void	pop_back()
		{
			this->_allocator.destroy(this->_prt + this->_size - 1);
			--this->_size;
		}

		// void resize( size_type count, T value = T() );

		// void swap( vector& other );
	};
}

#endif