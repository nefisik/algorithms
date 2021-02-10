//42338424
//в качестве метода сортировки использовался quick_sort

#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int cmp(string X, string Y) {

	string XY = X.append(Y);

	string YX = Y.append(X);

	return XY.compare(YX) > 0 ? 1 : 0;
}

void print(vector<string> arr) {

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
}

int main() {
    
	vector<string> v;    
    int size;
	string str="", s="";

	cin>>size;
	cin.ignore();
	
	getline(cin,str);
	std::stringstream ss(str);

	int i=0, j=0;
    while(i<str.size()) {
        while(str[i]!=' ' && i<str.size()) { s+=str[i]; ++i; }
        v.push_back(s);
        ++i; s="";
    }

	print(v);

	return 0;
}
