#ifndef DASECONDPAGE_H
#define DASECONDPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QRadioButton>

class DASecondPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit DASecondPage(QWidget *parent = 0);
    
    int getId();
    QString getName();
    QString getMode();
    QString getIP();
    int getTriggerMode();
    int getTransferPoint();
    int getTriggerDelayPoint();
    int getSampleLength();
signals:
    
public slots:
    void onModelComboBoxEdited(QString);
private:
    void getIpFromHost();

private:
    QLabel *infolabel;

    QLabel *idLabel;
    QLabel *nameLabel;
    QLabel *modelLabel;
    QLabel *ipLabel;
    QLabel *trigmodeLabel;
    QLabel *delayLabel;
    QLabel *transferLabel;
    QLabel *lengthLabel;
    QLabel *remarkLabel;

    QLabel *channelLabel;

    QLineEdit *idLineEdit;
    QLineEdit *nameLineEdit;
    QComboBox *modelCmb;
    QLineEdit *ipLineEdit;
    QRadioButton *freeRbtn, *signalRbtn;
    QComboBox *delayCmb, *transferCmb, *lengthCmb;
};

#endif // DASECONDPAGE_H
