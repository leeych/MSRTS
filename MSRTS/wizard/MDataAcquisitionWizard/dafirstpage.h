#ifndef DAFIRSTPAGE_H
#define DAFIRSTPAGE_H

#include <QWizardPage>
#include <QLabel>

class DAFirstPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit DAFirstPage(QWidget *parent = 0);
    
signals:
    
public slots:
private:
    QLabel *infoLabel;
};

#endif // DAFIRSTPAGE_H
