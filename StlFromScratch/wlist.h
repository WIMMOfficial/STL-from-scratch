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
		T1		m_data;

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
	void Show();  //for debugging purposes
	void Swap(wlist<T>& l);
	const T& Back() const;
	T& Back();
	wlist<T>& operator=(const wlist<T>& e);
	wlist<T>& operator=(wlist<T>&& e);

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
	if (e.m_head == nullptr)
	{
		m_head = m_tail = nullptr;
	}

	else
	{
		m_head = new Node<T>(e.m_head->m_data, e.m_head->m_next, e.m_head->m_prev);
		Node<T>* tmp = e.m_head->m_next;
		Node<T>* tmpCurrent = m_head;

		while (tmp != nullptr)
		{
			tmpCurrent->m_next = new Node<T>(tmp->m_data, nullptr, tmpCurrent);
			tmp = tmp->m_next;
			tmpCurrent = tmpCurrent->m_next;
		}

		m_tail = tmpCurrent;
	}

}


template <typename T>
wlist<T>::wlist(wlist<T>&& e)
{
	e.Swap(*this);
}


template <typename T>
wlist<T>::~wlist()
{
	Clean();
}


template <typename T>
void wlist<T>::PushBack(const T& e)
{
	
	Node<T>* newNode = new Node<T>(e, nullptr, m_tail);

	if (!m_head)
	{
		m_head = newNode;
		m_tail = m_head;
		
	}

	else
	{
		m_tail->m_next = newNode;
		m_tail = newNode;
	}

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
	Node<T>* n = m_head;
	while (n != m_tail)
	{
		n->m_data.~T();
		n = n->m_next;
		delete n->m_prev;
	}

	delete n;
	m_size = 0;
}


template<typename T>
void wlist<T>::Show()
{
	Node<T>* n = m_head;

	while (n != nullptr)
	{
		std::cout << n->m_data << " ";
		n = n->m_next;
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
void wlist<T>::Swap(wlist<T>& l)
{
	using std::swap;

	swap(m_head, l.m_head);
	swap(m_tail, l.m_tail);
	swap(m_size, l._size);
}


template <typename T>
const size_t wlist<T>::Size() const
{
	return m_size;
}


template <typename T>
wlist<T>& wlist<T>::operator=(const wlist<T>& e)
{
	//TODO
}


template <typename T>
wlist<T>& wlist<T>::operator=(wlist<T>&& e)
{
	//TODO
}