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
	const int m_MaxQueueCount = 0; //允许队列内部元素的最大数量
	int m_currentItems;  // 当前元素的个数
	struct Item* m_frontPtr;
	struct Item* m_lastPtr;



};