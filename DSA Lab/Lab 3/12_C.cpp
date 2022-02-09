//12
//12
//12
#include <iostream>
#include <cmath> //Used For Power Function to evaluate Postfix
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class Linkedlist
{
private:
	Node *head;
	int Listlen;

public:
	Linkedlist()
	{
		head = NULL;
		Listlen = 0;
	}
	int Length()
	{
		return this->Listlen;
	}
	void InsertNode(int data, int position)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			newNode->next = NULL;
			head = newNode;
		}
		else if (position == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			Node *temp = head;
			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
				{
					printf("\ncan't insert as position is out of range\n");
					return;
				}
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		Listlen++;
	}
	void PrintList()
	{
		Node *temp = head;
		if (head == NULL)
		{
			cout << "List empty" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void DeleteNode(int position)
	{
		Node *temp1 = head, *temp2 = NULL;
		if (this->Listlen == 0)
		{
			cout << "List empty!" << endl;
			return;
		}
		if (this->Listlen <= position)
		{
			cout << "Index out of range!"
				 << endl;
			return;
		}
		if (position == 0)
		{
			head = head->next;
			delete temp1;
			return;
		}
		while (position-- > 0)
		{

			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;

		delete temp1;
		this->Listlen--;
		return;
	}
	Node *Returnhead() { return head; }
};
class Stack
{
private:
	Linkedlist stacklist;
	int len;

public:
	Stack()
	{
		Linkedlist stacklist = Linkedlist();
		len = 0;
	}
	void Push(char num)
	{
		stacklist.InsertNode(num, 0);
		len++;
	}
	char Pop()
	{
		char firstelement = stacklist.Returnhead()->data;
		stacklist.DeleteNode(0);
		len--;
		return firstelement;
	}
	char Top()
	{
		if (IsEmpty())
		{
			printf("Stack Is Empty!\n");
			return 0;
		}
		return stacklist.Returnhead()->data;
	}
	bool IsEmpty()
	{
		if (stacklist.Returnhead() == NULL)
			return 1;
		return 0;
	}
	void Print()
	{
		stacklist.PrintList();
	}
	int Length()
	{
		return len;
	}
};
bool isparanthesesok(string arr)
{
	Stack Container;
	int i = 0;
	while (arr[i] != '\n' && arr[i] != '\0')
	{

		if (arr[i] == ']' && Container.Top() == '[')
			Container.Pop();
		else if (arr[i] == '}' && Container.Top() == '{')
			Container.Pop();
		else if (arr[i] == ')' && Container.Top() == '(')
			Container.Pop();
		else if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
			Container.Push(arr[i]);

		i++;
	}
	if (Container.IsEmpty())
		return true;
	else
		return false;
}
int maxdepth(string arr)
{
	int maxdept = 0, i = 0;
	Stack Container;

	while (arr[i] != '\n' && arr[i] != '\0')
	{

		if (arr[i] == ']' && Container.Top() == '[')
		{
			if (Container.Length() > maxdept)
				maxdept = Container.Length();

			Container.Pop();
		}
		else if (arr[i] == '}' && Container.Top() == '{')
		{
			if (Container.Length() > maxdept)
				maxdept = Container.Length();

			Container.Pop();
		}
		else if (arr[i] == ')' && Container.Top() == '(')
		{
			if (Container.Length() > maxdept)
				maxdept = Container.Length();
			Container.Pop();
		}
		else if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
			Container.Push(arr[i]);

		i++;
	}

	return maxdept;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string UserInput;
	cin >> UserInput;
	cout<<maxdepth(UserInput)<<endl;
	return 0;
}
