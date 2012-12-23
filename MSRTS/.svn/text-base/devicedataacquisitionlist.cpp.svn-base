#include <QtGui>
#include "devicedataacquisitionlist.h"
#include "MacroImage.h"
#include "data/mrtsdatabase.h"
#include "mutility.h"
#include "wizard/MTriggerCreateWizard/mtriggercreatewizard.h"

DeviceDataAcquisitionList::DeviceDataAcquisitionList(QWidget *parent) :
    QScrollArea(parent)
{
    widget_name_ = STRING_DATAACQUISITION;
    main_table_ = new QTableWidget;
    main_table_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    main_table_->setSelectionBehavior(QTableWidget::SelectRows);
    main_table_->setSelectionMode(QAbstractItemView::SingleSelection);
//    setStyleSheet("border : 0px;");
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

QString &DeviceDataAcquisitionList::widget_name()
{
    return widget_name_;
}


void DeviceDataAcquisitionList::CreateTable(int w)
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
    int wunit = w/77;
    main_table_->setColumnWidth(0, wunit*2);
    main_table_->setColumnWidth(1,  wunit*9);
    main_table_->setColumnWidth(2,  wunit*9);
    main_table_->setColumnWidth(3,  wunit*4);
    main_table_->setColumnWidth(4,  wunit*5);
    main_table_->setColumnWidth(5,  wunit*9);
    main_table_->setColumnWidth(6,  wunit*7);
    main_table_->setColumnWidth(7,  wunit*9);
    main_table_->setColumnWidth(8,  wunit*5);
    main_table_->setColumnWidth(9,  wunit*3);
    main_table_->setColumnWidth(10,  wunit*3);
    main_table_->setColumnWidth(11,  wunit*7);
    main_table_->setColumnWidth(12,  wunit*2);
    main_table_->setColumnWidth(13,  wunit*3);
//    main_table_->setColumnWidth(0, fm.width(STRING_DATAACQUISITION_ID) + 4);
//    main_table_->setColumnWidth(1,  fm.width(STRING_DATAACQUISITION_NAME) + 4);
//    main_table_->setColumnWidth(2,  fm.width(STRING_DATAACQUISITION_MODEL) + 4);
//    main_table_->setColumnWidth(3,  fm.width(STRING_DATAACQUISITION_CHANNEL_COUNT) + 4);
//    main_table_->setColumnWidth(4,  fm.width(STRING_DATAACQUISITION_SAMPLERATE) + 4);
//    main_table_->setColumnWidth(5,  fm.width(STRING_TIME2) + 4);
//    main_table_->setColumnWidth(6,  fm.width(STRING_IP) + 4);
//    main_table_->setColumnWidth(7,  fm.width(STRING_DATAACQUISITION_TRIGGER) + 4);
//    main_table_->setColumnWidth(8,  fm.width(STRING_DATAACQUISITION_TRIGGER_MODE) + 4);
//    main_table_->setColumnWidth(9,  fm.width(STRING_DATAACQUISITION_DELAY_POINTS) + 4);
//    main_table_->setColumnWidth(10,  fm.width(STRING_DATAACQUISITION_TRANSFER_POINTS) + 4);
//    main_table_->setColumnWidth(11,  fm.width(STRING_DATAACQUISITION_SAMPLE_LENGTH) + 4);
//    main_table_->setColumnWidth(12,  fm.width(STRING_DATAACQUISITION_START_CHANNEL_ID) + 4);
//    main_table_->setColumnWidth(13,  fm.width(STRING_TRIGGER_STATUS) + 4);

    //remove row number
    QHeaderView *headerView = main_table_->verticalHeader();
    headerView->setHidden(true);

    //header content
    QStringList headers;
    headers<<STRING_DATAACQUISITION_ID<<STRING_DATAACQUISITION_NAME<<STRING_DATAACQUISITION_MODEL
           <<STRING_DATAACQUISITION_CHANNEL_COUNT<<STRING_DATAACQUISITION_SAMPLERATE<<STRING_TIME2
             <<STRING_IP<<STRING_DATAACQUISITION_TRIGGER<<STRING_DATAACQUISITION_TRIGGER_MODE<<STRING_DATAACQUISITION_DELAY_POINTS
               <<STRING_DATAACQUISITION_TRANSFER_POINTS<<STRING_DATAACQUISITION_SAMPLE_LENGTH<<STRING_DATAACQUISITION_START_CHANNEL_ID
                 <<STRING_TRIGGER_STATUS;
//    QFontMetrics fm;
//    fm.width(STRING_DATAACQUISITION_ID);
    main_table_->setHorizontalHeaderLabels(headers);
}

