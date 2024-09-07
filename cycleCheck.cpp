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
public:
    Node* head;
    Node* tail;


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

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        } cout << "NULL" << endl;
    }
};

bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow==fast) {
            cout << "cycle exists!" << endl;
            return true;
        }
    }
    cout << "cycle doesn't exist!" << endl;
    return false;
}

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;
    isCycle(ll.head);

    return 0;
}