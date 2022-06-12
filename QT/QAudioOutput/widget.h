#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAudioOutput>
#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QFile>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QString playPath;
    QAudioFormat format;
    QList<QAudioDeviceInfo> outputlist;
    int searchDevice(QString str, QList<QAudioDeviceInfo> &list);

private slots:
    void on_playButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
