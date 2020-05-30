#include <QCoreApplication>

#include <QtNetwork>


class QServer : public QObject
{
    Q_OBJECT
public:
    QServer(QObject* object);
    ~QServer();

public slots:
    void acceptConnection();
    void readClient();

private:
    QTcpServer *server;
    QTcpSocket *clientConnection ;

};
