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

int digitSum(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

Node* deleteEvenSum(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        if (digitSum(temp->data) % 2 == 0) {
            Node* del = temp;

            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next)
                temp->next->prev = temp->prev;

            temp = temp->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->prev = head;
    head->next->next = new Node(35);
    head->next->next->prev = head->next;

    cout << "Original list: ";
    print(head);

    head = deleteEvenSum(head);

    cout << "\nAfter deletion: ";
    print(head);

    return 0;
}
