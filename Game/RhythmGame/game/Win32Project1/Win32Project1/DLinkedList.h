#pragma once

template <class T> class Node;
template <class T> class DLinkedList;
template <class T> class DLinkedListIterator;

template <class T>
class Node
{
public:
	T data;
	Node* next;
	Node* prev;

public:
	void InsertAfter(T data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->next = next;
		newNode->prev = this;

		if (0 != next)
		{
			next->prev = newNode;
		}
		next = newNode;
	}

	void InsertBefore(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = this;
		newNode->prev = prev;

		if (0 != prev)
		{
			prev->next = newNode;
		}
		prev = newNode;
	}

	void Delink()
	{
		if (0 != prev)
			prev->next = next;

		if (0 != next)
			next->prev = prev;
	}
};

template <class T>
class DLinkedList
{
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _count;

public:
	DLinkedList<T>()
	{
		_head = 0;
		_tail = 0;
		_count = 0;
	}

public:
	void Append(T data)
	{
		if (0 == _head)
		{
			_head = _tail = new Node<T>();
			_head->data = data;
			_head->next = 0;
			_head->prev = 0;
		}
		else
		{
			_tail->InsertAfter(data);
			_tail = _tail->next;
		}
		_count++;
	}

	void Prepend(T data)
	{
		if (0 == _head)
		{
			_head = _tail = new Node<T>();
			_head->data = data;
			_head->next = 0;
			_head->prev = 0;
		}
		else
		{
			_head->InsertBefore(data);
			_head = _head->prev;
		}
		_count++;
	}

	void RemoveHead()
	{
		if (0 != _head)
		{
			Node *node = _head->next;
			delete _head;
			_head = node;

			if (0 == _head)
			{
				_tail = 0;
			}
			else
			{
				_head->prev = 0;
			}

			_count--;
		}
	}

	void RemoveTail()
	{
		if (0 != _tail)
		{
			Node *node = _tail->prev;
			delete _tail;
			_tail = node;

			if (0 == _tail)
			{
				_head = 0;
			}
			else
			{
				_tail->next = 0;
			}

			_count--;
		}
	}

	Node<T>* GetHead()
	{
		return _head;
	}

	Node<T>* GetTail()
	{
		return _tail;
	}

	int GetCount()
	{
		return _count;
	}

	// ¹Ýº¹ÀÚ
public:
	DLinkedListIterator<T> GetIterator()
	{
		return DLinkedListIterator<T>(this, _head);
	}

	void Remove(DLinkedListIterator<T>& itr)
	{
		if (0 == itr.GetNode())
			return;

		Node<T>* node = itr.GetNode();
		if (node == _head)
			_head = _head->next;
		else if (node == _tail)
			_tail = _tail->prev;

		itr.forth();

		node->Delink();
		delete node;

		if (0 == _head)
			_tail = 0;

		_count--;
	}

	void InsertAfter(DLinkedListIterator<T>& itr, int data)
	{
		if (0 != itr.GetNode())
		{
			itr.GetNode()->InsertAfter(data);
			if (itr.GetNode() == _tail)
				_tail = itr.GetNode()->next;
			_count++;
		}
		else
		{
			Append(data);
		}
	}

	void InsertBefore(DLinkedListIterator<T>& itr, int data)
	{
		if (0 != itr.GetNode())
		{
			itr.GetNode()->InsertBefore(data);
			if (itr.GetNode() == _head)
				_head = itr.GetNode()->prev;
			_count++;
		}
		else
		{
			Prepend(data);
		}
	}
};

template <class T>
class DLinkedListIterator
{
private:
	DLinkedList<T>* _linkedList;
	Node<T>* _node;

public:
	DLinkedListIterator<T>(DLinkedList<T>* linkedList, Node<T>* node)
	{
		_linkedList = linkedList;
		_node = node;
	}

public:
	void begin()
	{
		if (0 != _linkedList)
		{
			_node = _linkedList->GetHead();
		}
	}

	void end()
	{
		if (0 != _linkedList)
		{
			_node = _linkedList->GetTail();
		}
	}

	void forth()
	{
		if (0 != _node)
		{
			_node = _node->next;
		}
	}

	void back()
	{
		if (0 != _node)
		{
			_node = _node->prev;
		}
	}

	bool valid()
	{
		if (0 != _node)
			return true;
		return false;
	}

	T item()
	{
		return _node->data;
	}

	Node<T>* GetNode()
	{
		return _node;
	}
};


