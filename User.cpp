#include "User.h"

User::User(const std::string& l, const std::string& p, const std::string& n)
    : login(l), password(p), name(n) {
}

//проверка на совпадение введённого и установленного паролей
bool User::checkPassword(const std::string& pass) const {
    return password == pass;
}

//набор геттеров для класса
std::string User::getLogin() const { return login; }
std::string User::getName() const { return name; }