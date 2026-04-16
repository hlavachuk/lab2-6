#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

struct User {
    string nickname;
    int age;
};

vector<shared_ptr<Shape>> shapes;
vector<User> users;

bool adminLogin() {
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    return password == "2112";
}

void saveHistory(const string& action) {
    ofstream file("history.txt", ios::app);
    if (file.is_open()) {
        file << action << endl;
    }
    file.close();
}

void saveShapesToFile() {
    ofstream file("shapes.txt");
    if (!file.is_open()) {
        throw runtime_error("File not opened!");
    }

    for (const auto& shape : shapes) {
        Circle* c = dynamic_cast<Circle*>(shape.get());
        Rectangle* r = dynamic_cast<Rectangle*>(shape.get());
        Triangle* t = dynamic_cast<Triangle*>(shape.get());

        if (c) {
            file << "Circle " << *c << endl;
        }
        else if (r) {
            file << "Rectangle " << *r << endl;
        }
        else if (t) {
            file << "Triangle " << *t << endl;
        }
    }

    file.close();
}

void loadShapesFromFile() {
    ifstream file("shapes.txt");
    if (!file.is_open()) {
        return;
    }

    string type;
    while (file >> type) {
        if (type == "Circle") {
            auto c = make_shared<Circle>();
            file >> *c;
            shapes.push_back(c);
        }
        else if (type == "Rectangle") {
            auto r = make_shared<Rectangle>();
            file >> *r;
            shapes.push_back(r);
        }
        else if (type == "Triangle") {
            auto t = make_shared<Triangle>();
            file >> *t;
            shapes.push_back(t);
        }
    }

    file.close();
}

void saveUsersToFile() {
    ofstream file("users.txt");
    if (!file.is_open()) {
        throw runtime_error("Users file not opened!");
    }

    for (const auto& user : users) {
        file << user.nickname << " " << user.age << endl;
    }

    file.close();
}

void loadUsersFromFile() {
    ifstream file("users.txt");
    if (!file.is_open()) {
        return;
    }

    User user;
    while (file >> user.nickname >> user.age) {
        users.push_back(user);
    }

    file.close();
}

bool userExists(const string& nickname) {
    for (const auto& user : users) {
        if (user.nickname == nickname) {
            return true;
        }
    }
    return false;
}

void showAllUsers() {
    if (users.empty()) {
        cout << "No users available.\n";
        return;
    }

    cout << "\n=== USERS LIST ===\n";
    for (size_t i = 0; i < users.size(); i++) {
        cout << i + 1 << ". Nickname: " << users[i].nickname
            << ", Age: " << users[i].age << endl;
    }
}

void addUser() {
    User user;
    cout << "Enter user nickname: ";
    cin >> user.nickname;
    cout << "Enter user age: ";
    cin >> user.age;

    if (userExists(user.nickname)) {
        cout << "User with this nickname already exists.\n";
        return;
    }

    users.push_back(user);
    saveUsersToFile();

    cout << "User added.\n";
    saveHistory("Admin added user: " + user.nickname);
}

void deleteUser() {
    if (users.empty()) {
        cout << "No users available.\n";
        return;
    }

    showAllUsers();

    int index;
    cout << "Enter user number to delete: ";
    cin >> index;

    if (index < 1 || index >(int)users.size()) {
        cout << "Wrong number.\n";
        return;
    }

    string deletedName = users[index - 1].nickname;

    users.erase(users.begin() + (index - 1));

    saveUsersToFile();

    cout << "User deleted.\n";
    saveHistory("Admin deleted user: " + deletedName);
}

void showAllShapes() {
    if (shapes.empty()) {
        cout << "No shapes available.\n";
        return;
    }

    for (size_t i = 0; i < shapes.size(); i++) {
        cout << i + 1 << ". ";
        shapes[i]->display();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
        cout << "-------------------" << endl;
    }
}

