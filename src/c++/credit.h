#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>
#include <QMessageBox>
extern "C" {
#include "calc.h"
}

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_radioButton_clicked();

  void on_radioButton_2_clicked();

  void on_pushButton_ac_clicked();

  void on_comboBox_currentIndexChanged(int index);

 private:
  Ui::Credit *ui;

 public:
  QString globalStr;
  int globalInt = 1;
};

#endif  // CREDIT_H
