#include <QtGui>
#include "statusinfowidget.h"
#include "MacroImage.h"

StatusInfoWidget::StatusInfoWidget()
{
    resize(QSize(STATUSINFO_WIDTH,STATUSINFO_HEIGHT));
}

void StatusInfoWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    DrawInfo(painter);
}

void StatusInfoWidget::TriggerInfoDisplay(int triggerId)
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();

    MTrigger* t;
    db->Trigger(triggerId,t);
    trigger_ = *t;
}
//#define STRING_STATUS_INFO               QObject::tr("Status Infomation");
//#define STRING_COMMON_INFO               QObject::tr("Common Infomation")
//#define STRING_ID                        QObject::tr("ID")
//#define STRING_NAME                      QObject::tr("Name")
//#define STRING_MODEL                     QObject::tr("Model")
//#define STRING_TYPE                      QObject::tr("Type")
//#define STRING_SENSITIVITY               QObject::tr("Sensitivity")
//#define STRING_TRIGGER_COORDINATE        QObject::tr("Trigger Coordinate")
//#define STRING_TRIGGER_POSITION          QObject::tr("Trigger Position")
//#define STRING_TRIGGER_STATUS            QObject::tr("Work Status")
//#define STRING_NORMAL                    QObject::tr("Normal")
//#define STRING_ABNORMAL                  QObject::tr("Abnormal")
//#define STRING_NOT_WORK                  QObject::tr("Nor work")
//#define STRING_DIP                       QObject::tr("Dip")
//#define STRING_AZIMUTH                   QObject::tr("Azimuth")
void StatusInfoWidget::DrawInfo(QPainter &painter)
{
    QFont font1("WenQuanYi",11);
    font1.setBold(true);
    painter.setFont(font1);
    painter.setPen(QColor(0,0,0));

    QString title;
    QString strTmp;
    title = trigger_.trigger_name();
    strTmp.sprintf(" %d ",trigger_.trigger_id());
    title += strTmp;
    title += STRING_STATUS_INFO;
    painter.drawText(20,20,title);
}
