#include <QtGui>
#include "mutility.h"

void getMainDir(QString& strDir)
{
    strDir = QCoreApplication::applicationDirPath();
    strDir += "/";
}

void getImageDir(QString& strImageDir)
{
    //strImageDir = QCoreApplication::applicationDirPath();
    strImageDir = ":";
    strImageDir += "/images/";
}

void getCurIconDir(QString& strCurIconDir)
{
    strCurIconDir = QCoreApplication::applicationDirPath();
    strCurIconDir += "/images/toolbaricon/currenticon/";
}

void getCurseIconDir(QString& strCurseIconDir)
{
    strCurseIconDir = QCoreApplication::applicationDirPath();
    strCurseIconDir += "/images/toolbaricon/curseicon/";
}


void getClickIconDir(QString& strClickIconDir)
{
    strClickIconDir = QCoreApplication::applicationDirPath();
    strClickIconDir += "/images/toolbaricon/clickedicon/";
}

void GetPolarIconDir(QString &strDir)
{
	strDir = QCoreApplication::applicationDirPath();
	strDir += "/images/polar_toolbar_icon/";
}

void getCssDir(QString& strCssDir)
{
    strCssDir = QCoreApplication::applicationDirPath();
    strCssDir += "/css/";
}

QByteArray fetchQrc(const QString &fileName)
{
    QFile file(fileName);
    bool ok = file.open(QIODevice::ReadOnly);
    //QTC_ASSERT(ok, qWarning() << fileName << "not there!"; return QByteArray());
    return file.readAll();
}