void deleteShapeMenu() {
    int choice;
    do {
        cout << "\n=== DELETE MENU ===\n";
        cout << "1. Delete Circle\n";
        cout << "2. Delete Rectangle\n";
        cout << "3. Delete Triangle\n";
        cout << "4. Delete all shapes\n";
        cout << "5. Delete shape by number\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        bool deleted = false;

        switch (choice) {
        case 1:
            for (auto it = shapes.begin(); it != shapes.end(); ++it) {
                if (dynamic_cast<Circle*>(it->get())) {
                    shapes.erase(it);
                    saveShapesToFile();
                    cout << "Circle deleted.\n";
                    saveHistory("Admin deleted Circle");
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                cout << "No Circle found.\n";
            }
            break;

        case 2:
            for (auto it = shapes.begin(); it != shapes.end(); ++it) {
                if (dynamic_cast<Rectangle*>(it->get())) {
                    shapes.erase(it);
                    saveShapesToFile();
                    cout << "Rectangle deleted.\n";
                    saveHistory("Admin deleted Rectangle");
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                cout << "No Rectangle found.\n";
            }
            break;

        case 3:
            for (auto it = shapes.begin(); it != shapes.end(); ++it) {
                if (dynamic_cast<Triangle*>(it->get())) {
                    shapes.erase(it);
                    saveShapesToFile();
                    cout << "Triangle deleted.\n";
                    saveHistory("Admin deleted Triangle");
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                cout << "No Triangle found.\n";
            }
            break;

        case 4:
            shapes.clear();
            saveShapesToFile();
            cout << "All shapes deleted.\n";
            saveHistory("Admin deleted all shapes");
            break;

        case 5: {
            if (shapes.empty()) {
                cout << "No shapes available.\n";
                break;
            }

            showAllShapes();

            int index;
            cout << "Enter shape number to delete: ";
            cin >> index;

            if (index < 1 || index >(int)shapes.size()) {
                cout << "Wrong number.\n";
            }
            else {
                shapes.erase(shapes.begin() + (index - 1));
                saveShapesToFile();
                cout << "Shape deleted.\n";
                saveHistory("Admin deleted shape by number");
            }
            break;
        }

        case 0:
            break;

        default:
            cout << "Wrong choice.\n";
        }

    } while (choice != 0);
}

void adminMenu() {
    int choice;
    do {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add Circle\n";
        cout << "2. Add Rectangle\n";
        cout << "3. Add Triangle\n";
        cout << "4. Show all shapes\n";
        cout << "5. Save shapes to file\n";
        cout << "6. Delete menu\n";
        cout << "7. Add user\n";
        cout << "8. Show all users\n";
        cout << "9. Save users to file\n";
        cout << "10. Delete user\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                double radius;
                cout << "Enter radius: ";
                cin >> radius;
                shapes.push_back(make_shared<Circle>(radius));
                saveShapesToFile();
                cout << "Circle added.\n";
                saveHistory("Admin added Circle");
                break;
            }
            case 2: {
                double width, height;
                cout << "Enter width: ";
                cin >> width;
                cout << "Enter height: ";
                cin >> height;
                shapes.push_back(make_shared<Rectangle>(width, height));
                saveShapesToFile();
                cout << "Rectangle added.\n";
                saveHistory("Admin added Rectangle");
                break;
            }
            case 3: {
                double a, b, c;
                cout << "Enter side a: ";
                cin >> a;
                cout << "Enter side b: ";
                cin >> b;
                cout << "Enter side c: ";
                cin >> c;
                shapes.push_back(make_shared<Triangle>(a, b, c));
                saveShapesToFile();
                cout << "Triangle added.\n";
                saveHistory("Admin added Triangle");
                break;
            }
            case 4:
                showAllShapes();
                break;
            case 5:
                saveShapesToFile();
                cout << "Shapes saved to file.\n";
                break;
            case 6:
                deleteShapeMenu();
                break;
            case 7:
                addUser();
                break;
            case 8:
                showAllUsers();
                break;
            case 9:
                saveUsersToFile();
                cout << "Users saved to file.\n";
                break;
            case 10:
                deleteUser();
                break;
            case 0:
                break;
            default:
                cout << "Wrong choice.\n";
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);
}

void userMenu(const string& currentUser) {
    int choice;
    do {
        cout << "\n=== USER MENU ===\n";
        cout << "Hello, " << currentUser << "!\n";
        cout << "1. Show all shapes\n";
        cout << "2. Save action to history\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                showAllShapes();
                saveHistory("User " + currentUser + " viewed shapes");
                break;
            case 2:
                saveHistory("User " + currentUser + " used the program");
                cout << "Saved to history.\n";
                break;
            case 0:
                break;
            default:
                cout << "Wrong choice.\n";
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);
}

int main() {
    loadShapesFromFile();
    loadUsersFromFile();

    int choice;

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (adminLogin()) {
                adminMenu();
            }
            else {
                cout << "Wrong password!\n";
            }
            break;

        case 2: {
            string nickname;
            cout << "Enter your nickname: ";
            cin >> nickname;

            if (userExists(nickname)) {
                saveHistory("User logged in: " + nickname);
                userMenu(nickname);
            }
            else {
                cout << "User not found. Ask admin to add you first.\n";
            }
            break;
        }

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Wrong choice.\n";
        }

    } while (choice != 0);

    return 0;
}