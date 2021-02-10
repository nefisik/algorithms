#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

int main() {
	int size;
	vector<int> vec;
	string str;

	cin>>size;
	cin.ignore();
	
	getline(cin,str);
	std::stringstream ss(str);

    while(ss >> str) { vec.push_back(stoi(str)); }


 
  	for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (vec[j] > vec[j + 1]) {
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }

	for(auto &i : vec) { cout<<i<<" "; }
    
    return 0;
}
