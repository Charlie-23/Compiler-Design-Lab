#include <bits/stdc++.h>
using namespace std;

int nax=1e7;


vector<string> keyword{"if", "else" , "then"};

vector<char> relop{'>','=','<' };

vector<string> relop1{">","=","<" };

vector<pair<string,string>> answer;

void tokenchecker(string res1){
    int flag=0;
    for(string j:keyword){
        if(res1==j){
            answer.push_back({"keyword", j});
            flag=1;
            break;
        }
    }
    if(flag)
        return;
    for(string j:relop1){
        if(res1==j){
            answer.push_back({"relop", j});
            flag=1;
            break;
        }
    }
    if(flag)
        return;

    int num=0;
    for(char c: res1){
        if(c!='.' && !isdigit(c))
        {
            num=1;
            break;
        }
    }
    if(!num){
        answer.push_back({"number", res1});
    }
    else
        answer.push_back({"id", res1});
    return;
}
int main() {
	string str;
	cout<< "String Input"<<endl;
	getline(cin, str);
	int n=str.length();
	string res;
	int flag=0;
	for(int i=0;i<n;i++){
	    flag=0;
	    for(char j: relop){
	        if(str[i]==j){
	            if(res[res.length()-1]!=' ')
	                res=res+" ";
	            res=res+str[i]+" ";
	            flag=1;
	            break;
	        }
	    }
	    if(flag==0){
	        if(str[i]==' ' && res[res.length()-1]==' ')
	            continue;
	        else
	            res=res+str[i];
	    }
	}
	cout<<res<<endl;
	string res1;
	res+=" ";
	for(int i=0;i<res.length();i++){
	    if(res[i]==' '){
	        tokenchecker(res1);
	        res1="";
	    }
	    else{
	        res1=res1+res[i];
	    }
	}

	for(int i=0;i<answer.size();i++){
	    if((answer[i].second == ">"|| answer[i].second=="<") && (i+1<answer.size() && answer[i+1].second== "=") ||
	    (answer[i].second=="<" && (i+1<answer.size() && answer[i+1].second==">"))){
	        string tp=answer[i].second + answer[i+1].second;
	        cout<< answer[i].first<<"  "<<tp<<endl;
	        i++;
	    }
	    else{
	        cout<< answer[i].first<<"  "<<answer[i].second<<endl;
	    }
	}
	return 0;
}
