#pragma once
#include "Observer.h"
#include "UserMessage.h"

class ChatSession : public Subject {
private:
	std::vector<UserMessage> messages;
public:
	void addMessage(User u, Message m) {
		UserMessage um{ u,m };
		messages.push_back(um);
		notify();
	}
	std::vector<UserMessage> getMessages() {
		return messages;
	}
};