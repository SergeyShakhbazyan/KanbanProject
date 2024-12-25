//
// Created by Serg_Sh on 24.12.24.
//

#ifndef KANBANPROJECT_MAINWINDOW_H
#define KANBANPROJECT_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QWidget* centralWidget;
    QHBoxLayout* mainLayout;
};


#endif //KANBANPROJECT_MAINWINDOW_H
