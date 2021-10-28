#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* insertfrontNode(Node* head,int value){
     Node* temp=new Node();
       temp->next=nullptr;
       temp->data=value;

if(head==nullptr)
    return temp;
temp->next=head;
return temp;
    }

    Node* deletedata(Node* head,int val){
         Node* cur=head;
         Node* prev=nullptr;
         
         if(head->data==val){
            if(head->next==nullptr)
                return nullptr;
            else
                return head->next;
         }
         while(cur!=nullptr && cur->data!=val){
             prev=cur;
             cur=cur->next;
         }
         prev->next=cur->next;
         return head;
    }

    void removeDuplicates(Node* head1,Node* head2){
         Node* temp1=head1;
         Node* temp2=head2;
         while(temp1!=nullptr){
            while(temp2!=nullptr){
                if(temp1->data==temp2->data)
                    head2=deletedata(head2,temp1->data);
                temp2=temp2->next;
            }
            temp1=temp1->next;
            temp2=head2;
         }
    }
   
    void print(Node *head){
        Node* temp;
        temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }


int main(){
    int n1;
cout<<"Enter the number of nodes in linkedlist1"<<endl;
cin>>n1;

Node* head1=nullptr;
while(n1!=0){
        int data;
        cout<<"enter the data"<<endl;
cin>>data;
    head1=insertfrontNode(head1,data);
n1--;
}

    int n2;
cout<<"Enter the number of nodes in linkedlist2"<<endl;
cin>>n2;
Node* head2=nullptr;
while(n2!=0){
        int data;
        cout<<"enter the data"<<endl;
cin>>data;
    head2=insertfrontNode(head2,data);
n2--;
}

cout<<"First linked list"<<endl;
print(head1);
cout<<"Second linked list"<<endl;
print(head2);

removeDuplicates(head1,head2);

cout<<"After removing duplicates"<<endl;

cout<<"First linked list"<<endl;
print(head1);
cout<<"Second linked list"<<endl;
print(head2);
}