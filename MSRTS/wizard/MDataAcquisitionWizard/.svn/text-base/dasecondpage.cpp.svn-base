#include "dasecondpage.h"
#include "MacroImage.h"
#include <QGridLayout>
#include <QVBoxLayout>

DASecondPage::DASecondPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_DAWIZARDPAGE_SECOND_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_DATAACQISITION_WIZARD_IMAGE2));

    QGridLayout *layout = new QGridLayout;

    idLabel = new QLabel(STRING_DATAACQUISITION_ID);
    nameLabel = new QLabel(STRING_DATAACQUISITION_NAME);
    modelLabel = new QLabel(STRING_DATAACQUISITION_MODEL);
    ipLabel = new QLabel(STRING_IP);
    trigmodeLabel = new QLabel(STRING_DATAACQUISITION_TRIGGER_MODE);
    delayLabel = new QLabel(STRING_DATAACQUISITION_DELAY_POINTS);
    transferLabel = new QLabel(STRING_DATAACQUISITION_TRANSFER_POINTS);
    lengthLabel = new QLabel(STRING_DATAACQUISITION_SAMPLE_LENGTH);
    //channelLabel = new QLabel(STRING_DATAACQUISITION_CHANNEL_COUNT);
    remarkLabel = new QLabel(STRING_DAWIZARD_REMARK);

    idLineEdit = new QLineEdit;
    nameLineEdit = new QLineEdit;
    modelCmb = new QComboBox;
    modelCmb->setEditable(true);
    ipLineEdit = new QLineEdit;
    //ipLineEdit->setEnabled(false);
    freeRbtn = new QRadioButton(STRING_DATAACQUISITION_FREE_TRIGGER);
    freeRbtn->setChecked(true);
    signalRbtn = new QRadioButton(STRING_DATAACQUISITION_TRIGGER);
    delayCmb = new QComboBox;
    transferCmb = new QComboBox;
    transferCmb->addItem(STRING_DATAACQISITION_TRANSFERPOINT_VALUE1);
    transferCmb->addItem(STRING_DATAACQISITION_TRANSFERPOINT_VALUE2);
    transferCmb->addItem(STRING_DATAACQISITION_TRANSFERPOINT_VALUE3);
    transferCmb->addItem(STRING_DATAACQISITION_TRANSFERPOINT_VALUE4);

    lengthCmb = new QComboBox;

    delayCmb->setEnabled(false);
    lengthCmb->setEnabled(false);

    //channelCmb = new QComboBox;

    layout->addWidget(idLabel, 0, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(idLineEdit, 0, 1, 1, 1, Qt::AlignLeft);
    layout->addWidget(nameLabel, 1, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(nameLineEdit, 1, 1, 1, 1, Qt::AlignLeft);
    layout->addWidget(modelLabel, 2, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(modelCmb, 2, 1, 1, 2, Qt::AlignLeft);
    layout->addWidget(ipLabel, 3, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(ipLineEdit, 3, 1, 1, 2, Qt::AlignLeft);
    layout->addWidget(trigmodeLabel, 4, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(freeRbtn, 4, 1, 1, 1, Qt::AlignLeft);
    layout->addWidget(signalRbtn, 4, 2, 1, 1, Qt::AlignLeft);
    layout->addWidget(delayLabel,  5, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(delayCmb, 5, 1, 1, 2, Qt::AlignLeft);
    layout->addWidget(transferLabel, 6, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(transferCmb, 6, 1, 1, 2, Qt::AlignLeft);
    layout->addWidget(lengthLabel, 7, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(lengthCmb, 7, 1, 1, 1, Qt::AlignLeft);
    //layout->addWidget(channelLabel, 6, 0, 1, 1, Qt::AlignLeft);
    //layout->addWidget(channelCmb, 6, 1, 1, 1, Qt::AlignLeft);

    QVBoxLayout *vlayout = new QVBoxLayout;
    QFrame *frame = new QFrame;
    frame->setLayout(layout);
    //frame->setMaximumHeight(280);

    vlayout->addWidget(frame);
    vlayout->addStretch(10);
    vlayout->addWidget(remarkLabel);
    vlayout->addStretch(5);
    setLayout(vlayout);

    registerField("DAID*", idLineEdit);
    registerField("DAName*", nameLineEdit);

    connect(modelCmb, SIGNAL(editTextChanged(QString)), modelCmb, SLOT(onModelComboBoxEdited(QString)));
}

void DASecondPage::getIpFromHost()
{
    // get ip from server.
    ipLineEdit->setText("192.168.1.1");
}

void DASecondPage::onModelComboBoxEdited(QString str)
{
    modelCmb->addItem(str);
}

int DASecondPage::getId()
{
    return idLineEdit->text().toInt();
}

QString DASecondPage::getName()
{
    return nameLineEdit->text();
}

QString DASecondPage::getMode()
{
    return modelCmb->currentText();
}

QString DASecondPage::getIP()
{
    return ipLineEdit->text();
}

int DASecondPage::getTriggerMode()
{
    return freeRbtn->isChecked() ? 0 : 1;
}

int DASecondPage::getTransferPoint()
{
    return transferCmb->currentText().toInt();
}

int DASecondPage::getTriggerDelayPoint()
{
    return delayCmb->currentText().toInt();
}

int DASecondPage::getSampleLength()
{
    return lengthCmb->currentText().toInt();
}
