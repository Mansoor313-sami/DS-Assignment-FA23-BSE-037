#include <iostream>
#include <string>
using namespace std;

// Node structure:
struct TaskNode {
    int taskID;
    string description;
    int priority;
    TaskNode* next;
};

// Insert task at the beginning:
TaskNode* insertTask(TaskNode* head, int taskID, string description, int priority) {
    TaskNode* newNode = new TaskNode;
    newNode->taskID = taskID;
    newNode->description = description;
    newNode->priority = priority;
    newNode->next = head;
    return newNode;
}

// View all tasks:
void viewTasks(TaskNode* head) {
    TaskNode* temp = head;
    while (temp != NULL) {
        cout << "Task ID: " << temp->taskID << ", Description: " << temp->description << ", Priority: " << temp->priority << "\n";
        temp = temp->next;
    }
}

// Remove first task:
TaskNode* removeTask(TaskNode* head) {
    if (head == NULL) {
        cout << "No tasks to remove.\n";
        return head;
    }
    TaskNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Menu system:
void menu() {
    TaskNode* head = NULL;
    int choice, id, priority;
    string description;
    while (true) {
        cout << "\nTask Management System\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove first task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Task ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Task Description: ";
            getline(cin, description);
            cout << "Enter Task Priority: ";
            cin >> priority;
            head = insertTask(head, id, description, priority);
        } else if (choice == 2) {
            viewTasks(head);
        } else if (choice == 3) {
            head = removeTask(head);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// Main function:
int main() {
    menu();
    return 0;
}

