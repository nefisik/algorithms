#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

const string BASE = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" ;

string toBase62(int value) {
    string str;
    do {
        str.insert(0, string(1, BASE[value % 62]));
        value /= 62;
    } while (value > 0);

    return str;
}

int main() {
    int url, n;
    cin>>url>>n;
    string str, base_url, long_url, short_url;
    const string base_str="https://prakti.kum/";
    unordered_map<string,string> mp1;
    unordered_map<string,string> mp2;

    for(int i=0; i<=n; ++i) {
        getline(cin,str);
        if(str[0]=='p') {
            base_url=str.erase(0,5);
        	short_url=toBase62(url);
            long_url=base_str + short_url;
            if(mp1.find(long_url)==mp1.end() && mp2.find(base_url)==mp2.end()) {
                mp1.emplace(std::make_pair(long_url, base_url));
                mp2.emplace(std::make_pair(base_url, long_url));
                cout<<long_url<<endl;
                url+=1;
            }
            else {
                auto search=mp2.find(base_url);
                cout<<search->second<<endl;
            }
            str=""; base_url=""; short_url=""; long_url=""; 
        }
        if(str[0]=='g') {
            long_url=str.erase(0,4);
            if(mp1.find(long_url)!=mp1.end()) { cout<<mp1[long_url]<<endl; }
            else { cout<<"error"<<endl; }
            str=""; long_url="";
        }
    }

    return 0;
}
