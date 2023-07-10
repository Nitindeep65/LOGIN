#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
};

void registerUser() {
    User user;
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;

    // Open file in append mode
    ofstream outfile("users.txt", ios::app);
    outfile << user.username << " " << user.password << endl;
    outfile.close();

    cout << "Registration successful!" << endl;
}

bool loginUser() {
    User user;
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;

    // Open file for reading
    ifstream infile("users.txt");
    string username, password;
    while (infile >> username >> password) {
        if (username == user.username && password == user.password) {
            infile.close();
            return true;
        }
    }
    infile.close();
    return false;
}

int main() {
    int choice;
    bool isLoggedIn = false;

    do {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                isLoggedIn = loginUser();
                if (isLoggedIn) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Login failed. Invalid username or password." << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
