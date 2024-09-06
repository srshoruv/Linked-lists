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

class List {
    Node* tail;
    Node* head;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
    void reverse() {
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
    }

};