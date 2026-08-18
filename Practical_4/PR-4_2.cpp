#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};
Node* head = NULL;

void insert_front(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->link = head;
    head = temp;
}

void insert_end(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->link = NULL;
    if(head==NULL){
        head = temp;
        return;
    }
    Node* temp1 = head;
    while(temp1->link!=NULL){
        temp1 = temp1->link;
    }
    temp1->link = temp;

}

void insert_at_position(int data, int pos){
    Node* temp = new Node();
    temp->data = data;
    if(pos==1){
        temp->link = head;
        head = temp;
        return;
    }
    Node* temp1 = head;
    for(int i=1;i<pos-1;i++){
        if(temp1==NULL){
            cout<<"Position out of bounds"<<endl;
            return;
        }
        temp1 = temp1->link;
    }
    if(temp1==NULL){
        cout<<"Position out of bounds"<<endl;
        return;
    }
    temp->link = temp1->link;
    temp1->link = temp;

}

void DeleteByValue(int val)
{
   
    if (head->data == val)
    {
        Node* temp = head;
        head = head->link;

        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->link!= NULL && temp->link->data!= val)
    {
        temp = temp->link;
    }

    if (temp->link == NULL)
    {
        cout << "Value not found!" << endl;
        return;
    }

    Node* deleteNode = temp->link;

    temp->link = deleteNode->link;

    delete deleteNode;
}

void display(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}



int main()
{
    while(int n=1){
        cout<<"1. Insert at front"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Insert at position"<<endl;
        cout<<"4. Delete by value "<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        int choice;
        cout<<"Select operation: ";
        cin>>choice;
        switch(choice){
            
            case 1:
                int data;
                cout<<"Enter data: ";
                cin>>data;
                insert_front(data);
                break;
            case 2:
                int data_end;
                cout<<"Enter data: ";
                cin>>data_end;
                insert_end(data_end);
                break;
            case 3:
                int data_pos,pos;
                cout<<"Enter data: ";
                cin>>data_pos;
                cout<<"Enter position";
                cin>>pos;
                insert_at_position(data_pos,pos) ;
                break;
            case 4:
                int del_data;
                cout<<"Enter data to delete: ";
                cin>>del_data;
                DeleteByValue(del_data);
            case 5:
                display();
                break;
            case 6:
                n=0;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;

}