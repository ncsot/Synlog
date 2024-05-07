//loginUser.cpp
#include "../lib/lib.hpp"

bool checkBlockStatus(User& user, const std::time_t& currentTime) {
    double minutes = std::difftime(currentTime, user.last_failed_time) / 60;
    if (minutes >= 30) {
        user.failed_attempts = 0;
        return false; // Аккаунт не заблокирован
    }
    if (user.failed_attempts >= 5) {
        return true; // Аккаунт заблокирован
    }
    return false; // Аккаунт не заблокирован
}

bool loginUser(std::map<std::string, User>& users) {
    std::string username, password;
    std::wcout << L"Введите имя: ";
    std::cin >> username;
    password = getPassword();
    std::time_t now = std::time(nullptr);
    auto user = users.find(username);
    if (user != users.end()) {
        if (checkBlockStatus(user->second, now)) {
            std::wcout << L"Пользователь временно заблокирован. Попробуйте позже.\n";
            return 1;
        }
        if (user->second.password == password) {
            user->second.failed_attempts = 0;
            std::wcout << L"Вход выполнен. Здравствуйте ";
            std::cout << username << std::endl << std::endl;
            showData(user->second.role);
        } else {
            user->second.failed_attempts++;
            user->second.last_failed_time = now;
            std::wcout << L"Вход не выполнен. Неверный пароль\n";
        }
    } else {
        std::wcout << L"Пользователь не найден.\n";
    }
    return 0;
}