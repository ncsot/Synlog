//loadUsers.cpp
#include "../lib/lib.hpp"

bool loadUsers(std::map<std::string, User>& users) {
    std::ifstream file("users.txt");
    if (!file.is_open()) {
        std::wcerr << L"Файл с пользователями не может быть открыт\n";
        return false;
    }
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password, role;
        getline(iss, username, ';');
        getline(iss, password, ';');
        getline(iss, role);
        users[username] = {username, password, role, users[username].failed_attempts, users[username].last_failed_time};
    }
    file.close();
    return true;
}