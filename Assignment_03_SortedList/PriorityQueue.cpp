#include "PriorityQueue.h"



template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
	front = nullptr;
	rear = nullptr;
	length = 0;
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
	make_empty();
}

template<class ItemType>
bool PriorityQueue<ItemType>::Enqueue(ItemType newItem)
{
	if (IsFull())
		return false;

	NodeType* newNode = new NodeType;
	newNode->info = newitem;
	NodeType* curr = front;
	NodeType* prev = nullptr;
	bool posFound = false;
	while (curr != nullptr && !posFound) {
		if (curr->info < newItem) {
			prev = curr;
			curr = curr->next;
		}
		else {
			posFound = true;
			newNode->next = curr;
			if (prev == nullptr) {
				front = newNode;
			}
			else {
				prev->next = newNode;
			}
		}
	}
	if (!posFound)
	{
		posFound = true;
		newNode->next = curr;
		if (prev == nullptr) {
			front = newNode;
		}
		else {
			prev->next = newNode;
			
		}
		rear = newNode;
	}
	length++;
}

template<class ItemType>
void PriorityQueue<ItemType>::Dequeue(ItemType item)
{
	if (IsEmpty()) {
		throw EmptyQueue();
	}
	else {
		NodeType* dequeuedNode = front;

		front = front->next;
		item = dequeuedNode->info;

		if (front == nullptr)
			rear = nullptr;

		delete dequeuedNode;
		length--;
	}
}

template<class ItemType>
bool PriorityQueue<ItemType>::is_full()
{
	try {
		NodeType* newNode = new NodeType();
		delete newNode;
	}
	catch (const std::bad_alloc&) {
		return true;
	}
	return false;
}

template<class ItemType>
void PriorityQueue<ItemType>::make_empty()
{
	ItemType dummyItem;
	while (!IsEmpty())
		Dequeue(dummyItem);
}

template<class ItemType>
bool PriorityQueue<ItemType>::is_empty()
{
	return ((currentSize == 0) && (front == nullptr) && (rear == nullptr));
}

template<class ItemType>
int PriorityQueue<ItemType>::get_length()
{
	return length;
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::Top()
{
	return front->info;
}


