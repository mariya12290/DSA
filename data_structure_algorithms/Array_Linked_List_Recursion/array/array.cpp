#include <iostream>
#include <string>
#include <exception>
#include <memory>

class GameEntry{
    public:
    GameEntry(const std::string&name="",int s=0);
    std::string getName() const;
    int getScore() const;
    private:
    std::string name{};
    int score{};
};

GameEntry::GameEntry(const std::string &name, int s):name{name},score{s}{

}
std::string GameEntry::getName()const{
    return name;
}
int GameEntry::getScore()const {

    return score;
}

class Scores{
    public:
    Scores(int maxEnt =10); //constructor
    ~Scores(); //destructor 
    void add(const GameEntry&e);  //add a game entry
    GameEntry remove(int i);       //remove the ith entry
    void display(); //display the Gameentries
    private:
    int MaxEntries; //maximum number of entries
    int numEntries; //actual number of entries
    GameEntry* entries;  //array of game entries
};

Scores::Scores(int maxEnt):MaxEntries{maxEnt}{ //constructor
entries = new GameEntry[MaxEntries];  //allocate array storage
numEntries =0;   //initially no elements
}

Scores::~Scores(){//destructor
    delete [] entries; 
}
void Scores::add(const GameEntry& e){
    int newScore = e.getScore(); //score to add
    if(numEntries == MaxEntries){ //array is full
        if(newScore <=entries[MaxEntries-1].getScore()){
            return; //not high enough - ignore
        }
    }
    else{
        numEntries++; //if not full, one more entry
    }
    int i= numEntries-2;//start with the next to last
    while(i>=0&& newScore>entries[i].getScore()){
        entries[i+1]=entries[i];    //right shoft if smaller
        i--;
    }
    entries[i+1]=e;
}

GameEntry Scores::remove(int i){
    if((i<0)|| (i>=numEntries)){
        throw std::out_of_range("index is not valid");
    }
    GameEntry e= entries[i];
    for(int j=i+1;j<numEntries;j++){
        entries[j-1]= entries[j];
    }
    numEntries--;
    return e;
}
 void Scores::display(){
        for(int i{0};i<numEntries;++i){
            std::cout<<"Player name "<<entries[i].getName()<<" player score "<<entries[i].getScore()<<std::endl;
        }
    }
 
int main(){

std::unique_ptr<Scores>scores;

scores = std::make_unique<Scores>(10);
scores->add({"Suri",30});
scores->add({"Kumar",10});
scores->add({"Mariya",20});


scores->display();

scores->remove(0);
std::cout<<"===========Entries after removal============ "<<std::endl;
scores->display();


    return 0;
}