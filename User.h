#pragma once
#include <string>

class User {
public:
    User(const std::string& login, const std::string& pass, const std::string& name);

    bool checkPassword(const std::string& pass) const;
    std::string getLogin() const;
    std::string getName() const;

private:
    std::string login;
    std::string password;
    std::string name;
};