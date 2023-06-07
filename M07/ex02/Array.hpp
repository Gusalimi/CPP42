#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {
	public:
		Array<T>()
		{
			this->_array = new T[0];
			this->_size = 0;
		}
		Array<T>(unsigned int n)
		{
			this->_array = new T[n];
			this->_size = n;
		}
		Array<T>(Array<T> const &src)
		{
			this->_array = new T[src.size()];
			this->_size = src.size();
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src[i];
		}
		~Array<T>()
		{
			delete[] this->_array;
		}

		Array<T> &operator=(Array<T> const &src)
		{
			if (this != &src)
			{
				delete[] this->_array;
				this->_array = new T[src.size()];
				this->_size = src.size();
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src[i];
			}
			return *this;
		}

		T &operator[](unsigned int i) const
		{
			if (i >= this->_size)
				throw std::exception();
			return this->_array[i];
		}

		int size() const
		{
			return this->_size;
		}

	private:
		T *_array;
		unsigned int _size;
};

#endif /* ARRAY_HPP */
