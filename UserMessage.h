#pragma once
#include "User.h"
#include "Message.h"
#include <sstream>
#include <iostream>

class UserMessage {
private:
	User user;
	Message message;
public:
	UserMessage(User user, Message message) : user(user), message(message) {};
	User getUser() {
		return user;
	}
	Message getMessage() {
		return message;
	}
	std::string toString() {
		std::stringstream txt;
		txt << user.getName() << ": " << message.getMessage() << "\t" << message.getTimeStamp();
		return txt.str();
	}
};