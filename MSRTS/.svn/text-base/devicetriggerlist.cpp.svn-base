#include <QtGui>
#include "devicetriggerlist.h"
#include "MacroImage.h"
#include "data/mrtsdatabase.h"
#include "mutility.h"
#include "wizard/MTriggerCreateWizard/mtriggercreatewizard.h"

DeviceTriggerList::DeviceTriggerList(QWidget *parent) :
    QScrollArea(parent)
{
    widget_name_ = STRING_TRIGGER;
    main_table_ = new QTableWidget;
    main_table_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    main_table_->setSelectionBehavior(QTableWidget::SelectRows);
    main_table_->setSelectionMode(QAbstractItemView::SingleSelection);
    //setStyleSheet("border : 0px;");
    setWidget(main_table_);
    setWidgetResizable(true);

    popmenu_ = new QMenu(main_table_);

    QString menu_qss = "QMenu{background-color: rgb(255,255,255);}"
                           "QMenu::item{background-color:transparent;color:#000000}"
                           "QMenu::item:selected{background-color:rgb(164,209,251);color:rgb(255,101,3)}";
    popmenu_->setStyleSheet(menu_qss);
    main_table_->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(main_table_,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onCustomContextMenuRequested(QPoint)));

    CreateMenus();
}

QString &DeviceTriggerList::widget_name()
{
    return widget_name_;
}

void DeviceTriggerList::CreateTable(int w)
{
    if(w <= 0)
    {
        return;
    }

    main_table_->setColumnCount(14);
    main_table_->setRowCount(10);

    //header's background color
    main_table_->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: rgb(184, 219, 255)}");

    QPalette pal;
    pal.setColor(QPalette::Base, QColor(233, 246, 254));
    main_table_->setPalette(pal);
    main_table_->setStyleSheet("font:12px");
//    table->setAlternatingRowColors(true);

    //setlect a row
//    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    int wunit = w/88;
    main_table_->setColumnWidth(0, wunit*2);
    main_table_->setColumnWidth(1,  wunit*9);
    main_table_->setColumnWidth(2,  wunit*9);
    main_table_->setColumnWidth(3,  wunit*4);
    main_table_->setColumnWidth(4,  wunit*5);
    main_table_->setColumnWidth(5,  wunit*8);
    main_table_->setColumnWidth(6,  wunit*8);
    main_table_->setColumnWidth(7,  wunit*8);
    main_table_->setColumnWidth(8,  wunit*9);
    main_table_->setColumnWidth(9,  wunit*4);
    main_table_->setColumnWidth(10,  wunit*4);
    main_table_->setColumnWidth(11,  wunit*3);
    main_table_->setColumnWidth(12,  wunit*9);
    main_table_->setColumnWidth(13,  wunit*5);

    //remove row number
    QHeaderView *headerView = main_table_->verticalHeader();
    headerView->setHidden(true);

    //header content
    QStringList headers;
    headers<<STRING_TRIGGER_ID<<STRING_TRIGGER_NAME<<STRING_TRIGGER_MODEL
           <<STRING_TRIGGER_CHANNEL<<STRING_TRIGGER_TYPE<<STRING_TRIGGER_NORTH<<STRING_TRIGGER_EAST
             <<STRING_TRIGGER_DOWN<<STRING_TRIGGER_SENSITIVITY<<STRING_TRIGGER_DIP<<STRING_TRIGGER_AZIMUTH
               <<STRING_TRIGGER_IS_TRIGGER<<STRING_TRIGGER_BELONG_DA<<STRING_TRIGGER_STATUS;
          //<<SITES_MAX_AMP + "\n" + tr("[m/s, m/s/s]")<<SITES_SAMP_RATE + "\n" + tr("[Hz]");
    main_table_->setHorizontalHeaderLabels(headers);
}

