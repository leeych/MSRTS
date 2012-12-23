#ifndef MTRIGGERCREATEWIZARD_H
#define MTRIGGERCREATEWIZARD_H

#include <QWizard>
#include "data/mtrigger.h"
#include "firstpage.h"
#include "secondpage.h"
#include "thirdpage.h"
#include "fourthpage.h"

class MTriggerCreateWizard : public QWizard
{
    Q_OBJECT
public:
    explicit MTriggerCreateWizard(QWidget *parent = 0);
    enum { Page_First, Page_Second, Page_Third, Page_Fourth };
    ~MTriggerCreateWizard();
signals:
    void addTriggerFinish();
public slots:
    void onFinishButtonPressed();
public:
    bool commitTriggerInfo();
    void run();
private:
    MTrigger *getTrigger();
    void setTrigger();
private:
    QAbstractButton *btn;
    MTrigger *trigger_;

    FirstPage *firstPg;
    SecondPage *secondPg;
    ThirdPage *thirdPg;
    FourthPage *fourthPg;
};

#endif // TRIGGERADDWIZARD_H
