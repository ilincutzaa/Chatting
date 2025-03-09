#include "ChatWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    User u1{ "1", "User1" };
    User u2{ "2", "User2" };
    User u3{ "3", "User3" };

    ChatSession chatSession;

    ChatWindow w1(chatSession, u1);
    ChatWindow w2(chatSession, u2);
    ChatWindow w3(chatSession, u3);

    chatSession.registerObserver(&w1);
    chatSession.registerObserver(&w2);
    chatSession.registerObserver(&w3);

    w1.show();
    w2.show();
    w3.show();

    return a.exec();
}
