#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QQueue>

QTreeWidgetItem * currRoot;
QTreeWidgetItem * originalRoot;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawChart() {

    series = new QPieSeries();

    for (int i = 0; i < currRoot->childCount(); i++) {
        QTreeWidgetItem * currChild = currRoot->child(i);
        series->append(currChild->text(0), currChild->text(2).toDouble());
    }

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Current Root Directory: '" + currRoot->text(0) + "'");

    chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
    chartview->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
}

void MainWindow::initializeTreeNodes(treeNode *root, double fullSpace, double freeSpace)
{
    // initialize disk space info
    fullDiskSpace = fullSpace;
    freeDiskSpace = freeSpace;
    usedDiskSpace = fullDiskSpace - freeDiskSpace;
    ui->diskDisplay->setText("Full Disk Space: " + QString::number(fullSpace/1000/1000/1000) + "GB Free Space: " + QString::number(freeSpace/1000/1000/1000) + "GB");
    levelordertraversal(root);
    drawChart();

}

void MainWindow::levelordertraversal(treeNode* root){

    bool isMainRoot = true;
    QTreeWidgetItem * currParentWI;
    treeNode * currParent;
    wholeTree = ui->treeWidget;
    QString currParentPath;

    if (root==nullptr)
        return;

    QQueue <treeNode*> q;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        int n = q.size();
        while(n>0)
        {
            treeNode* t = new treeNode(q.head());
            q.dequeue();

            if (isMainRoot) { // for main root
                addTreeRoot(root->getName(), (root->getSize()/usedDiskSpace)*100, root->getSize()/1000/1000, root->getChildrenNumber(), root->getPath());
                mainRootSize = root->getSize();
                currParent = root;
                currParentWI = currRoot;
                currParentPath = currParentWI->text(4);
                isMainRoot = false;
            } else {
                if (t->getParent()->getPath() != currParentPath)
                {
                    QString s = t->getParentPath();

                    QList<QTreeWidgetItem*> clist = wholeTree->findItems(s  , Qt::MatchExactly|Qt::MatchRecursive, 4);
                    addTreeChild(clist[0], t->getName(), (t->getSize()/usedDiskSpace)*100, t->getSize()/1000/1000, t->getChildrenNumber(), t->getPath());
                    currParentPath = clist[0]->text(4);
                    currParentWI = clist[0];
                }  else {
                    addTreeChild(currParentWI, t->getName(), (t->getSize()/usedDiskSpace)*100, t->getSize()/1000/1000, t->getChildrenNumber(), t->getPath());
                }
            }

            for (int i =0; i<t->getChildrenNumber(); i++)
                q.enqueue(t->getChild(i+1));
            n--;
        }

    }

}

void MainWindow::addTreeRoot(QString folderName, double usage , double size, int contents, QString path)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(wholeTree);
    originalRoot  = treeItem;

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, folderName);
    treeItem->setText(1, QString::number(usage));
    treeItem->setText(2, QString::number(size));
    treeItem->setText(3, QString::number(contents));
    treeItem->setText(4, path);

    currRoot  = treeItem;
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent, QString folderName, double usage , double size, int contents, QString path)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, folderName);
    treeItem->setText(1, QString::number(usage));
    treeItem->setText(2, QString::number(size));
    treeItem->setText(3, QString::number(contents));
    treeItem->setText(4, path);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    if (parent != nullptr) {
        parent->addChild(treeItem);
    }
}

void MainWindow::on_actionScan_triggered()
{
    currRoot = ui->treeWidget->currentItem();
    if (currRoot != nullptr && (currRoot->childCount() > 0)) {
        series->clear();
        for (int i = 0; i < currRoot->childCount(); i++) {
            QTreeWidgetItem * currChild = currRoot->child(i);
            series->append(currChild->text(0), currChild->text(2).toDouble());
        }
        chart->setTitle("Current Root Directory: '" + currRoot->text(0) + "'");
    }
    if (currRoot->childCount() == 0) {
        series->clear();
        series->append("This file/ directory has no children to be displayed.", 0);
    }
}

void MainWindow::on_actionStop_triggered()
{
    series->clear();
    chart->setTitle("");
}

void MainWindow::on_actionRefresh_triggered()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
}

