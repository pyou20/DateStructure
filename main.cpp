//
// Created by HP on 2022/5/8.
//
#include <iostream>
using namespace std;

typedef struct LinkNode{
    int Date;
    struct LinkNode *next;
} LinkNode;

void Create_List_Front(LinkNode *&L,int const date[],int n){        //ͷ�巨��������
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof (LinkNode));
    L->next=NULL;
    for(int i=0;i<n;i++){
        s=(LinkNode*) malloc(sizeof (LinkNode));
        s->Date=date[i];
        s->next=L->next;
        L->next=s;
    }
}

void Create_List_Rear(LinkNode *&L,int const date[],int n){   //β�巨��������
    LinkNode *s,*r;
    L=(LinkNode *) malloc(sizeof (LinkNode));
    r=L;
    for(int i=0;i<n;i++){
        s=(LinkNode *) malloc(sizeof (LinkNode));
        s->Date=date[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

//��ʼ�����Ա�
void InitList(LinkNode *&L){
    L=(LinkNode *) malloc(sizeof (LinkNode));
    L->next=NULL;
}

//�������Ա�
void DestroyList(LinkNode *&L){
    LinkNode *p=L->next;
    LinkNode *pre = L;
    while(p!=NULL){
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

//�ж����Ա��Ƿ�Ϊ�ձ�
bool ListEmpty(LinkNode *L){
    return(L->next==NULL);
}

/*�����Ա�ĳ���*/
int ListLength(LinkNode *L){
    int len=0;
    LinkNode *p=L;
    while(p->next!=NULL){
        len++;
        p=p->next;
    }
    return len;
}


void Display(LinkNode *L){
    LinkNode *p;
    p=L->next;
    while(p!=NULL){
        cout<<p->Date<<" ";
        p=p->next;
    }
    cout<<endl;
}

/*�����Ա���ĳ��Ԫ�ص�ֵ*/
bool GetElemLinkNode(LinkNode *L,int index,int &value){
    if(index<0)
        return false;
    LinkNode *p=L;
    int j=0;
    while(p!=NULL&&j<index){
        j++;
        p=p->next;
    }
    if(p->next==NULL)
        return false;
    else{
        value=p->Date;
        return true;
    }
}

/*��Ԫ�ز���*/
bool LocateElem(LinkNode *L,int value,int &Location){
    int index=0;
    LinkNode *p=L;
    while(p!=NULL&&p->Date!=value){
        p=p->next;
        index++;
    }
    if(p!=NULL){
        Location=index;
        return true;
    }
    else
        Location=0;
    return false;
}

/*����ڵ�*/
bool ListInsert(LinkNode *&L, int index, int value){
    int j=0;
    LinkNode *p=L,*s;
    if(index <= 0)
        return false;
    while(j < index - 1 && p != NULL){
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    else{
        s=(LinkNode*) malloc(sizeof (LinkNode));
        s->Date=value;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

/*ɾ���ڵ�*/
bool ListDelete(LinkNode *&L,int index){
    if(index<1)
        return false;
    LinkNode *p=L,*q=NULL;
    int j=0;
    bool flag= false;
    while(p!=NULL&&j<index-1){
        j++;
        p=p->next;
    }
    if(p!=NULL){
        q=p->next;
        if(q!=NULL){p->next=q->next;
            free(q);
            flag=true;
        }
    }
    return flag;
}

int main() {
    int date[5]={1,2,3,4,5};
    int value=0;
    LinkNode *LinkNode1,*LinkNode2=NULL;

    cout<<"ͷ�巨��������"<<endl;
    Create_List_Front(LinkNode1,date,5);
    Display(LinkNode1);

    cout<<"β�巨��������"<<endl;
    Create_List_Rear(LinkNode2,date,5);
    Display(LinkNode2);

    cout<<"��λ�ò���Ԫ��ֵ(2)"<<endl;
    cout<<"LinkNode1�еĶ���Ԫ��Ϊ��"<<endl;
    GetElemLinkNode(LinkNode1,2,value);
    cout<<value<<endl;
    cout<<"LinkNode2�еĶ���Ԫ��Ϊ��"<<endl;
    GetElemLinkNode(LinkNode2,2,value);
    cout<<value<<endl;

    cout<<"��ֵ����(3)"<<endl;
    LocateElem(LinkNode1,3,value);
    cout<<value<<endl;

    cout<<"����ڵ�(3������4)"<<endl;
    ListInsert(LinkNode1,3,4);
    Display(LinkNode1);

    cout<<"ɾ���ո���ӵĽڵ�"<<endl;
    ListDelete(LinkNode1,3);
    Display(LinkNode1);
    return 0;
}
