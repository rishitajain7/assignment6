#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int x) {
      data = x;
      prev = next = NULL; 
    }
};

Node* reverseK(Node* head, int k) {
    Node *curr = head, *newHead = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        Node* nxt = curr->next;
        curr->next = curr->prev;
        curr->prev = nxt;
        newHead = curr;
        curr = nxt;
        count++;
    }

    if (curr != NULL) {
        head->next = reverseK(curr, k);
        if (head->next)
            head->next->prev = head;
    }

    return newHead;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    head->next->next->next = new Node(4); head->next->next->next->prev = head->next->next;

    cout << "Original: ";
    print(head);

    int k = 2;
    head = reverseK(head, k);

    cout << "\nReversed in groups: ";
    print(head);

    return 0;
}
