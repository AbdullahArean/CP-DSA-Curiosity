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
	/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
	void deleteNode(int position) 
{ 
   // If linked list is empty 
   if (this->LinkedListHead == NULL) 
      return; 
  
   // Store head node 
    Node* temp = this->LinkedListHead; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        this->LinkedListHead = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of ndoes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    Node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
} 
  
	Node *ReturnLinkedListHead() 
	{ return LinkedListHead; }
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
	Node *deleteDuplicates(Node *head)
{
//Link:https:// leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
//Link: https://caring-august-d6b.notion.site/Remove-Duplicates-in-Linked-List-18cbb228467842d08e53867c6ed595da
	
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
	bool detectLoop(Node * head){
	Node * slow_p= head, *fast_p = head;
	while(slow_p && fast_p && fast_p->next){
		slow_p=slow_p->next;
		fast_p= fast_p->next->next;
		if(slow_p==fast_p) return 1;
	}
	return 0;
}
	void movethelastelefirst(Node * head){
		Node * cur = head, *store= head, *temp=NULL;
		while(cur!=NULL){
			if(cur->next && cur->next->next==NULL){
				temp = cur->next;
				temp->next = store;
				cur->next = NULL;
			 }
			cur=cur->next;
		}
		this->LinkedListHead= temp;

	}
	Node* addOne(Node* head){
        head =ReverseIterative(head);
		Node * cur= head, *store =NULL;
		short int onhand= 1;
		while(cur!=NULL && onhand) {

			if(cur->next==NULL) store =cur;
			if(cur->data<9) {
				cur->data++;
				onhand = 0;

			}
			else if(cur->data==9) {
				cur->data=0;
				onhand = 1;
			}

			cur= cur->next;
		}
		if(onhand) store->next = new Node(onhand);
		head =ReverseIterative(head);
		return head;

	}
	void printMiddle(Node *head){
		//Delete middle is also easy
        Node *slow_ptr = head;
        Node *fast_ptr = head;
		//Node * store = NULL; //To delete the middle element 
  
        if (head!=NULL)
        {
            while (fast_ptr && fast_ptr->next)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
				//if(fast_ptr->next) store = slow_ptr; //To delete the middle element 
            }
            cout << "The middle element is [" << slow_ptr->data << "]" << endl;
			//store->next= slow_ptr->next;//To delete the middle element 
        }
    }
	void swapNodes(int x, int y)
{/* Function to swap nodes x and y in linked list by
changing links */
    // Nothing to do if x and y are same
    if (x == y)
        return;
 
    // Search for x (keep track of prevX and CurrX
    Node *prevX = NULL, *currX = this->LinkedListHead;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
 
    // Search for y (keep track of prevY and CurrY
    Node *prevY = NULL, *currY = this->LinkedListHead;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
 
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
 
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        this->LinkedListHead = currY;
 
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        this->LinkedListHead = currX;
 
    // Swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
};
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
	
//Push onto a linked list
	void push(Node** LinkedListHead, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*LinkedListHead);
    (*LinkedListHead) = new_node;
}

Add two numbers ::https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
*/


int main()
{
	LinkedList l;
	l.InsertNode(1, 0);
	l.InsertNode(2, 1);
	l.InsertNode(4, 2);
	l.InsertNode(4, 3);
	l.InsertNode(9, 4);
	l.InsertNode(9, 5);
	l.InsertNode(29, 6);
	l.InsertNode(92, 7);
	l.InsertNode(29, 8);
	l.PrintList();
	l.swapNodes(1,29);
	l.printMiddle(l.ReturnLinkedListHead());
	l.PrintList();

	
	return 0;
}
