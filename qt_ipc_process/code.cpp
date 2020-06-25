//server端开进程
//if(! pro )
//{
//pro = new QProcess(this);
//connect(pro, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(processFinished(int, QProcess::ExitStatus)));
//connect(pro, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
//connect(pro, SIGNAL(readyRead()), this, SLOT(readFromClient()));
//pro->start(“./client”);
//}

//server端接收数据
//void MainWin::readFromClient()
//{
//if( !pro) return;
//QByteArray output = pro->readAllStandardOutput();
//qWarning() }

//server端发送数据
//void MainWin::writeToClient()
//{
//if( !pro) return;
//pro->write(le->text().toLatin1().constData(), le->text().length());
//qWarning() text();
//}

//client端监控stdin的读写消息
//filein.open(stdin, QIODevice::ReadOnly);
//QSocketNotifier* sn = new QSocketNotifier(filein.handle(), QSocketNotifier::Read, this);
//connect(sn, SIGNAL(activated(int)), this, SLOT(readFromServer(int)));

//client端接收数据
//void MainWin::readFromServer(int fd)
//{
//if(fd != filein.handle() )
//return;

//char buffer[256];
//int count = read(filein.handle(), buffer, 256);
//le->setText(“FROM SERVER:” + QString(buffer).left(count));
//}

//client端发送数据
//void MainWin::writeToServer()
//{
//QFile fileout;
//fileout.open(stdout, QIODevice::WriteOnly);
//fileout.write(le->text().toLatin1().constData(), le->text().length()); // write to stderr
//qWarning() text();
//fileout.close();
//}
