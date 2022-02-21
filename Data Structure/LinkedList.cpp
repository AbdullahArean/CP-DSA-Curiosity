#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node *previous;
	Node()
	{
		data = 0;
		next = NULL;
		previous = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
		this->previous = NULL;
	}
};
class LinkedList
{
private:
	Node *LinkedListHead;
	int LengthOfLinkedList;
	Node *ReverseRecursion(Node *current)
	{

		if (current == NULL || current->next == NULL)
			return current;
		Node *newhead = ReverseRecursion(current->next);
		current->next->next = current;
		current->next = NULL;
		return newhead;
	}
	Node *ReverseIterative(Node *current)
	{
		Node *prev = NULL, *next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		return prev;
	}

public:
	LinkedList()
	{
		LinkedListHead = NULL;
		LengthOfLinkedList = 0;
	}
	LinkedList(Node *head)
	{
		this->LinkedListHead = head;
	}
	int Length()
	{
		return this->LengthOfLinkedList;
	}
	void InsertNode(int data, int position)
	{
		Node *newNode = new Node(data);
		if (position < 0)
			printf("Invalid Position!\n");
		else if (LinkedListHead == NULL)
		{
			newNode->next = NULL;
			LinkedListHead = newNode;
		}
		else if (position == 0)
		{
			newNode->next = LinkedListHead;
			LinkedListHead = newNode;
		}
		else
		{
			Node *temp = LinkedListHead;
			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
				{
					printf("Invalid Position!\n");
					return;
				}
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		LengthOfLinkedList++;
	}
	void PrintList()
	{
		Node *temp = LinkedListHead;
		if (LinkedListHead == NULL)
		{
			cout << "List is empty!" << endl;
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
		Node *temp1 = LinkedListHead, *temp2 = NULL;
		if (this->LengthOfLinkedList == 0)
		{
			cout << "List is empty!" << endl;
			return;
		}
		if (this->LengthOfLinkedList <= position)
		{
			cout << "Invalid Position!" << endl;
			return;
		}
		if (position == 0)
		{
			LinkedListHead = LinkedListHead->next;
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
		this->LengthOfLinkedList--;
		return;
	}
	Node *ReturnLinkedListHead() { return LinkedListHead; }
	void ReverseIterative()
	{
		this->LinkedListHead = ReverseIterative(this->LinkedListHead);
	}
	void ReverseRecursion()
	{
		this->LinkedListHead = ReverseRecursion(this->LinkedListHead);
	}
	void removeDuplicates(struct Node *head)
	{
		Node *temp = head, *tempstore1 = NULL;
		while (temp != NULL)
		{
			if (tempstore1 != NULL && tempstore1->data != temp->data)
			{
				tempstore1->next = temp;
				tempstore1 = temp;
			}
			if (!tempstore1)
				tempstore1 = temp;
			temp = temp->next;
		}
	}
	Node *removeDuplicates2(Node *head)
	{ //Unsorted
		vector<bool> v(100000, false);
		Node *temp = head, *tempstore = NULL;
		while (temp != NULL)
		{
			if (!v[temp->data])
			{
				if (tempstore != NULL)
					tempstore->next = temp;
				v[temp->data] = true;
				tempstore = temp;
			}
			else
			{
				tempstore->next = NULL;
			}
			temp = temp->next;
		}

		return head;
	}
};


Node *Reversevariation(Node *current, int k)
{
	int count = k;
	Node *prev = NULL, *next = NULL, *temp2 = current, *temp1 = NULL, *tempfinal = NULL;
	while (current != NULL)
	{
		count = k;
		prev = NULL, next = NULL, temp2 = current;
		while (current != NULL && count--)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		if (temp1 == NULL)
			tempfinal = prev;
		if (temp1 != NULL)
		{
			temp1->next = prev;
		}
		temp1 = temp2;
	}
	return tempfinal;
}
/*
Loop 	Related Problem
Links: https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
Floyds Cycle Finding Algorithm
https://caring-august-d6b.notion.site/Floyd-s-Cycle-Finding-Algorithm-For-Finding-Loop-in-Linked-List-a6ad400975134526af91c9c31ebeeaa2
//solution using map //
time – O(n)
space-O(n)

	bool detectLoop(Node* head)
   {
	   // your code here
	   map<Node*,bool>visited;
	   Node* temp=head;
	   while(temp!=NULL)
	   {
		   if(visited[temp]==true)
		   {
			   return true;
		   }
		   visited[temp]=true;
		   temp=temp->next;
	   }
	   return false;

   }

// O(n) time complexity and O(1) Auxiliary Space
bool detectLoop(Node* head)
	{
		// your code here
		Node*cur=head;
		if(head==NULL)
			return false;
		while(cur!=NULL)
		{
			if(cur->data<0)
				return true;
			else
			{
				cur->data=-(cur->data);
			}
			cur=cur->next;
		}
		return false;
	}
bool detectLoop(Node * head){
	Node * slow_p= head, *fast_p = head;
	while(slow_p && fast_p && fast_p->next){
		slow_p=slow_p->next;
		fast_p= fast_p->next->next;
		if(slow_p==fast_p) return 1;
	}
	return 0;
}
void removeLoop(Node* head)
	{
	   // hash map to hash addresses of the linked list nodes
	unordered_map<Node*, int> node_map;
	// pointer to last node
	Node* last = NULL;
	while (head != NULL) {
		// if node not present in the map, insert it in the map
		if (node_map.find(head) == node_map.end()) {
			node_map[head]++;
			last = head;
			head = head->next;
		}
		// if present, it is a cycle, make the last node's next pointer NULL
		else {
			last->next = NULL;
			break;
		}
	}
*/
/*
//Function to remove duplicates from sorted linked list.
link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
Node *removeDuplicates(Node *head)
{
 // your code goes here
  Node* temp = head, *tempstore1=NULL;
	while(temp!=NULL){
		if(tempstore1!=NULL && tempstore1->data!=temp->data) {tempstore1->next=temp; tempstore1= temp;}
		if(!tempstore1) tempstore1=temp;
		temp=temp->next;
	}
	tempstore1->next= NULL;
	return head;
}
*/
void removeDuplicates(struct Node *head)
{
	Node *temp = head, *tempstore1 = NULL;
	while (temp != NULL)
	{
		if (tempstore1 != NULL && tempstore1->data != temp->data)
		{
			tempstore1->next = temp;
			tempstore1 = temp;
		}
		if (!tempstore1)
			tempstore1 = temp;
		temp = temp->next;
	}
}
Node *deleteDuplicates(Node *head)
{
//Link:https:// leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	Node *temp = head;
	map<int, int> map;

	while (temp != NULL)
	{
		map[temp->data]++;
		temp = temp->next;
	}

	Node *NewHead = new Node(0);
	temp = NewHead;

	for (auto x : map)
	{
		if (x.second == 1)
		{
			temp->next = new Node(x.first);
			temp = temp->next;
		}
	}

	return NewHead->next;
}
Node *deleteDuplicates2(Node *head)
{
//Link:https: // leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Node *cur= head, *prev= NULL, *next= NULL;
while(cur!=NULL){
	next= cur->next;
	if(prev==NULL && ){


	}
	else if(next!=NULL && cur->data!=prev->data && cur->data!=next->data){

	}
}
}
Node *removeDuplicates2(Node *head)
{
	//Link: https://caring-august-d6b.notion.site/Remove-Duplicates-in-Linked-List-18cbb228467842d08e53867c6ed595da
	vector<bool> v(100000, false);
	Node *temp = head, *tempstore = NULL;
	while (temp != NULL)
	{
		if (!v[temp->data])
		{
			if (tempstore != NULL)
				tempstore->next = temp;
			v[temp->data] = true;
			tempstore = temp;
		}
		else
		{
			tempstore->next = NULL;
		}
		temp = temp->next;
	}

	return head;
}

int main()
{
	LinkedList l;
	l.InsertNode(1, 0);
	l.InsertNode(2, 1);
	l.InsertNode(2, 2);
	l.InsertNode(7, 3);
	l.InsertNode(7, 4);
	l.InsertNode(6, 5);
	l.InsertNode(7, 6);
	l.InsertNode(8, 7);
	l.InsertNode(9, 8);
	// l.PrintList();
	// l.ReverseIterative();
	// l.PrintList();
	// l.ReverseRecursion();
	l.PrintList();
	l.removeDuplicates2(l.ReturnLinkedListHead());
	l.PrintList();
	return 0;
}
