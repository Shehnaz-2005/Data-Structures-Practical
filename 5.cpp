/*
Q5:
            Implement Circular Linked List using templates. Include functions for insertion, deletion and
            search of a number, reverse the list.
Code:
*/
#include<iostream>
using namespace std;
template<class t>
class node
{
public:
t data;
node *next;
};
template<class t>
class clist
{
int n;
node<t> *first,*last;
public:
clist()
{
first=NULL;
}
//create function
void create()
{
node<t> *current,*temp;
cout<<"Enter how many nodes you want to enter in linked list:\n";
cin>>n;
//fflush(stdin);
if(n>0)
{
if(first==NULL)
{
first=new node<t>;
cout<<"Enter data for first node:\n";
cin>>first->data;
//fflush(stdin);
first->next=first;

}
current=first;
for(int i=1;i<n;i++)
{
cout<<"Enter data:\n";
temp=new node<t>;
cin>>temp->data;
//fflush(stdin);
temp->next=current->next;
current->next=temp;
current=current->next;
}
last=current;
}
}
//count the list
int count()
{
node<t> *current;
current=first;
int c=0;
while(current->next!=first)
{
c++;
current=current->next;
}
c++;
return c;
}
//insert function
void insert()
{
cout<<"Enter the position of insertion;\n";
cin>>n;
int b=count();
if(n<=b+1)
{
node<t> *current,*temp;
current=first;
temp=new node<t>;
cout<<"Enter data:\n";
cin>>temp->data;
temp->next=NULL;
if(n==1)
{
temp->next=first;
first=temp;
last->next=first;
}
else
{
for(int i=1;i<n-1;i++)
current=current->next;
temp->next=current->next;
current->next=temp;
}
}
else
cout<<"Can't be inserted\n";
}
//deletion now vomes
void search()
{
int flag=0;
cout<<"Enter data to be searched:\n";
cin>>n;
node<t> *current,*prev,*temp;
int b=count();
current=first;
for(int i=1;i<=b;i++)
{
if(current->data==n)
{
flag=1;
break;
}
prev=current;
current=current->next;
}
if(flag==1)
{
int c;
cout<<"Data found:\nEnter what you want to do:\n 1.delete data\n 2.replace it\n 3.do nothing\n";
cin>>c;
switch(c)
{
case 1:temp=current;
prev->next=current->next;
delete(temp);
cout<<"Data deleted:\n";
break;
case 2:cout<<"Enter new data:\n";
cin>>current->data;
cout<<"data replaced:\n";
break;
case 3:break;
default:cout<<"wrong choice:\n";
}
}
else
cout<<"Data not found:\n";
}
//reverse function
void reverse()
{
node<t> *a,*b,*temp;
a=first;
b=a->next;
temp=b->next;
a->next=NULL;
while(temp!=first)
{
//fflush(stdin);
b->next=a;
a=b;
b=temp;
temp=temp->next;
//this->display();
}
b->next=a;
first->next=b;
first=first->next;
}
//create display
int display()
{
node<t> *current;
current=first;
while(current->next!=first)
{
cout<<current->data<<" -> ";
current=current->next;
}
cout<<current->data<<" -> \n";
}
};
int main()
{
    cout << "\n\t ~~~~~~~~~~~~~~~~~~~~~~~Practical 5~~~~~~~~~~~~~~~~~~~~\n\t\t\t\t  \n";
char ch;
clist<int> l1;
l1.create();
l1.display();
//doing insertion
do
{
cout<<"Want to insert a node(y/n):\n";
cin>>ch;
if(ch=='y')
l1.insert();
}while(ch=='y');
cout<<"The linked list after all insertions:\n";
l1.display();
do
{
cout<<"Want to search a node(y/n):\n";
cin>>ch;
if(ch=='y')
l1.search();
}while(ch=='y');
cout<<"The linked list after all operations:\n";
l1.display();
cout<<"Want to see reversed linked list(y/n):\n";
cin>>ch;
if(ch=='y')
{
l1.reverse();
}
cout<<"The linked list after reversing:-\n";
l1.display();
}
