#include "circlebutton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QInputDialog>
#include <QLineEdit>


CircleButton::CircleButton(QWidget *parent) :
    QWidget(parent),_text("CircleButton"),_center(30,30),_radius(20)
{
    initForm();
}
CircleButton::CircleButton(const QString text, QPoint center,int radius,QWidget* parent):
    QWidget(parent),_text(text), _center(center),_radius(radius)
{
    initForm();
}

void CircleButton::initForm()
{
    _pressed = false;
    beginPos = this->pos();
    //无边框
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint|Qt::WindowStaysOnTopHint);
    /*  窗口整体透明，但窗口控件不透明*/
   this->setAttribute(Qt::WA_TranslucentBackground,true);
    menu = new QMenu(this);//创建右键菜单
    menu->addAction("Settings Text", this, SLOT(inputText()));
    menu->addAction("Exit", this, SLOT(close()));
}
void CircleButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);//将当前窗体作为画布
    QPen pen = QPen(Qt::red);
    pen.setWidth(1);
    p.setPen(pen);
    if(_pressed)
        p.setBrush(Qt::yellow);//粉刷为黄色
    else
        p.setBrush(QColor(255,255,255,1));
    p.drawText(QRect(_center.x()-_radius,_center.x()-_radius,2*_radius,2*_radius), _text, QTextOption(Qt::AlignCenter));//文本居中：QTextOption(Qt::AlignCenter)

    pen.setColor(QColor(255,255,255,1));
    p.setPen(pen);
    //画圆
    p.drawEllipse(_center,_radius,_radius);

}
void CircleButton::mousePressEvent(QMouseEvent *e)
{
   if(e->button() == Qt::LeftButton && isContains(e->pos()))
    {
        _pressed = true;
        beginPos = e->pos();//鼠标相对窗体的位置
        update();//触发窗体重绘
    }

}

void CircleButton::mouseReleaseEvent(QMouseEvent *e)
{
    _pressed = false;
    update();//触发窗体重绘

    if(isContains(e->pos()))//当鼠标点击按钮
        emit clicked();//发送点击信号

}

void CircleButton::mouseMoveEvent(QMouseEvent *e)       //--鼠标移动事件
{
    if (_pressed)
    {//当前鼠标相对窗体的位置-刚按下左键时的相对位置=鼠标移动的大小
         this->move(e->pos() - beginPos + this->pos());
         //           鼠标移动的大小+窗体原来的位置=窗体移动后的位置
    }
}

void CircleButton::contextMenuEvent(QContextMenuEvent *)
{
    this->setCursor(Qt::ArrowCursor);
    menu->exec(cursor().pos());
}

bool CircleButton::isContains(QPoint p)
{
    return (_center.x()-_radius < p.x()
            && _center.x()+_radius > p.x()
            && _center.y()-_radius < p.y()
            && _center.y()+_radius > p.y());
}
void CircleButton::setText(QString text)
{
    this->_text = text;
}

void CircleButton::inputText()
{
    bool ok = false;

    QString text = QInputDialog::getText(this,tr("Setting Text"),tr("Input text"),QLineEdit::Normal,getText(),&ok,0);
    if ( ok && !text.isEmpty() )
    {
        this->setText(text);
    }
}
void CircleButton::closeEvent(QCloseEvent * )
{
    this->close();
}
QString CircleButton::getText()
{
    return this->_text;
}

