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

    ~Node(){
        if (next != NULL) {
            delete next;
            next = NULL;
        }
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

    ~List() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
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

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        } cout << "NULL";
    }

    void insert(int val, int pos) {
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i=0; i<pos-1; i++) {
            if (temp == NULL) {
                cout << "Invalid Position!";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if (head==NULL) {
            cout << "Already empty"<< endl;
            return;
        } else {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        }
        
    }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.insert(100,2);
    ll.printList();
    ll.pop_front();
    ll.printList();

    return 0;
}