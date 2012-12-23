#include "dafourthpage.h"
#include "MacroImage.h"
#include <QVBoxLayout>
#include <QtGui>

DAFourthPage::DAFourthPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_DAWIZARDPAGE_FOURTH_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_DATAACQISITION_WIZARD_IMAGE4));

    infoLabel = new QLabel(STRING_DAWIZARDPAGE_FOURTH_TEXT);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(infoLabel);
    setLayout(layout);
}

void DAFourthPage::setVisible(bool visible)
{
    QWizardPage::setVisible(visible);
    if (visible)
    {
        btn = wizard()->button(QWizard::FinishButton);
        connect(btn, SIGNAL(pressed()),
                wizard(), SLOT(onFinishButtonPressed()));
    }
}
