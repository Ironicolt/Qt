#include <QCoreApplication>

#include <QtNetwork>


class QClient : public QObject
{
    Q_OBJECT
public:
    QClient(QObject* object);
    ~QClient();

public slots:
    void readClient();

private:
    QTcpSocket *client;

};
