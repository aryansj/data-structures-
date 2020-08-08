#include<bits/stdc++.h>
using namespace std ;

class node {
    public:
        int data;
        node *next;
};

// add node to beginning of list by taking pointer to address of head pointer 
void push(node* &head, int data ){ // head has to be changed so passed by reference
    node* new_node = new node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// add node at a particular position
void insertAt(int pos, node* head, int data){
    int i;
    node* temp = head;
    for(i = 1; i < pos - 1; i++){
        temp = temp->next;
    }
    node* new_node = new node();
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->data = data;
}

void printList(node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next; 
    }
}

// delete at a particular location
void deleteAt(node* &head, int pos){
    node* temp = head;
    int i = 0;
    for(i = 1; i < pos - 1; i++){
        temp = temp->next;
    }
    node *t = temp->next;
    temp->next = temp->next->next;
    delete(t);
}

int main (){
    node* head = NULL;
    push(head, 6);
    push(head, 7);
    insertAt(2, head, 10);
    deleteAt(head, 2);
    deleteAt(head, 2);
    printList(head);
    return 0;
}