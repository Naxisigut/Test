#include "widget.h"
#include <fftw3.h>
#include <QDebug>
#include <QApplication>
#define N 8
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    int i;
    fftw_complex *din,*out;
    fftw_plan p;
    din = (fftw_complex*)fftw_malloc(sizeof (fftw_complex)* N);
    out = (fftw_complex*)fftw_malloc(sizeof (fftw_complex)* N);

    if ((din == NULL)||(out == NULL))
    {
        qDebug() << "Error:insufficient available memory" << endl;
    }
    else
    {
        for (i=0; i<N; i++)
        {
            din[i][0] = i+1;
            din[i][1] = 0;
        }
    }

    p = fftw_plan_dft_1d(N, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
    fftw_cleanup();

    //输出din out
    for(i=0; i<N; i++)
    {
        qDebug() <<din[i][0] << "," << din[i][1] << "i" << endl;
    }
    qDebug() << endl;
    for(i=0; i<N; i++)
    {
        qDebug() <<out[i][0] << "," << out[i][1] << "i" << endl;
    }

    if(din != NULL)fftw_free(din);
    if(out != NULL)fftw_free(out);

    return a.exec();
}
