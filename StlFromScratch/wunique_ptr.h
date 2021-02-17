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
	wunique_ptr<T>& operator=(std::nullptr_t p);
	T* Get() const;
	explicit operator bool() const;
	T& operator*() const;
	T* operator->() const;
	//T* Release();
	void Reset(T* p);

	wunique_ptr& operator=(const wunique_ptr&) = delete;
	wunique_ptr operator=(const wunique_ptr&) = delete;

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
inline wunique_ptr<T>& wunique_ptr<T>::operator=(std::nullptr_t p)
{
	m_data = p;
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

/*
template<class T>
inline T* wunique_ptr<T>::Release()
{
	T* retValue = m_data;
	m_data = nullptr;
	return retValue;
}
*/

template<class T>
inline void wunique_ptr<T>::Reset(T* p)
{
	delete m_data;
	m_data = p;
}

