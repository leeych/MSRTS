#include "systemstatusframe.h"
#include "ui/mtitlewidget.h"
#include "data/mrtsdatabase.h"
#include "mutility.h"
#include "MacroImage.h"

SystemStatusFrame::SystemStatusFrame(QWidget *parent) :
    QFrame(parent)
{

    infodisplaylayout_ = new QVBoxLayout;
    QString strDir;
    getImageDir(strDir);
    QString strTitle;
    strTitle = strDir + SYSTEM_STATUS_IMAGE;
    QString strTip;
    strTip = strDir + SYSTEM_STATUS_1PX_IMAGE;
    MTitleWidget* titlewidget = new MTitleWidget(strTip);
    titlewidget->SetTitleName(strTitle);
    treewidget_ = new MTreeWidget;

    infodisplaylayout_->addWidget(titlewidget);
    infodisplaylayout_->addWidget(treewidget_);
    infodisplaylayout_->setMargin(0);
    infodisplaylayout_->setSpacing(0);

    setLayout(infodisplaylayout_);
    titlewidget->setDrawBottomLine(false);

    connect(treewidget_,SIGNAL(itemDoubleClickedSignal(int)),this,SLOT(onTreeWidgetDoubleClicked(int)));
}

void SystemStatusFrame::UpdateDataToTree()
{
    if(treewidget_ == NULL)
    {
        return;
    }

    treewidget_->clear();

    QString strImageDir;
    getImageDir(strImageDir);

    QTreeWidgetItem * root = AddTreeTopLevelFolder(QString(STRING_RUNTIME_CONTROL_SYSTEM));

    MRtsDataBase* db = MRtsDataBase::GetInstance();

    QList<int> daList = db->DataAcquisitionList();

    MDataAcquisition* da;
    MTrigger* tr;
    QString strIconImage;
    QString strItemText;
    QColor itemColor;
    QString strTmp;
    for(QList<int>::iterator itr = daList.begin();itr != daList.end();itr++)
    {
        db->DataAcquisition(*itr,da);

        if(da->status() == 0)
        {
            strIconImage = strImageDir + DATAACQUISITION_NORMAL_IMAGE;
            itemColor.setRgb(0,0,0);
        }
        else if(da->status() == 1)
        {
            strIconImage = strImageDir + DATAACQUISITION_ABNORMAL_IMAGE;
            itemColor.setRgb(255,0,0);
        }
        else
        {
            strIconImage = strImageDir + DATAACQUISITION_NOTWORK_IMAGE;
            itemColor.setRgb(102,102,102);
        }

        strItemText = da->name();
        strItemText += "-";

        strTmp.sprintf("%d",da->id());
        strItemText += strTmp;

        QTreeWidgetItem* node = treewidget_->addWidgetItem(root,QIcon(strIconImage),strItemText,itemColor,SECOND_LEVEL,da->id());
        QList<int> triggerList = da->triggerid_list();
        for(QList<int>::iterator tritr = triggerList.begin();tritr != triggerList.end();tritr++)
        {
            db->Trigger(*tritr,tr);
            if(tr->status() == 0)
            {
                strIconImage = strImageDir + TRIGGER_NORMAL_IMAGE;
                itemColor.setRgb(0,0,0);
            }
            else if(tr->status() == 1)
            {
                strIconImage = strImageDir + TRIGGER_ABNORMAL_IMAGE;
                itemColor.setRgb(255,0,0);
            }
            else
            {
                strIconImage = strImageDir + TRIGGER_NOTWORK_IMAGE;
                itemColor.setRgb(102,102,102);
            }

            strItemText = tr->trigger_name();
            strItemText += "-";
            QString strTmp;
            strTmp.sprintf("%d",tr->trigger_id());
            strItemText += strTmp;

            treewidget_->addWidgetItem(node,QIcon(strIconImage),strItemText,itemColor,THIRD_LEVEL,tr->trigger_id());
        }
    }

}

void SystemStatusFrame::onTreeWidgetDoubleClicked(int id)
{
    emit treeWidgetDoubleClicked(id);
}

QTreeWidgetItem *SystemStatusFrame::AddTreeTopLevelFolder(const QString &name)
{
    if(treewidget_ == NULL)
    {
        return NULL;
    }

    QString strImageDir;
    getImageDir(strImageDir);
    QIcon forderIcon(strImageDir + FOLDER_IMAGE);

    return treewidget_->addWidgetItem(NULL,forderIcon,
                               name,QColor(0,0,0),TOP_LEVEL);
}
