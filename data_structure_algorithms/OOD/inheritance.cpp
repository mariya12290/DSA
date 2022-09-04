#include <iostream>
#include <string>


class Progression{
    public:
    Progression(long f=0):first(f),cur(f){

    };//constructor
    virtual ~Progression(){}; //destructor
    void printProgression(int n);  //print the first n values
    protected:
    virtual long firstValue(); //reset
    virtual long nextValue();   //advance

    protected:
    long first; //first value
    long cur; //current value
};

void Progression::printProgression(int n){   //print n values
    std::cout<<firstValue()<<std::endl; //print the first
    for(int i=2; i<=n;++i){                //print 2 through n
        std::cout<<" "<<nextValue()<<std::endl;
    }
}

long Progression::firstValue(){
    cur = first;
    return cur;
}

long Progression::nextValue(){
    return ++cur;
}

class ArithProgression : public Progression{
    public:
    ArithProgression(long i=1);
    protected:
    virtual long nextValue();
    protected:
    long inc;
};

ArithProgression::ArithProgression(long i):Progression(), inc(i){

}
long ArithProgression::nextValue(){
    cur += inc;
    return cur;
}

class GeomProgression : public Progression{
    public:
    GeomProgression(long b =2);
    protected:
    virtual long nextValue(); 
    protected:
    long base;
};

GeomProgression::GeomProgression(long b):Progression(1),base(b){

}
long GeomProgression::nextValue(){
    cur *=base;
    return cur;
}

class FibonacciProgression: public Progression{
    public:
    FibonacciProgression(long f=0, long s=1);

    protected:
    virtual long firstValue();
    virtual long nextValue();
    protected:
    long second;
    long prev;
};

FibonacciProgression::FibonacciProgression(long f, long s): Progression(f), second(s), prev(second-first){

}
long FibonacciProgression::firstValue(){
    cur = first;
    prev = second - first;
    return cur;
}
long FibonacciProgression::nextValue(){
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}
int main(){

std::cout<<" progression "<<std::endl;
Progression pP(10);
pP.printProgression(10);
std::cout<<"Arthimetic progression "<<std::endl;
ArithProgression aP(1);

aP.printProgression(10);

std::cout<<"Fibonacci progression "<<std::endl;
FibonacciProgression fP;
fP.printProgression(10);
    return 0;
}