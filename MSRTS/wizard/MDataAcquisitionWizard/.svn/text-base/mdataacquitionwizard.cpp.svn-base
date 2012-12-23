#include "mdataacquitionwizard.h"
#include "MacroImage.h"
#include <QMessageBox>

MDataAcquitionWizard::MDataAcquitionWizard(QWidget *parent) :
    QWizard(parent)
{
    setStyleSheet("background-color:#eaf6fe");
    setFixedSize(685, 509);
    setWindowTitle(STRING_DAWIZARD_TITLE);

    dataAcqisition = new MDataAcquisition;

    firstPg = new DAFirstPage;
    secondPg  = new DASecondPage;
    thirdPg = new DAThirdPage;
    fourthPg = new DAFourthPage;

    setPage(Page_First, firstPg);
    setPage(Page_second, secondPg);
    setPage(Page_Third, thirdPg);
    setPage(Page_Fourth, fourthPg);
    setStartId(Page_First);

#ifndef Q_WS_MAC
    setWizardStyle(ModernStyle);
#endif
}

void MDataAcquitionWizard::setDataAcqisition()
{
    dataAcqisition->SetId(secondPg->getId());
    dataAcqisition->SetName(secondPg->getName());
    dataAcqisition->SetModel(secondPg->getMode());
    dataAcqisition->SetIp(secondPg->getIP());
    dataAcqisition->SetTriggerMode(secondPg->getTriggerMode());
    dataAcqisition->SetEveryTransferPoint(secondPg->getTransferPoint());

    dataAcqisition->SetSampleRate(thirdPg->getSamplyRate());
    dataAcqisition->SetChannelCount(thirdPg->getChannelCount());
    dataAcqisition->SetStartChannelId(thirdPg->getStartChannelId());
}

void MDataAcquitionWizard::onFinishButtonPressed()
{
    int ret = QMessageBox::question(NULL, STRING_WRITEDB_DIALOG_TITLE,
                                    STRING_WRITEDB_DIALOG_TEXT, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    //setTrigger();
    if (ret == QMessageBox::Yes && commitDataAcqisitionInfo())
    {
        QMessageBox::information(NULL, STRING_WRITEDB_DIALOG_TITLE,
                                 STRING_WRITEDB_DIALOG_TIP);
        btn = this->button(QWizard::BackButton);
        btn->setEnabled(false);
        btn = this->button(QWizard::CancelButton);
        btn->setEnabled(false);
    }
    else
    {
        QMessageBox::information(NULL, STRING_WRITEDB_DIALOG_TITLE,
                                 STRING_WRITEDB_DIALOG_FAILURE);
    }
    btn = this->button(QWizard::FinishButton);
    disconnect(btn, SIGNAL(pressed()), this, SLOT(onFinishButtonPressed()));
}

bool MDataAcquitionWizard::commitDataAcqisitionInfo()
{
    /*
    setDataAcqisition();
    MRtsDataBase* db = MRtsDataBase::GetInstance();
    if(!db->AddTrigger(*trigger_))
    {
        return false;
    }
*/
    return true;
}
