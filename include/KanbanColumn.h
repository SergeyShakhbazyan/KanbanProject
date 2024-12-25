//
// Created by Serg_Sh on 24.12.24.
//

#ifndef KANBANPROJECT_KANBANCOLUMN_H
#define KANBANPROJECT_KANBANCOLUMN_H

#include <QWidget>
#include <QString>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDragEnterEvent>

class KanbanColumn : public QWidget{
public:
    KanbanColumn(const QString& title, QWidget* parent = nullptr);

private slots:
    void addCard();

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void dropEvent(QDropEvent* event) override;


private:
    QListWidget* taskList;
    QLineEdit* inputTask;
};


#endif //KANBANPROJECT_KANBANCOLUMN_H
