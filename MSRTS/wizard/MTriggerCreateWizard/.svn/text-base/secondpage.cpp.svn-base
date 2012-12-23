#include "secondpage.h"
#include "MacroImage.h"
#include <QMessageBox>

SecondPage::SecondPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_SECONDPAGE_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_TRIGGER_WIZARD_IMAGE2));
    QVBoxLayout *vlayout = new QVBoxLayout;

    // basicInfo Group
    QGridLayout *blayout = new QGridLayout;
    idLabel = new QLabel(STRING_ID);
    nameLabel = new QLabel(STRING_NAME);
    modelLabel = new QLabel(STRING_MODEL);
    typeLabel = new QLabel(STRING_TYPE);
    sensitivityLabel = new QLabel(STRING_SENSITIVITY);

    idLineEdit = new QLineEdit;
    nameLineEdit = new QLineEdit;
    sensitivityLineEdit = new QLineEdit;
    modelLineEdit = new QLineEdit;
    typeLineEdit = new QLineEdit;
    //modelComboBox = new QComboBox;
    //typeComboBox = new QComboBox;
    //modelComboBox->addItem(tr("151-SM6 with tap"));
    //typeComboBox->addItem(tr("Acceleration"));
    blayout->addWidget(idLabel, 0, 0, 1, 1, Qt::AlignLeft);
    blayout->addWidget(idLineEdit, 0, 1, 1, 1, Qt::AlignLeft);
    blayout->addWidget(nameLabel, 1, 0, 1, 1, Qt::AlignLeft);
    blayout->addWidget(nameLineEdit, 1, 1, 1, 2, Qt::AlignLeft);
    blayout->addWidget(modelLabel, 2, 0, 1, 1, Qt::AlignLeft);
    //blayout->addWidget(modelComboBox, 2, 1, 1, 4, Qt::AlignLeft);
    blayout->addWidget(modelLineEdit, 2, 1, 1, 4, Qt::AlignLeft);
    blayout->addWidget(typeLabel, 3, 0, 1, 1, Qt::AlignLeft);
    //blayout->addWidget(typeComboBox, 3, 1, 1, 1, Qt::AlignLeft);
    blayout->addWidget(typeLineEdit, 3, 1, 1, 1, Qt::AlignLeft);
    blayout->addWidget(sensitivityLabel, 3, 3, 1, 1, Qt::AlignLeft);
    blayout->addWidget(sensitivityLineEdit, 3, 4, 1, 1, Qt::AlignLeft);

    basicInfo = new QGroupBox;
    basicInfo->setFlat(true);
    basicInfo->setLayout(blayout);

    // triggerCoordinate Group
    northLabel = new QLabel(STRING_TRIGGER_NORTH);
    eastLabel = new QLabel(STRING_TRIGGER_EAST);
    downLabel = new QLabel(STRING_TRIGGER_DOWN);

    northLineEdit = new QLineEdit;
    northLineEdit->setAlignment(Qt::AlignRight);
    eastLineEdit = new QLineEdit;
    eastLineEdit->setAlignment(Qt::AlignRight);
    downLineEdit = new QLineEdit;
    downLineEdit->setAlignment(Qt::AlignRight);

    QGridLayout *glayout = new QGridLayout;
    glayout->addWidget(northLabel, 0, 2, 1, 1, Qt::AlignCenter);
    glayout->addWidget(northLineEdit, 0, 3, 1, 2, Qt::AlignLeft);
    glayout->addWidget(eastLabel, 1, 2, 1, 1, Qt::AlignCenter);
    glayout->addWidget(eastLineEdit, 1, 3, 1, 2, Qt::AlignLeft);
    glayout->addWidget(downLabel, 2, 2, 1, 1, Qt::AlignCenter);
    glayout->addWidget(downLineEdit, 2, 3, 1, 2, Qt::AlignLeft);
    triggerCoordinate = new QGroupBox(STRING_TRIGGER_COORDINATE);
    triggerCoordinate->setLayout(glayout);

    // triggerPosition Group
    azimuthLabel = new QLabel(STRING_AZIMUTH);
    dipLabel = new QLabel(STRING_DIP);
    channelLabel = new QLabel(STRING_TRIGGER_CHANNEL);

    xAzimuthLineEdit = new QLineEdit("0");
    xDipLineEdit = new QLineEdit("0");
    yAzimuthLineEdit = new QLineEdit("-");
    yAzimuthLineEdit->setEnabled(false);
    yDipLineEdit = new QLineEdit("-");
    yDipLineEdit->setEnabled(false);
    zAzimuthLineEdit = new QLineEdit("-");
    zAzimuthLineEdit->setEnabled(false);
    zDipLineEdit = new QLineEdit("-");
    zDipLineEdit->setEnabled(false);
    pAzimuthLineEdit = new QLineEdit("-");
    pAzimuthLineEdit->setEnabled(false);
    pDipLineEdit = new QLineEdit("-");
    pDipLineEdit->setEnabled(false);

    xchannel = new QCheckBox(STRING_X_CHECKBOX);
    xchannel->setChecked(true);
    xchannel->setStyleSheet("color: red;");
    ychannel = new QCheckBox(STRING_Y_CHECKBOX);
    ychannel->setStyleSheet("color: #55d101");
    zchannel = new QCheckBox(STRING_Z_CHECKBOX);
    zchannel->setStyleSheet("color: #4c89d9;");
    pchannel = new QCheckBox(STRING_P_CHECKBOX);

    QGridLayout *playout = new QGridLayout;
    playout->addWidget(channelLabel, 0, 2, 1, 1, Qt::AlignLeft);
    playout->addWidget(xchannel, 0, 3, 1, 1, Qt::AlignLeft);
    playout->addWidget(ychannel, 0, 4, 1, 1, Qt::AlignLeft);
    playout->addWidget(zchannel, 0, 5, 1, 1, Qt::AlignLeft);
    playout->addWidget(pchannel, 0, 6, 1, 1, Qt::AlignLeft);
    playout->addWidget(azimuthLabel, 1, 2, 1, 1, Qt::AlignCenter);
    playout->addWidget(xAzimuthLineEdit, 1, 3, 1, 1, Qt::AlignLeft);
    playout->addWidget(yAzimuthLineEdit, 1, 4, 1, 1, Qt::AlignLeft);
    playout->addWidget(zAzimuthLineEdit, 1, 5, 1, 1, Qt::AlignLeft);
    playout->addWidget(pAzimuthLineEdit, 1, 6, 1, 1, Qt::AlignLeft);

    playout->addWidget(xDipLineEdit, 2, 3, 1, 1, Qt::AlignLeft);
    playout->addWidget(yDipLineEdit, 2, 4, 1, 1, Qt::AlignLeft);
    playout->addWidget(zDipLineEdit, 2, 5, 1, 1, Qt::AlignLeft);
    playout->addWidget(pDipLineEdit, 2, 6, 1, 1, Qt::AlignLeft);

    playout->addWidget(dipLabel, 2, 2, 1, 1, Qt::AlignLeft);
    playout->addWidget(xDipLineEdit, 2, 3, 1, 1, Qt::AlignLeft);

    triggerPosition = new QGroupBox(STRING_TRIGGER_POSITION);
    triggerPosition->setLayout(playout);

    vlayout->addWidget(basicInfo);
    vlayout->addWidget(triggerCoordinate);
    vlayout->addWidget(triggerPosition);

    errMsg = new QString(idLineEdit->text());
    registerField("TriggerID*", idLineEdit);
    registerField("TriggerName*", nameLineEdit);

    connect(xchannel, SIGNAL(clicked(bool)), this, SLOT(onXComponentChecked(bool)));
    connect(ychannel, SIGNAL(clicked(bool)), this, SLOT(onYComponentChecked(bool)));
    connect(zchannel, SIGNAL(clicked(bool)), this, SLOT(onZComponentChecked(bool)));
    connect(pchannel, SIGNAL(clicked(bool)), this, SLOT(onPComponentChecked(bool)));

    setLayout(vlayout);
}

