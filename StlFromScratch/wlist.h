#pragma once
template <class T>

class wlist
{
	template <class T1>
	class Node
	{
	public:

		Node*	m_next;
		Node*	m_prev;
		T1			m_data;

		Node(T1 data = T1(), Node* next = nullptr, Node* prev = nullptr)
			: m_next (next)
			, m_prev (prev)
			, m_data (data)
		{

		}
	};

	Node<T>* m_head;
	Node<T>* m_tail;
	size_t m_size;


public:
	wlist();
	wlist(const wlist<T>& e);
	wlist(wlist<T>&& e);
	~wlist();

	void PushBack(const T& e);
	void PushFront(const T& e);
	void PopBack();
	void PopFront();
	void Clean();
	const T& Back() const;
	T& Back();

	const size_t Size() const;


};


template <typename T>
wlist<T>::wlist()
	:m_head	(nullptr)
	,m_tail	(nullptr)
	,m_size	(0)
{

}


template <typename T>
wlist<T>::wlist(const wlist<T>& e)
{
	//TODO
}


template <typename T>
wlist<T>::wlist(wlist<T>&& e)
{
	//TODO
}


template <typename T>
wlist<T>::~wlist()
{
	//TODO
}


template <typename T>
void wlist<T>::PushBack(const T& e)
{
	
	if (!m_head)
	{
		m_head = new Node<T>(e);
		m_tail = m_head;
		++m_size;
		return;
	}

	Node<T>* newNode = new Node<T>(e, nullptr, m_tail);
	m_tail = newNode;
	++m_size;
}


template <typename T>
const T& wlist<T>::Back() const
{
	return m_tail->m_data;
}

template <typename T>
T& wlist<T>::Back()
{
	return m_tail->m_data;
}

template <typename T>
void wlist<T>::Clean()
{
	Node<T> n = m_head;
	while (n != m_tail)
	{
		n->m_data.~T();
		n->m_prev = nullptr;
		n = n->m_next;
		n->m_next = nullptr;
	}
}


template <typename T>
void wlist<T>::PopBack()
{
	//TODO
}


template <typename T>
void wlist<T>::PushFront(const T& e)
{
	//TODO
}


template <typename T>
void wlist<T>::PopFront()
{
	//TODO
}



template <typename T>
const size_t wlist<T>::Size() const
{
	return m_size;
}