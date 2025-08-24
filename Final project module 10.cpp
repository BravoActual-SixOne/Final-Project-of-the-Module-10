#include <iostream>
#include "Chat.h"

int main() {
    Chat chat;

    try {
        chat.registerUser("alice", "123", "Alice");
        chat.registerUser("bob", "qwe", "Bob");

        // попытка повторной регистрации
        chat.registerUser("alice", "xxx", "Alice2");
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Ошибка: " << e.what() << std::endl;
    }

    try {
        if (chat.loginUser("alice", "123")) {
            chat.sendMessage("alice", "bob", "Привет, Боб!");
            chat.sendMessage("alice", "all", "Всем привет!");
        }

        if (chat.loginUser("bob", "qwe")) {
            chat.sendMessage("bob", "alice", "И тебе привет, Алиса!");
        }

        chat.showMessagesFor("bob");
        chat.showMessagesFor("alice");
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Ошибка: " << e.what() << std::endl;
    }

    return 0;
}