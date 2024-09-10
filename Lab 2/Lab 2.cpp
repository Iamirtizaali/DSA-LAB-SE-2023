#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
//
//class Node
//{
//public:
//	int data;
//	Node* next;
//	Node(int data=0);
//	~Node();
//
//private:
//
//};
//
//Node::Node(int data)
//{
//	this->data=data;
//	this->next = NULL;
//}
//
//Node::~Node()
//{
//}
//
//void insertAtHead(Node* &head, int data){
//	Node* n = new Node(data);
//	n->next = head;
//	head = n;
//}
//
//void insertAtTail(Node* &tail, int data){
//	Node* n = new Node(data);
//	tail->next = n;
//	tail = n;
//
//}
//
//void print(Node* head){
//	while(head!=NULL){
//		cout<<head->data<<"-->";
//		head = head->next;
//	}
//	cout<<endl;
//}
//
//void insertAtCenter(Node* &head, int idx, int d) {
//	
//	Node* temp = head;
//	int count = 0;
//	while (count<idx-1)
//	{
//		temp = temp->next;
//		count++;
//	}
//	Node* newNode = new Node(d);
//	newNode->next = temp;
//	temp->next = newNode;
//
//}
//
//void insertAtPosition(Node*& head, int data,int idx) {
//	int count = 0;
//	Node* temp = head;
//	Node* prev = head;
//	if (head==NULL)
//	{
//		Node* newNode = new Node(data);
//		head = newNode;
//		return;
//	}
//	while (temp->next!=NULL && count<idx-1)
//	{
//		prev = temp;
//		temp = temp->next;
//		count++;
//	}
//	if (temp->next==NULL && count<idx-2)
//	{
//		cout << "count is: " << count << endl;
//		cout << "Wrong value"<<endl;
//		return;
//	}
//	if (idx==1)
//	{
//		Node* newNode = new Node(data);
//		newNode->next = head;
//		head = newNode;
//		return;
//	}
//	if (temp->next==NULL)
//	{
//		Node* newNode = new Node(data);
//		temp->next = newNode;
//		return;
//	}
//
//	Node* newNode = new Node(data);
//	prev->next = newNode;
//	newNode->next = temp->next;
//
//}
//
//
//int main() {
//	Node* node1 = new Node(10);
//	cout<<node1->data<<endl;
//	cout<<node1->next<<endl;
//	Node* head=node1;
//	Node* tail=node1;
//	print(head);
//	insertAtHead(head, 20);
//	print(head);
//	insertAtTail(tail, 30);
//	print(head);
//	insertAtTail(tail, 60);
//	print(head);
//	insertAtPosition(head, 23, 5);
//	print(head);
//	return 0;
//}

class Node
{
	int value;
	Node* next;
public:
	Node(int value = 0) {
		this->value = value;
		this->next = NULL;
	};
	void setValue(int value) {
		this->value = value;
	}
	int getValue() {
		return value;
	}
	void setNext(Node* next) {
		this->next = next;
	}
	Node* getNext() {
		return this->next;
	}

private:

};

class List
{
	Node* head;
public:
	List() {
		this->head = NULL;
	};
	void insertAtStart(int value) {
		if (this->head == NULL)
		{
			Node* newNode = new Node(value);
			this->head = newNode;
			cout << "headaer value is " << head->getValue() << endl;
		}
		else
		{
			Node* newNode = new Node(value);
			newNode->setNext(head);
			head = newNode;
		}
	}
	void insertAtEnd(int value) {
		if (this->head == NULL)
		{
			Node* newNode = new Node(value);
			this->head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			Node* newNode = new Node(value);
			temp->setNext(newNode);
		}
	}
	/*void insertAtPosition(int value, int position) {
		if (head==NULL)
		{
			Node* newNode = new Node(value);
			head = newNode;
		}
		else
		{
			if (position==1)
			{
			Node* newNode = new Node(value);
			newNode->setNext(head);
			head = newNode;
			}
			int count = 0;
			Node* prev = head;
			Node* temp = head;
			while (temp->getNext()!=NULL && count<position-1)
			{
				prev = temp;
				temp=temp->getNext();
				count++;
			}
			if (temp->getNext() == NULL && count < position - 2)
			{
				cout << "Wrong value" << endl;
				return;

			}
			if (temp->getNext()==NULL && count<position-1)
			{
				Node* newNode = new Node(value);
				temp->setNext(newNode);
			}
			else
			{

				Node* newNode = new Node(value);
				newNode->setNext(temp);
				prev->setNext(newNode);
			}
		}
	}*/

