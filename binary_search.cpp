//39417458

#include <iostream> 
#include <string>
#include <sstream> 
using namespace std; 

int binarySearch(int arr[], int l, int r, int x) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 

int main() { 

   int size, el, i=0, j=1, res;
   int arr[10000];
   
   cin>>size>>el;
 
   cin.ignore();

   string str;
   getline(cin,str);
   std::stringstream ss(str);
 
   while (ss >> str) {
      arr[i]=stoi(str);
      ++i;
   }

   /*
   vector<int> vec;
	string str;

	cin>>size;
	cin.ignore();
	
	getline(cin,str);
	std::stringstream ss(str);

    while (ss >> str) vec.push_back(stoi(str));
   */

   if(size==1 && arr[0]==el) { cout<<0; return 0; }
   else if(size==1 && arr[0]!=el) { cout<<-1; return 0; }

   while(arr[j]>arr[j-1] && j!=size) { ++j; }

   if(i==size-1) {  
      cout<<binarySearch(arr, 0, size-1, el); 
   }

   else {
       res=binarySearch(arr, 0, j-1, el);
       if(res!=-1) { cout<<res; return 0; }

       res=binarySearch(arr, j, size-1, el);
       cout<<res; return 0;
   }

}