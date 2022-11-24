#pragma once

#include <iterator>
#include "vector_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public :

			typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference			const_reference;
			typedef typename	allocator_type::pointer					pointer;
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef				ft::vector_iterator<pointer>			iterator;
			typedef				ft::vector_iterator<const_pointer>		const_iterator;
			typedef				std::reverse_iterator<iterator>			reverse_iterator;
			typedef				std::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef				std::ptrdiff_t							difference_type;
			typedef				std::size_t								size_type;

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

			explicit	vector(const allocator_type & alloc = allocator_type()) : _data(NULL), _size(0), _capacity(0)	{};
			explicit	vector(size_type size, const value_type & value = value_type(), const allocator_type& alloc = allocator_type()) : _size(size), _capacity(size)
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

			/* Modifiers */

			void	clear()
			{
				if (!empty())
				{
					_destroy_array();
					_size = 0;
				}
			}
	};
}