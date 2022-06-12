#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDebug>
#include <QVector>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QFile file("../FFT1/1KHz.wav");
    bool openOK = file.open(QIODevice::ReadOnly);

    QFile test("../FFT1/Test2.wav");
    test.open(QIODevice::WriteOnly);

    QByteArray V;
    V = file.readAll();
    test.write(V);
}
