#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node *son;
    Node *brother;
}TR;

TR *createTR(char *in,char* pre,int n){
    if(n<=0) return NULL;
    TR *newnode = new TR;
    newnode->data =pre[0];
    int i=0;
    for(i=0;in[i]!=pre[0];i++){
        newnode->brother=(in,pre+1,i);
        createTR(in+i+1,pre+i+1,n-i-1);
    }
}
//前序遍历
//递归写法
void preorder(TR *T){
    if(T){
        cout<<T->data;
        preorder(T->son);
        preorder(T->brother);
    }
}
//非递归写法
void preorder1(TR *T){
    stack<TR*> s;
    int top=0;
    s[top++]=T;
    while(top){
        p=s[top--];
        cout<<p->data;
        if(p->brother) s[top++]=p->brother;
        if(p->son) s[top++]=p->son;
    }
}

//后序遍历(相当于二叉树的中序遍历)
//递归写法

void postorder(TR*T){
    if(T){
        postorder(T->son);
        cout<<T->data;
        postorder(T->brother);
                
    }

}

//非递归写法
void postorder1(TR *T){
    stack<TR*> s;
    TR*p=T;
    int top=0;
    s[top++]=T;
    while(top||p){
        while(p){
            s[top++]=p;
            p=p->son;
        }
        p=s[top--];
        cout<<p->data;
        p=p->brother;
    }
}
//层序遍历
void levelorder(TR*T){
    queue<TR*> q;
    q.push(T);
    while(!q.empty()){
        TR*p=q.front();
        cout<<p->data;
        q.pop();
        p=p->son;
        while(p){
            q.push(p);
            p=p->brother;
        }    
    }
}

