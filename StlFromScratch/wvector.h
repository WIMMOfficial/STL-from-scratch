#pragma once
#include <iostream>

template <class T>

class wvector
{
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;

	
public:

	wvector();
	wvector(size_t size);
	wvector(const wvector& wv);
	wvector(wvector&& wv) noexcept;
	~wvector();
	void Clear(void);
	T* Begin(void) const;
//	T& operator=(const wvector& wv) noexcept;
//  T& operator=(wvector&& wv);
	void Swap(wvector& wv);
	void Resize(size_t new_capacity);
	size_t MaxSize() const;
	const T& operator[](const size_t index) const;
	T& operator[](const size_t index);
	size_t Size(void) const;
	void PushBack(const T& e);
	T& Back(void) const;
	void PopBack(void);
};


template<typename T>
inline wvector<T>::wvector()
{
	Resize(3);
}


template<typename T>
inline wvector<T>::wvector(size_t size)
{
	Resize(m_capacity + m_size / 2);
}


template<typename T>
inline wvector<T>::wvector(const wvector& wv)
{
	m_size = wv.Size();
	m_capacity = wv.MaxSize();

	m_data = new T[m_size];

	std::copy(wv.Begin(), wv.Begin() + wv.Size(), m_data);
}


template<typename T>
inline wvector<T>::wvector(wvector&& wv) noexcept
{
	//TODO
}



template<typename T>
inline wvector<T>::~wvector()
{
	Clear();
	delete[] m_data;
}


template<typename T>
inline void wvector<T>::Clear(void)
{
	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i].~T();
	}

	m_size = 0;
}


template<typename T>
inline T* wvector<T>::Begin(void) const
{
	return m_data;
}

/*
template<typename T>
inline T& wvector<T>::operator=(const wvector& wv)
{
	//TODO
}
*/

/*
template<typename T>
inline T& wvector<T>::operator=(wvector&& wv) noexcept
{
	//TODO
}
*/


template<typename T>
inline void wvector<T>::Swap(wvector& wv)
{
	//TODO
}


template<typename T>
void wvector<T>::Resize(size_t new_capacity)
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


template<typename T>
inline size_t wvector<T>::MaxSize() const
{
	return m_capacity;
}


template<typename T>
inline const T& wvector<T>::operator[](const size_t index) const
{
	return m_data[index];
}


template<typename T>
inline T& wvector<T>::operator[](const size_t index)
{
	return m_data[index];
}


template<typename T>
inline size_t wvector<T>::Size(void) const
{
	return m_size;
}


template<typename T>
inline void wvector<T>::PushBack(const T& e)
{
	if (m_size >= m_capacity)
	{
		Resize(m_capacity + m_size / 2);
	}

	m_data[m_size] = e;
	++m_size;
}


template<typename T>
inline T& wvector<T>::Back(void) const
{
	return m_data[m_size - 1];
}


template<typename T>
inline void wvector<T>::PopBack(void)
{
	if (m_size > 0)
	{
		m_size--;
		m_data[m_size].~T();
	}
}
