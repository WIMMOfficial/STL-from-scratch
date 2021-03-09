#pragma once

template <class T>

class wvector
{
	T* m_data;
	size_t m_size;
	size_t m_capacity;

	
public:

	
	wvector();
	wvector(size_t size);
	wvector(const wvector<T>& wv);
	wvector(wvector<T>&& wv) noexcept;
	~wvector();

	void PushBack(const T& e);
	void PushBack(T&& e);
	void PopBack();
	void Clear();

	const T* Data() const;
	T* Data();
	T& operator[](const size_t index);
	wvector<T>& operator=(const wvector<T>& wv);
	wvector<T>& operator=(wvector<T>&& wv) noexcept;
	const T& operator[](const size_t index) const;
	T& Back() const;

	void Swap(wvector& wv) noexcept;
	void Resize(size_t new_capacity);
	size_t MaxSize() const;
	size_t Size() const;

};


template<typename T>
wvector<T>::wvector()
{
	Resize(3);
}


template<typename T>
wvector<T>::wvector(size_t size)
{
	Resize(m_capacity + size/ 2);
}


template<typename T>
wvector<T>::wvector(const wvector<T>& wv) 
		: m_data		(new T[m_size])
		, m_size		(wv.Size())
		, m_capacity	(wv.MaxSize())
		 
{
	std::copy(wv.Data(), wv.Data() + wv.Size(), m_data);
}


template<typename T>
wvector<T>::wvector(wvector<T>&& wv) noexcept
		: m_data		(nullptr)
		, m_capacity	(0)
		, m_size		(0)
{

	wv.Swap(*this);
}



template<typename T>
 wvector<T>::~wvector()
{
	Clear();
	delete[] m_data;
}


template<typename T>
 void wvector<T>::Clear()
{
	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i].~T();
	}

	m_size = 0;
}


template<typename T>
 const T* wvector<T>::Data() const
{
	return m_data;
}


 template<typename T>
 T* wvector<T>::Data()
 {
	 return m_data;
 }

 
template<typename T>
wvector<T>& wvector<T>::operator=(const wvector<T>& wv)
{
	wvector tmp(wv);
	tmp.Swap(*this);
	return *this;
}



template<typename T>
 wvector<T>& wvector<T>::operator=(wvector<T>&& wv) noexcept
{
	wv.Swap(*this);
	return *this;
 }

 
template<typename T>
 void wvector<T>::Swap(wvector<T>& wv) noexcept
{
	 using std::swap;
	 swap(m_capacity, wv.m_capacity);
	 swap(m_size, wv.m_size);
	 swap(m_data, wv.m_data);
}



template<typename T>
void wvector<T>::Resize(size_t new_capacity)
{

	if (m_size > new_capacity)
	{
		m_size = new_capacity;
	}

	T* new_data = new T[new_capacity];
	if (m_data != nullptr)
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			new_data[i] = m_data[i];
		}

		delete[] m_data;
	}

	m_data = new_data;
	m_capacity = new_capacity;

}


template<typename T>
 size_t wvector<T>::MaxSize() const
{
	return m_capacity;
}


template<typename T>
 const T& wvector<T>::operator[](const size_t index) const
{
	return m_data[index];
}


template<typename T>
 T& wvector<T>::operator[](const size_t index)
{
	return m_data[index];
}


template<typename T>
 size_t wvector<T>::Size() const
{
	return m_size;
}


template<typename T>
 void wvector<T>::PushBack(const T& e)
{
	if (m_size >= m_capacity)
	{
		Resize(m_capacity + m_size / 2);
	}

	m_data[m_size] = e;
	++m_size;
}


template<typename T>
 T& wvector<T>::Back() const
{
	return m_data[m_size - 1];
}


 template<typename T>
 void wvector<T>::PushBack(T&& e)
 {
	 if (m_size >= m_capacity)
	 {
		 Resize(m_capacity + m_size / 2);
	 }

	 m_data[m_size] = std::move(e);
	 ++m_size;
 }


template<typename T>
 void wvector<T>::PopBack()
{
	if (m_size > 0)
	{
		m_size--;
		m_data[m_size].~T();
	}
}
