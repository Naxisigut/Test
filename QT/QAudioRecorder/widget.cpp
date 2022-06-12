#include "widget.h"
#include "ui_widget.h"

#include <QUrl>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    recorder = new QAudioRecorder;
    recorder->setAudioInput("麦克风阵列 (Realtek(R) Audio)");

    //第一次设置输出文件
    bool OK1 = recorder->setOutputLocation(QUrl::fromLocalFile("H:/TEST/QAudioRecorder/temp.wav"));
    if(OK1 == false){qDebug()<<"Firstfail";}else{qDebug()<<"FirstOK";}

    //第二次设置输出文件
    bool OK2 = recorder->setOutputLocation(QUrl::fromLocalFile("H:/TEST/QAudioRecorder/temp.wav"));
    if(OK2 == false){qDebug()<<"Secondsetfail";}else{qDebug()<<"SecondsetOK";}

    recorder->record();
//    recorder->stop();
}

Widget::~Widget()
{
    delete ui;
}

