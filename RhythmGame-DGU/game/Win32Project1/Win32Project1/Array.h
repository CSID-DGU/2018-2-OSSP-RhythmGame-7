#pragma once

template<class T>
class Array
{
private:
	T* _array;
	int _size;

public:
	T& operator[] (int index);
	operator T*();	// 변환 연산자 오버로딩

public:
	Array(int size)
	{
		_array = new T[size];
		_size = size;
	}

	~Array();

	void Set(int index, T value);
	T Get(int index);

	void Insert(T newValue, int insertIndex);
	void Remove(int removeIndex);

	int Size();
	void Resize(int newSize);
};

/*
template<class T>
Array<T>::Array(int size)
{
	_array = new T[size];
	_size = size;
}
*/

template<class T>
Array<T>::~Array()
{
	if (NULL != _array)
	{
		delete[] _array;
		_array = NULL;
	}
}

template<class T>
T& Array<T>::operator[] (int index)
{
	return _array[index];
}

template<class T>
Array<T>::operator T*()
{
	return _array;
}

template<class T>
void Array<T>::Set(int index, T value)
{
	if (index < _size)
		_array[index] = value;
}

template<class T>
T Array<T>::Get(int index)
{
	if (index < _size)
		return _array[index];
	return 0;
}

template<class T>
void Array<T>::Insert(T newValue, int insertIndex)
{
	for (int i = _size - 1; insertIndex < i; i--)
	{
		_array[i] = _array[i - 1];
	}
	_array[insertIndex] = newValue;
}

template<class T>
void Array<T>::Remove(int removeIndex)
{
	for (int i = removeIndex + 1; i < _size; i++)
	{
		_array[i - 1] = _array[i];
	}
}

template<class T>
int Array<T>::Size()
{
	return _size;
}

template<class T>
void Array<T>::Resize(int newSize)
{
	T* newArray = new T[newSize];

	int minSize = 0;
	if (newSize < _size)
		minSize = newSize;
	else
		minSize = _size;

	for (int i = 0; i < minSize; i++)
	{
		newArray[i] = _array[i];
	}
	_size = newSize;

	if (NULL != _array)
		delete[] _array;

	_array = newArray;
}

