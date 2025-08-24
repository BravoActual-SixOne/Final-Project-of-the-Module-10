#include "Message.h"

Message::Message(const std::string& f, const std::string& t, const std::string& msg)
    : sender(f), receiver(t), text(msg) {
}

std::string Message::getSender() const { return sender; }
std::string Message::getReceiver() const { return receiver; }
std::string Message::getText() const { return text; }