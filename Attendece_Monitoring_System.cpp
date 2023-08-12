#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Function to mark attendance
void markAttendance() {
    string studentRollNo;
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    char dateStr[11];
    strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", localTime);

    ofstream outFile("attendance.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    cout << "Enter student's Roll Number: ";
    cin >> studentRollNo;

    outFile << dateStr << " " << studentRollNo << endl;

    cout << "Attendance marked for " << studentRollNo << " on " << dateStr << endl;
}

// Function to display attendance
void displayAttendance() {
    ifstream inFile("attendance.txt");

    if (!inFile) {
        cout << "No attendance records found." << endl;
        return;
    }

    string line;
    cout << "Date\t\tStudent Name" << endl;
    cout << "--------------------------------" << endl;

    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Attendance Monitoring System" << endl;
        cout << "1. Mark Attendance" << endl;
        cout << "2. Display Attendance" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                markAttendance();
                break;
            case 2:
                displayAttendance();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 3);

    return 0;
}
