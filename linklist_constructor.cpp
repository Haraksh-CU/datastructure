#include <iostream>
using namespace std;
class node{
    public:
  int data;
  node *next;
  node(int data){
     this->data=data;
     this->next=NULL;
  }
};
class linklist{
    public:
    int element;
    bool found=false;
    node* head= NULL;
    node *first=head;
    node *second=first;
    int cnt=0;
    void insert(int data){
        cnt++;
        if(cnt==1){
            head=new node(data);
            first=head;
            second=head;
        }
        else if(cnt>=2){
            second=new node(data);
            first->next=second;
            first=second;
        }
    }
    void display(){
        second=head;
        while(second!=NULL){
            cout << second->data << " ";
            second=second->next;
        }
    }
    void del (int data){
        second=head;
        while(second!=NULL){
            if (data==second->data){
                found=true;
                if (second==head){
                    head=second->next;
                }
                else if(second->next==NULL){
                    first->next=NULL;
                }
                else {
                    first->next=second->next;
                }
            }
            first=second;
            second=second->next;
        }
    }
};
 int main () {
     linklist obj;
     cout << "how many elements you want to insert : ";
     cin >> obj.element;
     int temp;
     int del;
     for(int i=0;i<obj.element;i++){
         cin >> temp;
         obj.insert(temp);
     }
     cout << "elements before deletion-------";
     obj.display();
     cout << endl;
     cout << "enter the element you want to delete: ";
     cin >> del;
     obj.del(del);
     if (obj.found==true){
     cout << "elements after deletion: ";
     obj.display();
     }
     else{
         cout << "element not present in the list";
     }
    return 0;
 }