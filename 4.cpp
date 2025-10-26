#include <iostream>
using namespace std;


struct Node {
    char data;
    Node* next;
    Node* prev;
};


class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(char ch) {
        Node* newNode = new Node{ch, nullptr, nullptr};
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

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome() {
        if (!head){
          return true;
        }

       
        Node* left = head;
        Node* right = head;
        while (right->next)
            right = right->next;

     
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};


int main() {
    DoublyLinkedList dll;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    for (char ch : str)
        dll.insertAtEnd(ch);

    dll.display();

    if (dll.isPalindrome())
        cout << "palindrome.\n";
    else
        cout << " NOT a palindrome.\n";

    return 0;
}
