#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int max = 5000;

void display(int arr[]){
    int ctr = 0;
    for (int i=0; i<5000; i++){
    	if (!ctr && arr[i])			ctr = 1;
    	if(ctr)
            std::cout<<arr[i];
    }
}


void factorial(int arr[], int n){
    if (!n) return;
    int carry = 0;
    for (int i=5000-1; i>=0; --i){
        arr[i] = (arr[i] * n) + carry;
        carry = arr[i]/10;
        arr[i] %= 10;
    }
    factorial(arr,n-1);
}

int main(){
    int *arr = new int[5000];
    std::memset(arr,0,5000*sizeof(int));
    arr[5000-1] = 1;
    int num;
    std::cout<<"Enter the number: ";
    //std::cin>>num;

    num = 123456789;
    std::cout<<"factorial of "<<num<<"is :\n";
    factorial(arr,num);
    display(arr);
    delete[] arr;
    return 0;
}
