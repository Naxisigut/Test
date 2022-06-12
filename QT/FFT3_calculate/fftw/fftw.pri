#宏定义项，指明采用fftw
DEFINES += fftw_DLL

##指明fftw库所对应的头文件所在目录
INCLUDEPATH += $$PWD/include

#指明依赖库关系
LIBS += -L$$PWD/lib -lfftw3-3
LIBS += -L$$PWD/lib -lfftw3f-3
LIBS += -L$$PWD/lib -lfftw3l-3

#LIBS += -L$$PWD/lib/libfftw3-3.lib
#LIBS += -L$$PWD/lib/libfftw3f-3.lib
#LIBS += -L$$PWD/lib/libfftw3l-3.lib

#LIBS += H:\TEST\FFT3_calculate\fftw\lib\libfftw3-3.lib
#LIBS += H:\TEST\FFT3_calculate\fftw\lib\libfftw3f-3.lib
#LIBS += H:\TEST\FFT3_calculate\fftw\lib\libfftw3l-3.lib
