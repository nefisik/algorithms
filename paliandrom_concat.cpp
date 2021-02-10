#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

bool isPal(string& s, int l, int r) {
    while(l<r && s[l]==s[r]) l++, r--;
    return l >= r;
}

void palindromePairs(vector<string>& words) {
	std::ios::sync_with_stdio(false);
    vector<vector<int>> vv;
    unordered_map<string, int> word_map;
    for(int i = 0; i < words.size(); ++i) word_map[words[i]] = i;
    for(int i = 0; i < words.size(); ++i){
        int len = words[i].length(), t;
        string cur = words[i], t_str;
        reverse(cur.begin(), cur.end());
        for(int l = 0; l <= len; ++l){
            if(isPal(cur, 0, l-1)){
                t_str = cur.substr(l);
                if(word_map.count(t_str)){
                    t = word_map[t_str];
                    if(t!=i) vv.push_back(vector<int>{i, t});
                }
            }
            if(isPal(cur, l, len-1)){
                t_str = cur.substr(0, l);
                if(word_map.count(t_str)){
                    t = word_map[t_str];
                    if(len>l) vv.push_back(vector<int>{t, i});
                }
            }
        }
    }
	sort(vv.begin(), vv.end());
	for(int i=0; i<vv.size(); ++i) {
		for(int j=0; j<1; ++j) {
			cout<<vv[i][0]+1<<" "<<vv[i][1]+1<<'\n';
		}	
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<string> v(n);
	for(auto& i : v) { cin>>i; }

	palindromePairs(v);
	
	return 0;
}
