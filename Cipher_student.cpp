#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Pupil {
    int id;
    string fullname;
    string dept;
    string subject;
    int yearOfStudy;
};

vector<Pupil> pupilList;

void insertPupil();
void displayAllPupils();
void searchPupil();
void updatePupil(); 
void removePupil(); 
void displayMenu();

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int option;
    do {
        cout << "\n==== Student Record Management System ====\n";
        cout << "1. Insert Pupil Record\n";
        cout << "2. Show All Pupil Records\n";
        cout << "3. Find Pupil Record\n";
        cout << "4. Edit Pupil Record\n";
        cout << "5. Remove Pupil Record\n";
        cout << "6. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        // Check if the input is valid
        if (cin.fail()) {
            cout << "Invalid option! Please enter a number between 1 and 6.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Skip the rest of the loop and start over
        }

        // Clear input buffer to avoid incorrect inputs
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(option) {
            case 1: insertPupil(); break;
            case 2: displayAllPupils(); break;
            case 3: searchPupil(); break;
            case 4: updatePupil(); break;
            case 5: removePupil(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid option! Please try again.\n";
        }
    } while(option != 6);
}

void insertPupil() {
    Pupil pupil;

    // Loop to ensure valid integer input for roll number
    while (true) {
        cout << "\nEnter ID Number: ";
        cin >> pupil.id;
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer for ID Number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            break; // Valid input
        }
    }

    cout << "Enter Full Name: ";
    getline(cin, pupil.fullname);
    cout << "Enter Department: ";
    getline(cin, pupil.dept);
    cout << "Enter Subject: ";
    getline(cin, pupil.subject);
    cout << "Enter Year of Study: ";
    cin >> pupil.yearOfStudy;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

    pupilList.push_back(pupil);
    cout << "\nPupil record has been added\n";
}

void displayAllPupils() {
    if (pupilList.empty()) {
        cout << "\nNo pupil records found.\n";
        return;
    }

    cout << "\n==== Displaying All Pupil Records ====\n";
    for (const auto& pupil : pupilList) {
        cout << "\nID Number: " << pupil.id;
        cout << "\nFull Name: " << pupil.fullname;
        cout << "\nDepartment: " << pupil.dept;
        cout << "\nSubject: " << pupil.subject;
        cout << "\nYear of Study: " << pupil.yearOfStudy;
        cout << "\n====================================\n";
    }
}

void searchPupil() {
    int id;
    cout << "\nEnter the ID number of the pupil to search: ";
    cin >> id;

    // Clear input buffer to avoid incorrect inputs
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;
    for (const auto& pupil : pupilList) {
        if (pupil.id == id) {
            cout << "\nID Number: " << pupil.id;
            cout << "\nFull Name: " << pupil.fullname;
            cout << "\nDepartment: " << pupil.dept;
            cout << "\nSubject: " << pupil.subject;
            cout << "\nYear of Study: " << pupil.yearOfStudy;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nPupil record not found.\n";
    }
}

void updatePupil() {
    int id;
    cout << "\nEnter the ID number of the pupil to modify: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

    bool found = false;
    for (auto& pupil : pupilList) {
        if (pupil.id == id) {
            cout << "\nEnter new details for the pupil\n";
            cout << "Enter Full Name: ";
            getline(cin, pupil.fullname);
            cout << "Enter Department: ";
            getline(cin, pupil.dept);
            cout << "Enter Subject: ";
            getline(cin, pupil.subject);
            cout << "Enter Year of Study: ";
            cin >> pupil.yearOfStudy;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

            cout << "\nPupil record has been updated\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nPupil record not found.\n";
    }
}

void removePupil() {
    int id;
    cout << "\nEnter the ID number of the pupil to delete: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

    auto it = pupilList.begin();
    bool found = false;
    while (it != pupilList.end()) {
        if (it->id == id) {
            it = pupilList.erase(it);
            found = true;
            cout << "\nPupil record has been deleted\n";
            break;
        } else {
            ++it;
        }
    }

    if (!found) {
        cout << "\nPupil record not found.\n";
    }
}

