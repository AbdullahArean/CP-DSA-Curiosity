#include<bits/stdc++.h>
using namespace std;

class node{
    public:int data;
    public:node* link;
    public:node(){
        link= NULL;
    }
    public:node(int inp){
        link = NULL;
        data = inp;
    }
};
class linkedlist{
    public:node* head;
    public:linkedlist(){
        head= NULL;
    }
    //here position starts from zero
    public:void add(int inp, int pos){
        node* newnode = new node(inp);
        if(head== NULL){
            if(pos==0)
            head =newnode;
            else printf("Invalid Position Can't insert\n");
        }
        else{
            if(pos=0) {newnode->link= head; head = newnode;}
            else{
                node* temp= head;
                for(int i=0; i<pos; i++){
                    if(temp->link==NULL){
                        if(i!=pos) {printf("Invalid Position Can't Insert\n"); break;}
                        else break;
                    }
                    temp= temp->link;

                }
                newnode->link = temp->link;
                temp->link = newnode;
            }
            }
            

    }
    public:void print(){
        node* temp = head;
        while(temp!=NULL){
                printf("%d ->", temp->data);
                temp = temp->link;
            }
    }
};

int main()
{
    linkedlist a;
    a.add(12,0);
    a.add(134,1);
    a.add(123,2);
    a.add(12,2);
    a.add(34,0);
    a.add(45,4);
    a.print();
     

}