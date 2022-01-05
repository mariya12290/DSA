#include <iostream>
#include <array>

void insertion_sort(int* A, int n){
    for(int i=1; i<n;++i){
        int cur = A[i];
        int j =i-1;
        while(j>=0 &&A[j]>cur){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=cur;
    }
}

int main(){

int arr[]={6,4,3,7,5};

for(const auto&i:arr){
    std::cout<<i<<" ";
}std::cout<<std::endl;
insertion_sort(arr,5);


for(const auto&i:arr){
    std::cout<<i<<" ";
}std::cout<<std::endl;

    return 0;
}
