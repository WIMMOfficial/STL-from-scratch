#pragma once
#include <algorithm>
template <class T, size_t N = 1>

class warray
{
	T m_data[N];
	 
public:
	warray();
	warray(const warray<T, N>& wa);
	warray(warray<T, N>&& wa) noexcept;
	~warray();

	T& operator[](const size_t index);
	const T* Data() const;
	T* Data();
	warray<T, N>& operator=(const warray<T, N>& val);
	warray<T, N>& operator=(warray<T, N>&& val) noexcept;
	const T& operator[](const size_t index) const;

	size_t Size() const;
	void Fill(const T& val);
	void Swap(warray<T, N>& e);
};


template <typename T, size_t N>
 warray<T, N>::warray() {}


template <typename T, size_t N>
 warray<T, N>::warray(const warray<T, N>& wa)
{
	std::copy(wa.Data(), wa.Data() + wa.Size(), m_data);
}


 template <typename T, size_t N>
 warray<T, N>::warray(warray<T, N>&& wa) noexcept
 {
	 wa.Swap(*this);
 }


template <typename T, size_t N>
 warray<T, N>::~warray() {}


template <typename T, size_t N>
 const T* warray<T, N>::Data() const
{
	return m_data;
}


template <typename T, size_t N>
 T* warray<T, N>::Data()
{
	return m_data;
}


template <typename T, size_t N>
 size_t warray<T, N>::Size() const
{
	return N;
}


template <typename T, size_t N>
 const T& warray<T, N>::operator[](const size_t index) const
{
	return m_data[index];
}


template <typename T, size_t N>
 T& warray<T, N>::operator[](const size_t index)
{
	return m_data[index];
}


template <typename T, size_t N>
 void warray<T, N>::Fill(const T& val)
{
	std::fill(m_data, m_data + N, val);
}


template <typename T, size_t N>
warray<T, N>& warray<T, N>::operator=(const warray<T, N>& val)
{
	warray<T, N> tmp(val);
	Swap(tmp);
	return *this;
}


 template <typename T, size_t N>
 warray<T, N>& warray<T, N>::operator=(warray<T, N>&& val) noexcept
 {
	 val.Swap(*this);
	 return *this;
 }


 template <typename T, size_t N>
 void warray<T, N>::Swap(warray<T, N>& e)
 {
	 using std::swap;
	 swap(m_data, e.m_data);
 }