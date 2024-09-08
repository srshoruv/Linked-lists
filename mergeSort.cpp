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

void printList(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        } cout << "NULL" << endl;
    }

Node* splitMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast!= NULL && fast->next!= NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev!=NULL) {
        prev->next = NULL;
    } 
    return slow;
}

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;

    while (i!= NULL && j!= NULL) {
        if ( i->val <= j->val) {
            ans.push_back(i->val);
            i = i->next;
        } else {
            ans.push_back(j->val);
            j = j->next;
        }
    }

    while (i!= NULL) {
        ans.push_back(i->val);
        i = i->next;
    }
    while (j != NULL) {
        ans.push_back(j->val);
        j = j->next;
    }

    return ans.head;

}

Node* mergeSort(Node* head) {
    if (head==NULL || head->next==NULL) {
        return head;
    }

    Node* rightHead = splitMid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left,right);
}
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

Node* zigZagLL(Node* head) {
    Node* rightHead = splitMid(head);
    Node* rightHeadRev = reverse(rightHead);

    //alternation
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while (left && right) {
        Node* leftNxt = left->next;
        Node* rightNxt = right->next;

        left->next = right;
        right->next = leftNxt;

        tail = right;

        right = rightNxt;
        left = leftNxt;
    }

    if (!right) {
        tail->next = right;} 
        return head;
}

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    printList(ll.head);
    ll.head = zigZagLL(ll.head);
    printList(ll.head);
}