#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "AudioFile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    AudioFile<double> audioFile;
private slots:
    void on_viewDataButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
