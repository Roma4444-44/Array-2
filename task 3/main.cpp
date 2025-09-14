#include <iostream>
#include <SinglyLinkedList.h>
using namespace std;
int main() {
    SinglyLinkedList list;
    int choice, value, position;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert Left\n";
        cout << "2. Insert Right\n";
        cout << "3. Insert at Position\n";
        cout << "4. Remove Left\n";
        cout << "5. Remove Right\n";
        cout << "6. Remove at Position\n";
        cout << "7. Search\n";
        cout << "8. Print List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.InsertLeft(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.InsertRight(value);
            break;
        case 3:
            cout << "Enter position (0-based index): ";
            cin >> position;
            cout << "Enter value to insert: ";
            cin >> value;
            list.InsertAtPosition(position, value);
            break;
        case 4:
            list.RemoveLeft();
            break;
        case 5:
            list.RemoveRight();
            break;
        case 6:
            cout << "Enter position to remove: ";
            cin >> position;
            list.RemoveAtPosition(position);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            list.Search(value);
            break;
        case 8:
            list.Print();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}

