#include "LinkedQueue.hpp" // ADT Queue operations
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

void queueTester(std::shared_ptr<QueueInterface<std::string>> queuePtr);
void copyConstructorTester(std::shared_ptr<QueueInterface<std::string>> queuePtr);

int main()
{
	std::shared_ptr<QueueInterface<std::string>> queuePtr;

	queuePtr = std::make_shared<LinkedQueue<std::string>>();

	//copyConstructorTester(queuePtr);
	queueTester(queuePtr);

	return 0;
}  // end main

void queueTester(std::shared_ptr<QueueInterface<std::string>> queuePtr)
{
	std::string items[] = { "one", "two", "three", "four", "five", "six" };
	
	std::cout << "isEmpty(): " << queuePtr->isEmpty() 
		<< " [should be 1]" << std::endl << std::endl;
	
	for (int i = 0; i < 6; i++)
	{
		std::cout << "enqueue(" << items[i] << "): "
			<< queuePtr->enqueue(items[i]) << " [should be 1]" << std::endl;

	}

	std::cout << std::endl << "isEmpty(): " << queuePtr->isEmpty()
		<< " [should be 0]" << std::endl << std::endl;

	for (int i = 0; i < 6; i++)
	{
				try
		{
			std::cout << "peekFront(): " << queuePtr->peekFront() 
				<< " [should be " << items[i] << "]" << std::endl;
		}
		catch (std::runtime_error e)
		{
			std::cout << e.what() << std::endl;
		}  // end try/catch

		std::cout << "isEmpty(): " << queuePtr->isEmpty()
			<< " [should be 0]" << std::endl;

		std::cout << "dequeue(): " << queuePtr->dequeue() 
			<< " [should be 1]" << std::endl << std::endl;
	}

	std::cout << "isEmpty(): " << queuePtr->isEmpty()
		<< " [should be 1]" << std::endl;
	std::cout << "dequeue(): " << queuePtr->dequeue()
		<< " [should be 0]" << std::endl << std::endl;

	try
	{
		std::cout << "peekFront() with an empty queue should yield exception: " 
			<< std::endl;
		queuePtr->peekFront(); // throws exception
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}  // end try/catch

}  // end queueTester

void copyConstructorTester(std::shared_ptr<QueueInterface<std::string>> queuePtr)
{
	std::string items[] = { "zero", "one", "two", "three", "four", "five" };
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Adding " << items[i] << std::endl;
		bool success = queuePtr->enqueue(items[i]);
		if (!success)
			std::cout << "Failed to add " << items[i] << " to the queue.\n";
	}
	std::shared_ptr<QueueInterface<std::string>> copyOfQueue(queuePtr);

	std::cout << "Queue contains, from front to back, zero one two three four five.\n";

	std::cout << "Original queue contains, from front to back,";
	for (int i = 0; i < 6; i++)
	{
		std::cout << " " << queuePtr->peekFront();
		queuePtr->dequeue();
	}
	std::cout << "." << std::endl << std::endl;


	std::cout << "Copy of queue contains, from front to back, ";
	for (int i = 0; i < 6; i++)
	{
		try {
			std::cout << " " << copyOfQueue->peekFront();
			copyOfQueue->dequeue();
		}
		catch (std::runtime_error e)
		{
			std::cout << e.what() << std::endl;
		}  // end try/catch
	}
	std::cout << "." << std::endl;

}  // end copyConstructorTester