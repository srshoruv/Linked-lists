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

Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;

            //updation
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }

void printList(Node* head){
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    } cout << "NULL\n";
}

Node* swapNNodes(Node* head, int m, int n) {
    Node* temp = head;
    Node* temp2 = head;

    for (int i=1; i<m && temp; i++) {
        temp = temp->next;
    }

    for (int i=1; i<n && temp2; i++) {
        temp2 = temp2->next;
    }

    List revLL;

    while (temp != temp2) {
        revLL.push_front(temp->val);
        temp = temp->next;
    }
    cout << "New addition -> ";
    Node* revHead = revLL.head;
    head = temp;
    temp->next = revHead;
    // printList(revLL.head);

    // cout << "temp -> " << temp->val;
    // cout << "temp2 -> " << temp2->val;


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
    swapNNodes(ll.head, 2 , 4);
    printList(ll.head);
    return 0;
}

