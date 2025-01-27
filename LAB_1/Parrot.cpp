#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Parrot {
private:
    vector<string> phrases;

public:
    Parrot() {
        srand(time(0));  
    }

    void addPhrase(string newPhrase) {
        phrases.push_back(newPhrase);
    }

    void say(int times) {
        for (int i=0; i<times; i++) {
                if (phrases.empty()) {
                    cout << "I don't have anything to say" << endl;
                }
                else {
                int randomIndex = rand() % phrases.size();
                cout << phrases[randomIndex] << endl;
                }
            }
         
        
    }
};

int main() {
    Parrot parrot;
    parrot.say(2);
    parrot.addPhrase("Hello!");
    parrot.say(1);
    parrot.addPhrase("I'm tired!");
    parrot.addPhrase("To the left!");
    parrot.say(2);  

    return 0;
}