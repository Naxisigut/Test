#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    i=1;

    connect(ui->addButton, &QPushButton::clicked,
            [=]()
    {
        i++;
        qDebug()<< i;//输出lambda内部的变量i
        qDebug()<< &i << "内部";//输出lambda内部的变量i

    }
            );

    //下面是复制的网上的代码

    j = 10;
    qDebug()<<"extern_address: "<<&j<<endl;

    auto by_val_lambda =
            [=]
    {
        qDebug()<<"by_val_lambda_address: "<<&j<<endl;
        return j + 1;
    };

    auto by_ref_lambda =
            [&]
    {
        qDebug()<<"by_ref_lambda_address: "<<&j<<endl;
        return j + 1;
    };

    qDebug()<<"by_val_lambda: "<<by_val_lambda()<<endl;
    qDebug()<<"by_ref_lambda: "<<by_ref_lambda()<<endl;

    j=13;
    qDebug()<<"by_val_lambda: "<<by_val_lambda()<<endl;
    qDebug()<<"by_ref_lambda: "<<by_ref_lambda()<<endl;

    //复制的代码结束
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_outButton_clicked()
{
    qDebug() << i;//输出外部变量i
    qDebug() << &i << "外部";//输出外部变量i
}
