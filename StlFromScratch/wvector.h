#pragma once
#include <iostream>

template <class T>

class wvector
{
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;

	void Allocate(const size_t new_capacity)
	{
		
		if (m_size > new_capacity)
		{
			m_size = new_capacity;
		}

		T* new_data = new T[new_capacity];

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
		m_capacity = new_capacity;

	}


public:

	inline wvector(const size_t size = 0) 
	{ 
		Allocate(3);
	}


	inline ~wvector() { Clear(); }


	void Clear(void)
	{
		//TODO
	}


	const T& operator[](const size_t index) const
	{
	   return m_data[index];
	}


	T& operator[](const size_t index)
	{
		return m_data[index];
	}


	inline size_t Size(void) const
	{
		return m_size;
	}



	inline void PushBack(const T& e)
	{
		if (m_size >= m_capacity)
		{
			Allocate(m_capacity + m_size / 2);
		}

		m_data[m_size] = e;
		++m_size;
	}


	inline void PopBack(void)
	{
		if (m_size > 0)
		{
			m_size--;
			m_data[m_size].~T();
		}
	}
};