#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
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

	template <typename T>
	class iterator
	{
	public:
		typedef	T														Iter;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

	protected:
		pointer	_prt;
	
	public:
		iterator() {}
		iterator(const iterator& src) { *this = src; }
		iterator(pointer prt) { this->_prt = prt; }
		~iterator() {}

		iterator	&operator=(const iterator &src)
		{
			if (this == &src)
				return *this;
			this->_prt = src._prt;
			return *this;
		}
		reference	operator*() const { return *this->_prt; }
		pointer		operator->() const { return this->_prt; }
		reference	operator[](size_t n) const { return *(this->_prt + n); }
		iterator	operator++(__attribute__((unused)) int unused)
		{
			iterator	result(*this);
			this->_prt++;
			return result;
		}
		iterator	operator--(__attribute__((unused)) int unused)
		{
			iterator	result(*this);
			this->_prt--;
			return result;
		}
		iterator&	operator++() { this->_prt++; return *this; }
		iterator&	operator--() { this->_prt--; return *this; }
		iterator	operator+(size_t n) const { return iterator(this->_prt + n); }
		iterator	operator-(size_t n) const { return iterator(this->_prt - n); }
		int			operator-(const iterator& src) const { return this->_prt - src._prt; }
		iterator&	operator+=(size_t n) { this->_prt += n; return *this; }
		iterator&	operator-=(size_t n) { this->_prt -= n; return *this; }
		bool		operator==(const iterator &src) const { return this->_prt == src._prt; }
		bool		operator!=(const iterator &src) const { return this->_prt != src._prt; }
		bool		operator>(const iterator &src) const { return this->_prt > src._prt; }
		bool		operator>=(const iterator &src) const { return this->_prt >= src._prt; }
		bool		operator<(const iterator &src) const { return this->_prt < src._prt; }
		bool		operator<=(const iterator &src) const { return this->_prt <= src._prt; }
		pointer		base() const { return this->_prt; }
	};

	template <typename T>
	class reverse_iterator
	{
	public:
		typedef	T														Iter;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

	protected:
		pointer	_prt;

	public:
		reverse_iterator() {}
		reverse_iterator(const reverse_iterator& src) { *this = src; }
		reverse_iterator(pointer prt) { this->_prt = prt; }
		~reverse_iterator() {}

		reverse_iterator	&operator=(const reverse_iterator &src)
		{
			if (this == &src)
				return *this;
			this->_prt = src._prt;
			return *this;
		}
		reference			operator*() const { return *this->_prt; }
		pointer				operator->() const { return this->_prt; }
		reference			operator[](size_t n) const { return *(this->_prt - n); }
		reverse_iterator	operator++(__attribute__((unused)) int unused)
		{
			reverse_iterator	result(*this);
			this->_prt--;
			return result;
		}
		reverse_iterator	operator--(__attribute__((unused)) int unused)
		{
			reverse_iterator	result(*this);
			this->_prt++;
			return result;
		}
		reverse_iterator&	operator++() { this->_prt--; return *this; }
		reverse_iterator&	operator--() { this->_prt++; return *this; }
		reverse_iterator	operator+(size_t n) const { return reverse_iterator(this->_prt + n); }
		reverse_iterator	operator-(size_t n) const { return reverse_iterator(this->_prt - n); }
		int					operator-(const reverse_iterator& src) const { return this->_prt - src._prt; }
		reverse_iterator&	operator+=(size_t n) { this->_prt -= n; return *this; }
		reverse_iterator&	operator-=(size_t n) { this->_prt += n; return *this; }
		bool				operator==(const reverse_iterator &src) const { return this->_prt == src._prt; }
		bool				operator!=(const reverse_iterator &src) const { return this->_prt != src._prt; }
		bool				operator>(const reverse_iterator &src) const { return this->_prt > src._prt; }
		bool				operator>=(const reverse_iterator &src) const { return this->_prt >= src._prt; }
		bool				operator<(const reverse_iterator &src) const { return this->_prt < src._prt; }
		bool				operator<=(const reverse_iterator &src) const { return this->_prt <= src._prt; }
		pointer				base() const { return this->_prt; }
	};
}

#endif