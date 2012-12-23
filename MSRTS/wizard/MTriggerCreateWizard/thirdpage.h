#ifndef THIRDPAGE_H
#define THIRDPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>

class ThirdPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit ThirdPage(QWidget *parent = 0);
    bool isUsing();
signals:
    
public slots:

private:
    QLabel *triggerlabel;
    QRadioButton *yesradio;
    QRadioButton *noradio;
};

#endif // THIRDPAGE_H
