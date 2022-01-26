#pragma once
#include <iostream>
#include <exception>
#include <initializer_list>

typedef struct Node 
{
	struct Node* next;
	int data;
	Node(const int& data) : next(nullptr), data(data) {}
}Node;

class List
{
private:
	Node* head;
	int size;
public:
	List() : head(nullptr), size(0) {}
	List(const std::initializer_list<int>& dataList) : size(dataList.size()) {
		head = new Node(*(dataList.begin()));
		Node* tmpHead = head;
		for (auto it = dataList.begin() + 1; it < dataList.end(); it++) {
			Node* copyNode = new Node(*it);
			tmpHead->next = copyNode;
			tmpHead = tmpHead->next;
		}
	}
	List(const List& otherList) : size(otherList.size)  {
		std::cout << "Worked Copy Constructor\n";
		head = new Node(otherList.head->data);

		Node* tmpThisHead = head;//head had been already copyed
		Node* tmpOtherHead = otherList.head->next;//head had been already copyed

		for (int i = 0; i < otherList.size - 1; i++) {
			Node* copyNode = new Node(tmpOtherHead->data);
			tmpThisHead->next = copyNode;
			tmpThisHead = tmpThisHead->next;
			tmpOtherHead = tmpOtherHead->next;
		}
	} 
	List(List&& otherList) : head(otherList.head), size(otherList.size)
	{
		std::cout << "Worked Moveing Constructor\n";
		otherList.head = nullptr;
	}
	~List() {
		std::cout << "Object Destroyed\n";
		while (head) {
			Node* tmpNode = head;
			head = head->next;
			delete tmpNode;
		}
	}
	bool isEmpty() const {
		if (!head) return true;
		else return false;
	}
	int getSize() const { return size; }
	Node* findByData(const int& data) const;
	void pushBack(const int& data);
	bool addIntoPos(const int& data, const int& dataBefore);
	bool deleteByData(const int& data);
	void printList() const;

	List& operator += (const int& data) {
		pushBack(data);
		return *this;
	}
	List& operator -= (const int& data) {
		if (!deleteByData(data)) {
			std::cout << "Node not found!\n";
		}
		return* this;
	}
	friend std::ostream& operator << (std::ostream& out, const List& list);
};