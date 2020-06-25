#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("process_client");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::writeToServer()
{
    QString sendString = ui->textEdit->toPlainText();

    //TODO 1
    QFile fileout;
    fileout.open(stdout, QIODevice::WriteOnly);
    fileout.write(sendString.toUtf8().data(), strlen(sendString.toUtf8().data())); // write to stderr
    fileout.close();

    //TOOD 2
    std::cout<<"test"<<std::endl;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    writeToServer();
}
