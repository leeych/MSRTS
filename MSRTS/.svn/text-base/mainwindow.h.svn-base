#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QVBoxLayout>
#include "ui/msplitter.h"
#include "ui/mtreewidget.h"
#include "ui/mtabwidget.h"
#include "systemstatusframe.h"
#include "rtwavewindow.h"  //runtime wave window
#include "devicemanagepage.h"
#include "topologypage.h"
#include "ui/mscrollarea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void UpdateDataToTree();
signals:
    
public slots:
    void onAddTriggerAction();
    void onAddDataAcqisitionAction();
    void unused();
    void OnToolButtonDeviceManagerClicked();
    void OnToolButtonTopologyClicked();

    void OnTopologyTriggerClicked(int id);
    void OnTopologyDAClicked(int id);
private:
    void CreateFileAction();
    void CreateDeviceManagerAction();
    void CreateWindowAction();
    void CreateHelpAction();
    void CreateToolBarButton();

    void CreateActions();
    void CreateMenus();
    void CreateToolbar();

private:
    /*append menu here*/
    QMenu* file_menu_;
    QMenu* device_manager_menu_;
    QMenu* window_menu_;
    QMenu* help_menu_;

    QToolBar* main_toolbar_;

    QToolButton* save_button_;
    QToolButton* start_sample_button_;
    QToolButton* add_data_capture_button_;
    QToolButton* add_trigger_button_;
    QToolButton* topology_button_;
    QToolButton* trigger_setting_button_;
    QToolButton* auto_setting_button_;
    QToolButton* device_manager_button_;

    /*append action here*/
    /*file*/
    QAction* save_action_;
    QAction* close_action_;

    /*device */
    QAction* addtrigger_action_;
    QAction* triggerlist_action_;
    QAction* adddatacapture_action_;
    QAction* datacapturelist_action_;

    /*window*/
    QAction* startsample_action_;
    QAction* topology_action_;
    QAction* trigger_setting_action_;
    QAction* location_method_action_;
    QAction* focalmechanism_action_;

    /*help*/
    QAction* about_action_;

    MSplitter* main_splitter_;
    QSplitter* left_splitter_;
    SystemStatusFrame *infodisplayframe_;
    MTabWidget* main_tab_window_;
    RTWaveWindow* runtime_wave_window_;
    DeviceManagePage* device_manager_page_;
    TopologyPage* topology_page_;
    MScrollArea* topology_scrollarea_;
};

#endif // MAINWINDOW_H
