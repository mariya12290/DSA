#include <iostream>
#include <string>
#include <list>

class  LinkedStack{
    public:
    LinkedStack();
    int size();
    bool empty();
    std::string top();
    void push(std::string s);
    void pop();

    private:
    std::list<std::string>*S;
    int n; 
};

LinkedStack::LinkedStack():S(),n(0){

}
int LinkedStack::size(){
    return n;
}
bool LinkedStack::empty(){
    return n==0;
}

std::string LinkedStack::top(){
    return S->front();
}

void LinkedStack::push(std::string s){
    S->
}
int main(){



    return 0;
}