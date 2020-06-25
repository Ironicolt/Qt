#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void StanardrdOutput();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QProcess* m_client;
};

#endif // MAINWINDOW_H
