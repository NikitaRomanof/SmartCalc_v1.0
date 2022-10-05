#include "graph.h"

#include <QDebug>
#include <QGridLayout>
#include <cmath>

#include "ui_graph.h"

Graph::Graph(QWidget *parent, QString strOut)
    : QDialog(parent), ui(new Ui::Graph) {
  pubStr = strOut;
  ui->setupUi(this);
  setLayout(new QGridLayout());
  graphicsView = new QGraphicsView();
  graphicsView->setMinimumSize(1100, 1080);
  graphicsView->setMaximumSize(1100, 1080);
  layout()->addWidget(graphicsView);
  graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  m_scene = new QGraphicsScene();
  m_scene->setSceneRect(-450, -450, 900, 900);
  draw();
  graphicsView->setScene(m_scene);
}

Graph::~Graph() { delete ui; }

void Graph::on_pushButton_8_clicked() {
  m_scene->clear();
  if (QString::compare(ui->label->text(), "1", Qt::CaseInsensitive) == 0) {
    ui->label->setText("2");
  } else if (QString::compare(ui->label->text(), "2", Qt::CaseInsensitive) == 0) {
    ui->label->setText("3");
  } else if (QString::compare(ui->label->text(), "3", Qt::CaseInsensitive) == 0) {
    ui->label->setText("4");
  } else if (QString::compare(ui->label->text(), "4", Qt::CaseInsensitive) == 0) {
    ui->label->setText("5");
  } else if (QString::compare(ui->label->text(), "5", Qt::CaseInsensitive) == 0) {
    ui->label->setText("10");
  } else if (QString::compare(ui->label->text(), "10", Qt::CaseInsensitive) == 0) {
    ui->label->setText("50");
  } else if (QString::compare(ui->label->text(), "0.1", Qt::CaseInsensitive) == 0) {
      ui->label->setText("1");
  } else if (QString::compare(ui->label->text(), "0.01", Qt::CaseInsensitive) == 0) {
      ui->label->setText("0.1");
  }
  draw();
  graphicsView->setScene(m_scene);
}

void Graph::on_pushButton_7_clicked() {
  m_scene->clear();
  if (QString::compare(ui->label->text(), "50", Qt::CaseInsensitive) == 0) {
    ui->label->setText("10");
  } else if (QString::compare(ui->label->text(), "10", Qt::CaseInsensitive) == 0) {
    ui->label->setText("5");
  } else if (QString::compare(ui->label->text(), "5", Qt::CaseInsensitive) == 0) {
    ui->label->setText("4");
  } else if (QString::compare(ui->label->text(), "4", Qt::CaseInsensitive) == 0) {
      ui->label->setText("3");
  } else if (QString::compare(ui->label->text(), "3", Qt::CaseInsensitive) == 0) {
    ui->label->setText("2");
  } else if (QString::compare(ui->label->text(), "2", Qt::CaseInsensitive) == 0) {
    ui->label->setText("1");
  } else if (QString::compare(ui->label->text(), "1", Qt::CaseInsensitive) == 0) {
      ui->label->setText("0.1");
  } else if (QString::compare(ui->label->text(), "0.1", Qt::CaseInsensitive) == 0) {
      ui->label->setText("0.01");
  }

  draw();
  graphicsView->setScene(m_scene);
}

void Graph::draw() {
  QPainterPath x(QPointF(0, 0));
  x.lineTo(QPointF(550, 0));
  x.lineTo(QPointF(-550, 0));
  const QFont f("Orbitron", 30, QFont::Bold);
  x.addText(530, 20, f, "x");
  m_scene->addPath(x, QPen(Qt::black, 2));
  QPainterPath y(QPointF(0, 0));
  y.lineTo(QPointF(0, -550));
  y.lineTo(QPointF(0, 550));
  const QFont z("Orbitron", 25, QFont::Bold);
  y.addText(5, -520, z, "y");
  y.addText(2, 21, z, "0");
  m_scene->addPath(y, QPen(Qt::black, 2));
  QByteArray ba = pubStr.toLocal8Bit();
  char *c_str2 = ba.data();
  double out = 0.0;
  int error = 0;
  double i = -550.0;
  double j = 550.0;
  double k =0.05;
  double s = (ui->label->text()).toDouble() * 50;

  if (pubStr.contains("log") || pubStr.contains("ln")) {
    i = 0.001;
  } else if (pubStr.contains("sqrt")) {
      i = 0;
  }
  error = s21_start(c_str2, &out, i);
  while (error != 0 && i < j && error != 1 && error != 2) {
     i = i + k;
     error = s21_start(c_str2, &out, i);
  }
  QPainterPath gr(QPointF(i * s, -1 * out * s));
  double min_x = 10000001.0;
  double max_x = -10000001.0;
  double min_y = 10000001.0;
  double max_y = -10000001.0;
  for (; i <= j && error != 1 && error != 2; i += k) {
    if (i > 0.95 && i < 1.00) {
       i = 1.00;
    }
      error = s21_start(c_str2, &out, i);
    if (((fabs(out) - 19) > 1e-16) && pubStr.contains("tan")) {
      gr.moveTo(i * s, -1 * out * s);
    }
    if (out <= 500.00 && out >= -500.00 && i <= 500 && i >= -500 && error == 0) {
        gr.lineTo(QPointF(i * s, -1 * out * s));
    }
    if (min_x >= i && error == 0) {
        min_x = i;
    }
    if (max_x <= i && error == 0) {
        max_x = i;
    }
    if (min_y >= out && error == 0) {
        min_y = out;
    }
    if (max_y <= out && error == 0) {
        max_y = out;
    }
  }
  if (min_x < -450 && error != 1 && error != 2) {
      min_x = -1000000;
      double buf = 0.0;
      s21_start(c_str2, &buf, min_x);
      min_y = buf <= min_y ? buf : min_y;
  }
  if (max_x > 450 && error != 1 && error != 2) {
      max_x = 1000000;
      double buf = 0.0;
      s21_start(c_str2, &buf, max_x);
      max_y = buf >= max_y ? buf : max_y;
  }
  ui->label_4->setText("от " + QString::number(min_x, 'f', 2) + "\n" +
                       "до " + QString::number(max_x, 'f', 2));
  ui->label_6->setText("от " + QString::number(min_y, 'f', 2) + "\n" +
                       "до " + QString::number(max_y, 'f', 2));

  for (int j = -550; j < 550; j += 50) {
      if (j != 0) {
          QPainterPath a(QPointF(j, 0));
          a.lineTo(QPointF(j, 550));
          a.lineTo(QPointF(j, -550));
          m_scene->addPath(a, QPen(Qt::darkGray, 1));
          QPainterPath b(QPointF(0, j));
          b.lineTo(QPointF(550, j));
          b.lineTo(QPointF(-550, j));
          m_scene->addPath(b, QPen(Qt::darkGray, 1));
      }
  }
  if (error == 1 || error == 2) {
      gr.addText(5, 100, z, "ERROR №" + QString::number(error, 'd', 0));
      ui->label_4->setText("ERROR");
      ui->label_6->setText("ERROR");
  }
  m_scene->addPath(gr, QPen(Qt::blue, 2));
}
