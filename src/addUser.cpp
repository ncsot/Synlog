//addUser.cpp
#include "../lib/lib.hpp"

bool isPasswordComplex(const std::string& password) {
    static const std::regex pattern(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\x21-\x2F\x3A-\x40\x5B-\x60\x7B-\x7E]).{8,}$)");
    return std::regex_match(password, pattern);
}

bool addUser(std::map<std::string, User>& users) {
    std::string username, password, role;
    std::wcout << L"Введите имя пользователя: ";
    std::cin >> username;
    if (users.find(username) != users.end()) {
        std::wcout << L"Пользователь ";
        std::cout << username;
        std::wcout << L" уже существует!" << std::endl;
        return false;
    }
    password = getPassword();
    if (password.empty()) {
        std::wcout << L"Пароль не может быть пустым, пожалуйста введите пароль.\n";
        return false;
    }
    if (!isPasswordComplex(password)) {
        std::wcout << L"Пароль не достаточно сложный!\n";
        std::wcout << L"Минимальная длина - 8 символов, должен включать большие и маленькие латинские буквы, цифры и специальные символы.\n";
        return false;
    }
    role = "user";
    users[username] = {username, password, role, 0, std::time(nullptr)};
    std::ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << username << ';' << password << ';' << role << '\n';
        file.close();
    } else {
        std::wcerr << L"Не удалось открыть файл для записи.\n";
        return false;
    }
    std::wcout << L"Пользователь ";
    std::cout << username;
    std::wcout << L" успешно создан." << std::endl;
    return true;
}