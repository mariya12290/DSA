#include <iostream>
#include <string>

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



int main(){




    return 0;
}