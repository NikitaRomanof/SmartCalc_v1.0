#include "mainwindow.h"

#include "choice.h"
#include "credit.h"
#include "deposit.h"
#include "graph.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_close, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *but = (QPushButton *)sender();
  QString str_form;
  str_form = (ui->result_inter->text() + but->text());
  ui->result_inter->setText(str_form);
}

void MainWindow::on_pushButton_dot_clicked() {
  int count = 0;
  QString str = ui->result_inter->text();
  int len = str.isNull() ? 0 : str.length();
  for (int i = 0; i < len; i++) {
    if (str[i] == '.') {
      count = 1;
    } else if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
               str[i] != '3' && str[i] != '4' && str[i] != '5' &&
               str[i] != '6' && str[i] != '7' && str[i] != '8' &&
               str[i] != '9') {
      count = 0;
    }
  }
  if (len != 0) {
    if (count == 0 && (str[len - 1] >= '0' && str[len - 1] <= '9')) {
      ui->result_inter->setText(ui->result_inter->text() + ".");
    }
  }
}

void MainWindow::on_pushButton_pi_clicked() {
  int count = 0;
  QString str = ui->result_inter->text();
  int len = str.isNull() ? 0 : str.length();
  for (int i = 0; i < len; i++) {
    if (str[i] == '.') {
      count = 1;
    } else if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
               str[i] != '3' && str[i] != '4' && str[i] != '5' &&
               str[i] != '6' && str[i] != '7' && str[i] != '8' &&
               str[i] != '9') {
      count = 0;
    }
  }
  int j = len - 1;
  if (len == 0) {
    ui->result_inter->setText(ui->result_inter->text() + "3.141592653589793");
  } else if (count == 0 && (str[j] != '1' && str[j] != '2' && str[j] != '3' &&
                            str[j] != '4' && str[j] != '5' && str[j] != '6' &&
                            str[j] != '7' && str[j] != '8' && str[j] != '9' &&
                            str[j] != '.')) {
    ui->result_inter->setText(ui->result_inter->text() + "3.141592653589793");
  }
}

void MainWindow::on_pushButton_e_clicked() {
  int count = 0;
  QString str = ui->result_inter->text();
  int len = str.isNull() ? 0 : str.length();
  for (int i = 0; i < len; i++) {
    if (str[i] == '.') {
      count = 1;
    } else if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
               str[i] != '3' && str[i] != '4' && str[i] != '5' &&
               str[i] != '6' && str[i] != '7' && str[i] != '8' &&
               str[i] != '9') {
      count = 0;
    }
  }
  int j = len - 1;
  if (len == 0) {
    ui->result_inter->setText(ui->result_inter->text() + "2.718281828459045");
  } else if (count == 0 && (str[j] != '1' && str[j] != '2' && str[j] != '3' &&
                            str[j] != '4' && str[j] != '5' && str[j] != '6' &&
                            str[j] != '7' && str[j] != '8' && str[j] != '9' &&
                            str[j] != '.')) {
    ui->result_inter->setText(ui->result_inter->text() + "2.718281828459045");
  }
}

void MainWindow::on_pushButton_div_clicked() {
  QString str = ui->result_inter->text();
  int len = str.isNull() ? 0 : str.length();
  if (len != 0) {
    if ((str[len - 1] >= '0' && str[len - 1] <= '9') || str[len - 1] == ')' ||
        str[len - 1] == 'x') {
      ui->result_inter->setText(ui->result_inter->text() + "/");
    }
  }
}

void MainWindow::on_pushButton_mul_clicked() {
  QString str = ui->result_inter->text();
  int len = str.isNull() ? 0 : str.length();
  if (len != 0) {
    if ((str[len - 1] >= '0' && str[len - 1] <= '9') || str[len - 1] == ')' ||
        str[len - 1] == 'x') {
      ui->result_inter->setText(ui->result_inter->text() + "*");
    }
  }
}

void MainWindow::on_pushButton_equals_clicked() {
  QString str_expr = ui->result_inter->text();
  QByteArray ba = str_expr.toLocal8Bit();
  char *c_str2 = ba.data();
  char outStr[256] = {0};
  double out = 0.0;
  int error = 0;

  if (str_expr.contains("x")) {
    QMessageBox::StandardButton do_x = QMessageBox::question(
        this, "",
        "Заданное выражение содержит х:\n yes - построить график функции;\n no "
        "- подставить значение х в выражение и получить результат.",
        QMessageBox::Yes | QMessageBox::No);
    if (do_x == QMessageBox::Yes) {
      Graph window(nullptr, str_expr);
      window.setModal(true);
      window.exec();
    } else if (do_x == QMessageBox::No) {
      Choice ch_wind(nullptr, str_expr);
      ch_wind.setModal(true);
      ch_wind.exec();
    }
  } else {
    error = s21_start(c_str2, &out, 0.0);
    if (error == 0) {
      if (out == -0.0) {
        out = 0.0;
      }
      sprintf(outStr, "%.15g", out);
      ui->result_show->setText(outStr);
    } else {
      if (error == 1) {
        sprintf(outStr, "%s", "Error 1: incorrect string");
      } else if (error == 2) {
        sprintf(outStr, "%s", "Error 2: invalid functions");
      } else if (error == 3) {
        sprintf(outStr, "%s", "Error 3: stack overflow error");
      } else if (error == 4) {
        sprintf(outStr, "%s", "Error 4: stack underflow error");
      } else if (error == 5) {
        sprintf(outStr, "%s", "Error 5: division by zero");
      } else if (error == 6) {
        sprintf(outStr, "%s", "Error 6: mod by zero");
      } else if (error == 7) {
        sprintf(outStr, "%s", "Error 7: asin() out of range");
      } else if (error == 8) {
        sprintf(outStr, "%s", "Error 8: acos() out of range");
      } else if (error == 9) {
        sprintf(outStr, "%s", "Error 9: Negative number! Can't take sqrt()");
      } else if (error == 10) {
        sprintf(outStr, "%s", "Error 10: Negative number! Can't take log()");
      } else if (error == 11) {
        sprintf(outStr, "%s", "Error 11: Negative number! Can't take ln()");
      } else {
        sprintf(outStr, "%s", "Unspecified error!");
      }
      ui->result_show->setText(outStr);
    }
  }
}

void MainWindow::on_pushButton_ac_clicked() {
  ui->result_inter->setText("");
  ui->result_show->setText("0");
}

void MainWindow::on_pushButton_del_clicked() {
  QString str = ui->result_inter->text();
  QByteArray ba = str.toLocal8Bit();
  char *c_str2 = ba.data();
  char c_str3[256] = {0};
  if (str.isNull() == false) {
    for (int i = 0; i < str.length() - 1; i++) {
      c_str3[i] = c_str2[i];
    }
    ui->result_inter->setText(c_str3);
  }
}

void MainWindow::on_pushButton_credit_clicked() {
  Credit cwind(nullptr);
  cwind.setModal(true);
  cwind.exec();
}

void MainWindow::on_pushButton_deposit_clicked() {
  Deposit dwind(nullptr);
  dwind.setModal(true);
  dwind.exec();
}
