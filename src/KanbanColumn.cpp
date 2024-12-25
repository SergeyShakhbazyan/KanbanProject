//
// Created by Serg_Sh on 24.12.24.
//

#include "../include/KanbanColumn.h"
#include "../include/CardWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidgetItem>
#include <QMimeData>
#include <iostream>

KanbanColumn::KanbanColumn(const QString &title, QWidget *parent) : QWidget(parent){
    setAcceptDrops(true);

    QVBoxLayout* columnLayout = new QVBoxLayout(this);
    columnLayout->setSpacing(19);
    columnLayout->setContentsMargins(5, 10, 5, 10);

    QLabel* titleLabel = new QLabel(title, this);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #172b4d;");
    columnLayout->addWidget(titleLabel);

    taskList = new QListWidget(this);
    taskList->setStyleSheet(
            "background-color: #f9fafc; border: 1px solid #dfe1e6; border-radius: 5px;"
    );

    taskList->setSpacing(5);
    taskList->setDragEnabled(true);
    taskList->setAcceptDrops(true);
    taskList->setDropIndicatorShown(true);
    taskList->setDefaultDropAction(Qt::MoveAction);
    taskList->setSelectionMode(QAbstractItemView::SingleSelection);
    columnLayout->addWidget(taskList);

    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputTask = new QLineEdit(this);
    inputTask->setPlaceholderText("Add Task...");
    inputTask->setStyleSheet("padding: 5px; border: 1px solid #ccc; border-radius: 5px;");
    QPushButton* addTaskButton = new QPushButton("+", this);
    addTaskButton->setFixedSize(30, 30);
    addTaskButton->setStyleSheet("background-color: #0f4c75; color: white; border-radius: 15px;");

    connect(addTaskButton, &QPushButton::clicked, this, &KanbanColumn::addCard);

    inputLayout->addWidget(inputTask);
    inputLayout->addWidget(addTaskButton);
    columnLayout->addLayout(inputLayout);

}

void KanbanColumn::addCard() {
    if (inputTask->text().trimmed().isEmpty()){
        return;
    }

    CardWidget* cardWidget = new CardWidget(inputTask->text(), this);
    QListWidgetItem* listItem = new QListWidgetItem(taskList);

    listItem->setSizeHint(cardWidget->sizeHint());
    taskList->addItem(listItem);
    taskList->setItemWidget(listItem, cardWidget);

    connect(cardWidget, &CardWidget::deleteRequested, [=](){
       delete listItem;
    });
    inputTask->clear();
}

void KanbanColumn::dragEnterEvent(QDragEnterEvent* event) {
    std::cout<<event->mimeData()->hasText()<<std::endl;
    if (event->mimeData()->hasText()) {
        event->acceptProposedAction();

    }
}

void KanbanColumn::dragMoveEvent(QDragMoveEvent* event) {
    std::cout<<event->mimeData()->hasText()<<std::endl;
    if (event->mimeData()->hasText()) {
        event->acceptProposedAction();
    }
}

void KanbanColumn::dropEvent(QDropEvent* event) {
    std::cout<<event->mimeData()->hasText()<<std::endl;
    if (event->mimeData()->hasText()) {
        QString taskText = event->mimeData()->text();

        CardWidget* cardWidget = new CardWidget(taskText, this);
        QListWidgetItem* listItem = new QListWidgetItem(taskList);
        listItem->setSizeHint(cardWidget->sizeHint());
        taskList->addItem(listItem);
        taskList->setItemWidget(listItem, cardWidget);

        connect(cardWidget, &CardWidget::deleteRequested, [=]() {
            delete listItem;
        });

        event->acceptProposedAction();
    }
}
