//showdData.cpp
#include "../lib/lib.hpp"

void showData(std::string& role) {
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::wcerr << L"Не удалось открыть файл с данными.\n";
        return;
    }
    std::string line;
    while (getline(file, line)) {
        // Разбиваем строку на части по запятой
        std::istringstream iss(line);
        std::vector<std::string> parts;
        std::string part;
        while (getline(iss, part, ',')) {
            parts.push_back(part);
        }
        // Проверяем роль пользователя
        if (role == "admin") {
            // Если пользователь - администратор, то выводим всю информацию
            std::cout << std::setw(5) << parts[0] << std::setw(15) << parts[1] << std::setw(10) << parts[2] << std::endl;
        } else {
            // Если пользователь - обычный, то выводим только ID и название
            std::cout << std::setw(5) << parts[0] << std::setw(15) << parts[1] << std::endl;
        }
    }
    file.close();
}
