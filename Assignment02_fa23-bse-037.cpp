#include <iostream>
using namespace std;

struct Patient {
    string name;
    int priority;
};

Patient patients[100];
int total = 0;

void addPatient() {
    Patient p;
    cout << "Enter patient name: ";
    cin >> p.name;
    cout << "Enter emergency level (1 = High, 2 = Medium, 3 = Low): ";
    cin >> p.priority;

    int i = total - 1;
    while (i >= 0 && patients[i].priority > p.priority) {
        patients[i + 1] = patients[i];
        i--;
    }
    patients[i + 1] = p;
    total++;

    cout << "Patient added successfully!\n";
}

void treatPatient() {
    if (total == 0) {
        cout << "No patients to treat.\n";
        return;
    }

    cout << "Treating: " << patients[0].name << " (Priority: " << patients[0].priority << ")\n";

    for (int i = 1; i < total; i++) {
        patients[i - 1] = patients[i];
    }
    total--;
}

void showPatients() {
    if (total == 0) {
        cout << "No patients in the queue.\n";
        return;
    }

    cout << "\nCurrent Patients in Queue:\n";
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << patients[i].name << " (Priority: " << patients[i].priority << ")\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n-:Hospital Menu:-\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Show Patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addPatient();
        } else if (choice == 2) {
            treatPatient();
        } else if (choice == 3) {
            showPatients();
        } else if (choice == 4) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

