#include "MainWgt.h"
#include <QFile>
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString styleName;
    styleName = ":/Data/Css/blue.css";

    QFile file(styleName);
    file.open(QFile::ReadOnly);
    QString qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);
    qApp->setPalette(QPalette(QColor("#F0F0F0")));

    QDesktopWidget* desktopWgt =  QApplication::desktop();
    MainWgt w;
    w.show();
    w.move((desktopWgt->width() - w.width())/2, (desktopWgt->height() - w.height()) /2);

    return a.exec();
}
