#pragma once

#include <QPushButton>
#include <QWidget>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget* parent = nullptr);

private slots:
    void onButtonClicked();

private:
    QPushButton* button;
};
