#include "thirdpage.h"
#include "MacroImage.h"
#include <QHBoxLayout>

ThirdPage::ThirdPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_THIRDPAGE_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_TRIGGER_WIZARD_IMAGE3));

    triggerlabel = new QLabel(STRING_TRIGGER_OR_NOT);
    yesradio = new QRadioButton;
    yesradio->setChecked(true);
    yesradio->setText(STRING_YES_RADIO);

    noradio = new QRadioButton;
    noradio->setText(STRING_NO_RADIO);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(triggerlabel);
    layout->addWidget(yesradio);
    layout->addWidget(noradio);

    setLayout(layout);
}

bool ThirdPage::isUsing()
{
    return yesradio->isChecked();
}
