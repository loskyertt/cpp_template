#include "MyWidget.hpp"
#include <QMessageBox>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent)
    , button(new QPushButton("Click Me", this))
{
    // 设置按钮位置和大小
    button->setGeometry(50, 50, 100, 30);

    // 连接按钮点击信号到槽函数
    connect(button, &QPushButton::clicked, this, &MyWidget::onButtonClicked);
}

void MyWidget::onButtonClicked()
{
    QMessageBox::information(this, "Message", "Button clicked!");
}
