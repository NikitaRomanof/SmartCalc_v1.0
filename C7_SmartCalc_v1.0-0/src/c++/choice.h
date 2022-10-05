#ifndef CHOICE_H
#define CHOICE_H

#include <QDialog>
extern "C" {
#include "calc.h"
}

namespace Ui {
class Choice;
}

class Choice : public QDialog {
  Q_OBJECT

 public:
  Choice(QWidget *parent, QString labelText);
  ~Choice();

 private:
  Ui::Choice *ui;

 private slots:
  void d_numbers();

  void on_pButton_dot_clicked();

  void on_pButton_del_clicked();

  void on_pushpButton_AC_clicked();

  void on_pButton_equals_clicked();

 signals:

 public:
  QString globalStr;
};

#endif  // CHOICE_H
