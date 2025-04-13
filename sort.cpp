#include<bits/stdc++.h>
using namespace std;
//堆排序
void shiftdown(vector<int> num,int n,int i){
    int l=2*i+1;
    int r=i*2+2;
    int max=i;
    if(l<n&&num[l]>num[max]){
        max=l;
    }
    if(r<n&&num[r]>num[max]){
        max=r;
    }
    if(max!=i){
        swap(num[i],num[max]);
        shiftdown(num,n,max);
    }
}
void heapsort(vector<int> num){
    int n=num.size();
    for(int i=n/2-1;i>=0;i--){
        shiftdown(num,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(num[0],num[i]);
        shiftdown(num,i,0);
    }
}
//快速排序
int qusort(vector<int> num,int l,int r){
    int i=l,j=r;
    int x=num[l];
    while(i<j){
        while(i<j&&num[j]>=x){
            j--;
        }
        if(i<j){
            num[i++]=num[j];
        }
        while(i<j&&num[i]<=x){
            i++;
        }
        if(i<j){
            num[j--]=num[i];
        }
    }
    num[i]=x;
    return i;
}
void quicksort(vector<int> num,int l,int r){
    if(l<r){
        int i=qusort(num,l,r);
        quicksort(num,l,i-1);
        quicksort(num,i+1,r);
    }
}
//归并排序
void merge(vector<int> num,int l,int mid,int r){
    vector<int> temp;
    int i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(num[i]<num[j]){
            temp.push_back(num[i++]);
        }else{
            temp.push_back(num[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(num[i++]);
    }
    while(j<=r){
        temp.push_back(num[j++]);
    }
    for(int k=l;k<=r;k++){
        num[k]=temp[k-l];
    }
}
void mergesort(vector<int> num,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(num,l,mid);
        mergesort(num,mid+1,r);
        merge(num,l,mid,r);
    }
}