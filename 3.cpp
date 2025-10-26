#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev; 
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


// CIRCULAR LINKED LISt
class CircularLinkedList {
    Node* last;

public:
    CircularLinkedList() { last = nullptr; }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!last) {
            last = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    int getSize() {
        if (!last)
            return 0;
        int count = 0;
        Node* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }

    void display() {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    cll.insertAtEnd(5);
    cll.insertAtEnd(15);
    cll.insertAtEnd(25);
    cll.insertAtEnd(35);

    dll.display();
    cout << "Size of Doubly Linked List: " << dll.getSize() << endl;

    cll.display();
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}
