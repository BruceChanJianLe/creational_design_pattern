/*  Abstract Factory Design Pattern

    A factory of factories!
    - Provides an interface for creating families of related objects without specifying thier concrete classes

*/

#include <iostream>
#include <string>


using namespace std;


// Create Door object
class Door
{
public:
    Door()
    {
    }
    // A method that needs to be over-written later, hence 'virtual'
    virtual void Open() = 0;
};


// Gas car door inherit from Door
class gasCarDoor : public Door
{
public:
    gasCarDoor()
    {
        cout << "Making a door for a gas car" << endl;
    }
    void Open()
    {
        cout << "Click!" << endl;
    }
};


// Electric car door inherit from Door
class electricCarDoor : public Door
{
public:
    electricCarDoor()
    {
        cout << "Making a door for an electric car" << endl;
    }
    void Open()
    {
        cout << "shhhh" << endl;
    }
};


// Create Engine object
class Engine
{
protected:
    string _sound;
public:
    Engine()
    {
        _sound = "";
    }
    // virtual method to be declared when inherit, hence make it equal to 0.
    virtual void Run() = 0;
};


// Gas engine inherit from Engine
class gasEngine : public Engine
{
public:
    gasEngine()
    {
        _sound = "vroom";
        cout << "Making a gas engine" << endl;
    }
    void Run()
    {
        cout << _sound << endl;
    }
};


// Electric engine inherit from Engine
class electricEngine : public Engine
{
public:
    electricEngine()
    {
        _sound = "SHHHH";
        cout << "Making an electric engine" << endl;
    }
    void Run()
    {
        cout << _sound << endl;
    }
};


// Factories
class carFactory
{
public:
    virtual Door * buildDoor() = 0;
    virtual Engine * buildEngine() = 0;
};


// Gas car factory
class gasCarFactory : public carFactory
{
public:
    Door * buildDoor()
    {
        return new gasCarDoor();
    }
    Engine * buildEngine()
    {
        return new gasEngine();
    }
};


// Electric car factory
class electricCarFactory : public carFactory
{
public:
    Door * buildDoor()
    {
        return new electricCarDoor();
    }
    Engine * buildEngine()
    {
        return new electricEngine();
    }
};


int main(int argc, char ** argv)
{
    // Create a generic carFactory
    carFactory * carPlant;

    // User choice on which type of car to be made
    int choice;
    cout << "Please select a type of car you wish to make..." << endl;
    cout << "1. Gasoline" << endl << "2. Electric" << endl;
    cout << "Selection: " ;
    cin >> choice;
    cout << endl;

    // Handling the user input
    switch (choice)
    {
    case 1:
        carPlant = new gasCarFactory();
        break;
    case 2:
        carPlant = new electricCarFactory();
        break;
    default:
        cout << "Invalid selection" << endl;
        carPlant = NULL;
        break;
    }

    if(carPlant != NULL)
    {
        Door * myDoor = carPlant->buildDoor();
        Engine * myEngine = carPlant->buildEngine();

        myDoor->Open();
        myEngine->Run();
    }
    return 0;
}