void DeviceDataAcquisitionList::UpdateDataAcquisitionList()
{
    MRtsDataBase* db = MRtsDataBase::GetInstance();

    QList<int> dalist = db->DataAcquisitionList();
    main_table_->setRowCount(dalist.size());
    main_table_->setColumnCount(14);
    MDataAcquisition* da;
    QString strtmp;
    int i = 0;

    for(QList<int>::iterator itr = dalist.begin();itr != dalist.end();itr++,i++)
    {
        if(!db->DataAcquisition(*itr,da))
        {
            continue;
        }

        strtmp.sprintf("%d",da->id());
        QTableWidgetItem *itemid = new QTableWidgetItem(strtmp);
        itemid->setTextAlignment(Qt::AlignCenter);
        itemid->setText(strtmp);
        main_table_->setItem(i, 0, itemid);

        QTableWidgetItem *itemname = new QTableWidgetItem(da->name());
        itemname->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 1, itemname);

        QTableWidgetItem *itemmodel = new QTableWidgetItem(da->model());
        itemmodel->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 2, itemmodel);

        if(da->channel_count() != UN_INITID_INT)
        {
            strtmp.sprintf("%d",da->channel_count());
            QTableWidgetItem *itemchannelcount = new QTableWidgetItem(strtmp);
            itemchannelcount->setTextAlignment(Qt::AlignCenter);
            itemchannelcount->setText(strtmp);
            main_table_->setItem(i, 3, itemchannelcount);
        }

        if(da->sample_rate() != UN_INITID_INT)
        {
            strtmp.sprintf("%d",da->sample_rate());
            QTableWidgetItem *itemsamplerate = new QTableWidgetItem(strtmp);
            itemsamplerate->setTextAlignment(Qt::AlignCenter);
            itemsamplerate->setText(strtmp);
            main_table_->setItem(i, 4, itemsamplerate);
        }

        QTableWidgetItem *itemip = new QTableWidgetItem(da->ip());
        itemip->setTextAlignment(Qt::AlignCenter);
        main_table_->setItem(i, 6, itemip);

        QList<int> trlist;
        trlist = da->triggerid_list();
        QString trid;
        strtmp = "";
        for(QList<int>::iterator tritr = trlist.begin();tritr != trlist.end();tritr++)
        {
            trid.sprintf("%d",*tritr);
            strtmp += trid;
            if((tritr+1) == trlist.end())
            {
                break;
            }
            strtmp += ",";
        }
        QTableWidgetItem *itemtrlist = new QTableWidgetItem(strtmp);
        itemtrlist->setTextAlignment(Qt::AlignCenter);
        itemtrlist->setText(strtmp);
        main_table_->setItem(i, 7, itemtrlist);

        if(da->trigger_mode() == 0)
        {
            strtmp = STRING_DATAACQUISITION_FREE_TRIGGER;
        }
        else
        {
            strtmp = STRING_DATAACQUISITION_FREE_TRIGGER;
        }
        QTableWidgetItem *itemtriggermode = new QTableWidgetItem(strtmp);
        itemtriggermode->setTextAlignment(Qt::AlignCenter);
        itemtriggermode->setText(strtmp);
        main_table_->setItem(i, 8, itemtriggermode);

        if(da->trigger_delay_point() != UN_INITID_INT)
        {
            strtmp.sprintf("%d",da->trigger_delay_point());
            QTableWidgetItem *itemdelaypoint = new QTableWidgetItem(strtmp);
            itemdelaypoint->setTextAlignment(Qt::AlignCenter);
            itemdelaypoint->setText(strtmp);
            main_table_->setItem(i, 9, itemdelaypoint);
        }

        if(da->every_transfer_point() != UN_INITID_INT)
        {
            strtmp.sprintf("%d",da->every_transfer_point());
            QTableWidgetItem *itemeverytransferpoint = new QTableWidgetItem(strtmp);
            itemeverytransferpoint->setTextAlignment(Qt::AlignCenter);
            itemeverytransferpoint->setText(strtmp);
            main_table_->setItem(i, 10, itemeverytransferpoint);
        }

        if(da->every_transfer_point() != UN_INITID_INT)
        {
            strtmp.sprintf("%d/1024",da->sample_length());
            QTableWidgetItem *itemsamplelength = new QTableWidgetItem(strtmp);
            itemsamplelength->setTextAlignment(Qt::AlignCenter);
            itemsamplelength->setText(strtmp);
            main_table_->setItem(i, 11, itemsamplelength);
        }

        if(da->every_transfer_point() != UN_INITID_INT)
        {
            strtmp.sprintf("%d",da->start_channel_id());
            QTableWidgetItem *itemstartchannelid = new QTableWidgetItem(strtmp);
            itemstartchannelid->setTextAlignment(Qt::AlignCenter);
            itemstartchannelid->setText(strtmp);
            main_table_->setItem(i, 12, itemstartchannelid);
        }

        int status  = da->status();
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
}

