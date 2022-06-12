#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "AudioFile.h"
#include <fftw3.h>
#include <QFile>
#include <QTextStream>
#include <QtMath>
#define N 8192

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    AudioFile<double> sourceFile;
    fftw_complex *din,*out;
    fftw_plan fftwPlan;

private slots:
    void on_fftButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
