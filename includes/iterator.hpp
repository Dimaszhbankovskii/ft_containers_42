#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
	template<typename T> struct remove_const { typedef T type; };
	template<typename T> struct remove_const <const T> { typedef T type; };

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


	/********************************************************/
	/******           ITERATOR CLASS TEMPLATE           *****/
	/********************************************************/

	template <typename Iter>
	class iterator
	{
		/*********************************************/
		/******           MEMBER TYPES           *****/
		/*********************************************/

	public:
		typedef	Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

	protected:
		pointer	_current;

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/

	public:
		iterator() {}
		// iterator(const iterator& src) { *this = src; }

		iterator(const iterator<typename remove_const<value_type>::type >& src) { *this = src; }

		iterator(pointer current) { this->_current = current; }
		~iterator() {}

		iterator<value_type>&	operator=(const iterator<typename remove_const<value_type>::type >& src)
		{
			if (this == &src)
				return *this;
			this->_current = src._current;
			return *this;
		}

		// iterator<value_type>&	operator=(const iterator<typename ft::remove_const<value_type>::type> &src)
		// {
		// 	if (this == &src)
		// 		return *this;
		// 	this->_current = src._current;
		// 	return *this;
		// }
		
		iterator_type	base() const { return this->_current; }
		
		reference		operator*() const { return *this->_current; }
		pointer			operator->() const { return this->_current; }
		
		reference		operator[](difference_type n) const { return *(this->_current + n); }

		iterator&		operator++() { this->_current++; return *this; }
		iterator		operator++(__attribute__((unused)) int unused) { iterator result(*this); this->_current++; return result; }
		iterator&		operator+=(difference_type n) { this->_current += n; return *this; }
		iterator		operator+(difference_type n) const { return iterator(this->_current + n); }
		iterator&		operator--() { this->_current--; return *this; }
		iterator		operator--(__attribute__((unused)) int unused) { iterator result(*this); this->_current--; return result; }
		iterator&		operator-=(difference_type n) { this->_current -= n; return *this; }
		iterator		operator-(difference_type n) const { return iterator(this->_current - n); }

		/**********************************************************************/
		/******       NON-MEMBER FUNCTIONS - ITERATOR CLASS TEMPLATE      *****/
		/**********************************************************************/

		friend bool		operator==(const iterator& left, const iterator& rigth) { return left._current == rigth._current; }
		friend bool		operator!=(const iterator& left, const iterator& rigth) { return left._current != rigth._current; }
		friend bool		operator<(const iterator& left, const iterator& rigth) { return left._current < rigth._current; }
		friend bool 	operator<=(const iterator& left, const iterator& rigth) { return left._current <= rigth._current; }
		friend bool		operator>(const iterator& left, const iterator& rigth) { return left._current > rigth._current; }
		friend bool 	operator>=(const iterator& left, const iterator& rigth) { return left._current >= rigth._current; }

		friend iterator	operator+(difference_type n, const iterator& src) { return iterator(src._current + n); }

		friend difference_type	operator-(const iterator& left, const iterator& right) { return left._current - right._current; }
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
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

		/*********************************************/
		/******          MEMBER OBJECTS          *****/
		/*********************************************/

	protected:
		pointer	_current;

		/*********************************************/
		/******         MEMBER FUNCTIONS         *****/
		/*********************************************/

	public:
		reverse_iterator() {}
		reverse_iterator(const reverse_iterator& src) { *this = src; }
		reverse_iterator(pointer _current) { this->_current = _current; }
		~reverse_iterator() {}

		reverse_iterator	&operator=(const reverse_iterator &src)
		{
			if (this == &src)
				return *this;
			this->_current = src._current;
			return *this;
		}

		iterator_type		base() const { return this->_current; }

		reference			operator*() const { return *this->_current; }
		pointer				operator->() const { return this->_current; }
		
		reference			operator[](difference_type n) const { return *(this->_current - n); }

		reverse_iterator&	operator++() { this->_current--; return *this; }
		reverse_iterator	operator++(__attribute__((unused)) int unused) { reverse_iterator result(*this); this->_current--; return result; }
		reverse_iterator&	operator+=(difference_type n) { this->_current -= n; return *this; }
		reverse_iterator	operator+(difference_type n) const { return reverse_iterator(this->_current - n); }
		reverse_iterator&	operator--() { this->_current++; return *this; }
		reverse_iterator	operator--(__attribute__((unused)) int unused) { reverse_iterator result(*this); this->_current++; return result; }
		reverse_iterator&	operator-=(difference_type n) { this->_current += n; return *this; }
		reverse_iterator	operator-(difference_type n) const { return reverse_iterator(this->_current + n); }

		/******************************************************************************/
		/******       NON-MEMBER FUNCTIONS - REVERSE_ITERATOR CLASS TEMPLATE      *****/
		/******************************************************************************/

		friend bool				operator==(const reverse_iterator &left, const reverse_iterator &right) { return left._current == right._current; }
		friend bool				operator!=(const reverse_iterator &left, const reverse_iterator &right) { return left._current != right._current; }
		friend bool				operator<(const reverse_iterator &left, const reverse_iterator &right) { return left._current > right._current; }
		friend bool				operator<=(const reverse_iterator &left, const reverse_iterator &right) { return left._current >= right._current; }
		friend bool				operator>(const reverse_iterator &left, const reverse_iterator &right) { return left._current < right._current; }
		friend bool				operator>=(const reverse_iterator &left, const reverse_iterator &right) { return left._current <= right._current; }

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator& src) { return reverse_iterator(src._current - n); }

		friend difference_type	operator-(const reverse_iterator &left, const reverse_iterator &right) { return right._current - left._current; }
	};
}

#endif