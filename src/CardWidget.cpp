//
// Created by Serg_Sh on 24.12.24.
//

#include "../include/CardWidget.h"
#include <QHBoxLayout>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <iostream>

CardWidget::CardWidget(const QString &taskText, QWidget *parent) : QWidget(parent){
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10, 5, 10, 5);
    mainLayout->setSpacing(10);

    taskLabel = new QLabel(taskText, this);
    taskLabel->setStyleSheet("font-size: 14px; color: #172b4d;");
    mainLayout->addWidget(taskLabel);

    deleteButton = new QPushButton("🗑️", this);
    deleteButton->setFixedSize(20,20);
    deleteButton->setStyleSheet("background-color: transparent; border: none;");
    connect(deleteButton, &QPushButton::clicked, this, &CardWidget::deleteRequested);
    mainLayout->addWidget(deleteButton);

    setLayout(mainLayout);
    setStyleSheet(
            "background-color: white; border: 1px solid #dfe1e6; border-radius: 8px; padding: 5px;"
    );
}

void CardWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QDrag* drag = new QDrag(this);
        QMimeData* mimeData = new QMimeData();

        mimeData->setText(taskLabel->text());
        drag->setMimeData(mimeData);

        QPixmap pixmap(size());
        pixmap.fill(Qt::transparent);

        QPainter painter(&pixmap);
        render(&painter);
        painter.end();

        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos()); // Set the drag hotspot to the mouse click position

        std::cout << "Drag started with text: " << taskLabel->text().toStdString() << std::endl;

        if (drag->exec(Qt::MoveAction) == Qt::MoveAction) {
            emit deleteRequested();
        }
    }
}

