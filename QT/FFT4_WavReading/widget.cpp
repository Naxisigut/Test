#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    audioFile.load ("../FFT4_WavReading/1KHz.wav");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_viewDataButton_clicked()
{
    QString audioDataString;

    int channel = 0;
    int numSamples = audioFile.getNumSamplesPerChannel();
    qDebug() << numSamples;

    for (int i = 0; i < numSamples; i++)
    {
        double currentSample = audioFile.samples[channel][i];
        audioDataString.append(QString::number(currentSample));
        audioDataString.append(',');
    }

    ui->textEdit->append(audioDataString);
}
