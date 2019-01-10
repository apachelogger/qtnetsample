#include <QCoreApplication>
#include <QDebug>

#include <QtNetwork> // all

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QUrl url("http://networkcheck.kde.org");
    QNetworkAccessManager qnam;
    QNetworkReply *reply = qnam.get(QNetworkRequest(url));
    QObject::connect(reply, &QNetworkReply::finished, [&](){
        qDebug() << "finished";
        qDebug() << reply->readAll();
        app.quit(); // quit upon reply
    });
    QObject::connect(reply, &QIODevice::readyRead, [&](){
        qDebug() << "readyread";
    });

    app.exec();
}

