#include <iostream>
#include <bits/stdc++.h>
class Stack_LL
{
	struct Node
	{
		int data;
		Node *next;
		Node(int val)
		{
			data = val;
			next = nullptr;
		}
		Node(int val, Node *node)
		{
			data = val;
			next = node;
		}
	};

private:
	// topPtr points to the top element of the stack
	Node *topPtr;

public:
	Stack_LL();
	~Stack_LL();

	bool isEmpty() const;
	void push(int newItem);
	void pop();
	int peek() const;
	void print();
};

Stack_LL::Stack_LL()
{
	topPtr = nullptr;
}

Stack_LL::~Stack_LL()
{
	Node *temp = topPtr;
	while (temp != nullptr)
	{
		Node *deleted = temp;
		temp = temp->next;
		delete deleted;
	}
}

bool Stack_LL::isEmpty() const
{
	if (topPtr == nullptr)
		return true;
	return false;
}

void Stack_LL::push(int newItem)
{
	if (topPtr == nullptr)
	{
		Node *node = new Node(newItem);
		topPtr = node;
		return;
	}
	Node *temp = topPtr;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = new Node(newItem);
}

void Stack_LL::pop()
{
	if (topPtr->next = nullptr)
	{
		delete topPtr;
		return;
	}
	Node *temp = topPtr;
	while (temp->next->next != nullptr)
		temp = temp->next;
	Node *deleted = temp->next;
	temp->next = nullptr;
	delete deleted;
}

int Stack_LL::peek() const
{
	Node *temp = topPtr;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	return temp->data;
}
void Stack_LL::print()
{
	if (topPtr == nullptr)
	{
		return;
	}
	Node *temp = topPtr;
	while (temp != nullptr)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
	}
}
bool inLanguage(const char *theString)
{
	std::stack<char> s;
	while (*theString != '\0')
	{
		s.push(*theString);
		theString++;
	}
	int aCount = 0;
	int bCount = 0;
	while (!s.empty())
	{
		char temp = s.top();
		std::cout << temp;
		if (temp != 'A' && temp != 'B')
			return false;
		if (temp == 'A')
			aCount++;
		else
			bCount++;
		s.pop();
	}
	std::cout << aCount << bCount;
	return aCount == bCount;
}
int main()
{
	const char *x = "ABBA";
	std::cout << inLanguage(x);
}