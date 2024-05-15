//showdData.cpp
#include "../lib/lib.hpp"

using namespace std;

void showData(string& role) {
    ifstream file("data.txt");
    if (!file.is_open()) {
        wcerr << L"Не удалось открыть файл с данными.\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        // Разбиваем строку на части по запятой
        istringstream iss(line);
        vector<string> parts;
        string part;
        while (getline(iss, part, ',')) {
            parts.push_back(part);
        }
        // Проверяем роль пользователя
        if (role == "admin") {
            // Если пользователь - администратор, то выводим всю информацию
            cout << setw(5) << parts[0] << setw(15) << parts[1] << setw(10) << parts[2] << endl;
        } else {
            // Если пользователь - обычный, то выводим только ID и название
            cout << setw(5) << parts[0] << setw(15) << parts[1] << endl;
        }
    }
    file.close();
}
