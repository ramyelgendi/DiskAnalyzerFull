#include "treenode.h"

treeNode::treeNode(QObject *parent) : QObject(parent)
{

}

treeNode::treeNode(QString path)
{
    this->path = path;
    children.resize(1500);
    childNumber=0;
    name = setName(path);
}

void treeNode::addToSize(treeNode * node, double sizex)
{
    node->size += sizex;
}

double treeNode::getSize()
{
    return this -> size;
}

int treeNode::getChildrenNumber()
{
    return this -> childNumber;
}

treeNode *treeNode::addChild(QString pathx)
{
    int s = static_cast<int>(this->children.size());
    if (s == childNumber)
        parent->children.resize(2*s);
    this->children[childNumber] = new treeNode(pathx);
    children[childNumber]->parent = this;
    (this->childNumber)++;
    return this;
}

treeNode *treeNode::getChild(int childNum)
{
    return this->children[childNum-1];
}

void treeNode::setsize(double size)
{
    this->size=size;
}

QString treeNode::getName()
{
    return this->name;
}

QString treeNode::getPath()
{
    return this->path;
}

treeNode *treeNode::getParent()
{
    return this->parent;
}

QString treeNode::setName(QString x)
{
  QString y = "";
        int i=x.length()-1;
        while (x[i] != '/')
        {
            y = x[i] + y;
            i--;
        }
        return y;
}

treeNode::treeNode(treeNode* tn)    // instead of the equal operator

{

    this->path = tn->path;

    this->children.resize(tn->children.size());

    this->name = tn->name;

    this->childNumber=0;

    for (int i=0; i<tn->childNumber; i++)

        this->children[i] = new treeNode(tn->children[i]);

    this->childNumber=tn->childNumber;

    this->parent = tn->parent;

    this->size = tn->getSize();

}

QString treeNode::getParentPath()
{
    return this->parent->getPath();
}
