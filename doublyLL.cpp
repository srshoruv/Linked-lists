#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode; // extra line for doublyLL
            head = newNode;
        }
        
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;

        if (!head) {
            head->prev = NULL;
        }
        temp->next = NULL;
    }

    void printList() {
        Node* temp = head;

        while (temp) {
            cout << temp->val << " <=> ";
            temp = temp->next;
        } cout << "NULL \n";
    } 

};

int main() {
    DoublyList dbll;
    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printList();
    return 0;
}