/*  Factory Method Design Pattern

    - Extensible to include objects
    - Object generation located in one place
    - Easily switch between factories

    Usually based on user input/choice
*/
#include <iostream>
#include <string>


using namespace std;


// Product from which the concrete products will inherit from
class Coffee{
protected:
    string _type;
public:
    Coffee(){
    }
    const string getType(){
        return _type;
    }
};


// First concrete class
class Espresso : public Coffee{
public:
    Espresso() : Coffee(){
        _type = "Espresso";
        cout << "\nMaking a cup of espresso" << endl;
        cout << "Grind and brew one scoop of espresso beans." << endl;
    }
};


// Second concrete class
class Cappuccino : public Coffee{
public:
    Cappuccino() : Coffee(){
        _type = "Cappuccino";
        cout << "\nMaking a cup of cappuccino" << endl;
        cout << "Grind and brew one scoop of espresso beans." << endl;
        cout << "Heat and foam milk." << endl;
    }
};


// Create coffee maker factory
class coffeeMakerFactory{
private:
    Coffee * _coffee;
public:
    Coffee * getCoffee(){
        int choice;
        // Ask user for which coffee to make
        cout << "Please select a type of coffee to make: " << endl;
        cout << "1. Espresso" << endl << "2. Cappuccino" << endl;
        cout << "Selection: ";
        cin >> choice;

        // Handling user choice
        switch (choice)
        {
        case 1:
            return new Espresso;
        case 2:
            return new Cappuccino;
        default:
            cout << "Invalid selection" << endl;
            return NULL;
        }
    }
};


// The main function
int main(int argc, char ** argv){
    // Create an instance of the coffee maker factory and name it coffee machine
    coffeeMakerFactory coffeeMachine;

    // To view the coffee we selected
    auto * cup = coffeeMachine.getCoffee();
    cout << "\nThe coffee that you have selected is " << cup->getType() << endl;
    
    return 0;
}