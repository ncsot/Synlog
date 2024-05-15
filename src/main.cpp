//main.cpp
#include "../lib/lib.hpp"

using namespace std;

int main() {
    setlocale(LC_CTYPE,"Russian");
    map<string, User> users;
    int menuUsrSelect;
    wstring menuStr = L"Выберите действие: \n1) Войти\n2) Добавить пользователя\n3) Для выхода\n";
    wstring endStr = L"Программа завершена. До свидания!";

    wcout << menuStr;
    while (cin >> menuUsrSelect) {
        if (!loadUsers(users)) return 1;
        switch (menuUsrSelect) {
            case 1:
                loginUser(users);
                break;
            case 2:
                addUser(users);
                break;
            default:
                wcout << endStr << endl;
                return 0;
        }
        wcout << "\n" << menuStr;
    }
    wcout << endStr << endl;
    return 0;
}