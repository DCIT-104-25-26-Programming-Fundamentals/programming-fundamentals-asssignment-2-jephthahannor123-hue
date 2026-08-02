// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

vector<Student> students;

// ---------------------------------------------------------
// Helper: compute average of a student's scores
// ---------------------------------------------------------
double calculateAverage(const Student& s) {
    if (s.scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : s.scores) {
        sum += score;
    }
    return sum / s.scores.size();
}

// ---------------------------------------------------------
// 1. Add a Student
// ---------------------------------------------------------
void addStudent() {
    Student s;

    cout << "Student name: ";
    cin.ignore(); // clear leftover newline from previous input
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    while (numScores < 0) {
        cout << "Please enter a non-negative number of scores: ";
        cin >> numScores;
    }

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// ---------------------------------------------------------
// 2. Display All Students
// ---------------------------------------------------------
void displayAllStudents() {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n----------------------------------------------------------\n";
    cout << left << setw(20) << "Name" << setw(12) << "ID"
         << setw(20) << "Scores" << "Average\n";
    cout << "----------------------------------------------------------\n";

    for (const Student& s : students) {
        cout << left << setw(20) << s.name << setw(12) << s.id;

        string scoreStr;
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoreStr += to_string((int)s.scores[i]);
            if (i != s.scores.size() - 1) scoreStr += ",";
        }
        cout << setw(20) << scoreStr;
        cout << calculateAverage(s) << "\n";
    }
    cout << "----------------------------------------------------------\n\n";
}

// ---------------------------------------------------------
// 3. Calculate Average Score for a Specific Student
// ---------------------------------------------------------
void calculateAverageForStudent() {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& s : students) {
        if (s.id == id) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: "
                 << calculateAverage(s) << "\n";
            return;
        }
    }

    cout << "Error: Student with ID " << id << " not found.\n";
}

// ---------------------------------------------------------
// Menu display
// ---------------------------------------------------------
void printMenu() {
    cout << "================================\n";
    cout << "   STUDENT RECORD SYSTEM MENU\n";
    cout << "================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
}

// ---------------------------------------------------------
// Main program loop
// ---------------------------------------------------------
int main() {
    int choice;
    bool running = true;

    while (running) {
        printMenu();

        if (!(cin >> choice)) {
            // handle non-numeric input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                calculateAverageForStudent();
                break;
            case 4:
                cout << "Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }
        cout << "\n";
    }

    return 0;
}
