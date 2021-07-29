#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>  
#include "User.h"
#include "Utils.h"

std::vector<User> load_db(std::string path) {
    std::ifstream db(path);
    std::vector<User> users;
    std::string login, password, nickname;
    if (db.is_open()) {
        std::string line;

        while (!db.eof()) {
            getline(db, nickname, ';');
            getline(db, login, ';');
            getline(db, password, '\n');

            User user = User(nickname, login, password);
            users.push_back(user);
        }
        db.close();
    }
    else {
        std::cout << "Couldn't open the file!\n";
    }
    return users;
}

bool search_credentials(std::string login, std::string password, std::vector<User> users) {
    for (User u : users) {
        if (u.getLogin() == login && u.getPassword() == password) {
            return true;
        }
    }
    return false;
}

User find_user(std::string login, std::vector<User> users) {
    for (User u : users) {
        if (u.getLogin() == login) {
            return u;
        }
    }
}

void add_user(User user) {
    std::ofstream db;
    db.open("./users_db.txt", std::ios::app);
    if (db.is_open()) {
        db << user.getNickname() << ";" << user.getLogin() << ";" << user.getPassword() << std::endl;
    }
    else {
        std::cout << "Couldn't open the file!\n";
    }
}


int main()
{
    int choice = 0;
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
            {
                std::string l_login, l_password;
                std::cout << "You are currently trying to log in." << std::endl;
                std::vector<User> users = load_db("./users_db.txt");
                while (true) {
                    std::cout << "Login: ";
                    std::cin >> l_login;
                    std::cout << "Password: ";
                    std::cin >> l_password;

                    if (search_credentials(l_login, l_password, users)) {
                        std::cout << "You are logged as " << find_user(l_login, users).getNickname();
                    }
                    else {
                        std::cout << "WRONG LOGIN OR PASSWORD\n";
                    }
                }
                break;
            } 
            case 2:
            {
                std::cout << "You are currently trying to register." << std::endl;
                std::string r_nickname, r_login, r_password;
                while (true) {
                    std::cout << "Enter Nickname: ";
                    std::cin >> r_nickname;
                    std::cout << "Enter Login: ";
                    std::cin >> r_login;
                    std::cout << "Enter Password";
                    std::cin >> r_password;
                    User new_user = User(r_nickname, r_login, r_password);
                    add_user(new_user);
                    break;
                }
                break;
            } 
            case 3:
                return 0;
                break;
            default:
                std::cout << "There is no such choice." << std::endl;
                break;
        }
    }
    return 0;
}