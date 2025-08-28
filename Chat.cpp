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

//получаем отоброжаемое имя по логину
std::string Chat::getNameByLogin(const std::string& login) const {
    for (auto& u : users) {
        if (u.getLogin() == login) {
            return u.getName();
        }
    }
    return "";
}

//отправка сообщения - от кого, кому, содержимое
void Chat::sendMessage(const std::string& fromName, const std::string& toName, const std::string& text) {
    messages.emplace_back(fromName, toName, text);
}

//отображение истории сообщений
void Chat::showMessagesFor(const std::string& name) const {
    cout << "📩 Сообщения для " << name << ":\n";
    for (auto& m : messages) {
        if (m.getReceiver() == name || m.getReceiver() == "all") {
            string target = (m.getReceiver() == "all") ? "всех" : m.getReceiver();
            cout << "[От " << m.getSender() << " для " << target << "]: "
                << m.getText() << endl;
        }
    }
    cout << "--------------------------\n";
}
