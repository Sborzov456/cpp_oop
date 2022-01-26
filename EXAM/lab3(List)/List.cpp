#include "List.h"
void List::pushBack(const int& data)
{
	if (isEmpty())
		head = new Node(data);
	else {
		Node* addingNode = new Node(data);

		Node* tmpHead = head;
		while (tmpHead->next)
			tmpHead = tmpHead->next;
		tmpHead->next = addingNode;
	}
	size++;
}

Node* List::findByData(const int& data) const
{
	Node* tmpHead = head;
	while (tmpHead && tmpHead->data != data)
		tmpHead = tmpHead->next;
	return tmpHead;
}

bool List::deleteByData(const int& data)
{
	Node* nodeForDelete = findByData(data);
	if (!nodeForDelete)
		return false;

	if (nodeForDelete == head) {
		if (size == 1) {
			delete head;
			head = nullptr;
		}
		else {
			head = head->next;
			delete nodeForDelete;
		}
	}	
	else {
		Node* tmpHead = head;
		while (tmpHead->next != nodeForDelete)
			tmpHead = tmpHead->next;
		tmpHead->next = nodeForDelete->next;
		delete nodeForDelete;
	}
	size--;
	return true;
}

bool List::addIntoPos(const int& data, const int& dataBefore)
{
	Node* nodeBefore = findByData(dataBefore);
	if (!nodeBefore) {
		return false;
	}
	Node* nodeAfter = nodeBefore->next;

	Node* addingNode = new Node(data);

	nodeBefore->next = addingNode;
	addingNode->next = nodeAfter;
	size++;

	return true;
}

void List::printList() const
{
	if (isEmpty())
		std::cout << "List is empty\n";
	else {
		Node* tmpHead = head;
		while (tmpHead) {
			std::cout << tmpHead->data << " ";
			tmpHead = tmpHead->next;
		}
		std::cout << std::endl << "Number of nodes: " << size << std::endl;
	}
}

std::ostream& operator << (std::ostream& out, const List& list)
{
	list.printList();
	return out;
}