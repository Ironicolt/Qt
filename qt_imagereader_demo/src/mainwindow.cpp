#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::parserimage(const char* filename)
{
    int ret = true;
    qDebug()<<"support format:"<<QImageReader::supportedImageFormats();
    m_imageReader.setFileName(QString(filename));
    m_imageReader.setAutoDetectImageFormat(true);
    int imageCount = m_imageReader.imageCount();
    qDebug()<<imageCount<<" current number:"<<m_imageReader.currentImageNumber();
    ui->image_label->setPixmap(QPixmap(filename));
    return ret;
}

void MainWindow::on_next_pushButton_clicked()
{
    int imageCount = m_imageReader.imageCount();
    m_imageReader.autoDetectImageFormat();
    QImage image;
    while(m_imageReader.canRead())
    {
       image = m_imageReader.read();
    }
    ui->image_label->setPixmap(QPixmap::fromImage(image));
}
