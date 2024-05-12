#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <regex>
#include <ctime>
#include <windows.h>
#include <iomanip>

// Структура для хранения данных пользователя
struct User {
    std::string username;
    std::string password;
    std::string role;
    int failed_attempts;
    std::time_t last_failed_time;
};

// Проверка сложности пароля
bool isPasswordComplex(const std::string& password);
// Логин пользователя
bool loginUser(std::map<std::string, User>& users);
// Добавление пользователя
bool addUser(std::map<std::string, User>& users);
// Загрузка пользователей из файла
bool loadUsers(std::map<std::string, User>& users);
// Показывает данные в зависимости от статуса польз-ля
void showData(std::string& role);
// Запрос пароля
std::string getPassword();