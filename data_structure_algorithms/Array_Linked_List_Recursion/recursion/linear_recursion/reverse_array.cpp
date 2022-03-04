#include <iostream>
#include <utility>

//reverse an Array using recursion
void ReverseArrayRecursion(int *A, int i, int j){
    if(i<j){
        std::swap(A[i],A[j-1]);
        ReverseArrayRecursion(A, i+1, j-1);
    }
}

//reverse an array without recursion
void ReverseArray(int *A, int i, int j){
    while(i<j){
        std::swap(A[i],A[j-1]);
        i++;
        --j;
    }
}

int main(){

    int a[]={1,2,3,4,5};
    for(const auto &i:a){
        std::cout<<i<<" ";
    }std::cout<<"\n";
    ReverseArrayRecursion(a,0,5);
    for(const auto &i:a){
        std::cout<<i<<" ";
    }std::cout<<"\n";
    ReverseArray(a,0,5);
    for(const auto &i:a){
        std::cout<<i<<" ";
    }std::cout<<"\n";
}