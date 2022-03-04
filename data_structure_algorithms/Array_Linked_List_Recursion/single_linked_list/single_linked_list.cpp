#include <iostream>
#include <memory>
#include <string>

class StringNode{  // a node in a list of integers
    public:
    std::string elem;     //element value
    StringNode* next;      //next item in the list
};

class StringLinkedList{ //a linked list of strings
public:
StringLinkedList(); //constructor
~StringLinkedList(); //destructor
bool empty()const; //is list empty
const std::string& front()const; //get the front element
void addFront(const std::string&e); //add to front of list
void removeFront();   //remove the front item list

void display();
private:
StringNode* head;   //pointer to the head of the list

};

StringLinkedList::StringLinkedList(){
    head=NULL;
}
StringLinkedList::~StringLinkedList(){
    while(!empty()){
        removeFront();
    }

}

bool StringLinkedList::empty()const{
    return head==NULL;
}
const std::string& StringLinkedList::front()const{
    return head->elem;
}

void StringLinkedList::addFront(const std::string&e){
    StringNode* v= new StringNode;
    v->elem = e;
    v->next=head;
    head =v;
}
void StringLinkedList::removeFront(){
    StringNode* old = head;
    head = old->next;
    delete old;
}


int main(){

std::unique_ptr<StringLinkedList>sl;
sl= std::make_unique<StringLinkedList>();
sl->addFront("suri");

sl->addFront("kumar");
sl->addFront("mariya");

std::cout<<sl->front()<<std::endl;
sl->removeFront();



std::cout<<sl->front()<<std::endl;

}