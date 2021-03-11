#pragma once
template<class T>

class wunique_ptr
{
	T* m_data;


public:
	wunique_ptr();
	explicit wunique_ptr(T* e);
	wunique_ptr(wunique_ptr<T>&& e) noexcept;
	~wunique_ptr();


	wunique_ptr<T>& operator=(wunique_ptr<T>&& e) noexcept;
	wunique_ptr<T>& operator=(std::nullptr_t p);


	explicit operator bool() const;
	T& operator*() const;
	T* operator->() const;

	T* Get() const;
	T* Release();
	void Reset(T* p);


	wunique_ptr(const wunique_ptr<T>& e) = delete;
	wunique_ptr<T>& operator=(const wunique_ptr<T>& e) = delete;

};


template<class T>
 wunique_ptr<T>::wunique_ptr()
{
	m_data = nullptr;
}


template<class T>
 wunique_ptr<T>::wunique_ptr(T* e)
{
	m_data = e;
}


 template <class T>
 wunique_ptr<T>::wunique_ptr(wunique_ptr<T>&& e) noexcept
				:m_data(e.m_data)
 {
	 e.m_data = nullptr;
 }


template<class T>
  wunique_ptr<T>::~wunique_ptr()
{
	delete m_data;
}


template<class T>
 wunique_ptr<T>& wunique_ptr<T>::operator=(wunique_ptr<T>&& e) noexcept
{
	 m_data = e.m_data;
	 e.m_data = nullptr;
	 return *this;
}


template<class T>
 wunique_ptr<T>& wunique_ptr<T>::operator=(std::nullptr_t p)
{
	m_data = p;
}


template<class T>
 T* wunique_ptr<T>::Get() const
{
	return m_data;
}


template <class T>
  wunique_ptr<T>::operator bool() const
{
	if (Get() != nullptr)
		return true;

	return false;
}


template <class T>
 T& wunique_ptr<T>::operator*() const
{
	return *m_data;
}


template <class T>
 T* wunique_ptr<T>::operator->() const
{
	return m_data;
}


template<class T>
 T* wunique_ptr<T>::Release()
{
	T* retValue = m_data;
	m_data = nullptr;
	return retValue;
}


template<class T>
 void wunique_ptr<T>::Reset(T* p)
{
	delete m_data;
	m_data = p;
}

