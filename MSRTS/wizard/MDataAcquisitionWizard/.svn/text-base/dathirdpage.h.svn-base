#ifndef DATHIRDPAGE_H
#define DATHIRDPAGE_H

#include <QWizardPage>
#include <QLabel>
//#include <QComboBox>
#include <QGroupBox>
#include <QList>
#include "triggercomponentcombobox.h"

class DAThirdPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit DAThirdPage(QWidget *parent = 0);
    
    int getChannelCount();
    int getStartChannelId();
    int getSamplyRate();
    QList<int> getTriggerId();

    void setVisible(bool visible);
signals:
    
public slots:
    void onChannelIdCmbItemSelected(int);
private:
    QLabel *rateLabel;
    QLabel *channelCountLabel;
    QLabel *channelIdLabel;
    QComboBox *channelIdCmb;

    QLabel *channelLabel1;
    QLabel *channelLabel2;
    QLabel *channelLabel3;
    QLabel *channelLabel4;
    QLabel *channelLabel5;
    QLabel *channelLabel6;
    QLabel *channelLabel7;
    QLabel *channelLabel8;

    QComboBox *channelCmb1;
    QComboBox *channelCmb2;
    QComboBox *channelCmb3;
    QComboBox *channelCmb4;
    QComboBox *channelCmb5;
    QComboBox *channelCmb6;
    QComboBox *channelCmb7;
    QComboBox *channelCmb8;

    QLabel *componentLabel1;
    QLabel *componentLabel2;
    QLabel *componentLabel3;
    QLabel *componentLabel4;
    QLabel *componentLabel5;
    QLabel *componentLabel6;
    QLabel *componentLabel7;
    QLabel *componentLabel8;

    QComboBox *rateCmb;
    QComboBox *channelCountCmb;

    TriggerComponentComboBox *componentCmb1;
    TriggerComponentComboBox *componentCmb2;
    TriggerComponentComboBox *componentCmb3;
    TriggerComponentComboBox *componentCmb4;
    TriggerComponentComboBox *componentCmb5;
    TriggerComponentComboBox *componentCmb6;
    TriggerComponentComboBox *componentCmb7;
    TriggerComponentComboBox *componentCmb8;
};

#endif // DATHIRDPAGE_H
