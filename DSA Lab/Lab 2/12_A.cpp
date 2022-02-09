//12
//12
//12
#include <stdio.h>
#include <stdlib.h>
struct Node* head = NULL;
typedef struct Result
{
    char name[100];
    int roll;
    float cgpa;
    int marks;
} Result;
struct Node {

	struct Node* next;
    struct Result result;
};
bool comparator(struct Node a, struct Node b)
{
    if (a.result.cgpa < b.result.cgpa)
        return 1;
    else if (a.result.cgpa == b.result.cgpa)
    {
        if (a.result.marks < b.result.marks)
            return 1;
        else if (a.result.marks == b.result.marks)
        {
            if (a.result.roll > b.result.roll)
                return 1;
        }
    }
    return 0;
}
struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef);

void MergeSort(struct Node** headRef)
{
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;

	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (!comparator(*a, *b)) {
		res = a;
		res->next = SortedMerge(a->next, b);
	}
	else {
		res = b;
		res->next = SortedMerge(a, b->next);
	}
	return (res);
}


void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef)
{
	struct Node* f;
	struct Node* s;
	s = source;
	f = source->next;
    while (f != NULL) {
		f = f->next;
		if (f != NULL) {
			s = s->next;
			f = f->next;
		}
	}

	*frontRef = source;
	*backRef = s->next;
	s->next = NULL;
}

void printList()
{
	struct Node *temp1 = head;
    int n=1;
    while (temp1->next != NULL)
    {
        printf("%d %s %d %.2f %d\n",n, temp1->result.name,temp1->result.roll, temp1->result.cgpa, temp1->result.marks);
         temp1 = temp1->next;
         n++;
    }
   printf("%d %s %d %.2f %d\n",n, temp1->result.name,temp1->result.roll, temp1->result.cgpa, temp1->result.marks);

}

void InsertAtLinkedList(struct Result temp)
{
    struct Node *newnode;
    newnode = new Node();
    newnode->result = temp;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
int main()
{
	struct Node* res = NULL;
	

	int testcase;
    scanf("%d", &testcase);
    while (testcase--)
    {
        struct Result temp;
        scanf("%s %d %f %d", temp.name, &temp.roll, &temp.cgpa, &temp.marks);
        InsertAtLinkedList(temp);
    }
	MergeSort(&head);
	printList();

	getchar();
	return 0;
}
