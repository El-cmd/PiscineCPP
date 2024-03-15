#include "Array.hpp"

template <typename T>
class Array
{
	public:
	Array(): _size(0), _ptr(new T()) { }
	Array(unsigned int n): _ptr(new T[n]), _size(n) { }
	Array(const Array &other): _ptr(new T[other._size]), _size(other._size) { }
	Array &operator=(const Array &other)
	{
		if (this != other)
			delete[] _ptr;
		this->_size = other._size;
		new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			this->_ptr[i] = other._ptr[i];
		return *this;
	}

	T &operator[](unsigned int i)
	{
		if (i >= this->_size) 
			throw OutOfBoundsException();
		return _ptr[i];
	}

	size_t size()
	{
		return _size;
	}

	~Array() { delete[] _ptr; };
	private:

	T *_ptr;
	unsigned int _size;
	class OutOfBoundsException : public std::exception 
	{
	    public:
	        virtual const char* what() const throw() 
			{ return "Index is out of bounds";}
	};

};