bool SecondPage::validatePage()
{
    if (getTriggerId() == 0)
    {
        *errMsg = idLineEdit->text();
        return false;
    }
    else
    {
        return true;
    }
}

MTrigger *SecondPage::getTriggerInfo()
{
    MTrigger *trigger = new MTrigger;
    int id = idLineEdit->text().toInt();
    QString name = nameLineEdit->text();
    //QString model = modelComboBox->currentText();
    //int type = typeComboBox->currentText().toInt();
    QString model = modelLineEdit->text();
    int type = typeLineEdit->text().toInt();
    int sensitivity = sensitivityLineEdit->text().toInt();
    int azimuth = xAzimuthLineEdit->text().toFloat();
    int dip = xDipLineEdit->text().toFloat();
    // channel left
    Point *point = new Point;
    point->wgs_point.longitude = northLineEdit->text().toFloat();
    point->wgs_point.latitude = eastLineEdit->text().toFloat();
    point->wgs_point.elevation = downLineEdit->text().toFloat();

    trigger->SetTriggerId(id);
    trigger->SetTriggerName(name);
    trigger->SetTriggerModel(model);
    trigger->SetTriggerType(type);
    trigger->SetTriggerSensitivity(sensitivity);
    trigger->SetAzimuth(azimuth);
    trigger->SetDip(dip);
    trigger->SetTriggerPoint(*point);

    return trigger;
}

