#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>
#include<QSystemTrayIcon>
#include"readthread.h"
#include<QAction>
#include<QTimer>
//前向声明出来菜单
class QMenu;


class TrayIcon : public QObject
{
    Q_OBJECT
public:
    explicit TrayIcon(QObject *parent = nullptr);


    //声明托盘类的单例
    static TrayIcon* getInstance();

private:
    //维持托盘类的智能指针
    static QScopedPointer<TrayIcon> self;
    //维持所属的主窗体
    QWidget* mainWidget;
    //维持托盘对象
    QSystemTrayIcon* trayIcon;
    //维持托盘菜单
    QMenu* menu;

    //维持菜单
    QAction *actionScreenCap;
    QAction *actionStartRecord;
    QAction *actionStopRecord;
    QAction *actionGIFMake;
    QAction *actionCodeCount;
    QAction *actionDefaultPosition;
    QAction *actionShowMain;
    QAction *actionExit;

    QTimer m_timer;
public:
    //对外暴露的接口
    //所属的主窗体
    void setMainWidget(QWidget* mainWidget);
    //获取可见和不可见
    bool getVisible() const;
    void setVisible(bool visible);
    //设置鼠标放上去的提示信息
    void setToolTip(const QString& tip);
    //设置最小化托盘后的系统提示信息
    void showMessage(const QString& title,
                     const QString& msg,
                     QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information,
                     int msec = 5000);

public Q_SLOTS:
    //公共的槽函数

    //退出
    void closeAll();
    //回显主窗体
    void showMainWidget();
    //GIF制作
    void TrayGIFMake();
    //代码统计
    void TrayCodeCount();
//    托盘截屏
    void TrayScreenCap();
    //托盘录制
//    void TrayVideoCap();

//    void on_playState(ReadThread::PlayState state);

//    bool setSavePath();


signals:

};

#endif // TRAYICON_H
