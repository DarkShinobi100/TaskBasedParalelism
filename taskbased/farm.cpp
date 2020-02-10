#include "farm.h"

// FIXME - You may need to add #includes here (e.g. <thread>)

void Farm::add_task(Task *task)
{
	TaskQueue.push(task);
}

void Farm::run()
{
	// FIXME - Implement this
	for (int i = 0; i < std::thread::hardware_concurrency(); i++)
	{
		//create thread
		TaskThread.push_back(new thread(add_task, TaskQueue[i]));
		//add thread to vector
	}
}