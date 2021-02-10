//45745467

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin>>n;
    string str="", n1="", n2="";
    unordered_map<string,string> mp;

    for(int i=0; i<=n; ++i) {
        getline(cin,str);
        if(str[0]=='p') {
            str.erase(0,4);
            int j=0;
            while(str[j]!=' ') { n1+=str[j]; ++j; }
            auto const pos2=str.rfind(' ');
            n2=str.substr(pos2+1);

            mp.insert_or_assign(n1, n2);
            str=""; n1=""; n2=""; 
        }
        if(str[0]=='g') {
            n1=str.erase(0,4);
            
            auto search=mp.find(n1);
            if(search!=mp.end()) {
                cout<<search->second<<endl;
            }
            else { cout<<"-1"<<endl; }
            str=""; n1="";
        }
        if(str[0]=='d') {
            n1=str.erase(0,7);

            if(mp.find(n1)!=mp.end()) { 
                mp.erase(n1);
                cout<<"ok"<<endl;
            }
            else { cout<<"error"<<endl; }
            str=""; n1="";
        }
    }

    return 0;
}