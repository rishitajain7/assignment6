#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
      data = x; next = NULL; 
    }
};

void splitList(Node* head, Node** head1, Node** head2) {
    if (head == NULL) {
      return;}

    Node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;

    if (fast->next == head)
        fast->next = *head2;
    else
        fast->next->next = *head2;
}

// printing circular link list
void print(Node* head) {
    if (!head){
      return;}
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head; 
    Node *head1 = NULL, *head2 = NULL;

    splitList(head, &head1, &head2);

    cout << "First half: ";
    print(head1);

    cout << "\nSecond half: ";
    print(head2);

    return 0;
}
