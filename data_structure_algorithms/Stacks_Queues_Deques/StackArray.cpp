#include <iostream>

class ArrayStackInt{
    enum {DEF_CAPACITY = 100};
public:
ArrayStackInt(int cap = DEF_CAPACITY);
int size() ; //number of items in the stack
bool empty() ; //is the stack empty
 int top(); //get the top element
void push(int e); //push element onto the stack
void pop();
private:

int* S; //array of stack elements
int capacity; //stack capacity
int t;  //index of the top of the stack
};

ArrayStackInt::ArrayStackInt(int cap): S(new int[cap]), capacity(cap), t(-1){}

int ArrayStackInt::size() {
    return (t+1);
}
int ArrayStackInt::top(){
    return S[t];

}
void ArrayStackInt::push(int e){
    S[++t] = e;
}
void ArrayStackInt::pop(){
    --t;
}
bool ArrayStackInt::empty(){
    std::cout<<" t is "<<t<<std::endl;
    return (t<0);
}

int main(){

ArrayStackInt Asi(10);
Asi.push(10);
Asi.push(11);
Asi.push(12);
Asi.push(13);
Asi.push(14);

std::cout<<" Size is "<<Asi.size()<<std::endl;
std::cout<<" is empty "<<Asi.empty()<<std::endl;

std::cout<<" top is "<<Asi.top()<<std::endl;

Asi.pop();

std::cout<<" top is "<<Asi.top()<<std::endl;

    return 0;
}