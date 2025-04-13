#include<bits/stdc++.h>
using namespace std;
//表达式求值

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // 括号和其他情况
}
int eval(char *s){
    stack<int> num;
    stack<char> charactor;
    int i=0;
    while(s[i]){
        if(s[i]>='0'&&s[i]<='9'){
            int n=0;
            while(s[i]>='0'&&s[i]<='9'){
                n=n*10+s[i]-'0';
                i++;
            }
            num.push(n);
        }else if(s[i]=='('){
            charactor.push('(');
            i++;
        }else if(s[i]==')'){
            while(charactor.top()!='('){
                int b=num.top();num.pop();
                int a=num.top();num.pop();
                char op=charactor.top();charactor.pop();
                if(op=='+') num.push(a+b);
                else if(op=='-') num.push(a-b);
                else if(op=='*') num.push(a*b);
                else if(op=='/') num.push(a/b);
            }
            charactor.pop();
            i++;
        }else{
            while(!charactor.empty() && charactor.top() != '(' && getPriority(charactor.top()) >= getPriority(s[i])){
                int b=num.top();num.pop();
                int a=num.top();num.pop();
                char op=charactor.top();charactor.pop();
                if(op=='+') num.push(a+b);
                else if(op=='-') num.push(a-b);
                else if(op=='*') num.push(a*b);
                else if(op=='/') num.push(a/b);
            }
            charactor.push(s[i]);
            i++;
        }
    }
    while(!charactor.empty()){
        int b=num.top();num.pop();
        int a=num.top();num.pop();
        char op=charactor.top();charactor.pop();
        if(op=='+') num.push(a+b);
        else if(op=='-') num.push(a-b);
        else if(op=='*') num.push(a*b);
        else if(op=='/') num.push(a/b);
    }
    return num.top();
}
//单元测试
void test(){
    char s[100];
    cin>>s;
    // cin.getline(s,100);
    int result;
    result=eval(s);
    cout<<result<<endl;
}
int main(){
    test();
    return 0;
}