#pragma once

#include <iterator>
#include "iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public :

			typedef				T											value_type;
			typedef				Alloc										allocator_type;
			typedef typename	allocator_type::reference					reference;
			typedef typename	allocator_type::const_reference				const_reference;
			typedef typename	allocator_type::pointer						pointer;
			typedef typename	allocator_type::const_pointer				const_pointer;
			typedef				ft::random_access_iterator<pointer>			iterator;
			typedef				ft::random_access_iterator<const_pointer>	const_iterator;
			typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef				std::ptrdiff_t								difference_type;
			typedef				std::size_t									size_type;

		private :

			pointer			_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;

			size_type	_adjust_capacity(size_type newCap)
			{
				if (newCap > _capacity * 2)
					return newCap;
				else
					return _capacity * 2;
			}
			void		_destroy_array()
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_data + i);
			}

		public :

			explicit	vector() : _data(NULL), _size(0), _capacity(0)	{};
			explicit	vector(size_type size, const value_type & value = value_type()) : _size(size), _capacity(size)
			{
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < size; i++)
					_alloc.construct(&_data[i], value);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value, void *>::type = NULL)
			{
				_size = last - first;
				_capacity = _size;
				_alloc = alloc;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_data[i], *(first + i));
			}
			vector(const vector<T>& src) : _data(NULL), _size(0), _capacity(0)
			{
				if (src._capacity)
				{
					_size = src._size;
					_capacity = _size;
					_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < src._size; ++i)
						_alloc.construct(&_data[i], src._data[i]);
				}
			}
			~vector()
			{
				clear();
				if (_capacity)
					_alloc.deallocate(_data, _capacity);
			};

			vector<T> & operator=(const vector<T>& rhs)
			{
				if (this != &rhs)
				{
					clear();
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
					_size = rhs._size;
					_alloc = rhs._alloc;
					_capacity = rhs._capacity;
					if (_capacity)
					{
						_data = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(&_data[i], rhs._data[i]);
					}
				}
				return *this;
			};

			/* Iterator */

			iterator				begin()				{ return iterator(_data); }
			const_iterator			begin()		const	{ return const_iterator(_data); }
			iterator				end()				{ return iterator(_data + _size); }
			const_iterator			end()		const	{ return const_iterator(_data + _size); }
			reverse_iterator		rbegin()			{ return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() 	const	{ return const_reverse_iterator(end()); }
			reverse_iterator		rend()				{ return reverse_iterator(begin()); }
			const_reverse_iterator	rend() 		const	{ return const_reverse_iterator(begin()); }

			/* Capacity */

			size_type	size()		const	{ return _size; }
			size_type	max_size()	const	{ return _alloc.max_size(); }
			size_type	capacity()	const	{ return _capacity; }
			bool		empty()		const	{ return _size ? false : true; }
			void		resize(size_type n, value_type val = value_type())
			{
				if (n > _capacity)
					reserve(_adjust_capacity(n));
				if (n < _size)
				{
					for (size_type i = n; i < _size; ++i)
						_alloc.destroy(&_data[i]);
					_size = n;
				}
				else if (n > _size)
				{
					for (size_type i = _size; i < n; ++i)
						_alloc.construct(&_data[i], val);
					_size = n;
				}
			}
			void		reserve(size_type n)
			{
				if (n > max_size())
					throw(std::length_error("vector::reserve: max_size exceeded"));
				if (n > _capacity)
				{
					pointer newData = _alloc.allocate(n);
					for (size_type i = 0; i < _size; ++i)
						_alloc.construct(newData + i, _data[i]);
					_destroy_array();
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
					_data = newData;
					_capacity = n;
				}
			}

			/* Element access */

			value_type &	operator[](const size_t & i) const { return _data[i]; }
			reference		front()			{ return _data[0]; }
			const_reference	front()	const	{ return _data[0]; }
			reference		back()			{ return _data[_size - 1]; }
			const_reference	back()	const	{ return _data[_size - 1]; }
			pointer			data()			{ return _data; }
			const_pointer	data()	const	{ return _data; }
			reference		at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("ft::vector::at");
				return _data[n];
			}
			const_reference	at(size_type n)	const
			{
				if (n >= _size)
					throw std::out_of_range("ft::vector::at");
				return _data[n];
			}

			/* Modifiers */

			void	clear()
			{
				if (!empty())
				{
					_destroy_array();
					_size = 0;
				}
			}

			/* Alloctor */

			allocator_type get_allocator()	const	{ return _alloc; }
	};
}