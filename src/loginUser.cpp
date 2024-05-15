//loginUser.cpp
#include "../lib/lib.hpp"

using namespace std;

// Проверяем временную блокировку 
bool checkBlockStatus(User& user, const time_t& currentTime) {
    double minutes = difftime(currentTime, user.last_failed_time) / 60;
    if (minutes >= 30) {
        user.failed_attempts = 0;
        return false; // Аккаунт не заблокирован
    }
    if (user.failed_attempts >= 5) {
        return true; // Аккаунт заблокирован
    }
    return false; // Аккаунт не заблокирован
}
// Вход пользователя
bool loginUser(map<string, User>& users) {
    string username, password;
    wcout << L"Введите имя: ";
    cin >> username;
    time_t now = time(nullptr);
    auto user = users.find(username);
    if (user != users.end()) {
        password = getPassword();
        if (user->second.password == password) {
            if (checkBlockStatus(user->second, now)) {
                wcout << L"Пользователь временно заблокирован. Попробуйте позже.\n";
                return 1;
            } else {
                user->second.failed_attempts = 0;
                wcout << L"Вход выполнен. Здравствуйте ";
                cout << username << endl << endl;
                showData(user->second.role);
            }
        } else {
            user->second.failed_attempts++;
            user->second.last_failed_time = now;
            wcout << L"Вход не выполнен. Неверный пароль\n";
        }
    } else {
        wcout << L"Пользователь не найден.\n";
    }
    return 0;
}