//getPassword.cpp
#include "../lib/lib.hpp"

using namespace std;

string getPassword() {
    string password;
    char ch;
    DWORD mode, read;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    // Получаем текущий режим консоли
    GetConsoleMode(h, &mode);
    // Устанавливаем новый режим консоли
    // Отключаем ECHO_INPUT, чтобы символы не отображались при вводе
    SetConsoleMode(h, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
    wcout << L"Введите пароль: ";
    while (ReadConsole(h, &ch, 1, &read, NULL) && ch != '\r') {
        if (ch == '\b') { // Обработка нажатия backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // Стираем символ с консоли
            }
        } else {
            password.push_back(ch);
            cout << '*'; // Выводим символ замены
        }
    }
    cout << endl;
    // Восстанавливаем оригинальный режим консоли
    SetConsoleMode(h, mode);
    return password;
}