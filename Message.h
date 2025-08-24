#pragma once
#include <string>

class Message {
public:
    Message(const std::string& from, const std::string& to, const std::string& text);

    std::string getSender() const;
    std::string getReceiver() const;
    std::string getText() const;

private:
    std::string sender;
    std::string receiver;
    std::string text;
};