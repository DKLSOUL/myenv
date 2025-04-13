#include<bits/stdc++.h>
using namespace std;

class quene{
    public:
        int *arr;
        int front;
        int rear;
        int size;
        int capacity;
        quene(int cap){
            arr=new int[cap];
            front=0;
            rear=0;
            size=0;
            capacity=cap;
        }
        ~quene(){
            delete[] arr;
        }
        void push(int x){
            if(size==capacity){
                cout<<"quene is full"<<endl;
                return;
            }else{
                arr[rear]=x;
                rear=(rear+1)%capacity;
                size++;
            }
        }
        int pop(){
            if(size==0){
                cout<<"quene is empty"<<endl;
                return -1;
            }else{
                int result=arr[front];
                front=(front+1)%capacity;
                size--;
                return result;
            }
        }
        int getfront(){
            if(size==0){
                cout<<"quene is empty"<<endl;
                return -1;
            }else{
                return arr[front];
            }
        }
        bool empty(){
            return size==0;
        }
        int getSize(){
            return size;
        }
        int second(){
            if(size<2){
                cout<<"quene do not have the second element"<<endl;
                return -1;

            }else{
                return arr[(front+1)%capacity];
            }
        }

};
int main(){
    quene q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.getfront()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.second()<<endl;
    return 0;
}