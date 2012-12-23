#include "dathirdpage.h"
#include "MacroImage.h"
#include "channelcombobox.h"
#include "triggerallocator.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QMessageBox>

DAThirdPage::DAThirdPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(STRING_DAWIZARDPAGE_THIRD_TITLE);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(STRING_DATAACQISITION_WIZARD_IMAGE3));

    rateLabel = new QLabel(STRING_SAMPLE_RATE);
    channelCountLabel = new QLabel(STRING_DATAACQUISITION_CHANNEL_COUNT);
    channelIdLabel = new QLabel(STRING_DATAACQISITION_START_CHANNELID);
    rateCmb = new QComboBox;
    channelCountCmb = new QComboBox;
    channelCountCmb->addItem("1");
    channelCountCmb->addItem("2");
    channelCountCmb->addItem("3");
    channelCountCmb->addItem("4");
    channelCountCmb->addItem("5");
    channelCountCmb->addItem("6");
    channelCountCmb->addItem("7");
    channelCountCmb->addItem("8");
    channelIdCmb = new QComboBox;
    channelIdCmb->addItem("1");
    channelIdCmb->addItem("2");
    channelIdCmb->addItem("3");
    channelIdCmb->addItem("4");
    channelIdCmb->addItem("5");
    channelIdCmb->addItem("6");
    channelIdCmb->addItem("7");
    channelIdCmb->addItem("8");
    //channelNumberCmb->setEditable(true);

    channelLabel1 = new QLabel(STRING_CHANNEL);
    channelLabel2 = new QLabel(STRING_CHANNEL);
    channelLabel3 = new QLabel(STRING_CHANNEL);
    channelLabel4 = new QLabel(STRING_CHANNEL);
    channelLabel5 = new QLabel(STRING_CHANNEL);
    channelLabel6 = new QLabel(STRING_CHANNEL);
    channelLabel7 = new QLabel(STRING_CHANNEL);
    channelLabel8 = new QLabel(STRING_CHANNEL);

    componentLabel1 = new QLabel(STRING_DATAACQUISITION_COMPONENT);
    componentLabel2 = new QLabel(STRING_DATAACQUISITION_COMPONENT);
    componentLabel3 = new QLabel(STRING_DATAACQUISITION_COMPONENT);
    componentLabel4 = new QLabel(STRING_DATAACQUISITION_COMPONENT);
    componentLabel5 = new QLabel(STRING_DATAACQUISITION_COMPONENT);
    componentLabel6 = new QLabel(STRING_DATAACQUISITION_COMPONENT);
    componentLabel7 = new QLabel(STRING_DATAACQUISITION_COMPONENT);
    componentLabel8 = new QLabel(STRING_DATAACQUISITION_COMPONENT);

    channelCmb1 = new ChannelComboBox;
    channelCmb2 = new ChannelComboBox;
    channelCmb3 = new ChannelComboBox;
    channelCmb4 = new ChannelComboBox;
    channelCmb5 = new ChannelComboBox;
    channelCmb6 = new ChannelComboBox;
    channelCmb7 = new ChannelComboBox;
    channelCmb8 = new ChannelComboBox;

    componentCmb1 = new TriggerComponentComboBox;
    componentCmb2 = new TriggerComponentComboBox;
    componentCmb3 = new TriggerComponentComboBox;
    componentCmb4 = new TriggerComponentComboBox;
    componentCmb5 = new TriggerComponentComboBox;
    componentCmb6 = new TriggerComponentComboBox;
    componentCmb7 = new TriggerComponentComboBox;
    componentCmb8 = new TriggerComponentComboBox;

    QFrame *frame = new QFrame;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(rateLabel, 0, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(rateCmb, 0, 1, 1, 1, Qt::AlignLeft);
    layout->addWidget(channelCountLabel, 1, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(channelCountCmb, 1, 1, 1, 1, Qt::AlignLeft);
    layout->addWidget(channelIdLabel, 2, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(channelIdCmb, 2, 1, 1, 1, Qt::AlignLeft);
    frame->setLayout(layout);

    QGridLayout *gLayout = new QGridLayout;

    gLayout->addWidget(channelLabel1, 0, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb1, 0, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel1, 0, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb1, 0, 3, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(channelLabel2, 1, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb2, 1, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel2, 1, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb2, 1, 3, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(channelLabel3, 2, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb3, 2, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel3, 2, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb3, 2, 3, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(channelLabel4, 3, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb4, 3, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel4, 3, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb4, 3, 3, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(channelLabel5, 4, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb5, 4, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel5, 4, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb5, 4, 3, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(channelLabel6, 5, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb6, 5, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel6, 5, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb6, 5, 3, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(channelLabel7, 6, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb7, 6, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel7, 6, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb7, 6, 3, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(channelLabel8, 7, 0, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(channelCmb8, 7, 1, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentLabel8, 7, 2, 1, 1, Qt::AlignLeft);
    gLayout->addWidget(componentCmb8, 7, 3, 1, 1, Qt::AlignLeft);

    QGroupBox *group = new QGroupBox;
    group->setLayout(gLayout);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(frame);
    vLayout->addWidget(group);
    setLayout(vLayout);
}

int DAThirdPage::getChannelCount()
{
   return channelCountCmb->currentText().toInt();
}

int DAThirdPage::getStartChannelId()
{
    return channelIdCmb->currentText().toInt();
}

int DAThirdPage::getSamplyRate()
{
    return rateCmb->currentText().toInt();
}

QList<int> DAThirdPage::getTriggerId()
{
    QList<int> *triggerIdList = new QList<int>;
    return *triggerIdList;
}

void DAThirdPage::onChannelIdCmbItemSelected(int num)
{
    switch (num)
    {
    case 0:
        break;
    case 1:
        channelCmb1->setDisabled(true);
        componentCmb1->setDisabled(true);
        break;
    case 2:
        channelCmb1->setDisabled(true);
        channelCmb2->setDisabled(true);

        componentCmb1->setDisabled(true);
        componentCmb2->setDisabled(true);
        break;
    case 3:
        channelCmb1->setDisabled(true);
        channelCmb2->setDisabled(true);
        channelCmb3->setDisabled(true);

        componentCmb1->setDisabled(true);
        componentCmb2->setDisabled(true);
        componentCmb3->setDisabled(true);
        break;
    case 4:
        channelCmb1->setDisabled(true);
        channelCmb2->setDisabled(true);
        channelCmb3->setDisabled(true);
        channelCmb4->setDisabled(true);

        componentCmb1->setDisabled(true);
        componentCmb2->setDisabled(true);
        componentCmb3->setDisabled(true);
        componentCmb4->setDisabled(true);
        break;
    case 5:
        channelCmb1->setDisabled(true);
        channelCmb2->setDisabled(true);
        channelCmb3->setDisabled(true);
        channelCmb4->setDisabled(true);
        channelCmb5->setDisabled(true);

        componentCmb1->setDisabled(true);
        componentCmb2->setDisabled(true);
        componentCmb3->setDisabled(true);
        componentCmb4->setDisabled(true);
        componentCmb5->setDisabled(true);
        break;
    case 6:
        channelCmb1->setDisabled(true);
        channelCmb2->setDisabled(true);
        channelCmb3->setDisabled(true);
        channelCmb4->setDisabled(true);
        channelCmb5->setDisabled(true);
        channelCmb6->setDisabled(true);

        componentCmb1->setDisabled(true);
        componentCmb2->setDisabled(true);
        componentCmb3->setDisabled(true);
        componentCmb4->setDisabled(true);
        componentCmb5->setDisabled(true);
        componentCmb6->setDisabled(true);
        break;
    case 7:
        channelCmb1->setDisabled(true);
        channelCmb2->setDisabled(true);
        channelCmb3->setDisabled(true);
        channelCmb4->setDisabled(true);
        channelCmb5->setDisabled(true);
        channelCmb6->setDisabled(true);
        channelCmb7->setDisabled(true);

        componentCmb1->setDisabled(true);
        componentCmb2->setDisabled(true);
        componentCmb3->setDisabled(true);
        componentCmb4->setDisabled(true);
        componentCmb5->setDisabled(true);
        componentCmb6->setDisabled(true);
        componentCmb7->setDisabled(true);
        break;
    default:
        channelCmb1->setDisabled(false);
        channelCmb2->setDisabled(false);
        channelCmb3->setDisabled(false);
        channelCmb4->setDisabled(false);
        channelCmb5->setDisabled(false);
        channelCmb6->setDisabled(false);
        channelCmb7->setDisabled(false);
        channelCmb8->setDisabled(false);

        componentCmb1->setDisabled(false);
        componentCmb2->setDisabled(false);
        componentCmb3->setDisabled(false);
        componentCmb4->setDisabled(false);
        componentCmb5->setDisabled(false);
        componentCmb6->setDisabled(false);
        componentCmb7->setDisabled(false);
        componentCmb8->setDisabled(false);
        break;
    }
}

void DAThirdPage::setVisible(bool visible)
{
    QWizardPage::setVisible(visible);
    if (visible)
    {
        connect(channelIdCmb, SIGNAL(activated(int)),
                this, SLOT(onChannelIdCmbItemSelected(int)));
    }
}


