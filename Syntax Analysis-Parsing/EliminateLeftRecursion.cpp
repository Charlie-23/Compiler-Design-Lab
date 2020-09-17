#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void func(string ip){

    string ip1,op1,op2,temp;
    int sizes[10] = {};
    char c;

    int n,j,l;

    ip1.push_back(ip[0]);
    op1 += ip1 + "\'->";
    ip1 += "->";
    op2+=ip1;
 
    int cnt=0;
    n=0;   

    for(int i=3;i<ip.length();i++){
        if(i==ip.length()-1)
            cnt++;

        if(ip[i]=='|'||i==ip.length()-1){
      
            sizes[n]=cnt;
            cnt=0;
            n++;
            continue;
        }
            cnt++;

    }

    cout<<"Production Rule : "<<ip<<endl;
    for(int i=0,k=3;i<n;i++)
    {
        if(ip[0] == ip[k])
        {
            cout<<"Production "<<i+1<<" has left recursion."<<endl;
            if(ip[k] != '#')
            {
                for(l=k+1;l<k+sizes[i];l++)
                    op1.push_back(ip[l]);
                k=l+1;
                op1.push_back(ip[0]);
                op1 += "\'|";
            }
        }
        else
        {
            cout<<"Production "<<i+1<<" does not have left recursion."<<endl;
            if(ip[k] != '#')
            {
                for(j=k;j<k+sizes[i];j++)
                    op2.push_back(ip[j]);
                k=j+1;
                op2.push_back(ip[0]);
                op2 += "\'|";
            }
            else
            {
                op2.push_back(ip[0]);
                op2 += "\'";
            }}}
    op1 += "#";
    cout<<op2<<endl;
    cout<<op1<<endl;
    return ;

}
int main(){

    int n;
    cout<<"Enter the number of productions : ";
    cin>>n;
    vector<string>v(n);
    cout<<"Enter Productions"<<endl;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
        func(v[i]);
}
