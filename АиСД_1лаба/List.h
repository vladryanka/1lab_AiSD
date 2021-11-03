#include <iostream>

using namespace std;

class List
{
public:

	List(int element) { //creating a constructor with variables
		Node* buffer = new Node; // Create temporary node
		buffer->element = element;
		buffer->next = tail;
		head = buffer;
		tail = buffer;
	}

	List() // default constructor
	{
		Node* buffer = new Node; // Create temporary node
		buffer->next = NULL;
		buffer->element = NULL;
		head = tail = NULL;
	}
	~List() { // destructor
		clear();
	}

	void Print() // additional function for output
	{
		Node* buffer = head;
		cout << "List: ";
		while (buffer != NULL)
		{
			cout << buffer->element << " ";
			buffer = buffer->next;
		}
		cout << endl;
	}

	void push_back(int element) // addition in the end of list
	{
		Node* buffer = head;
		if (buffer->element == NULL)
		{
			buffer->element = element;
			head = buffer;
		}
		else
		{
			while (buffer->next != NULL)
			{
				buffer = buffer->next;
			}
			Node* penultimate = buffer;
			Node* buffer1 = new Node;
			penultimate->next = buffer1;
			buffer1->next = NULL;
			buffer1->element = element;
			tail = buffer1;
		}
	}
	void push_front(int element) // addition in the beggining of list
	{
		Node* buffer = new Node;
		int index = get_size();
		if (index != 0)
		{
			buffer->next = head;
			head = buffer;
			buffer->element = element;
		}
		else
		{
			buffer->element = element;
			buffer->next = NULL;
			head = tail = buffer;
		}
	}
	void pop_back() // delete last element
	{
		Node* buffer = head;
		int index = get_size();
		Node* penultimate = NULL;
		if (index == 0)
		{
			throw invalid_argument("List is empty. Deletion is not possible");
		}
		else {

			if (index == 1)
			{
				delete(buffer);
				head = tail = nullptr;
			}
			else {
				while (buffer->next != NULL)
				{
					penultimate = buffer;
					buffer = buffer->next;
				}
				buffer->element = NULL;
				delete(buffer);
				if (penultimate != NULL)
				{
					penultimate->next = NULL;
					tail = penultimate;
				}
			}
		}
	}

	void pop_front() // delete first element
	{
		int index = get_size();
		if (index != 0)
		{
			Node* buffer = head;
			if (index == 1)
			{
				delete (buffer);
				head = tail = nullptr;
			}
			else
			{
				head = buffer->next;
				delete(buffer);
			}
		}
		else
		{
			throw invalid_argument("List is empty. Deletion is not possible");
		}
	}


	void insert(int number, int element) // insert element with index
	{
		int index = get_size();
		int check = index;
		if (number <= index && number > 0)
		{
			Node* buffer = head;
			index = 1;
			Node* penultimate = head;
			while (index != number)
			{
				penultimate = buffer;
				buffer = buffer->next;
				index++;
			}
			Node* buffer1 = new Node;
			if (index == 1)
			{
				buffer1->element = element;
				buffer1->next = buffer;
				head = buffer1;
			}
			else
			{
				buffer1->element = element;
				buffer1->next = buffer;
				penultimate->next = buffer1;
			}
		}
		else
		{

			//throw out_of_range("incorrect index");
		}
	}

	int at(int number) // getting an element by index
	{
		Node* buffer = head;
		Node* buffer1 = head;
		int check;
		int index = get_size();
		if (number > index || number <= 0)
		{
			throw out_of_range("Incorrect index");
		}
		else
		{
			index = 0;
			while (index != number)
			{
				buffer1 = buffer;
				buffer = buffer->next;
				index++;
			}
			check = buffer1->element;
		}
		return check;
	}
	void remove(int number) // deleting an element by index
	{
		int index = get_size();
		if (number <= index && number > 0)
		{
			if (number == 1)
			{
				pop_front();
			}
			else
			{
				if (number == index) pop_back();
				else
				{
					Node* buffer = head;
					Node* penultimate = NULL;
					index = 1;
					while (index != number)
					{
						penultimate = buffer;
						buffer = buffer->next;
						index++;
					}
					penultimate->next = buffer->next;
					delete (buffer);
				}
			}
		}
		else
		{
			throw out_of_range("Incorrect index");
		}
	}

