# Qt
Qt DPI
1. 字体不要跟着变大小，那就要使用setPixe；setPointSize跟随界面、字体同事发生改变；

2. 图片可设置QPixmap::setDevicePixelRatio

    http://doc.qt.io/qt-5/qpixmap.html#setDevicePixelRatio

    http://doc.qt.io/qt-5/qpainter.html#drawing-high-resolution-versions-of-pixmaps-and-images

3. 图片通过QLabel来显示的时候，试试：

    QLabel::setScaledContents(true);

    http://doc.qt.io/qt-5/qlabel.html#scaledContents-prop

4. 其它参考文章：

  http://my.oschina.net/u/219482/blog/296027

5. 一种资源文件*2的方法（也是官方推荐的方法）：

  https://tano.si/2013/10/26/how-to-support-retina-screens-in-qt/
  
  
  
  
  
 出处源于：http://www.cnblogs.com/findumars/p/5750606.html
