#include "widget.h"
#include "ui_widget.h"
#include <QFileInfo>
#include <QAudioEncoderSettings>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //获取录音设备列表
    ui->setupUi(this);
    audioRecorder = new QAudioRecorder;
    QStringList inputs = audioRecorder->audioInputs();
    ui->comboBox->addItems(inputs);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_StartButton_clicked()
{
        //在程序运行目录下新建temp文件
        tempPath = qApp->applicationDirPath();//获取程序所在路径
        tempPath += "/temp.wav";//创建temp文件的路径
        qDebug()<< tempPath;

    //若temp.wav已存在，录制前会清空其之前的数据
    //若不存在，会在程序所在目录下自动新建一个temp.wav
    QFile tempFile(tempPath);
    bool QFileOpenOK = tempFile.open(QIODevice::ReadWrite |QIODevice::Truncate);
    //如果tempFile打开失败，提示临时文件打开失败
    if(QFileOpenOK == true)
    {
        qDebug()<<"QFileOpenOK";
    }else{
        qDebug()<< "QFileOpenFail";
        QMessageBox::information(this, "提示", "临时文件打开失败",QMessageBox::Ok);
        return;
    }
    tempFile.close();

    //选择当前comboBox里的设备进行录制
    audioRecorder->setAudioInput(ui->comboBox->currentText());
     qDebug() << audioRecorder->audioInput();

//    //音频参数设置
//    QAudioEncoderSettings AudioSettings;
//    AudioSettings.setCodec("audio/pcm");
//    AudioSettings.setQuality(QMultimedia::HighQuality);
//    audioRecorder->setAudioSettings(AudioSettings);

    bool setOK = audioRecorder->setOutputLocation(QUrl::fromLocalFile(tempPath));//注意，这个函数的返回值并不能准确反映文件是否存在、录音能否正常。
//  bool setOK = audioRecorder->setOutputLocation(QUrl::fromLocalFile(QFileDialog::getSaveFileName()));
    if(setOK == true)
    {
        qDebug() << "OutputSetOK";
    }else
    {
        qDebug() << "OutputSetFail";
    }

    audioRecorder->record();

    qDebug() << audioRecorder->status();
    qDebug() << audioRecorder->state();
    qDebug() << audioRecorder->error();

}

void Widget::on_PauseButton_clicked()
{
    audioRecorder->pause();
    if(ui->PauseButton->text() == "暂停录制")
        {
        ui->PauseButton->setText("继续录制");
        }else {
        ui->PauseButton->setText("暂停录制");
        }
}

void Widget::on_EndButton_clicked()
{
    audioRecorder->stop();
    //指定保存的文件名
    QString endFileName = QFileDialog::getSaveFileName(this, //父窗口
                                                    "Save File as",//窗口标题
                                                    "../FFT2_GetRecording/Recording",//目录
                                                    "Audio (*.wav *.pcm)");//过滤器
    QFile endfile(endFileName);
    bool openOk = endfile.open(QIODevice::WriteOnly);
    if (openOk == false)
        {
        qDebug()<< "文件不存在";
        return;
    }else
    {
        QFile tempFile(tempPath);
        tempFile.open(QIODevice::ReadOnly);
        QByteArray tempFileArray = tempFile.readAll();
        endfile.write(tempFileArray);
    }
}


