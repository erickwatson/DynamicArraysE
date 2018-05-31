#pragma once
#include "includes.h"
#include <exception>


template <typename T>
class LinkedList
{
private:
	
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;
		// Hi
	
		Node() {
			next = nullptr;
			prev = nullptr;
		}

		Node(const T& value) {
			next = nullptr;
			prev = nullptr;
			data = value;
		}

		~Node() {

		}
	};

public:


	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	~LinkedList() {
		clear();
	}
	
	
	// Makes Note
	/// Makes Note but DARK 
	//// Makes Note also
	// <[Makes a box around note]>
	/// <[Makes a GREY box around note]>


	void pushFront(const T& value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		if (head != nullptr) {
			head->prev = newNode;
		}
	
		head = newNode;

		if (tail == nullptr) {
			tail = head;
		}

	}

	void pushBack(const T& value) {
		Node* newNode = new Node(value);
		newNode->prev = tail;
		if (tail != nullptr) {
			tail->next = newNode;
		}

		tail = newNode;

		if (head == nullptr) {
			head = tail;
		}

	}

	T first() {
		if (head != nullptr) {
			return head->data;
		}
		else {
			throw exception("INVALID DATA");
		}

	}

	T last() {
		if (tail != nullptr) {
			return tail->data;
		}
		else {
			throw exception("NO END!");
		}
	}

	unsigned int count() {
		unsigned int result = 0;
		Node* node = head;
		while (node != nullptr) {
			result++;
			node = node->next;
		}
		return result;
	}

	void remove(Node* node) {
		if (node->prev == nullptr) {
			head = node->next;
		}
		else
			(node->prev)->next = node->next;
		
		if (node->next == nullptr) {
			tail = node->prev;
		}
		else (node->next)->prev = node->prev;
		
		delete node;
	}

	
	void searchAndDestroy(const T& value) {
		Node* target = find(value);
		if (target != nullptr) {
			remove(target);
		}
	}

	// To-do, add a function to find a value
	Node* find(const T& value) {
		Node* current = head;
		while (current != nullptr) {
			if (current->data == value) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

	void popBack() {
		if (tail == nullptr) {
			return;
		}
		// Make sure the Node before is not pointing to the tail
		// Tail is about to become null
		if (tail->prev != nullptr) {
			tail->prev->next = nullptr;
		}
		// Keep a temp reference to the old tail so we can delete it later
		Node* oldTail = tail;


		
		// Make tail into "previous"
		tail = tail->prev;

		// Check if there's a head, in case we pop all the tails off
		if (tail == nullptr) {
			head = nullptr;
		}

		// Delete temp reference
		delete oldTail;

		
	}

	void popFront() {
		if (head == nullptr) {
			return;
		}
		// Make sure the Node is not pointing to the head
		// Head is about to become null
		if (head->next != nullptr) {
			head->next->prev = nullptr;
		}
		// Keep a temp reference to the old head so we can delete it later
		Node* oldHead = head;

		// Make tail into "next"
		head = head->next;

		// Check if there's a tail, in case we pop all the heads off
		if (head == nullptr) {
			tail = nullptr;
		}
		
		// Delete temp reference
		delete oldHead;
	}

	bool empty() {
		return (head == nullptr || tail == nullptr);

	}

	void clear() {
		while (!empty()) {
			popBack();
		}
	}

	void toString() {
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << ": ";
			current = current->next;
		}
		cout << endl;
	}

	void insert(const T& value, int searchInt) {
		
		Node* target = new Node();
		target->data = value;
		target->next = nullptr;
		if (searchInt == 1) {
			target->next = head;
			head = target;
			return;
			}
		
		Node* newData = head;
		for (int i = 0; i < searchInt-2; i++) {
			newData = newData->next;
		}
		target->next = newData->next;
		newData->next = target;
		/*
		void pushFront(const T& value) {
			Node* newNode = new Node(value);
			newNode->next = head;
			if (head != nullptr) {
				head->prev = newNode;
			}

			head = newNode;

			if (tail == nullptr) {
				tail = head;
			}

		}
		*/

		// Iterate over list from head to tail (ie, Item->next)
		// If sorting condition met (eg, value < Item->data)
		//   Insert new Node(value) between Item and Item->prev
		//   return

		// If reached this point then PushBack(value) (because ran out of things to check)

	}

protected:
	Node* head;
	Node* tail;
};

