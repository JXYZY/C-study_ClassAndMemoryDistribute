#pragma once

struct Item
{
	int money;
	struct Item* pNext;
};

class Queue
{
public:
	Queue(int queuecount);
	~Queue();
	bool isempty();
	bool isFull();
	void enterQueue(const int& money);
	void deQueue(int& money);
private:
	Queue(const Queue& queue);
	Queue& operator=(const Queue& queue);
private:
	const int m_MaxQueueCount = 0; //��������ڲ�Ԫ�ص��������
	int m_currentItems;  // ��ǰԪ�صĸ���
	struct Item* m_frontPtr;
	struct Item* m_lastPtr;



};