#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void InsertLeft(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void InsertRight(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    void InsertAtPosition(int position, int value) {
        if (position < 0 || position > length()) {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 0) {
            InsertLeft(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 0; i < position - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << ".\n";
    }

    void RemoveLeft() {
        if (isEmpty()) {
            cout << "List is empty. Cannot remove.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "First node removed.\n";
    }

    void RemoveRight() {
        if (isEmpty()) {
            cout << "List is empty. Cannot remove.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        cout << "Last node removed.\n";
    }

    void RemoveAtPosition(int position) {
        if (position < 0 || position >= length()) {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 0) {
            RemoveLeft();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++)
            temp = temp->next;

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        cout << "Node at position " << position << " removed.\n";
    }

    void Search(int value) {
        Node* temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == value) {
                cout << "Value " << value << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Value " << value << " not found in the list.\n";
    }

    void Print() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "List elements: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        while (!isEmpty()) {
            RemoveLeft();
        }
    }
};
#endif
