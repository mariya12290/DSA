#include <iostream>
#include <string>


typedef std::string Elem;
class CNode{
    private:
    Elem elem;
    CNode* next;

    friend class CircleList;
};

class CircleList{
    public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem &e);
    void remove();
    private:
    CNode* cursor;
};

CircleList::CircleList():cursor{NULL}{

}
CircleList::~CircleList(){
    while (!empty())
    {
        remove();
    }
    
}

bool CircleList::empty() const{
    return cursor==NULL;
}
const Elem& CircleList::front() const{
    return cursor->next->elem;
}

const Elem& CircleList::back()const{
    return cursor->elem;
}
void CircleList::advance(){
    cursor = cursor->next;
}

void CircleList::add(const Elem&e){
    CNode* v= new CNode;
    v->elem =e;
    if(cursor==NULL){
        v->next =v;
        cursor=v;
    }else{
        v->next=cursor->next;
        cursor->next=v;
    }
}

void CircleList::remove(){
    CNode* old = cursor->next;
    if(old==cursor){
        cursor=NULL;
    }else{
        cursor->next=old->next;   //removing front element in the circular list
        
    }
    delete old;
}

int main(){

CircleList playlist; //[]
playlist.add("Suri"); //[Suri*]
playlist.add("Kumar");//[Kumar,Suri*]

std::cout<<"=====After adding Kumar======="<<std::endl;

std::cout<<playlist.front()<<std::endl;

playlist.add("Mariya"); //[Mariya, Kumar, Suri*]
std::cout<<"========After adding Mariya======= "<<std::endl;
std::cout<<playlist.front()<<std::endl;

playlist.advance();//[Kumar, Suri, Mariya*]
std::cout<<"========After advancing========== "<<std::endl;
std::cout<<playlist.front()<<std::endl;
    return 0;
}