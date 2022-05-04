#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;

	Node(int value, Node* next)
	{
		this->value = value;
		this->next = next;
	}
};

class linkedList
{
private:
	Node* head;
	Node* tail;
public:
	linkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void print()
	{
		Node* current = head;
		if (head == nullptr)
		{
			return;
		}

		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
	}

	void push_back(int val)
	{
		if (tail == nullptr)
		{
			head = new Node(val, nullptr);
			tail = head;
		}
		else
		{
			tail->next = new Node(val, nullptr);
			tail = tail->next;
		}
	}

	void push_front(int val)
	{
		if (head == nullptr)
		{
			head = new Node(val, nullptr);
			tail = head;
		}
		else
		{
			head = new Node(val, head);
		}
	}
	
	void insertAtPosition(int position, int val)
	{
		if (position < 0)
		{
			cout << "Invalid position" << endl;
			return;
		}

		if (position == 0)
		{
			push_front(val);
			return;
		}

		Node* current = head;

		for (int i = 0; i < position - 1; i++)
		{
			if (current->next == nullptr)
			{
				cout << "Invalid position" << endl;
				return;
			}
			current = current->next;
		}
		current->next = new Node(val, current->next);
	}

	void pop_front()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void pop_back()
	{
		Node* current = head;

		while (current->next != tail)
		{
			current = current->next;
		}
		Node* temp = tail;
		tail = current;
		delete temp;
		current->next = nullptr;
	}
	
	void removeAtPosition(int position)
	{
		if (position < 0)
		{
			cout << "Invalid position" << endl;
		}

		if (position == 0)
		{
			pop_front();
			return;
		}

		Node* prev = nullptr;
		Node* current = head;

		for (int i = 0; i < position - 1; i++)
		{
			if (current->next == nullptr)
			{
				cout << "Invalid position" << endl;
				return;
			}
			prev = current;
			current = current->next;
		}

		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
	}

	void clear()
	{
		if (head == nullptr)
		{
			return;
		}

		Node* prev = head;
		Node* current = head->next;

		while (current != nullptr)
		{
			delete prev;

			prev = current;
			current = current->next;
		}
		delete prev;
	}
	
	void reverse()
	{
		Node* prev = head;
		Node* current = head->next;
		Node* nextNode = head->next->next;

		while (nextNode != nullptr)
		{
			current->next = prev;

			prev = current;
			current = nextNode;
			nextNode = nextNode->next;
		}

		current->next = prev;

		head->next = nullptr;

		swap(head, tail);
	}
};

int main()
{
	linkedList list;
	list.push_back(5);
	list.push_front(3);
	list.push_front(3);

	list.push_front(8);
	list.push_back(9);
	list.insertAtPosition(0, 2);
	
	list.pop_back();
	list.pop_front();

	list.removeAtPosition(11);
	list.print();

	list.reverse();
	cout << endl;
	list.print();
	return 0;
}
