#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

  
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!last) {
            last = newNode;
            newNode->next = newNode; 
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void display() {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }
        Node* head = last->next;
        Node* temp = head;

        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    cll.display();

    return 0;
}
