#include <iostream>
using namespace std;

void fibonacci(int num) {
    int arr[num];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < num; i++) {
      arr[i] = arr[i-2] + arr[i-1];
    }
    for(int i = 0; i < num; i++) {
      cout<<arr[i]<<endl;
    }
}

int main() {
    fibonacci(10);
}
