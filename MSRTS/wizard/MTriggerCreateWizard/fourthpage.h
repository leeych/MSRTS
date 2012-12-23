#ifndef FOURTHPAGE_H
#define FOURTHPAGE_H

#include <QWizardPage>
#include <QLabel>

class FourthPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit FourthPage(QWidget *parent = 0);
    void setVisible(bool visible);
signals:

private:
    QAbstractButton *btn;
    QLabel *infoLabel;
};

#endif // FOURTHPAGE_H
