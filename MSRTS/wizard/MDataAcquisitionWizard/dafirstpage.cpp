#include "dafirstpage.h"
#include "MacroImage.h"
#include <QVBoxLayout>

DAFirstPage::DAFirstPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_DAWIZARDPAGE_FIRST_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_DATAACQISITION_WIZARD_IMAGE1));

    infoLabel = new QLabel(STRING_DAWIZARDPAGE_WELCOME_TIP);
    infoLabel->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(infoLabel);
    setLayout(layout);
}