	int getSize() {
		Node* temp = head;
		int count = 0;
		if (head==NULL)
		{
			return 0;
		}
		while (temp!=NULL)
		{
			temp = temp->getNext();
			count++;
		}
		return count;
	}
	void insertAtPosition(int value, int position) {
		if (position < 1) {
			cout << "Invalid position!" << endl;
			return;
		}

		Node* newNode = new Node(value);
		if (position == 1) {
			newNode->setNext(head);
			head = newNode;
			return;
		}

		Node* temp = head;
		int count = 0;  

		while (temp != NULL && count < position - 2) {
			temp = temp->getNext();
			count++;
		}

		if (temp == NULL) {
			cout << "Position out of bounds!" << endl;
			delete newNode;
			return;
		}
		newNode->setNext(temp->getNext());
		temp->setNext(newNode);
	}

	void displayList() {
		cout << "head is " << head << endl;
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->getValue() << "-->";
			temp = temp->getNext();
		}
		cout << endl;
	}
	void deleteNodebyIndex(int index) {
		if (index < 1) {
			cout << "Invalid index!" << endl;
			return;
		}

		Node* temp = head;
		if (index == 1 && head != NULL) {
			head = head->getNext();
			delete temp;
			return;
		}

		Node* prev = NULL;
		int count = 0;
		while (temp != NULL && count < index - 1) {
			prev = temp;
			temp = temp->getNext();
			count++;
		}

		if (temp == NULL) {
			cout << "Index out of bounds!" << endl;
			return;
		}
		prev->setNext(temp->getNext());
		delete temp;
	}
	void update(int index, int newValue) {
		if (index<1)
		{
			cout << "Wrong index" << endl;
		}
		Node* temp = head;
		int count = 0;
		while (temp!=NULL && count<index-1)
		{
			temp=temp->getNext();
			count++;
		}
		if (temp==NULL)
		{
			cout << "Wrong index\n";
			return;
		}
		else
		{
			temp->setValue(newValue);
			return;
		}
	}
	void sort() {
		if (head==NULL || head->getNext()==NULL)
		{
			return;
		}
		int size = getSize();
		cout << "the size of list is " << endl;
		Node* temp = head;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size-i-1; j++) {
				if (temp->getValue()>temp->getNext()->getValue())
				{
					int t = temp->getValue();
					temp->setValue(temp->getNext()->getValue());
					temp->getNext()->setValue(t);
				}
					temp = temp->getNext();
			}
			temp = head;
			
		}
	}
	bool search(int value) {
		if (head==NULL)
		{
			cout << "The list is empty" << endl;
			return false;
		}
		Node* temp = head;
		while (temp!=NULL)
		{
			if (temp->getValue() == value) {
				return 1;
			}
			temp = temp->getNext();
		}
		return 0;
	}

private:

};




int getValue() {
	int value = 0;
	cout << "Enter the value: ";
	cin >> value;
	return value;
}
int getIndex() {
	int idx = 0;
	cout << "Enter the index: ";
	cin >> idx;
	return idx;
}
int main() {
	List l1;
	do
	{
		cout << "Enter 1 to print list" << endl;
		cout << "Enter 2 to insert value at start" << endl;
		cout << "Enter 3 to insert value at end" << endl;
		cout << "Enter 4 to insert value at position" << endl;
		cout << "Enter 5 to delete value " << endl;
		cout << "Enter 6 to update value " << endl;
		cout << "Enter 7 to sort list " << endl;
		cout << "Enter 8 to get size of list " << endl;
		cout << "Enter 9 to search value in list " << endl;
		cout << "Enter 10 to Exit" << endl;
		cout << "Enter your choice: ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			l1.displayList();
			break;
		case 2:
			l1.insertAtStart(getValue());
			break;
		case 3:
			l1.insertAtEnd(getValue());
			break;
		case 4:
			l1.insertAtPosition(getValue(), getIndex());
			break;
		case 5:
			l1.deleteNodebyIndex(getIndex());
			break;
		case 6:
			l1.update(getIndex(), getValue());
			break;
		case 7:
			l1.sort();
			break;
		case 8:
			cout << "The size of list is " << (l1.getSize()) << endl;
			break;
		case 9:
			cout << ((l1.search(getValue())) ? "Value found" : "Value not found") << endl;
			break;
		case 10:
			exit(0);
			break;
		default:
			cout << "Wrong Choice" << endl;
			break;
		}
	} while (true);
	return 0;
}