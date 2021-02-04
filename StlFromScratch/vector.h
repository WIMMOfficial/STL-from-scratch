#pragma once
#include <iostream>

template <class T>

class vector
{
	T* m_data = nullptr;
	size_t m_size;
	size_t m_capacity;



	void Allocate()
	{
		if (m_size >= m_capacity)
		{
			m_capacity += m_size / 2;
		}
        
		T* new_data = new T[m_capacity];

		if (!new_data)
		{
			std::cout << "[ERROR]Cannot allocate memory for vector\n";
			return;
		}

		for (size_t i = 0; i < m_size; ++i)
		{
			new_data[i] = m_data[i];
		}

		delete[] m_data;
		m_data = new_data;



	}


public:
	vector(size_t size = 0, size_t capacity = 10)
	{
		m_size = size;
		m_capacity = capacity;
		Allocate();
	}


	~vector()
	{
		delete m_data;
	}


    size_t Size() const
	{
		return m_size;
	}


	void PushBack(T e)
	{
		if (m_size >= m_capacity)
		{
			Allocate();
		}

		m_data[m_size] = e;
		++m_size;
	}


	T At(size_t pos) const
	{
		if (pos > m_size)
		{
			std::cout << "[ERROR] Ttrying to refer an element outside the vector\n";
			return -1;
		}

		return m_data[pos];
	}


	T PopBack()
	{
		T tmp = m_data[m_size--];
		return tmp;
	}
};