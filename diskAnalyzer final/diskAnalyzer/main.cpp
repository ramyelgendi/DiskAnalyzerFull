#include "mainwindow.h"
#include "treenode.h"
#include <QApplication>
#include <QDir>
#include <QStorageInfo>
#include <QFileInfo>

using namespace std;

QStorageInfo storage= QStorageInfo::root();

// global variables
QString path = "/Users/Salma/Desktop/uni/Semester 6";
int counter = 0;
double ssize=0;
double ssize2 = 0;
double fullSpace;
double freeSpace;
int originalLevelNumber;

double getfullspace() {
  return storage.bytesTotal();
}


double getfreespace() {
    return storage.bytesAvailable();
}

void traverse(treeNode * node)
{
    QDir dir(node->getPath());
    dir.setFilter(QDir::Files| QDir::NoSymLinks| QDir::NoDot| QDir::Dirs| QDir::NoDotDot| QDir::NoDotAndDotDot);
//    |QDir::Hidden
    QFileInfoList list =dir.entryInfoList();
   for(int i=0; i<list.size();i++)
   {
       QFileInfo fileinfo = list.at(i);

       node->addChild(fileinfo.filePath());

       if(fileinfo.isFile()){
           node->getChild(node->getChildrenNumber())->setsize(fileinfo.size());
       }

         if(list[i].isDir())
        {
             int k= node->getChildrenNumber();
             traverse(node->getChild(k));
             }
         }
}


QFileInfo fileInfo;

void postorder (treeNode * p) {
    if (p == nullptr) return;
    for(int i =0 ; i<p->getChildrenNumber();i++){
        postorder (p->getChild(i+1));
    }
    // visit
    fileInfo = p->getPath();
    double currSize = 0;
    if (!fileInfo.isFile()) {
        for(int i = 0; i < p->getChildrenNumber(); i ++) {
            currSize += p->getChild(i+1)->getSize();
        }
        p->setsize(currSize);
        currSize = 0;
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    treeNode *root= new treeNode(path);
    traverse(root);

    postorder(root);

    fullSpace = getfullspace();
    freeSpace = getfreespace();

    MainWindow w;
    w.initializeTreeNodes(root, fullSpace, freeSpace);
    w.show();

    return a.exec();
}

