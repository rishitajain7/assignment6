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
    DoublyLinkedList() {
      head = nullptr; 
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    
    void deleteNode(int key) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << " not found!\n";
            return;
        }
        if (temp->prev){
          temp->prev->next = temp->next;}
        else {
          head = temp->next;} 
        if (temp->next) {
          temp->next->prev = temp->prev;}
        delete temp;
        cout << "Node deleted successfully.\n";
    }

    
    void search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found!\n";
    }

  
    void display() {
        Node* temp = head;
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


class CircularLinkedList {
    Node* last;

public:
    CircularLinkedList() { last = nullptr; }

    
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }


    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void deleteNode(int key) {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }

    
   
    void search(int key) {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = last->next;
        do {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node not found!\n";
    }

   
    void display() {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = last->next;
        cout << "List: ";
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
    int choice, listType, value, key;

    while (true) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> listType;

        if (listType == 3) break;

        cout << "\n1. Insert at Beginning\n";
        cout<<  "2. Insert at End\n";
        cout<< "3. Insert After Node\n";
        cout << "4. Delete Node\n;
        cout<<"5. Search Node\n";
         cout<<" 6. Display\n";
        cout<<"7. Back\n";
        cout << "Enter operation: ";
        cin >> choice;

        if (choice == 7) continue;

        cout << endl;
        switch (listType) {
            case 1: 
                if (choice == 1) { 
                  cout << "Enter value: ";
                  cin >> value;
                  dll.insertAtBeginning(value); }
                else if (choice == 2) { 
                  cout << "Enter value: "; 
                  cin >> value; dll.insertAtEnd(value); }
                else if (choice == 3) { 
                  cout << "Enter key and value: "; 
                  cin >> key >> value; 
                  dll.insertAfter(key, value); }
                else if (choice == 4) {
                  cout << "Enter value to delete: "; 
                  cin >> value; 
                  dll.deleteNode(value); }
                else if (choice == 5) {
                  cout << "Enter value to search: ";
                  cin >> value; 
                  dll.search(value); }
                else if (choice == 6) {
                  dll.display();}
                break;

            case 2: // Circular Linked List
                if (choice == 1) { 
                  cout << "Enter value: "; 
                  cin >> value;
                  cll.insertAtBeginning(value); }
                else if (choice == 2) { 
                  cout << "Enter value: ";
                  cin >> value; 
                  cll.insertAtEnd(value); }
                else if (choice == 3) { cout << "Enter key and value: ";
                                       cin >> key >> value; 
                                       cll.insertAfter(key, value); }
                else if (choice == 4) { cout << "Enter value to delete: "; 
                                       cin >> value; 
                                       cll.deleteNode(value); }
                else if (choice == 5) { cout << "Enter value to search: "; 
                                       cin >> value; 
                                       cll.search(value); }
                else if (choice == 6) cll.display();
                break;
        }
    }

    cout << "Program terminated.\n";
    return 0;
}
