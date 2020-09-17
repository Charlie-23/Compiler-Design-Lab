#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p;  
    int i = 0;
    cout<<"Give the number of productions: "<<endl;
        cin>>p;
        
        vector<string> lt(p),rt(p); 
        
        for(i=0;i<p;++i) 
        {
            cout<<"For production "<<i+1<<": \n";
            cout<<"left part"<<i+1<<": "<<endl;
            cin>>lt[i];
            cout<<"Right part"<<i+1<<": \n";
            cin>>rt[i];
        }
        
        int j = 0;

        for(i=0;i<p;++i) 
        {
            for(j=i+1;j<p;++j) 
            {
                if(lt[j]==lt[i]) 
                {
                    int k = 0;
                    string common = "";    
                    while(k<rt[i].length() && k<rt[j].length() && rt[i][k]==rt[j][k]) 
                    {
                        common+=rt[i][k];
                        ++k;
                    }
                    
                    if(k==0)
                    continue;
                    
                    string simlt=lt[i]; 
                    
                    if(k==rt[i].length()) 
                    {
                        lt[i] = lt[i]+"\'"; 
                        lt[j] = lt[j]+"\'";
                        rt[i] = "#";    
                        rt[j] = rt[j].substr(k,rt[j].length()-k);
                    }
                    else if(k==rt[j].length()) 
                    {
                        lt[i] = lt[i]+"\'";
                        lt[j] = lt[j]+"\'";
                        rt[j] = "#";
                        rt[i] = rt[i].substr(k,rt[i].length()-k);
                    }
                    else 
                    {
                        lt[i] = lt[i]+"\'";
                        lt[j] = lt[j]+"\'";
                        rt[j] = rt[j].substr(k,rt[j].length()-k);
                        rt[i] = rt[i].substr(k,rt[i].length()-k);
                    }
                    int l;
                    for(l=j+1;l<p;++l) 
                    {
                        if(simlt==lt[l] && common==rt[l].substr(0,fmin(k,rt[l].length()))) 
                        {
                                lt[l] = lt[l]+"\'";
                                rt[l] = rt[l].substr(k,rt[l].length()-k);
                        }
                    }
                    lt.push_back(simlt);
                    rt.push_back(common+lt[i]);
                    ++p;
                }
            }
        }
        cout<<"\nResult : "<<endl;
        for(i=0;i<p;++i) 
        {
            cout<<"\n"<<lt[i]<<"\t->  "<<rt[i];
        }
        cout<<"\n";
        return 0;
}
