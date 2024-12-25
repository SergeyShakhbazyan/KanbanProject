//
// Created by Serg_Sh on 24.12.24.
//

#include "../include/MainWindow.h"
#include "../include/KanbanColumn.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(10, 10, 10, 10);

    KanbanColumn* column1 = new KanbanColumn("To Do", centralWidget);
    KanbanColumn* column2 = new KanbanColumn("In Progress", centralWidget);
    KanbanColumn* column3 = new KanbanColumn("Done", centralWidget);

    mainLayout->addWidget(column1);
    mainLayout->addWidget(column2);
    mainLayout->addWidget(column3);

    setWindowTitle("Kanban Board");
    resize(1200, 800);
    setStyleSheet("background-color: #3282b8;");
}

MainWindow::~MainWindow() {
    delete centralWidget;
}
