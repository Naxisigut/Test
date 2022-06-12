#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    playPath = "E:/TEST/QAudioOutput/1KHz.pcm";
    playPath = qApp->applicationDirPath().append("/1KHz.pcm");
    qDebug()<<playPath;

    foreach(QAudioDeviceInfo deviceInfo, QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)){
        outputlist.append(deviceInfo);
    }

    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::searchDevice(QString str, QList<QAudioDeviceInfo> &list)
{
    for(int i=0; i<list.size(); i++)
    {
        if(list.at(i).deviceName().contains(str) == true)
        {
            return i;
        }
    }
    return -1;//搜索不到设备时，返回-1
}


void Widget::on_playButton_clicked()
{
    int i=0;
    outputlist.clear();
    foreach(QAudioDeviceInfo deviceInfo, QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)){
        outputlist.append(deviceInfo);
        qDebug()<<i++ <<deviceInfo.deviceName();
    }


    QFile testAudioFile(playPath);
    QFile* IODevice = &testAudioFile;
    bool openOk = testAudioFile.open(QIODevice::ReadOnly);

    int deviceIndex = searchDevice("JVC", outputlist);
    qDebug()<<deviceIndex;
    QAudioDeviceInfo usedDevice = outputlist.at(deviceIndex);
    qDebug()<<usedDevice.deviceName();

    QAudioOutput output(usedDevice, format);
    output.start(&testAudioFile);
//    output.start(IODevice);
    QEventLoop loop;
    loop.exec();

}
