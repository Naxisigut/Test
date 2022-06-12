#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    sourceFile.load("../FFT5_1KHz_FFT/1KHz.wav");
    int numChannels = sourceFile.getNumChannels();
    int numSamplesPerChanel = sourceFile.getNumSamplesPerChannel();

    din = (fftw_complex*)fftw_malloc(sizeof (fftw_complex)* N);
    out = (fftw_complex*)fftw_malloc(sizeof (fftw_complex)* N);
    fftwPlan = fftw_plan_dft_1d(N, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_fftButton_clicked()
{
    qDebug() << "采样率：" << sourceFile.getSampleRate() << endl;
    qDebug() << "位深度/采样深度："<< sourceFile.getBitDepth() << endl;
    qDebug() << "声道数：" << sourceFile.getNumChannels() << endl;
    qDebug() << "单声道采样总数：" << sourceFile.getNumSamplesPerChannel() << endl;
    qDebug() << "音频长度：" << sourceFile.getLengthInSeconds() << "s" << endl;

    if ((din == NULL)||(out == NULL))
    {
        qDebug() << "Error:insufficient available memory" << endl;
    }
    else
    {
        for (int i=0; i<N; i++)
        {
            din[i][0] = sourceFile.samples[0][i];//将samples的channel0的数据赋给din
            din[i][1] = 0;
        }
    }

    fftw_execute(fftwPlan);

    //输出到文件
    QFile outputFile("../FFT5_1KHz_FFT/output.txt");
    outputFile.open(QIODevice::WriteOnly |QIODevice::Truncate);
    QTextStream outStream(&outputFile);
    outStream.setCodec("UTF-8");

//    outStream << "Data:IN" << endl;
//    for(int i=0; i<N; i++)
//    {
//        outStream << i+1 << ".(" << din[i][0] << "," << din[i][1] << ")" << endl;
//    }

//    outStream << "Data:out" << endl;
//    for(int i=0; i<N; i++)
//    {
//        outStream <<  out[i][0] << "," << out[i][1]  << endl;
//        outStream <<  out[i][0] << endl;
//    }

    outStream << "Amplitude" << endl;
    for(int i=0; i<N; i++)
    {
//        outStream <<  out[i][0] << "," << out[i][1]  << endl;
        outStream << i << " " << qSqrt(qPow(out[i][0],2)+qPow(out[i][1],2)) << endl;
    }

}
