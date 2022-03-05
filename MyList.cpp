

#include <iostream>
using namespace std;


template <typename T>
class List
{
public:
	List();
	~List();
	void push_back(T date);
	int getSize() { return Size; }
	T& operator[](const int index);

private:

	template <typename T>
	class Node
	{
	public:
		Node *pNext;
		T date;

		Node(T date = T(), Node *pNext = nullptr) {

			this->pNext = pNext;
			this->date = date;
		}

	};
	int Size;
	Node<T> *head;

};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T date)
{
	if (head == nullptr)
	{
		head = new Node<T>(date);
	}
	else 
	{
		Node<T> *current = this->head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}

		current->pNext= new Node<T>(date);
	}

	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index) {
			return current->date;
		}
		current = current->pNext;
		counter++;
	}
	
}




int main()
{
	List<int> A;
	A.push_back(5);
	A.push_back(10);
	cout << A.getSize() << endl;
	cout << A[1] << endl;

	return 0;
}

