//getPassword.cpp
#include "../lib/lib.hpp"

std::string getPassword() {
    std::string password;
    char ch;
    DWORD mode, read;
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    // Получаем текущий режим консоли
    GetConsoleMode(hStdin, &mode);
    // Устанавливаем новый режим консоли
    // Отключаем ECHO_INPUT, чтобы символы не отображались при вводе
    SetConsoleMode(hStdin, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
    std::wcout << L"Введите пароль: ";
    while (ReadConsole(hStdin, &ch, 1, &read, NULL) && ch != '\r') {
        if (ch == '\b') { // Обработка нажатия backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b"; // Стираем символ с консоли
            }
        } else {
            password.push_back(ch);
            std::cout << '*'; // Выводим символ замены
        }
    }
    std::cout << std::endl;
    // Восстанавливаем оригинальный режим консоли
    SetConsoleMode(hStdin, mode);
    return password;
}