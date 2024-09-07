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
        if (head==NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        
    }
    void printList(){
        Node* temp = head;
        while (temp!=NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        } cout << "NULL" << endl;
    }

    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        while (curr !=NULL) {
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void checkPalindrome(){
        Node* slow = head;
        Node* fast = head;

        while (slow && fast) {
            slow= slow->next;
            fast = fast->next->next;
        }

        Node* prev = NULL;
        Node* curr = slow;
        while(curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node* left = head;
        Node* right = prev;
        while (right) {
            if (left->val != right->val) {
                cout << left->val << " and " << right->val << " are not the same!" << endl;
                return;
                }
            left = left->next;
            right = right->next;
        } cout << "Palindrome!";
    }
};

int main () {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.printList();
    ll.checkPalindrome();
}