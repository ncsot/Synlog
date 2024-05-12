//main.cpp
#include "../lib/lib.hpp"

int main() {
    setlocale(LC_CTYPE,"Russian");
    std::map<std::string, User> users;
    int menuUsrSelect;
    std::wstring menuStr = L"Выберите действие: \n1) Войти\n2) Добавить пользователя\n3) Для выхода\n";
    std::wstring endStr = L"Программа завершена. До свидания!";

    std::wcout << menuStr;
    while (std::cin >> menuUsrSelect) {
        if (!loadUsers(users)) return 1;
        switch (menuUsrSelect) {
            case 1:
                loginUser(users);
                break;
            case 2:
                addUser(users);
                break;
            default:
                std::wcout << endStr << std::endl;
                return 0;
        }
        std::wcout << "\n" << menuStr;
    }
    std::wcout << endStr << std::endl;
    return 0;
}