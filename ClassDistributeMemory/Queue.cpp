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
	//��ӿ����Ƿ���
	if (isFull())
		return;
	//���������
	Item * add = new Item;
	add->money = money;
	add->pNext = nullptr;
	m_currentItems++;  //��¼Ԫ�ظ���
	if (m_frontPtr == nullptr)
		m_frontPtr = add;
	else
		m_lastPtr->pNext = add;
	m_lastPtr = add;
	return;
}

void Queue::deQueue(int & money)
{
	//����Ϊ��
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