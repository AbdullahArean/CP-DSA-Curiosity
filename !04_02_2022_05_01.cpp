/*
Author:Abdullah Ibne Hanif Arean
Problem: APAS(Android App) Add Two Numbers
*/

#include<bits/stdc++.h>
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
int main(){
    Linkedlist n1, n2;
    n1.InsertNode(2,0);
    n1.InsertNode(4,1);
    n1.InsertNode(3,2);
    n2.InsertNode(2,0);
    n2.InsertNode(4,1);
    n2.InsertNode(3,2);

    Node* temp1=n1.Returnhead();
    Node* temp2=n2.Returnhead();
 

}