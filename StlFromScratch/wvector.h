#pragma once
#include <iostream>

template <class T>

class wvector
{
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;

	
public:

	inline wvector() 
	{ 
		Resize(3);
	}


	inline wvector(size_t size)
	{
		Resize(m_capacity + m_size / 2);
	}


	inline wvector(const wvector& wv)
	{
		m_size = wv.Size();
		m_data = new T[m_size];

		for (size_t i = 0; i < m_size; ++i)
		{
			m_data[i] = wv[i];
		}

		m_capacity = wv.MaxSize();
	}


	inline wvector(wvector&& wv)
	{
		//TODO
	}

	inline ~wvector() { Clear(); }


	void Clear(void)
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			m_data[i].~T();
		}

		m_size = 0;
	}


	void Resize(const size_t new_capacity)
	{

		if (m_size > new_capacity)
		{
			m_size = new_capacity;
		}

		T* new_data = new T[new_capacity];

		for (size_t i = 0; i < m_size; ++i)
		{
			new_data[i] = m_data[i];
		}

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;

	}


	inline const size_t MaxSize() const
	{
		return m_capacity;
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
			Resize(m_capacity + m_size / 2);
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