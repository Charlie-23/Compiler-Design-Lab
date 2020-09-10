#include<bits/stdc++.h>
using namespace std;
struct nfastate
{
    vector<int> a[2], e;
    bool f=0;
};
vector<nfastate> nfa;
stack<int> st;

int nfa_size;
string dispregex;
struct nfastate init_nfa_state;


void union_()
{
    nfa.push_back(init_nfa_state);
    nfa.push_back(init_nfa_state);
    int d = st.top(); st.pop();
    int c = st.top(); st.pop();
    int b = st.top(); st.pop();
    int a = st.top(); st.pop();
    nfa[nfa_size].e.push_back(a);
    nfa[nfa_size].e.push_back(c);
    nfa[b].e.push_back(nfa_size+1);
    nfa[d].e.push_back(nfa_size+1);
    st.push(nfa_size);
    nfa_size++;
    st.push(nfa_size);
    nfa_size++;
}

void concat()
{
    int d = st.top();
    st.pop();
    int c = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    int a = st.top();
    st.pop();
    nfa[b].e.push_back(c);
    st.push(a);
    st.push(d);
}

void kleene_star()
{
    nfa.push_back(init_nfa_state);
    nfa.push_back(init_nfa_state);
    int b = st.top();
    st.pop();
    int a = st.top();
    st.pop();
    nfa[nfa_size].e.push_back(a);
    nfa[nfa_size].e.push_back(nfa_size+1);
    nfa[b].e.push_back(a);
    nfa[b].e.push_back(nfa_size+1);
    st.push(nfa_size);
    nfa_size++;
    st.push(nfa_size);
    nfa_size++;
}

void character(int i)
{
    nfa.push_back(init_nfa_state);
    nfa.push_back(init_nfa_state);
    //cout<<nfa_size<<endl;
    nfa[nfa_size].a[i].push_back(nfa_size+1);
    st.push(nfa_size);
    nfa_size++;
    st.push(nfa_size);
    nfa_size++;
}

void display_nfa()
{
    cout<<endl<<endl;
    cout<<"States\t|\ta\t|\tb\t|\teps(e)\t|Accepting state|"<<endl;
    cout<<"------------------------------------------------------------------------\n";
    for(unsigned int i=0; i<nfa.size(); i++)
    {
        cout<<i<<"\t|\t";
        for(unsigned int j=0; j<nfa[i].a[0].size(); j++)cout<<nfa[i].a[0][j]<<' ';
        cout<<"\t|\t";
        for(unsigned int j=0; j<nfa[i].a[1].size(); j++)cout<<nfa[i].a[1][j]<<' ';
        cout<<"\t|\t";
        for(unsigned int j=0; j<nfa[i].e.size(); j++)cout<<nfa[i].e[j]<<' ';
        cout<<"\t|\t";
        if(nfa[i].f)cout<<"Yes"; else cout<<"No";
        cout<<"\t|\n";
    }
    cout<<"------------------------------------------------------------------------\n";
}

int priority(char c){
    switch(c){
        case '*': return 3;
        case '.': return 2;
        case '+': return 1;
        default: return 0; //this is for bracket (
    }
}

string to_postfix(string regexp)
{
    string postfix="";
    stack<char> op;
    char c;
    for(unsigned int i=0; i<regexp.size(); i++)
    {
        switch(regexp[i])
        {
            case 'a':
                postfix+=regexp[i]; break;
            case 'b':
                postfix+=regexp[i]; break;
            case '(':
                op.push(regexp[i]); break;
            case ')':
                while(op.top()!='('){
                    postfix+=op.top();
                    op.pop();
                }
                op.pop();
                break;
            default:
                while(!op.empty()){
                    c=op.top();
                    if(priority(c)>=priority(regexp[i])){
                        postfix+=op.top();
                        op.pop();
                    }
                    else break;
                }
                op.push(regexp[i]);
        }
        //cout<<regexp[i]<<' '<<postfix<<endl;
    }
    while(!op.empty())
    {
        postfix += op.top();
        op.pop();
    }
    return postfix;
}
int main()
{
    int n;
    n=1;
    while(n--){
        string regexp,postfix;
        cout<<"Enter Regular Expression: ";
        cin>>regexp;
        dispregex=regexp;
        string ret="";
        char c,c2;
        //inseting the concatenations symbol
        for(unsigned int i=0; i<regexp.size(); i++){
            c=regexp[i];
            if(i+1<regexp.size()){
                c2=regexp[i+1];
                ret+=c;
                if(c!='('&&c2!=')'&&c!='+'&&c2!='+'&&c2!='*'){
                    ret+='.';
                }
            }
        }
        ret+=regexp[regexp.size()-1];
        regexp=ret;
        postfix = to_postfix(regexp);

        cout<<"Postfix Expression for this is : "<<postfix<<endl;
        //converting postfix to the nfa
        for(unsigned int i=0; i<postfix.size(); i++)
        {
            switch(postfix[i])
            {
                case 'a': character(postfix[i]-'a'); break;
                case 'b': character(postfix[i]-'a'); break;
                case '*': kleene_star(); break;
                case '.': concat(); break;
                case '+': union_();
            }
        }

        int final_state=st.top();
        st.pop();
        int start_state=st.top();
        st.pop();
        nfa[final_state].f=1;
        display_nfa();
        return 0;
    }
}
