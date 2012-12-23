#include "firstpage.h"
#include "MacroImage.h"
#include <QVBoxLayout>

FirstPage::FirstPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_FIRSTPAGE_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_TRIGGER_WIZARD_IMAGE1));
    infolabel = new QLabel(STRING_WELCOME_TIP);
    infolabel->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(infolabel);

    setLayout(layout);
}
