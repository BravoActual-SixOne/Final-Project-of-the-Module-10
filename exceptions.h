#pragma once
#include <stdexcept>
#include <string>

//перехватываем наиболее стандартные для программы ошибки, выводим ошибку

class UserAlreadyExists : public std::runtime_error {
public:
    UserAlreadyExists(const std::string& login)
        : std::runtime_error("Пользователь с логином '" + login + "' уже существует") {}
};

class UserNotFound : public std::runtime_error {
public:
    UserNotFound(const std::string& login)
        : std::runtime_error("Пользователь с логином '" + login + "' не найден") {}
};

class WrongPassword : public std::runtime_error {
public:
    WrongPassword(const std::string& login)
        : std::runtime_error("Неверный пароль для пользователя '" + login + "'") {}
};