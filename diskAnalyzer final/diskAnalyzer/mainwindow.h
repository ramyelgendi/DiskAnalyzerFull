#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QMainWindow>
#include <QTreeWidget>

#include "treenode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initializeTreeNodes(treeNode *root, double fullSpace, double freeSpace);

private slots:
    void on_actionScan_triggered();

    void on_actionStop_triggered();

    void on_actionRefresh_triggered();

private:
    Ui::MainWindow *ui;
    QPieSeries * series;
    QChart * chart;
    QChartView *chartview;
    QTreeWidget * wholeTree;
    double mainRootSize;
    double fullDiskSpace;
    double freeDiskSpace;
    double usedDiskSpace;
    void addTreeRoot(QString folderName, double usage , double size, int contents, QString path);
    void addTreeChild(QTreeWidgetItem *parent, QString folderName, double usage , double size, int contents, QString path);
    void drawChart();
    void levelordertraversal(treeNode* root);
};
#endif // MAINWINDOW_H
