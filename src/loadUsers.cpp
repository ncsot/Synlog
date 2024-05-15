//loadUsers.cpp
#include "../lib/lib.hpp"

using namespace std;

bool loadUsers(map<string, User>& users) {
    ifstream file("users.txt");
    if (!file.is_open()) {
        wcerr << L"Файл с пользователями не может быть открыт\n";
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream stringStream(line);
        string username, password, role;
        getline(stringStream, username, ';');
        getline(stringStream, password, ';');
        getline(stringStream, role);
        users[username] = {username, password, role, users[username].failed_attempts, users[username].last_failed_time};
    }
    file.close();
    return true;
}