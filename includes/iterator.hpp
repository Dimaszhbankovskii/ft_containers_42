#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "type_traits.hpp"

namespace ft
{
	/********************************************************/
	/******               ITERATOR_TRAITS               *****/
	/********************************************************/

	template <typename Iterator>
	struct iterator_traits
	{
		typedef	typename Iterator::difference_type		difference_type;
		typedef	typename Iterator::value_type			value_type;
		typedef	typename Iterator::pointer				pointer;
		typedef	typename Iterator::reference			reference;
		typedef	typename Iterator::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};


	/**********************************************************************/
	/******           RANDOM_ACCESS_ITERATOR CLASS TEMPLATE           *****/
	/**********************************************************************/

	template <typename It>
	class RandomAccessIterator
	{
		/*********************************************/
		/******           MEMBER TYPES           *****/
		/*********************************************/

	public:
		typedef typename ft::iterator_traits<It*>::difference_type		difference_type;
		typedef typename ft::iterator_traits<It*>::value_type			value_type;
		typedef typename ft::iterator_traits<It*>::pointer				pointer;
		typedef typename ft::iterator_traits<It*>::reference			reference;
		typedef	pointer													iterator_type;
		typedef std::random_access_iterator_tag							iterator_category;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

	protected:
		pointer	_current;

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/

	public:
		RandomAccessIterator() {}
		RandomAccessIterator(pointer current) { this->_current = current; }
		RandomAccessIterator(const RandomAccessIterator<typename ft::remove_const<value_type>::type >& src) { this->_current = &(*src); }
		~RandomAccessIterator() {}

		RandomAccessIterator&	operator=(const RandomAccessIterator<typename ft::remove_const<value_type>::type >& src)
		{
			this->_current = &(*src);
			return *this;
		}
		
		iterator_type	base() const { return this->_current; }
		
		reference	operator*() const { return *this->_current; }
		pointer		operator->() const { return this->_current; }
		
		reference	operator[](difference_type n) const { return *(this->_current + n); }

		RandomAccessIterator&	operator++() { this->_current++; return *this; }
		RandomAccessIterator	operator++(__attribute__((unused)) int unused) { RandomAccessIterator result(*this); this->_current++; return result; }
		RandomAccessIterator&	operator+=(difference_type n) { this->_current += n; return *this; }
		RandomAccessIterator	operator+(difference_type n) const { return RandomAccessIterator(this->_current + n); }
		RandomAccessIterator&	operator--() { this->_current--; return *this; }
		RandomAccessIterator	operator--(__attribute__((unused)) int unused) { RandomAccessIterator result(*this); this->_current--; return result; }
		RandomAccessIterator&	operator-=(difference_type n) { this->_current -= n; return *this; }
		RandomAccessIterator	operator-(difference_type n) const { return RandomAccessIterator(this->_current - n); }

		/**********************************************************************/
		/******       NON-MEMBER FUNCTIONS - ITERATOR CLASS TEMPLATE      *****/
		/**********************************************************************/

		friend bool	operator==(const RandomAccessIterator& left, const RandomAccessIterator& rigth) { return *left == *rigth; }
		friend bool	operator!=(const RandomAccessIterator& left, const RandomAccessIterator& rigth) { return *left != *rigth; }
		friend bool	operator<(const RandomAccessIterator& left, const RandomAccessIterator& rigth) { return *left < *rigth; }
		friend bool operator<=(const RandomAccessIterator& left, const RandomAccessIterator& rigth) { return *left <= *rigth; }
		friend bool	operator>(const RandomAccessIterator& left, const RandomAccessIterator& rigth) { return *left > *rigth; }
		friend bool operator>=(const RandomAccessIterator& left, const RandomAccessIterator& rigth) { return *left >= *rigth; }

		friend RandomAccessIterator	operator+(difference_type n, const RandomAccessIterator& src) { return RandomAccessIterator(src._current + n); }

		friend difference_type	operator-(const RandomAccessIterator& left, const RandomAccessIterator& right) { return left._current - right._current; }
	};


	/****************************************************************/
	/******           REVERSE_ITERATOR CLASS TEMPLATE           *****/
	/****************************************************************/

	template <typename Iter>
	class reverse_iterator
	{
		/*********************************************/
		/******           MEMBER TYPES           *****/
		/*********************************************/

	public:
		typedef	Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

	protected:
		iterator_type	_current;

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/

	public:
		reverse_iterator() {}
		explicit reverse_iterator(iterator_type current) { this->_current = current; }		

		template <typename U>
		reverse_iterator(const reverse_iterator<U>& src) { *this = src; }
		~reverse_iterator() {}

		template <typename U>
		reverse_iterator&	operator=(const reverse_iterator<U>& src)
		{
			this->_current = src.base();
			return *this;
		}

		iterator_type		base() const { return this->_current; }

		reference	operator*() const { return *this->_current; }
		pointer		operator->() const { return this->_current; }
		
		reference	operator[](difference_type n) const { return *(this->_current - n); }

		reverse_iterator&	operator++() { this->_current--; return *this; }
		reverse_iterator	operator++(__attribute__((unused)) int unused) { reverse_iterator result(*this); this->_current--; return result; }
		reverse_iterator&	operator+=(difference_type n) { this->_current -= n; return *this; }
		reverse_iterator	operator+(difference_type n) const { return reverse_iterator(this->_current - n); }
		reverse_iterator&	operator--() { this->_current++; return *this; }
		reverse_iterator	operator--(__attribute__((unused)) int unused) { reverse_iterator result(*this); this->_current++; return result; }
		reverse_iterator&	operator-=(difference_type n) { this->_current += n; return *this; }
		reverse_iterator	operator-(difference_type n) const { return reverse_iterator(this->_current + n); }
	};

	/******************************************************************************/
	/******       NON-MEMBER FUNCTIONS - REVERSE_ITERATOR CLASS TEMPLATE      *****/
	/******************************************************************************/

	template <typename Iterator1, typename Iterator2>
	bool	operator==(const ft::reverse_iterator<Iterator1> &left, const ft::reverse_iterator<Iterator2> &right)
	{ return left.base() == right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool	operator!=(const ft::reverse_iterator<Iterator1> &left, const ft::reverse_iterator<Iterator2> &right)
	{ return left.base() != right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool	operator<(const ft::reverse_iterator<Iterator1> &left, const ft::reverse_iterator<Iterator2> &right)
	{ return left.base() > right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool	operator<=(const ft::reverse_iterator<Iterator1> &left, const ft::reverse_iterator<Iterator2> &right)
	{ return left.base() >= right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool	operator>(const ft::reverse_iterator<Iterator1> &left, const ft::reverse_iterator<Iterator2> &right)
	{ return left.base() < right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool	operator>=(const ft::reverse_iterator<Iterator1> &left, const ft::reverse_iterator<Iterator2> &right)
	{ return left.base() <= right.base(); }

	template <typename Iter>
	ft::reverse_iterator<Iter>	operator+(typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter>& src)
	{ return ft::reverse_iterator<Iter>(src.base() - n); }

	template <typename Iterator>
	typename ft::reverse_iterator<Iterator>::difference_type
	operator-(const ft::reverse_iterator<Iterator> &left, const ft::reverse_iterator<Iterator> &right)
	{ return right.base() - left.base(); }
}

#endif