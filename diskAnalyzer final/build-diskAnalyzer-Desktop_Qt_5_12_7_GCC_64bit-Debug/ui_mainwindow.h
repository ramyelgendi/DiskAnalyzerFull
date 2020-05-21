/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRefresh;
    QAction *actionScan;
    QAction *actionStop;
    QAction *actionEnter_Full_Screen;
    QAction *actionExit_Full_Screen;
    QAction *action;
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QTreeWidget *treeWidget;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuSettings;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1320, 640);
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/pngfuel.com.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon);
        actionScan = new QAction(MainWindow);
        actionScan->setObjectName(QString::fromUtf8("actionScan"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/pngfuel.com (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScan->setIcon(icon1);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/pngfuel.com (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon2);
        actionEnter_Full_Screen = new QAction(MainWindow);
        actionEnter_Full_Screen->setObjectName(QString::fromUtf8("actionEnter_Full_Screen"));
        actionExit_Full_Screen = new QAction(MainWindow);
        actionExit_Full_Screen->setObjectName(QString::fromUtf8("actionExit_Full_Screen"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(19, 19, 581, 491));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 579, 489));
        treeWidget = new QTreeWidget(scrollAreaWidgetContents_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(-5, 1, 591, 491));
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setAllColumnsShowFocus(true);
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        horizontalFrame = new QFrame(centralwidget);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(609, 29, 681, 491));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1320, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionRefresh);
        menuFile->addAction(actionScan);
        menuFile->addAction(actionStop);
        menuView->addAction(action);
        toolBar->addAction(actionScan);
        toolBar->addAction(actionRefresh);
        toolBar->addAction(actionStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        actionScan->setText(QApplication::translate("MainWindow", "Scan", nullptr));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        actionEnter_Full_Screen->setText(QApplication::translate("MainWindow", "Enter Full Screen", nullptr));
        actionExit_Full_Screen->setText(QApplication::translate("MainWindow", "Exit Full Screen", nullptr));
        action->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Contents", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Size", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Usage", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Folder", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "/", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "usr", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "mohamed", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "salma", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "home", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "sys", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        menuFile->setTitle(QApplication::translate("MainWindow", "Action", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
