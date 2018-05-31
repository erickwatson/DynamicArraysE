#pragma once
#include "includes.h"

const unsigned int MIN_CAP = 10;
const unsigned int GROWTH_FACTOR = 2;

template<typename T>
class dynamicArray
{
public:
	dynamicArray();
	~dynamicArray();

	void push(T value);
	T pop();
	void set(unsigned int index, T value);
	T get(unsigned int index);

	unsigned int size();
	unsigned int cap();
	void print();
	int is_empty();
	void sort();

	T& operator[](int index) { return m_data[index]; }

private:
	unsigned int m_size;
	unsigned int m_cap;
	T* m_data;
	void resize();

};

template<typename T>
dynamicArray<T>::dynamicArray()
{
	m_cap = MIN_CAP;
	m_size = 0;
	m_data = new T[m_cap]; //(T*)malloc(m_cap * sizeof(*m_data));
	if (!m_data)
		throw std::bad_alloc();
}

template<typename T>
unsigned int dynamicArray<T>::size()
{
	return m_size;
}

template<typename T>
unsigned int dynamicArray<T>::cap()
{
	return cap;
}

template<typename T>
dynamicArray<T>::~dynamicArray()
{
	delete[] m_data;
}

template<typename T>
void dynamicArray<T>::push(T value)
{
	if (m_size >= m_cap)
		resize();
	*(m_data + m_size++) = value;
}

template<typename T>
T dynamicArray<T>::pop()
{
	return *(m_data + --m_size);
}

template<typename T>
void dynamicArray<T>::set(unsigned int index, T value)
{
	while (index >= m_size)
		this->push(0);
	*(m_data + index) = value;
}

template<typename T>
T dynamicArray<T>::get(unsigned int index)
{
	return *(m_data + index);
}

template<typename T>
void dynamicArray<T>::resize()
{
	unsigned int cap = m_cap * GROWTH_FACTOR;
	T *tmp = new T[cap];
	if (!tmp)
		throw std::bad_alloc();

	for (unsigned int i = 0; i < m_cap; i++)
	{
		tmp[i] = m_data[i];
	}
	delete[] m_data;
	m_data = tmp;
	m_cap = cap;
}

template<typename T>
void dynamicArray<T>::sort()
{
	for (int i = 0; i < m_size; i++) {
		for (int j = 1; j < m_size; j++) {
			if (m_data[j] < m_data[j - 1]) {
				// Swap i and j around
				T temp = m_data[j];
				m_data[j] = m_data[j - 1];
				m_data[j - 1] = temp;
			}
		}
	}
}