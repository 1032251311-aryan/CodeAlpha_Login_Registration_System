
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    string savedUsername, savedPassword;

    cout << "\n========== USER REGISTRATION ==========\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Open file to check existing users
    ifstream file("users.txt");

    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username) {
            cout << "\nUsername already exists!\n";
            file.close();
            return;
        }
    }

    file.close();

    // Save new user details
    ofstream outfile("users.txt", ios::app);

    if (!outfile) {
        cout << "\nError: Unable to save user details!\n";
        return;
    }

    outfile << username << " " << password << endl;

    outfile.close();

    cout << "\nRegistration successful!\n";
    cout << "Welcome, " << username << "!\n";
}

// Function to login an existing user
void loginUser() {
    string username, password;
    string savedUsername, savedPassword;
    bool found = false;

    cout << "\n========== USER LOGIN ==========\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Open user database
    ifstream file("users.txt");

    if (!file) {
        cout << "\nNo registered users found. Please register first.\n";
        return;
    }

    // Verify username and password
    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username &&
            savedPassword == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "\nLogin successful!\n";
        cout << "Welcome back, " << username << "!\n";
    }
    else {
        cout << "\nInvalid username or password!\n";
    }
}

// Main function
int main() {
    int choice=0;

    do {
        cout << "\n====================================\n";
        cout << "    LOGIN AND REGISTRATION SYSTEM\n";
        cout << "====================================\n";

        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";

        cout << "\n\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input! Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch (choice) {

            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using our system!\n";
                cout << "Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please select 1, 2 or 3.\n";
        }

    } while (choice != 3);

    return 0;
}

