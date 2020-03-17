/*  Singleton Design Pattern

    - Must be *globally* accessible
    - Must only be *one* instance of a class (at a time)

*/

#include <iostream>
#include <string>


using namespace std;

class Leader
{
private:
    static Leader * _instance;
    Leader()
    {
        cout << "New leader has been elected" << endl;
    }
public:
    static Leader * getInstance()
    {
        if(_instance == NULL)
        {
            _instance = new Leader;
        }
        return _instance;
    }
    void giveSpeech()
    {
        cout << "Address the public" << endl;
    }
};

Leader * Leader::_instance = NULL;

int main(int argc, char ** argv)
{
    Leader::getInstance()->giveSpeech();
    Leader * elected = elected->getInstance();
    elected->giveSpeech();
}