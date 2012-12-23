#ifndef MDATAACQUITIONWIZARD_H
#define MDATAACQUITIONWIZARD_H

#include <QWizard>
#include "dafirstpage.h"
#include "dasecondpage.h"
#include "dathirdpage.h"
#include "dafourthpage.h"
#include "mdataacquisition.h"

class MDataAcquitionWizard : public QWizard
{
    Q_OBJECT
public:
    explicit MDataAcquitionWizard(QWidget *parent = 0);
    enum { Page_First, Page_second, Page_Third, Page_Fourth };
    bool commitDataAcqisitionInfo();
signals:
    
public slots:
    void onFinishButtonPressed();
private:
    void setDataAcqisition();
private:
    QAbstractButton *btn;
    MDataAcquisition *dataAcqisition;

    DAFirstPage *firstPg;
    DASecondPage *secondPg;
    DAThirdPage *thirdPg;
    DAFourthPage *fourthPg;
};

#endif // MDATAACQUITIONWIZARD_H
