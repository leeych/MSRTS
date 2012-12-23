#include "fourthpage.h"
#include "MacroImage.h"
#include <QVBoxLayout>
#include <QtGui>

FourthPage::FourthPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_FOURTHPAGE_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_TRIGGER_WIZARD_IMAGE4));

    infoLabel = new QLabel(STRING_FOURTH_TIP);
    infoLabel->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(infoLabel);

    setLayout(layout);
}

void FourthPage::setVisible(bool visible)
{
    QWizardPage::setVisible(visible);
    if (visible)
    {
        btn = wizard()->button(QWizard::FinishButton);
        connect(btn, SIGNAL(pressed()),
                wizard(), SLOT(onFinishButtonPressed()));\
    }
}

