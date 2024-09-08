#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class List{
public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

void push_front(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}



};

void printList(Node* head){
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    } cout << "NULL\n";
}

Node* deleteAfterM(Node* head, int m,int n) {
    Node* temp = head;
    while (temp) {
        for (int i=1; i<m; i++) {
        temp = temp->next;
    }
    Node* afterTemp = temp->next;
    for(int i=1; i<=n; i++) {
        afterTemp = afterTemp->next;
    }

    temp->next = afterTemp;
    temp = temp->next;
    // cout << afterTemp->val << "<-";
    }
    


    return head;
}

int main(){
    List ll;
    ll.push_front(10);
    ll.push_front(9);
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // ll.printList();
    ll.head = deleteAfterM(ll.head,3,2);
    printList(ll.head);
    return 0;
}

