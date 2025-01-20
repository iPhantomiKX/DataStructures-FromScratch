#include <iostream>

template <class T>
class Stack
{
private:
	T* container;
	size_t capacity;
	size_t size;
public:
	Stack();
	void push(const T& elem);
	void pop();
	T top();
	size_t getCapacity();
	size_t getSize();
	void print();
};

template<class T>
inline Stack<T>::Stack()
{
	capacity = 10;
	size = 0;
	container = new T[capacity];
}

template<class T>
inline void Stack<T>::push(const T& elem)
{
	if (size == 0) container[0] = elem;
	else
	{
		if (size + 1 >= capacity)
		{
			capacity *= 2;
			T* newContainer = new T[capacity];
			for (size_t i = 0; i < size; ++i)
			{
				newContainer[i] = container[i];
			}
			delete container;
			container = newContainer;
		}
		for (size_t i = size + 1; i >= 0; --i)
		{
			if (i == 0)
			{
				container[i] = elem;
				break; //because size_t is unsigned, therefore going negative becomes overflow
			}
			else
				container[i] = container[i - 1];
		}
	}
	size += 1;
}

template<class T>
inline void Stack<T>::pop()
{
	if (size == 0)
		return;
	size -= 1;
	for (size_t i = 0; i < size; ++i)
		container[i] = container[i + 1];
}

template<class T>
inline T Stack<T>::top()
{
	return container[0];
}

template<class T>
inline size_t Stack<T>::getCapacity()
{
	return capacity;
}

template<class T>
inline size_t Stack<T>::getSize()
{
	return size;
}

template<class T>
inline void Stack<T>::print()
{
	if (typeid(T).name() == typeid(int).name())
	{
		for (size_t i = 0; i < size; ++i) {
			std::cout << container[i] << std::endl;
		}
	}
}
