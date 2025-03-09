#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Chatting.h"

class Chatting : public QMainWindow
{
    Q_OBJECT

public:
    Chatting(QWidget *parent = nullptr);
    ~Chatting();

private:
    Ui::ChattingClass ui;
};
