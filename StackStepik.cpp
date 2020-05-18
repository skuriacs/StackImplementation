#include <iostream>
class Stack_LL
{
	struct Node
	{
		int data;
		Node* next;
		Node(int val)
		{
			data = val;
			next = nullptr;
		}
		Node(int val, Node* node)
		{
			data = val;
			next = node;
		}
	};

private:
	// topPtr points to the top element of the stack
	Node* topPtr;

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
	/* Node *temp = topPtr;
	while (temp != nullptr)
	{
		Node *deleted = temp;
		temp = temp->next;
		delete deleted;
	}*/
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
		Node* node = new Node(newItem);
		topPtr = node;
		return;
	}
	Node* temp = topPtr;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = new Node(newItem);
}

void Stack_LL::pop()
{
	Node* temp = topPtr;
	topPtr = topPtr->next;
	delete temp;
}

int Stack_LL::peek() const
{
	return topPtr->data;
}
void Stack_LL::print()
{
	if (topPtr == nullptr)
	{
		return;
	}
	Node* temp = topPtr;
	while (temp != nullptr)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
	}
}
int main()
{
	Stack_LL list;
	list.push(5);
	list.push(6);
	list.push(12);
	list.print();
	std::cout << list.peek();
	std::cin.get();
}
