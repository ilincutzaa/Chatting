#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <QWidget>
#include "ui_ChatWindow.h"
#include "Observer.h"
#include <qwidget.h>
#include "ChatSession.h"
#include <ctime>

class ChatWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	ChatWindow(ChatSession& chatSession, User& user, QWidget *parent = nullptr);
	~ChatWindow();
	void update() override;

private:
	Ui::ChatWindowClass ui;
	ChatSession& chatSession;
	User& user;
	void populateList();
private slots:
	void on_sendButton_clicked(){
		QString txt = ui.messageEdit->text();
		if (txt != "") {
			ui.messageEdit->clear();

			std::time_t now = std::time(nullptr);
			std::tm* localTime = std::localtime(&now);
			int hour = localTime->tm_hour;
			int minute = localTime->tm_min;

			std::stringstream time;
			time << hour << ":" << minute;

			Message message{ time.str(), txt.toStdString()};
			chatSession.addMessage(user, message);
		}
	}
};
