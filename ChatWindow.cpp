#include "ChatWindow.h"


ChatWindow::ChatWindow(ChatSession& chatSession, User& user, QWidget *parent)
	: chatSession(chatSession), user(user), QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(user.getName()));

	populateList();
}

ChatWindow::~ChatWindow()
{}

void ChatWindow::update() {
	populateList();
}

void ChatWindow::populateList() {
	ui.messageList->clear();
	for (auto m : chatSession.getMessages()) {
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(m.toString()) };
		ui.messageList->addItem(item);
	}
}
