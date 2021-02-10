#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <ctype.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int last_str_idx = strs.size();
        
    if( last_str_idx == 0 )
        return "";

    sort(strs.begin(), strs.end()); 
        
    int shortest_length = strs[0].length();
    int char_idx = 0;
        
    last_str_idx = last_str_idx - 1;
    string ret;

    while( char_idx < shortest_length && strs[0][char_idx] == strs[last_str_idx][char_idx] ) {
        ret += strs[0][char_idx++];
    }

    return ret;
}

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string decodeString(string s) {
    stack<string> st;
    string result;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '[') continue;
        if(isdigit(s[i])) {
            string str;
            while(isdigit(s[i])) str.push_back(s[i++]);
            i--;
            st.push(str);
        } else if(s[i] == ']') {
            string temp;
            string str = st.top();st.pop();
            while(!is_number(st.top())) {str = st.top() + str; st.pop();}
            string str2 = st.top();st.pop();
            int repeat = stoi(str2);
            for(int j = 0; j < repeat; j++) temp += str;
            st.push(temp);
        } else {
            string str;
            while(isalpha(s[i])) str.push_back(s[i++]);
            i--;
            st.push(str);
        }
    }
    while(!st.empty()) { result = st.top() + result; st.pop();}
    return result;
}
    

int main() {
	int n;
    cin>>n;
	vector<string> v(n);
	for(auto&& i : v) { cin>>i; }
	
	for(auto&& i : v) {
		i = decodeString(i);
    }
    
    cout<<longestCommonPrefix(v)<<endl;
}