#ifndef GRAPH_H
#define GRAPH_H
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
extern "C" {
#include "calc.h"
}

namespace Ui {
class Graph;
}
class Graph : public QDialog {
  Q_OBJECT

 public:
  Graph(QWidget *parent, QString labelText);
  ~Graph();

 private slots:
  void on_pushButton_8_clicked();
  void on_pushButton_7_clicked();

 public:
  QString pubStr;

 private:
  void draw();

 private:
  Ui::Graph *ui;
  QGraphicsScene *m_scene;
  QGraphicsView *graphicsView;
};

#endif  // GRAPH_H
