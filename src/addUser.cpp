//addUser.cpp
#include "../lib/lib.hpp"

using namespace std;

bool isPasswordComplex(const string& password) {
    static const regex pattern(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\x21-\x2F\x3A-\x40\x5B-\x60\x7B-\x7E]).{8,}$)");
    return regex_match(password, pattern);
}

bool addUser(map<string, User>& users) {
    string username, password, role;
    wcout << L"Введите имя пользователя: ";
    cin >> username;
    if (users.find(username) != users.end()) {
        wcout << L"Пользователь ";
        cout << username;
        wcout << L" уже существует!" << endl;
        return false;
    }
    password = getPassword();
    if (password.empty()) {
        wcout << L"Пароль не может быть пустым, пожалуйста введите пароль.\n";
        return false;
    }
    if (!isPasswordComplex(password)) {
        wcout << L"Пароль не достаточно сложный!\n";
        wcout << L"Минимальная длина - 8 символов, должен включать большие и маленькие латинские буквы, цифры и специальные символы.\n";
        return false;
    }
    role = "user";
    users[username] = {username, password, role, 0, time(nullptr)};
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << ';' << password << ';' << role << '\n';
        file.close();
    } else {
        wcerr << L"Не удалось открыть файл для записи.\n";
        return false;
    }
    wcout << L"Пользователь ";
    cout << username;
    wcout << L" успешно создан." << endl;
    return true;
}