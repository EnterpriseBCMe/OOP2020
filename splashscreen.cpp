#include "splashscreen.h"
#include <QDateTime>
#include <QProgressBar>
#include <QTimer>

SplashScreen::SplashScreen(QPixmap &pixmap, int time):QSplashScreen(pixmap),
    duration(time)
{
    w = new QWidget(this);
    w->setGeometry(pixmap.rect());
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(0, w->height()-20, w->width(), 20);
    progressBar->setStyleSheet("QProgressBar{text-align:center;}");
    progressBar->setRange(0,100);
    progressBar->setValue(0);

    qsrand(QTime::currentTime().msec());
    for (int i = 0; i < 100; i++) {
        progress.append(qrand()%101);
    }
    std::sort(progress.begin(), progress.end());

    setProgress();
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::setProgress()
{
    int tempTime = duration / 100;
    for (int i = 0; i < 100; i++) {
        QTimer::singleShot(i*tempTime, this, SLOT(updateProgress()));
    }
    QTimer::singleShot(duration, this, SLOT(close()));
}

void SplashScreen::updateProgress()
{
    static int num = 0;
    progressBar->setValue(progress[num]);
    num++;
}
