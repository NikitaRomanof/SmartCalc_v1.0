#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
extern "C" {
#include "calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

 private slots:
  void digits_numbers();
  void on_pushButton_dot_clicked();
  void on_pushButton_pi_clicked();
  void on_pushButton_e_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_mul_clicked();
  void on_pushButton_equals_clicked();
  void on_pushButton_ac_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_credit_clicked();

  void on_pushButton_deposit_clicked();

 signals:
};
#endif  // MAINWINDOW_H
