#include "mtriggercreatewizard.h"
#include "MacroImage.h"
#include <QtGui>
#include "data/mrtsdatabase.h"

MTriggerCreateWizard::MTriggerCreateWizard(QWidget *parent) :
    QWizard(parent)
{
    setStyleSheet("background-color:#eaf6fe");
    setFixedSize(685, 509);
    setWindowTitle(STRING_TRIGGER_TITLE);

    trigger_ = new MTrigger;

    firstPg = new FirstPage;
    secondPg = new SecondPage;
    thirdPg = new ThirdPage;
    fourthPg = new FourthPage;

    setPage(Page_First, firstPg);
    setPage(Page_Second, secondPg);
    setPage(Page_Third, thirdPg);
    setPage(Page_Fourth, fourthPg);

#ifndef Q_WS_MAC
    setWizardStyle(ModernStyle);
#endif
}

void MTriggerCreateWizard::onFinishButtonPressed()
{
    int ret = QMessageBox::question(NULL, STRING_WRITEDB_DIALOG_TITLE,
                                    STRING_WRITEDB_DIALOG_TEXT, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    setTrigger();
    if (ret == QMessageBox::Yes && commitTriggerInfo())
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

MTriggerCreateWizard::~MTriggerCreateWizard()
{
    delete firstPg;
    delete secondPg;
    delete thirdPg;
    delete fourthPg;

    delete trigger_;

    firstPg = NULL;
    secondPg = NULL;
    thirdPg = NULL;
    fourthPg = NULL;
    trigger_ = NULL;
}

void MTriggerCreateWizard::setTrigger()
{
    trigger_->SetTriggerId(secondPg->getTriggerId());
    trigger_->SetTriggerName(secondPg->getTriggerName());
    trigger_->SetTriggerModel(secondPg->getTriggerModel());
    trigger_->SetTriggerType(secondPg->getTriggerType());
    trigger_->SetTriggerPoint(secondPg->getTriggerPosition());
    trigger_->SetTriggerSensitivity(secondPg->getTriggerSensitivity());
    trigger_->SetTriggerChannel(secondPg->getChannel());
    trigger_->SetAzimuth(secondPg->getAzimuth());
    trigger_->SetDip(secondPg->getDip());
    trigger_->SetIsUing(thirdPg->isUsing());
}

MTrigger* MTriggerCreateWizard::getTrigger()
{
    return trigger_;
}

void MTriggerCreateWizard::run()
{
    exec();
}

bool MTriggerCreateWizard::commitTriggerInfo()
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();
    if(!db->AddTrigger(*trigger_))
    {
        return false;
    }

    return true;
}


