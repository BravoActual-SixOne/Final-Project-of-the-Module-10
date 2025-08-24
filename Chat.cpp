#include "Chat.h"
#include <iostream>

//Регистрация - принимаем логин и пароль, отоброжаемое имя.
void Chat::registerUser(const std::string& login, const std::string& pass, const std::string& name) {
    for (auto& u : users) {
        if (u.getLogin() == login) {
            throw UserAlreadyExists(login);
        }
    }
    users.emplace_back(login, pass, name);
}

//вход, по паролю и логину.
bool Chat::loginUser(const std::string& login, const std::string& pass) {
    for (auto& u : users) {
        if (u.getLogin() == login) {
            if (u.checkPassword(pass)) {
                return true;
            }
            else {
                throw WrongPassword(login);
            }
        }
    }
    throw UserNotFound(login);
}

//отправка сообщения - от кого, кому, содержимое
void Chat::sendMessage(const std::string& from, const std::string& to, const std::string& text) {
    messages.emplace_back(from, to, text);
}

//отображение истории сообщений
void Chat::showMessagesFor(const std::string& login) const {
    std::cout << "Сообщения для " << login << ":\n";
    for (auto& m : messages) {
        if (m.getReceiver() == login || m.getReceiver() == "all") {
            std::string target = (m.getReceiver() == "all") ? "всех" : m.getReceiver();
            std::cout << "[От " << m.getSender() << " для " << target << "]: "
                << m.getText() << std::endl;
        }
    }
    std::cout << "--------------------------\n";
}