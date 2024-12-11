#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QLabel>
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow(); // 添加 virtual 关键字

private:
    QLabel* label;
};

#endif // MAINWINDOW_HPP