#include "Chat.h"
#include <iostream>
using namespace std;

int main() {
    Chat chat;   // создаём объект чата
    string currentUserLogin; // логин вошедшего пользователя
    string currentUserName;  // имя вошедшего пользователя

    cout << "Добро пожаловать в чат!\n";
    cout << "Команды:\n";
    cout << " register <login> <pass> <name>\n"; // регистрация пользователя
    cout << " login <login> <pass>\n";          // вход по логину и паролю
    cout << " send <toName> <text>\n";          // отправка сообщения (по имени получателя)
    cout << " show\n";                          // показать все сообщения для вошедшего
    cout << " exit\n";                          // выход из программы

    // основной цикл программы — повторяется, пока пользователь не напишет "exit"
    while (true) {
        cout << "> ";   
        string command;
        cin >> command; // читаем первую "команду" из строки

        if (command == "register") {
            // регистрация: логин, пароль, имя
            string login, pass, name;
            cin >> login >> pass >> name;
            chat.registerUser(login, pass, name);
            cout << "Пользователь " << name << " зарегистрирован.\n";
        }
        else if (command == "login") {
            // вход: логин и пароль
            string login, pass;
            cin >> login >> pass;
            if (chat.loginUser(login, pass)) {
                currentUserLogin = login;                
                currentUserName = chat.getNameByLogin(login); // получаем отображаемое имя
                cout << "Вход выполнен: " << currentUserName << "\n";
            }
        }
        else if (command == "send") {
            if (currentUserLogin.empty()) {
                cout << "Сначала войдите.\n";
                continue;
            }
            // читаем имя получателя
            string toName;
            cin >> toName;

            // читаем оставшийся текст сообщения (может содержать пробелы)
            string text;
            getline(cin, text);
            if (!text.empty() && text[0] == ' ') text.erase(0, 1); // убираем лишний пробел

            // отправляем сообщение от имени вошедшего пользователя
            chat.sendMessage(currentUserName, toName, text);
            cout << "Сообщение отправлено.\n";
        }
        else if (command == "show") {
            // показать все сообщения для текущего пользователя
            if (currentUserLogin.empty()) {
                cout << "Сначала войдите.\n";
            }
            else {
                chat.showMessagesFor(currentUserName);
            }
        }
        else if (command == "exit") {
            // завершаем программу
            cout << "Выход из чата.\n";
            break;
        }
        else {
            // если введена неизвестная команда
            cout << "Неизвестная команда.\n";
        }
    }

    return 0;
}
