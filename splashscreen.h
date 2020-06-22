#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QProgressBar>
#include <QSplashScreen>
#include <QThread>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
    SplashScreen(QPixmap &pixmap, int time);
    ~SplashScreen();
    QWidget* w;
    void setProgress();
private:
    QProgressBar* progressBar;
    QList<int> progress;
    int duration;
private slots:
    void updateProgress();
};

#endif // SPLASHSCREEN_H
