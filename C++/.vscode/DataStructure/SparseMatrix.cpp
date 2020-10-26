#include "SparseMatrix.h"

/*----------------------------------------------------------
稀疏矩阵的十字链表的实现
----------------------------------------------------------*/

//Element的实现
istream& operator>>(istream& in,Element& ele)
{
    in>>ele.r>>ele.c>>ele.value;
    return in;
}
Element::Element()
{
    this->r=0;
    this->c=0;
    this->value=0;
}
Element::Element(int r,int c,int value)
{
    this->r=r;
    this->c=c;
    this->value=value;
}
Element& Element::operator=(const Element& ele)
{
    this->r=ele.r;
    this->c=ele.c;
    this->value=ele.value;
}

//Node的实现
Node::Node():ele()
{
    this->is_head=false;
    this->col_next=NULL;
    this->row_next=NULL;
}
Node::Node(int t)
{
    this->is_head=true;
    this->col_next=NULL;
    this->row_next=NULL;
    this->next_head=NULL;
}
Node::Node(Element ele)
{
    this->is_head=false;
    this->col_next=NULL;
    this->row_next=NULL;
    this->ele=ele;
}

//SparseMatrix的实现
//私有
NodePointer HeadMaster::find_head(int x)
{
    NodePointer p=this->head;
    for(int i=1;i<x;i++)
    {
        p=p->next_head;
    }
    return p;
}
Status HeadMaster::Insert_in_r(NodePointer cur_head,const Element& ele)
{
    NodePointer p=cur_head;
    NodePointer s=new Node(ele);    //要插入的节点
    if(s==NULL)exit(LOVERFLOW);
    while(p->row_next!=cur_head)
    {
        if(ele.c<=p->row_next->ele.c)   //ele小说明该插入了
        {
            s->row_next=p->row_next;
            p->row_next=s;
            //插入结束可以退出了
            return OK;
        }
        p=p->row_next;
    }
    //到这里说明到了最后一个节点了(即这个节点的c大于所以链表中的节点的c)
    s->row_next=p->row_next;
    p->row_next=s;

    return OK;
}
Status HeadMaster::Insert_in_c(NodePointer cur_head,const Element& ele)
{
    NodePointer p=cur_head;
    NodePointer s=new Node(ele);    //要插入的节点
    while(p->col_next!=cur_head)
    {
        if(ele.r<=p->col_next->ele.r)   //ele小说明该插入了
        {
            s->col_next=p->col_next;
            p->col_next=s;
            //插入结束可以退出了
            return OK;
        }
        p=p->col_next;
    }
    //到这里说明到了最后一个节点了(即这个节点的c大于所以链表中的节点的c)
    s->col_next=p->col_next;
    p->col_next=s;
    return OK;
}
//共有
HeadMaster::HeadMaster(int r,int c)
{
    this->r=r;
    this->c=c;
    this->exist_num=0;
    //对头结点的构造
    NodePointer p,q;
    for(int i=1;i<=max(r,c);i++)
    {
        p=new Node(1);  //申请的是头结点所以加1
        if(p==NULL)exit(LOVERFLOW);

        p->col_next=p;  //循环链表要求的 尾结点指向头结点
        p->row_next=p;  //循环链表要求的 尾结点指向头结点
        if(1==i)//第一次进入
        {
            this->head=p;
        }
        else
        {
            q->next_head=p;
        }
        q=p;
    }
}
HeadMaster::~HeadMaster()
{
    NodePointer qh,ph=this->head;
    for(int i=1;i<=max(this->r,this->c);i++)    //循环每一个头结点
    {
        NodePointer q,p;
        for(p=ph->row_next;p!=ph;)    //对行的链表进行删除
        {
            q=p;
            p=p->row_next;
            delete q;
        }
        for(p=ph->col_next;p!=ph;)    //对列的链表进行删除
        {
            q=p;
            p=p->col_next;
            delete q;
        }
        //结束要对头结点进行操作
        qh=ph;
        ph=ph->next_head;
        delete qh;
    }
}
Status HeadMaster::Insert(Element ele)
{
    NodePointer hr=this->find_head(ele.r),hc=this->find_head(ele.c);
    if(this->Insert_in_r(hr,ele)==OK&&this->Insert_in_c(hc,ele)==OK)
    {
        this->exist_num++;
        return OK;
    }
    else {return ERROR;}

}
Status HeadMaster::Insert(int rt,int ct,int valuet)
{
    Element ele(rt,ct,valuet);
    this->Insert(ele);
    this->exist_num++;
    return OK;
}
void HeadMaster::ShowMatrix()
{
    NodePointer ph=this->head;
    cout<<"  ";
    for(int i=1;i<=r;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    NodePointer p,q=ph;     //q用来暂存头结点
    for(int i=1;i<=r;i++)
    {
        p=q->row_next;  //q指向的第一个结点
        cout<<i<<" ";
        for(int j=1;j<=c;j++)
        {
            if(j==p->ele.c)
            {
                cout<<p->ele.value<<" ";
                p=p->row_next;
            }
            else
            {
                cout<<"* ";
            }
        }
        cout<<endl;
        q=q->next_head;
    }
}
/*
10 10 
1 1 3
5  5 9
2 3 1
5 9 6
*/
int main()
{
    int r,c,value;
    cin>>r>>c;
    SparseMatrix sm(r,c);
    while(scanf("%d %d %d",&r,&c,&value)==3&&r!=-1)
    {
        sm.Insert(r,c,value);
    }
    sm.ShowMatrix();
}

