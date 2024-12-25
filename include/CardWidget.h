//
// Created by Serg_Sh on 24.12.24.
//

#ifndef KANBANPROJECT_CARDWIDGET_H
#define KANBANPROJECT_CARDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>

class CardWidget : public QWidget{
    Q_OBJECT
public:
    explicit CardWidget(const QString& taskText, QWidget* parent = nullptr);

signals:
    void deleteRequested();

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    QLabel* taskLabel;
    QPushButton* deleteButton;
};


#endif //KANBANPROJECT_CARDWIDGET_H
