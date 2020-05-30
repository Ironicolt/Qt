#ifndef CIRCLEBUTTON_H
#define CIRCLEBUTTON_H

#include <QWidget>
#include <QMenu>
class CircleButton : public QWidget
{
    Q_OBJECT
public:
    explicit CircleButton(QWidget *parent = 0);
    CircleButton(const QString text, QPoint center,int radius,QWidget* parent = 0);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);       //--鼠标移动事件
    void contextMenuEvent(QContextMenuEvent *);  //--右键菜单事件
    void closeEvent(QCloseEvent *);     //重写退出

    bool isContains(QPoint p);//判断鼠标是否在控件范围之内
    void initForm();//初始化窗体
    void setText(QString text);//设置显示文本
signals:
    void clicked();//点击信号
public slots:
    void inputText();//输入文本
    QString getText();
private:
    QString _text;
    QPoint _center;
    QPoint beginPos;
    QMenu *menu; //右键菜单对象
    int _radius;
public:
    bool _pressed;//单击按钮变色控制
};

#endif // CIRCLEBUTTON_H
