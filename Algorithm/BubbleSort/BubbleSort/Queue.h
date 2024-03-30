#pragma once

#include <list>
template <typename T>
class Queue
{
public:
	void Push(T item)
	{
		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_back();
	}

	T Front()
	{
		return _list.front();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		int size = Size();
		return size == 0;
	}

private:
	list<T> _list;
};