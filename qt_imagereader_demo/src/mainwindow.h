#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImageReader>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int     parserimage(const char* filename);
private slots:
    void on_next_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QImageReader m_imageReader;
};

#endif // MAINWINDOW_H
