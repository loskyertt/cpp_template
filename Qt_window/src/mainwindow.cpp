#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    // 创建并设置 QLabel
    label = new QLabel("Hello, Qt!", this);
    label->setAlignment(Qt::AlignCenter);

    // 设置窗口的中心 widget
    setCentralWidget(label);
    setWindowTitle("Qt Test Application");
    resize(400, 300);
}

MainWindow::~MainWindow()
{
    // 删除 label
    delete label;
}