#ifndef TREENODE_H
#define TREENODE_H

#include <QMainWindow>
#include <QObject>

class treeNode : public QObject
{
    Q_OBJECT
public:
    explicit treeNode(QObject *parent = nullptr);
    treeNode(QString);

    void addToSize(treeNode*,double);
    double getSize();

    int getChildrenNumber();

    void setParent(treeNode*,treeNode*); // (parent, child)

    treeNode* addChild(QString);

    treeNode* getChild(int);

    void setsize(double size);
    QString getName();
    QString getPath();
    treeNode* getParent();
    treeNode(treeNode*);

    QString getParentPath();
signals:

private:
   QString name;
    QString path;
    int level;
    int childNumber;
    double size = 0;
    QVector < treeNode* > children;
    treeNode* parent;
    QString setName(QString);

private slots:


};

#endif // TREENODE_H
