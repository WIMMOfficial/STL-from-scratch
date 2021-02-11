#pragma once
#include <algorithm>
template <class T, size_t N = 1>

class warray
{
	T m_data[N];

public:
	warray();
	warray(const warray& wa);
	~warray();
	const T* Data(void) const;
	T* Data(void);
	size_t Size() const;
	const T& operator[](const size_t index) const;
	T& operator[](const size_t index);
	void Fill(const T& val);
	T& operator=(const T& val);
};


template <typename T, size_t N>
inline warray<T, N>::warray() {}


template <typename T, size_t N>
inline warray<T, N>::warray(const warray& wa)
{
	std::copy(wa.Data(), wa.Data() + wa.Size(), m_data);
}


template <typename T, size_t N>
inline warray<T, N>::~warray() {}


template <typename T, size_t N>
inline const T* warray<T, N>::Data() const
{
	return m_data;
}


template <typename T, size_t N>
inline T* warray<T, N>::Data()
{
	return m_data;
}


template <typename T, size_t N>
inline size_t warray<T, N>::Size() const
{
	return N;
}


template <typename T, size_t N>
inline const T& warray<T, N>::operator[](const size_t index) const
{
	return m_data[index];
}


template <typename T, size_t N>
inline T& warray<T, N>::operator[](const size_t index)
{
	return m_data[index];
}


template <typename T, size_t N>
inline void warray<T, N>::Fill(const T& val)
{
	std::fill(m_data, m_data + N, val);
}


template <typename T, size_t N>
inline T& warray<T, N>::operator=(const T& val)
{
	std::copy(val.Data(), val.Data() + val.Size(), m_data);
}