void DeviceDataAcquisitionList::SetDAHighlight(int id)
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

void DeviceDataAcquisitionList::resizeEvent(QResizeEvent *e)
{
    QScrollArea::resizeEvent(e);

    int wunit = e->size().width()/77;
    main_table_->setColumnWidth(0, wunit*2);
    main_table_->setColumnWidth(1,  wunit*8);
    main_table_->setColumnWidth(2,  wunit*6);
    main_table_->setColumnWidth(3,  wunit*4);
    main_table_->setColumnWidth(4,  wunit*4);
    main_table_->setColumnWidth(5,  wunit*8);
    main_table_->setColumnWidth(6,  wunit*6);
    main_table_->setColumnWidth(7,  wunit*6);
    main_table_->setColumnWidth(8,  wunit*5);
    main_table_->setColumnWidth(9,  wunit*7);
    main_table_->setColumnWidth(10,  wunit*7);
    main_table_->setColumnWidth(11,  wunit*5);
    main_table_->setColumnWidth(12,  wunit*6);
    main_table_->setColumnWidth(13,  e->size().width() - wunit*74);
}

void DeviceDataAcquisitionList::onCustomContextMenuRequested(const QPoint &pos)
{
    if(popmenu_ != NULL)
    {
        popmenu_->exec(QCursor::pos());
    }
}

void DeviceDataAcquisitionList::onAddAction()
{
    MTriggerCreateWizard trwizard;
    trwizard.run();
}

void DeviceDataAcquisitionList::onCopyAction()
{
}

void DeviceDataAcquisitionList::onEditAction()
{
}

void DeviceDataAcquisitionList::onDeleteAction()
{
    int ret = QMessageBox::question(NULL, STRING_WRITEDB_DIALOG_TITLE,
                                    STRING_DELETE_DATAACQUISITION, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (ret == QMessageBox::Yes)
    {
        int row = main_table_->currentRow();
        int daid = main_table_->item(row,0)->text().toInt();
        MRtsDataBase* db = MRtsDataBase::GetInstance();
        db->DeleteDataAcquisition(daid);
        UpdateDataAcquisitionList();
    }
}

void DeviceDataAcquisitionList::CreateMenus()
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
