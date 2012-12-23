#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QComboBox>
#include <QGroupBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "data/mtrigger.h"

class SecondPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit SecondPage(QWidget *parent = 0);
    MTrigger *getTriggerInfo();
    bool validatePage();
signals:

public slots:
    void onXComponentChecked(bool);
    void onYComponentChecked(bool);
    void onZComponentChecked(bool);
    void onPComponentChecked(bool);

public:
    QString& getErrMsg();

    int getTriggerId();
    QString getTriggerName();
    QString getTriggerModel();
    int getTriggerType();
    int getTriggerSensitivity();
    Point getTriggerPosition();
    float getAzimuth();
    float getDip();
    byte getChannel();

private:
    QString *errMsg;
    QLabel *idLabel;
    QLabel *nameLabel;
    QLabel *modelLabel;
    QLabel *typeLabel;
    QLabel *sensitivityLabel;
    QLabel *positionLabel;
    QLabel *northLabel;
    QLabel *eastLabel;
    QLabel *downLabel;
    QLabel *azimuthLabel;
    QLabel *dipLabel;
    QLabel *channelLabel;

    QLineEdit *idLineEdit;
    QLineEdit *nameLineEdit;
    //QComboBox *modelComboBox, *typeComboBox;
    QLineEdit *modelLineEdit, *typeLineEdit;
    QLineEdit *sensitivityLineEdit;

    QLineEdit *northLineEdit, *eastLineEdit, *downLineEdit;

    QLineEdit *xAzimuthLineEdit, *xDipLineEdit;
    QLineEdit *yAzimuthLineEdit, *yDipLineEdit;
    QLineEdit *zAzimuthLineEdit, *zDipLineEdit;
    QLineEdit *pAzimuthLineEdit, *pDipLineEdit;

    QCheckBox *xchannel, *ychannel, *zchannel, *pchannel;

    QGroupBox *basicInfo, *triggerCoordinate, *triggerPosition;
};

#endif // SECONDPAGE_H
