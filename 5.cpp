#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head; // last node points to head
    }

    bool isCircular() {
        if (!head) return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }
        return (temp == head);
    }

    void display() {
        Node* temp = head;
        int count = 0;
        cout << "List elements: ";
        while (temp && count < 10) { 
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << "...\n";
    }
};


int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "\nInitially:\n";
    list.display();
    if (list.isCircular())
        cout << "✅ The list is circular.\n";
    else
        cout << "❌ The list is NOT circular.\n";

    list.makeCircular();

    cout << "\nAfter making it circular:\n";
    if (list.isCircular())
        cout << "✅ The list is circular.\n";
    else
        cout << "❌ The list is NOT circular.\n";

    return 0;
}
