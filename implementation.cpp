#include <iostream>
using namespace std;

class Node{
    int val;
    Node* next;
public:
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
};

int main(){
    List ll();
}