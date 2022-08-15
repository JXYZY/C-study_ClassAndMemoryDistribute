#include "Queue.h"

Queue::Queue(int coutqueue)
	:m_MaxQueueCount(coutqueue)
	,m_currentItems(0)
{
	m_frontPtr = nullptr;
	m_lastPtr = nullptr;
}

Queue::~Queue()
{
	while (m_frontPtr != nullptr)
	{
		Item* temp = m_frontPtr;
		m_frontPtr = m_frontPtr->pNext;
		delete temp;
	}

}

bool Queue::isempty()
{
	return m_currentItems == 0 ? true : false;
}

bool Queue::isFull()
{
	return m_currentItems == m_MaxQueueCount ? true : false;
}

void Queue::enterQueue(const int & money)
{
	//入队考虑是否满
	if (isFull())
		return;
	//不满的情况
	Item * add = new Item;
	add->money = money;
	add->pNext = nullptr;
	m_currentItems++;  //记录元素个数
	if (m_frontPtr == nullptr)
		m_frontPtr = add;
	else
		m_lastPtr->pNext = add;
	m_lastPtr = add;
	return;
}

void Queue::deQueue(int & money)
{
	//队列为空
	if (isempty())
		return;
	money = m_frontPtr->money;
	Item* tempPtr = m_frontPtr;
	m_frontPtr = m_frontPtr->pNext;
	delete tempPtr;
	m_currentItems--;
	if (m_currentItems == 0)
	{
		m_lastPtr = nullptr;
	}
	return;
}

Queue::Queue(const Queue& queue)
{

}

Queue& Queue::operator=(const Queue& queue)
{
	return *this;
}