void DeviceTriggerList::UpdateTriggerList()
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();

    QList<int> trlist = db->TriggerList();
    main_table_->setRowCount(trlist.size());
    main_table_->setColumnCount(14);
    MTrigger* tr;
    QString strtmp;
    int i = 0;

    for(QList<int>::iterator itr = trlist.begin();itr != trlist.end();itr++,i++)
    {
        if(!db->Trigger(*itr,tr))
        {
            continue;
        }

        strtmp.sprintf("%d",tr->trigger_id());
        QTableWidgetItem *itemid = new QTableWidgetItem(strtmp);
        itemid->setTextAlignment(Qt::AlignCenter);
        itemid->setText(strtmp);
        main_table_->setItem(i, 0, itemid);

        QTableWidgetItem *itemname = new QTableWidgetItem(tr->trigger_name());
        itemname->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 1, itemname);

        QTableWidgetItem *itemmodel = new QTableWidgetItem(tr->trigger_model());
        itemmodel->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 2, itemmodel);

        byte ch;
        ch = tr->trigger_channel();
        strtmp = "";
        if((ch & 0x04) == 0x04)
        {
            strtmp += "X";
        }

        if((ch & 0x02) == 0x02)
        {
            strtmp += "Y";
        }

        if((ch & 0x01) == 0x01)
        {
            strtmp += "Z";
        }

        if((ch & 0x08) == 0x08)
        {
            strtmp += "P";
        }
        QTableWidgetItem *itemchannel = new QTableWidgetItem(strtmp);
        itemchannel->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 3, itemchannel);

        int type = tr->trigger_type();
        if(type == TRIGGER_TYPE_VELOCITY)
        {
            strtmp = STRING_VELOCITY;
        }
        else if(type == TRIGGER_TYPE_DISPLACEMENT)
        {
            strtmp = STRING_DISPLACEMENT;
        }
        else if(type == TRIGGER_TYPE_ACCELERATION)
        {
            strtmp = STRING_ACCELERATION;
        }
        else
        {
            strtmp = STRING_UNKNOWN_TYPE;
        }
        QTableWidgetItem *itemtype = new QTableWidgetItem(strtmp);
        itemtype->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 4, itemtype);


        strtmp.sprintf("%.1f",tr->trigger_point().wgs_point.latitude);
        QTableWidgetItem *itemnorth = new QTableWidgetItem(strtmp);
        itemnorth->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 5, itemnorth);
        strtmp.sprintf("%.1f",tr->trigger_point().wgs_point.longitude);
        QTableWidgetItem *itemeast = new QTableWidgetItem(strtmp);
        itemeast->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 6, itemeast);
        strtmp.sprintf("%.1f",tr->trigger_point().wgs_point.elevation);
        QTableWidgetItem *itemdown = new QTableWidgetItem(strtmp);
        itemdown->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 7, itemdown);

        strtmp.sprintf("%d",tr->trigger_sensitivity());
        QTableWidgetItem *itemsensitivity = new QTableWidgetItem(strtmp);
        itemsensitivity->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 8, itemsensitivity);

        strtmp.sprintf("%.2f",tr->azimuth());
        QTableWidgetItem *itemazimuth = new QTableWidgetItem(strtmp);
        itemazimuth->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 9, itemazimuth);

        strtmp.sprintf("%.2f",tr->dip());
        QTableWidgetItem *itemdip = new QTableWidgetItem(strtmp);
        itemdip->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 10, itemdip);

        if(tr->isusing())
        {
            strtmp = STRING_YES;
        }
        else
        {
            strtmp = STRING_NO;
        }
        QTableWidgetItem *itemisuing = new QTableWidgetItem(strtmp);
        itemisuing->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 11, itemisuing);

        int daid = tr->data_acquisition_id();
        MDataAcquisition* da;
        if(db->DataAcquisition(daid,da))
        {
            strtmp = da->name();
        }
        else
        {
            strtmp = "";
        }
        QTableWidgetItem *itemDAname = new QTableWidgetItem(strtmp);
        itemDAname->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 12, itemDAname);

        int status  = tr->status();
        if(status == 0)
        {
            strtmp = STRING_NORMAL;
        }
        else if(status == 1)
        {
            strtmp = STRING_ABNORMAL;
        }
        else
        {
            strtmp = STRING_NOT_WORK;
        }
        QTableWidgetItem *itemstatus = new QTableWidgetItem(strtmp);
        itemstatus->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 13, itemstatus);
    }

    update();
}

