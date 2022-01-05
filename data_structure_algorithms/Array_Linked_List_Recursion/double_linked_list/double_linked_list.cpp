#include <iostream>
#include <string>

typedef std::string Elem;  //list element type

class DNode{
    private:
    Elem elem;              //node element value
    DNode *prev;            //rev node in list
    DNode *next;         //next node is list
    friend class DLinkedList;   //allow DLinkedList access
};

class DLinkedList{
    public:
    DLinkedList ();
    ~DLinkedList();
    bool empty() const;
    const Elem& front()const;
    const Elem& back() const;
    void addFront(const Elem &e) ;
    void addBack(const Elem &e) ;
    void removeFront() ;
    void removeBack() ;

    void reverse();

    private:
    DNode* header;
    DNode* trailer;
    protected:
    void add(DNode* v, const Elem&e);
    void remove(DNode* v);
};

DLinkedList::DLinkedList(){
    header = new DNode;
    trailer = new DNode;
    header->next= trailer;
    //header->prev= NULL;
    trailer->prev= header;
    //trailer->next = NULL;
}

DLinkedList::~DLinkedList(){
    while (!empty()){
        removeFront();
    }
    delete header;
    delete trailer; 
}

bool DLinkedList::empty() const{
    return (header->next == trailer);
}

const Elem& DLinkedList::front()const{
    return header->next->elem;
}

const Elem& DLinkedList::back()const{
    return trailer->prev->elem;
}

void DLinkedList::add(DNode *v, const Elem &e){
    DNode*u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next=u;
    v->prev=u;
}

void DLinkedList::addFront(const Elem& e) // add to front of list
{ add(header->next, e); }

void DLinkedList::addBack(const Elem& e) // add to back of list
{ add(trailer, e); }

void DLinkedList::remove(DNode* v){
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next =w;
    w->prev = u;
    delete v;
    
}

void DLinkedList::removeFront()  {
    remove(header->next);
}

void DLinkedList::removeBack()  {
    remove(trailer->prev);
}

void DLinkedList::reverse(){
    DLinkedList T;
    while (!empty())
    {
        std::string s= front();
        removeFront();
        T.addFront(s);
    }
    while(!T.empty()){
        std::string s= T.front();
        T.removeFront();
        addBack(s);

    }
    
}


int main(){

DLinkedList DLL;
DLL.addFront("suri");
DLL.addFront("kumar");
DLL.addBack("mariya");

std::cout<<"=========Before reversing the list ========="<<std::endl;
std::cout<<DLL.front()<<std::endl;
std::cout<<DLL.back()<<std::endl;
DLL.reverse();

std::cout<<"=========After reversing the list ========="<<std::endl;

std::cout<<DLL.front()<<std::endl;
std::cout<<DLL.back()<<std::endl;
    return 0;
}