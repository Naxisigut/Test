#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAudioRecorder>
#include <QFileDialog>
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
    QAudioRecorder *audioRecorder;
    QString tempPath;

private slots:
    void on_StartButton_clicked();

    void on_PauseButton_clicked();

    void on_EndButton_clicked();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
