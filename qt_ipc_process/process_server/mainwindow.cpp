#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define IPC_CLIENT_PROC     "process_client.exe"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_client(NULL)
{
    ui->setupUi(this);
    this->setWindowTitle("process_server");
}

MainWindow::~MainWindow()
{
    delete ui;
    if( m_client )
    {
        m_client->waitForFinished();
        m_client->close();
    }
}

void MainWindow::StanardrdOutput()
{
    QByteArray output = m_client->readAllStandardOutput();
    qDebug()<<"Ret code:"<<output;

    QString textString = ui->textEdit->toPlainText();
    textString += QString::fromUtf8(output.data()) +"\n";

    ui->textEdit->setText(textString);
}

void MainWindow::on_pushButton_clicked()
{
    if( m_client )
        return ;

    m_client = new QProcess(this);
    connect(m_client,SIGNAL(readyRead()),this,SLOT(StanardrdOutput()));
    m_client->start(IPC_CLIENT_PROC);
    m_client->waitForStarted();
}