QString& SecondPage::getErrMsg()
{
    return *errMsg;
}

int SecondPage::getTriggerId()
{
    return idLineEdit->text().toInt();
}

QString SecondPage::getTriggerName()
{
    return nameLineEdit->text();
}

QString SecondPage::getTriggerModel()
{
    //return modelComboBox->currentText();
    return modelLineEdit->text();
}

int SecondPage::getTriggerType()
{
    //return typeComboBox->currentText().toInt();
    return typeLineEdit->text().toInt();
}

int SecondPage::getTriggerSensitivity()
{
    return sensitivityLineEdit->text().toInt();
}

Point SecondPage::getTriggerPosition()
{
    Point point;
    point.wgs_point.longitude = northLineEdit->text().toFloat();
    point.wgs_point.latitude = eastLineEdit->text().toFloat();
    point.wgs_point.elevation = downLineEdit->text().toFloat();
    return point;
}

float SecondPage::getAzimuth()
{
    return xAzimuthLineEdit->text().toFloat();
}

float SecondPage::getDip()
{
    return xDipLineEdit->text().toFloat();
}

byte SecondPage::getChannel()
{
    if (xchannel->isChecked() && ychannel->isChecked() && zchannel->isChecked())
    {
        pchannel->setChecked(false);
        return 0x08;
    }
    byte tmp = 0x00;
    if (pchannel->isChecked())
    {
        tmp |= 0x08;
    }
    if (xchannel->isChecked())
    {
        tmp |= 0x04;
    }
    if (ychannel->isChecked())
    {
        tmp |= 0x02;
    }
    if (zchannel->isChecked())
    {
        tmp |= 0x01;
    }
    return tmp;
}

void SecondPage::onXComponentChecked(bool flag)
{
    xAzimuthLineEdit->setEnabled(flag);
    xDipLineEdit->setEnabled(flag);
}

void SecondPage::onYComponentChecked(bool flag)
{
    yAzimuthLineEdit->setEnabled(flag);
    yDipLineEdit->setEnabled(flag);
}

void SecondPage::onZComponentChecked(bool flag)
{
    zAzimuthLineEdit->setEnabled(flag);
    zDipLineEdit->setEnabled(flag);
}

void SecondPage::onPComponentChecked(bool flag)
{
    pAzimuthLineEdit->setEnabled(flag);
    pDipLineEdit->setEnabled(flag);
}
