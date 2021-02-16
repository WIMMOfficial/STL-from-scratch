#pragma once
template<class T>

class wunique_ptr
{
	T* m_data;


public:
	wunique_ptr();
	explicit wunique_ptr(T* e);
	~wunique_ptr();
	wunique_ptr<T>& operator=(T&& el);
	wunique_ptr<T>& operator=(std::nullptr_t);
	T* Get() const;
	explicit operator bool() const;
	T& operator*() const;
	T* operator->() const;
	T& operator[](size_t i) const;
	

};


template<class T>
inline wunique_ptr<T>::wunique_ptr()
{
	m_data = nullptr;
}


template<class T>
inline wunique_ptr<T>::wunique_ptr(T* e)
{
	m_data = e;
}


template<class T>
inline  wunique_ptr<T>::~wunique_ptr()
{
	delete m_data;
}


template<class T>
inline wunique_ptr<T>& wunique_ptr<T>::operator=(T&& el)
{
	//TODO
}

template<class T>
inline wunique_ptr<T>& wunique_ptr<T>::operator=(std::nullptr_t)
{
	m_data = nullptr;
}


template<class T>
inline T* wunique_ptr<T>::Get() const
{
	return m_data;
}


template <class T>
inline  wunique_ptr<T>::operator bool() const
{
	if (Get() != nullptr)
		return true;

	return false;
}


template <class T>
inline T& wunique_ptr<T>::operator*() const
{
	return *m_data;
}


template <class T>
inline T* wunique_ptr<T>::operator->() const
{
	return m_data;
}


template <class T>
inline T& wunique_ptr<T>::operator[](size_t i) const
{
	return *(m_data + i);
}


