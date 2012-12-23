#include "triggercomponentcombobox.h"
#include "MacroImage.h"

TriggerComponentComboBox::TriggerComponentComboBox(QObject *parent) :
    QComboBox((QWidget *)parent)
{
    this->addItem("X");
    this->addItem("Y");
    this->addItem("Z");
    this->addItem("P");
    this->addItem("-");
}

void TriggerComponentComboBox::setDisabled(bool flag)
{
    if (flag)
    {
        this->setCurrentIndex(4);
    }
    this->setEnabled(!flag);
}
