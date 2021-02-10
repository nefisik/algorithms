//42719798

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
 
void heapify(vector<pair<int, pair<string,vector<int>>>>& vec, int n, int i) {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && vec[l].first > vec[largest].first)
        largest = l;

    if (r < n && vec[r].first > vec[largest].first)
        largest = r;

    if (largest != i) {
        swap(vec[i], vec[largest]);

        heapify(vec, n, largest);
    }
}

void heapSort(vector<pair<int, pair<string,vector<int>>>>& vec, int size) {
    
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(vec, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}
 

int main() {

	string str, s;
    int size;    

    cin>>size;
	cin.ignore();

    vector<int> v;
    vector<pair<int, pair<string,vector<int>>>> vec;
    vector<pair<int, pair<string,vector<int>>>> kondratiy;
    int sum=0;

    for(int i=0; i<size; ++i) {
        
        std::getline(cin,str);
        
        //Удаление слова из последовательности
        int k=0;
        while(str[k]!=' '){
            if ((str[k]>='a' && str[k]<='z') || (str[k]>='A' && str[k]<='Z')){
                s.push_back(str[k]);
                str.erase(k,1); --k;
            }
            ++k;
        }

        //Запись пар в массив (сумма, имя)
        std::stringstream ss(str);
        //Подсчёт суммы
        while(ss >> str) { v.emplace_back(stoi(str)); }
        for(auto& d : v) { if(d>0) { sum+=d; } }       
        vec.emplace_back(make_pair(sum, make_pair(s,v)));

        s="";
        v.clear();
        kondratiy.clear();
        sum=0;
    }

    //Проверка на кондратия
    int m=size-1, p=0;
    string s1, s2;
    for(int q=size-1; q>=0; --q) {
        s1=vec[q].second.first;
        while(p!=s1.size()){
            if (s1[p]=='k' || s1[p]=='o' || s1[p]=='n' || s1[p]=='d' || s1[p]=='r' || s1[p]=='a' || s1[p]=='t' || s1[p]=='i' || s1[p]=='y'){
                s2.push_back(s1[p]);
            }
            ++p;
        }
        sort(s2.begin(), s2.end());
        s2.erase(std::unique(s2.begin(), s2.end()), s2.end());
        if(s2=="adiknorty") {
            kondratiy.emplace_back(move(vec[q]));
            vec.erase(vec.begin()+q);
            --m;
        }
        p=0; s2=""; s1="";
    }

    //Пирамидальная сортировка массива
    heapSort(vec, vec.size());

    vector<string> vc;
    for(int a = 0; a < vec.size(); a++) {
        for(int b = 0; b < vec.size(); b++) {
            if(vec[b].first==vec[b+1].first) {
                    vc.emplace_back(vec[b].second.first);
                    vc.emplace_back(vec[b+1].second.first);
                    sort(vc.begin(), vc.end());
                    if(vc[0]==vec[b].second.first) { swap(vec[b],vec[b+1]); }
                    vc.clear();
            }
        }
    }

    //Вставка кондратиев
    if(!kondratiy.empty()) {
        for(int x=kondratiy.size()-1; x>=0; --x) {
            vec.emplace_back(move(kondratiy[x]));
        }
    }

    int r = 0;
    while(r!=vec.size()-1) {
        if(vec[r].first==0 && vec[r+1].first==0 && vec[r].second.first==vec[r+1].second.first) {
            swap(vec[r],vec[r+1]); break;
        }
        ++r;
    }

    //Вывод пар
    for(int l=vec.size()-1; l>=0; --l) {
        cout<<vec[l].second.first<<" ";
        for(int g=0; g<vec[l].second.second.size(); ++g) { cout<<vec[l].second.second[g]<<" "; }
        cout<<endl;
    }
}