#pragma once
#include <string>

class Message {
private:
	std::string tm;
	std::string message;
public:
	Message(std::string tm, std::string message) : tm(tm), message(message) {};
	std::string getTimeStamp() {
		return tm;
	}
	std::string getMessage() {
		return message;
	}
};