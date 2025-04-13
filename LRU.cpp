#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k,int v):key(k),value(v),next(NULL),prev(NULL){}
    };
    unordered_map<int,Node*> map;//用map对每个节点进行映射，使得可以快速访问到每个节点
    Node *head;
    Node *tail;
    int capacity;
    
    LRUCache(int cap) {
        capacity=cap;
        head=new Node(0,0);//c++用new分配堆空间
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    void remove(Node *node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insert(Node *node){
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
    }
    int get(int key) {
        if(map.find(key)!=map.end()){
            Node *node=map[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            Node *node=map[key];
            remove(node);
            node->value=value;
            insert(node);
        }else{
            if(map.size()==capacity){
                Node *node=tail->prev;
                remove(node);
                map.erase(node->key);
                delete node;
            }
            Node *node=new Node(key,value);
            insert(node);
            map[key]=node;
        }
    }
};
int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1)<<endl; // 返回 1
    cache.put(3,3); // 该操作会使得关键字 2 作废
    cout<<cache.get(2)<<endl; // 返回 -1 (未找到)
    cache.put(4,4); // 该操作会使得关键字 1 作废
    cout<<cache.get(1)<<endl; // 返回 -1 (未找到)
    cout<<cache.get(3)<<endl; // 返回 3
    cout<<cache.get(4)<<endl; // 返回 4
    return 0;
}