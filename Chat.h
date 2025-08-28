#pragma once
#include <vector>
#include "User.h"
#include "Message.h"
#include "exceptions.h"

class Chat {
public:
    void registerUser(const std::string& login, const std::string& pass, const std::string& name);
    bool loginUser(const std::string& login, const std::string& pass);

    void sendMessage(const std::string& from, const std::string& to, const std::string& text);
    void showMessagesFor(const std::string& login) const;

    std::string getNameByLogin(const std::string& login) const;

private:
    std::vector<User> users;
    std::vector<Message> messages;

};
