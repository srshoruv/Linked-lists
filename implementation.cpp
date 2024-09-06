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
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head==NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
    }
    }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_back(4);

    return 0;
}