#include "XThreadPool.h"
#include "XThread.h"
#include <thread>
#include <iostream>
#include "XTask.h"
using namespace std;

//�ַ��߳�
void XThreadPool::Dispatch(XTask *task)
{
	//��ѯ
	if (!task)return;
	int tid = (lastThread + 1) % threadCount;
	lastThread = tid;
	XThread *t = threads[tid];

	t->AddTask(task);

	//�����߳�
	t->Activate();


}
//��ʼ�������̲߳������߳�
void XThreadPool::Init(int threadCount)
{
	this->threadCount = threadCount;
	this->lastThread = -1;
	for (int i = 0; i < threadCount; i++)
	{
		XThread *t = new XThread();
		t->id = i + 1;
		cout << "Create thread " << i << endl;
		//�����߳�
		t->Start();
		threads.push_back(t);
		this_thread::sleep_for(10ms);
	}
}