#include <QApplication>
#include <QTranslator>
#include <QTextCodec>
#include <QMessageBox>
#include <QFontDatabase>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "test1.h"

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

    //QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("gbk"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));

    app.setFont(QFont("Fangsong Ti"));
    //app.setFont(QFont("wenquanyi",12,QFont::Bold));
    //QFontDatabase::addApplicationFont();

    QTranslator translator;

    translator.load(":/qm/MSRTS_cn.qm");
    app.installTranslator(&translator);

    Test1::getInstance()->TestInit();

    MainWindow mainwnd;
    mainwnd.showMaximized();
    mainwnd.UpdateDataToTree();
    mainwnd.show();

    return app.exec();
}

