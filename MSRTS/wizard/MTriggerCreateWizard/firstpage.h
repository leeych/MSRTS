#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QRadioButton>

class FirstPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit FirstPage(QWidget *parent = 0);
    
signals:
    
public slots:
private:
    QLabel *infolabel;
};

#endif // FIRSTPAGE_H