void DeviceTriggerList::SetTriggerHighlight(int id)
{
    int rowcount = main_table_->rowCount();

    QTableWidgetItem* tmpitem;
    for(int i = 0;i < rowcount;i++)
    {
        tmpitem = main_table_->item(i, 0);
        if(tmpitem != 0)
        {
            if(tmpitem->text().toInt() == id)
            {
                main_table_->setCurrentCell(i,0);
                break;
            }
        }

    }
}

void DeviceTriggerList::resizeEvent(QResizeEvent *e)
{
    QScrollArea::resizeEvent(e);
    int wunit = e->size().width()/88;
    main_table_->setColumnWidth(0, wunit*3);
    main_table_->setColumnWidth(1,  wunit*9);
    main_table_->setColumnWidth(2,  wunit*9);
    main_table_->setColumnWidth(3,  wunit*4);
    main_table_->setColumnWidth(4,  wunit*5);
    main_table_->setColumnWidth(5,  wunit*8);
    main_table_->setColumnWidth(6,  wunit*8);
    main_table_->setColumnWidth(7,  wunit*8);
    main_table_->setColumnWidth(8,  wunit*9);
    main_table_->setColumnWidth(9,  wunit*4);
    main_table_->setColumnWidth(10,  wunit*4);
    main_table_->setColumnWidth(11,  wunit*3);
    main_table_->setColumnWidth(12,  wunit*9);
    main_table_->setColumnWidth(13,  e->size().width() - wunit*83);
}

void DeviceTriggerList::onCustomContextMenuRequested(const QPoint &pos)
{
    if(popmenu_ != NULL)
    {
        popmenu_->exec(QCursor::pos());
    }
}

void DeviceTriggerList::onAddAction()
{
    MTriggerCreateWizard trwizard;
    trwizard.run();
}

void DeviceTriggerList::onCopyAction()
{
}

void DeviceTriggerList::onEditAction()
{
}

void DeviceTriggerList::onDeleteAction()
{
    int ret = QMessageBox::question(NULL, STRING_WRITEDB_DIALOG_TITLE,
                                    STRING_DELETE_TRIGGER, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (ret == QMessageBox::Yes)
    {
        int row = main_table_->currentRow();
        int trid = main_table_->item(row,0)->text().toInt();
        MRtsDataBase* db = MRtsDataBase::GetInstance();
        db->DeleteTrigger(trid);
        UpdateTriggerList();
    }
}

void DeviceTriggerList::CreateMenus()
{
    QString dir;
    getImageDir(dir);

    add_action_ = new QAction(tr("Add trigger"), this);
    add_action_->setIcon(QIcon(dir + "/icon/addtrigger.png"));
    add_action_->setStatusTip(tr("Add trigger"));
    connect(add_action_, SIGNAL(triggered()), this, SLOT(onAddAction()));

    copy_action_ = new QAction(tr("Copy"), this);
    copy_action_->setIcon(QIcon(dir + "/icon/copy.png"));
    copy_action_->setStatusTip(tr("copy"));
    connect(copy_action_, SIGNAL(triggered()), this, SLOT(onCopyAction()));

    edit_action_ = new QAction(tr("Edit"), this);
    edit_action_->setIcon(QIcon(dir + "/icon/edit.png"));
    edit_action_->setStatusTip(tr("edit"));
    connect(edit_action_, SIGNAL(triggered()), this, SLOT(onEditAction()));

    delete_action_ = new QAction(tr("Delete"), this);
    delete_action_->setIcon(QIcon(dir + "/icon/delete.png"));
    delete_action_->setStatusTip(tr("delete"));
    connect(delete_action_, SIGNAL(triggered()), this, SLOT(onDeleteAction()));

    popmenu_->addAction(add_action_);
    popmenu_->addAction(copy_action_);
    popmenu_->addAction(edit_action_);
    popmenu_->addAction(delete_action_);
}
