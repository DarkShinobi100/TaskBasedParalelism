#include "farm.h"

// FIXME - You may need to add #includes here (e.g. <thread>)

void Farm::add_task(Task *task)
{
	TaskQueue.push(task);
}


void Farm::run()
{
	//std::vector<std::thread> TaskThread;
	// FIXME - Implement this
	for (int i = 0; i < std::thread::hardware_concurrency(); i++)
	{
		//create thread
		//add thread to vector
		TaskThread.push_back(new thread());
	}

	thread worker_functor([=] {
		while (!TaskQueue.empty())
		{
			lock_threads.lock();
			Task* task = TaskQueue.front();
			TaskQueue.pop();
			lock_threads.unlock();
			task->run();
			delete task;
		}
	});
}