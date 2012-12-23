#ifndef DAFOURTHPAGE_H
#define DAFOURTHPAGE_H

#include <QWizardPage>
#include <QLabel>

class DAFourthPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit DAFourthPage(QWidget *parent = 0);

    void setVisible(bool visible);
signals:
    
public slots:

private:
    QAbstractButton *btn;
    QLabel *infoLabel;
};

#endif // DAFOURTHPAGE_H