	size_t get_size() // getting the size of list
	{
		Node* buffer = head;
		int index = 0;
		while (buffer != NULL)
		{
			index++;
			buffer = buffer->next;
		}
		if (head == NULL)
		{
			index = 0;
		}
		return index;
	}
	void clear()// delete all elements of the list
	{
		Node* buffer = head;
		Node* penultimate = head;
		while (buffer != tail)
		{
			penultimate = buffer->next;
			delete (buffer);
			buffer = penultimate;
		}
		head = tail = NULL;
	}
	void set(int element, int number) // replacing the list element by index with the passed element
	{
		int index = get_size();
		if (number > index || number <= 0)
		{
			throw out_of_range("Incorrect index");
		}
		else
		{
			Node* buffer = head;
			index = 1;
			while (index != number)
			{
				buffer = buffer->next;
				index++;
			}
			buffer->element = element;
		}
	}
	bool isEmpty()// test on empty list
	{
		bool answer = false;
		int index = get_size();
		if (index == 0)
		{
			answer = true;
			cout << "List is empty" << endl;
		}
		else cout << "List isn't empty" << endl;
		return answer;
	}


	void reverse() // the function reverses the order of the elements in the list
	{
		Node* buffer = head;
		Node* penultimate = tail;
		int buffernew; int count = 1;
		int index = get_size();
		for (int i = 1; i <= index; i++)
		{
			buffernew = buffer->element;
			penultimate = head;
			while (count != index)
			{
				penultimate = penultimate->next;
				count++;
			}
			buffer->element = penultimate->element;
			penultimate->element = buffernew;
			index--;
			buffer = buffer->next;
			count = 1;
		}
	}

	friend ostream& operator << (ostream& stream, const List& list); // operator overloading



private:
	class Node { // creating new class
	public:
		int element; // value of element
		Node* next; // pointers to next element and previous element
	};
	Node* tail; Node* head;

};
ostream& operator << (ostream& stream, const List& list) // for output
{
	List::Node* print = list.head;
	while (print != NULL) {
		stream << print->element << " ";
		print = print->next;
	}
	cout << endl;
	return stream;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Creating a list" << endl;
	List variable(8);
	cout << variable << endl;
	cout << "fill in the list. add 5" << endl;
	variable.push_back(5);
	cout << variable;
	cout << "getting an element by index" << endl;
	try
	{
		cout << variable.at(1);
	}
	catch (const out_of_range error)
	{
		cout << error.what();
	}
	cout << "Add 2 elements in list" << endl;
	variable.push_front(6);
	variable.push_front(1);
	cout << "List: " << variable << endl;
	cout << "check this operation again" << endl;
	try
	{
		cout << variable.at(1);
	}
	catch (const out_of_range error)
	{
		cout << error.what();
	}
	cout << "Size of list is: " << endl;
	cout << variable.get_size() << endl;

	variable.pop_back();
	cout << "delete last element" << endl << "List: " << variable << endl;
	variable.pop_front();
	cout << "delete first element" << endl << "List: " << variable << endl;
	variable.insert(2, 9);
	cout << "insert the list element by index with the passed element" << endl << "List: " << variable << endl;
	cout << "replacing the list element by index with the passed element" << endl;
	variable.set(5, 2);
	cout << "List: " << variable << endl;
	variable.push_back(7);
	cout << "ad an element in the end of list" << endl << "List: " << variable << endl;
	variable.reverse();
	cout << "reverse the list" << endl << "List: " << variable << endl;

	variable.remove(1);
	cout << "deleting an element by index" << endl << "List: " << variable << endl;
	cout << "clear the list" << endl;
	variable.clear();
	variable.isEmpty();

	return 0;
}
