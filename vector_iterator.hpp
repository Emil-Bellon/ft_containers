#pragma once

#include <iterator>

namespace ft {

	template <class Iterator> class vector_iterator
	{
		public:

			typedef typename traits_type::value_type		value_type;
			typedef typename traits_type::reference			reference;
			typedef typename traits_type::pointer			pointer;
			typedef typename traits_type::iterator_category	iterator_category;
			typedef typename traits_type::difference_type	difference_type;

		protected:

			Iterator	current;
			typedef		std::iterator_traits<Iterator>	traits_type;

		public:
		
			vector_iterator() : current(Iterator())	{}
			vector_iterator(const Iterator& p) : current(p)	{}
			template<typename Iter>
			vector_iterator(const vector_iterator<Iter>& other) : current(other.base())	{}
			~vector_iterator() {}

			vector_iterator& operator=(const vector_iterator& other)	{ current = other.current; return *this; }

			/* Accessor */

			const Iterator& base() const	{ return current; }

			/* Operators */

			reference			operator*() const	{ return *current; }
			pointer				operator->() const	{ return current; }
			vector_iterator&	operator++()	{ ++current; return *this; }
			vector_iterator		operator++(int)	{ return vector_iterator(current++); }
			vector_iterator&	operator--()	{ --current; return *this; }
			vector_iterator		operator--(int)	{ return vector_iterator(current--); }
			reference			operator[](difference_type n)	{ return current[n]; }
			vector_iterator&	operator+=(difference_type n)	{ current += n; return *this; }
			vector_iterator		operator+(difference_type n)	{ return vector_iterator(current + n); }
			vector_iterator&	operator-=(difference_type n)	{ current -= n; return *this; }
			vector_iterator		operator-(difference_type n)	{ return vector_iterator(current - n); }
			vector_iterator		operator+(difference_type n) const	{ return vector_iterator(current + n); }
	};
	
	template< class IteratorL, class IteratorR >
	inline bool	operator==(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs)	{ return lhs.base() == rhs.base(); }
	template< class IteratorL, class IteratorR >
	inline bool	operator!=(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs)	{ return lhs.base() != rhs.base(); }
	template< class IteratorL, class IteratorR >
	inline bool	operator<=(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs)	{ return lhs.base() <= rhs.base(); }
	template< class IteratorL, class IteratorR >
	inline bool	operator>=(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs)	{ return lhs.base() >= rhs.base(); }
	template< class IteratorL, class IteratorR >
	inline bool	operator<(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs)	{ return lhs.base() < rhs.base(); }
	template< class IteratorL, class IteratorR >
	inline bool	operator>(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs)	{ return lhs.base() > rhs.base(); }
	template< class Iterator>
	typename vector_iterator<Iterator>::difference_type operator-(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)	{ return lhs.base() - rhs.base(); }	
	template< class Iterator>
	typename vector_iterator<Iterator>::difference_type operator+(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)	{ return lhs.base() + rhs.base(); }
}