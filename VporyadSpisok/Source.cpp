#include <iostream>

class List
{
private:
	bool Empty = true;

public:

	struct Node
	{
		int Value;
		Node* Next;
		Node() = default;
		Node(int value, Node* next)
		{
			Value = value;
			Next = next;
		}
	};

	Node* Root;

	void Insert(int value) 
	{
		if (Empty)
		{
			Root->Value = value;
			Root->Next = nullptr;
			Empty = false;
		}
		else
		{
			if (Root->Next == nullptr)
			{
				if (value >= Root->Value)
				{
					Node* temp = new Node(value, nullptr);
					Root->Next = temp;
				}
				else
				{
					Node* temp = new Node(Root->Value, Root);
					Root->Value = value;
					Root->Next = nullptr;
				}
			}
			else
			{
				Node* current = Root;
				Node* prev = nullptr;
				do
				{
					if (value <= current->Value)
					{
						Node* temp = new Node(value, current);
						if (prev != nullptr)
							prev->Next = temp;
						else 
							Root = temp;
						return;
					}
					prev = current;
					current = current->Next;
				}while (current != nullptr);
				Node* temp = new Node(value, nullptr);
				prev->Next = temp;
			}
		}
	}

	void Print()
	{
		auto current = Root->Next;
		std::cout << Root->Value << std::endl;
		while (current != nullptr)
		{
			std::cout << current->Value << std::endl;
			current = current->Next;
		}
	}

	//create empty
	List()
	{
		Root = new Node();
		Root->Next = nullptr;
		Empty = true;
	}

};

int main()
{
	List list = List();
	list.Insert(14);
	list.Insert(2);
	list.Insert(13);
	list.Insert(15);
	list.Insert(92);
	list.Insert(6);
	list.Print();
	system("pause");
}

