#include <iostream>

void func(int* arr1, int* arr2, int* arr3, const int a, const int b) {
	int i=0;
	int j=0;
	for( ; i<(a+b); i++) {
		if(i<a) {
			arr3[i]=arr1[i];
		}
		else {
			for( ; j<b; j++) {
				arr3[i+j]=arr2[j];
			}
		}
	}
}

int main() {
	int arr1[3]={3,5,8};
	int arr2[5]={7,1,9,4,6};
	int arr3[3+5];
	func(arr1, arr2, arr3, 3, 5);
	for(int i=0; i<(3+5); i++) {
		std::cout<<arr3[i]<<std::endl;
	}
}
