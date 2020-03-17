/*  Prototype Design Pattern

    - Creates new objects by cloning an existing one

    Similar to a copy constructor, but a copy constructor needs to know ahead of time
    which one to copy, but the prototype or cloning method does not need to do so instead
    it takes user's input and clone on the spot.

    Shallow Copy                    Deep Copy
    ============                    =========
    - Member-only copy              - Makes copies of reference objects

    Is it better to perform a shallow copy or a deep copy?
    ==> DEPENDS if the intent is to share the reference object or not.
    A. If the objects refer to a log file that both objects need to write to then a shallow copy is suffice
    B. If the reference object is a component of a more complex object then a deep copy is more appropriate

*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;


// Abstract Animal class
class Animal
{
protected:
    string _hairColor;
    int _hairLength, _tail, _weight, _height, _age, _intelligence, _stubbornness, _agressiveness;

public:
    virtual Animal * clone() {};

    int setHairLength(int length)
    {
        _hairLength = length;
    }
    void setHairColor(string color)
    {
        _hairColor = color;
    }
    void setTail(int length)
    {
        _tail = length;
    }
    void setWeight(int kg)
    {
        _weight = kg;
    }
    void setHeight(int m)
    {
        _height = m;
    }
    void setAge(int age)
    {
        _age = age;
    }
};


// Sheep class inherit from Animal
class Sheep : public Animal
{
public:
    Sheep()
    {
        _hairLength = 5;
        _stubbornness = 3;
        _agressiveness = 2;
        _intelligence = 7;
    }
    // Constructor OVERLOADING
    Sheep(string hairColor, int tail, int weight, int height, int age)
    {
        _hairColor = hairColor;
        _tail = tail;
        _weight = weight;
        _height = height;
        _age = age;

        _hairLength = 5;
        _stubbornness = 3;
        _agressiveness = 2;
        _intelligence = 7;
    }
    Sheep *clone()
    {
        return new Sheep(* this);
    }
    void shearing()
    {
        _hairLength -= 2;
    }
};


// Cow class inherit from Animal
class Cow : public Animal
{
public:
    Cow()
    {
        _stubbornness = 6;
        _agressiveness = 5;
        _intelligence = 8;
    }
    Cow(string color, int tail, int weight, int height, int age)
    {
        _hairColor = color;
        _tail = tail;
        _weight = weight;
        _height = height;
        _age = age;

        _stubbornness = 6;
        _agressiveness = 5;
        _intelligence = 8;
    }
    Cow * clone()
    {
        return new Cow(* this);
    }
};


int main(int argc, char ** argv)
{
    // Create initial instance of a Sheep
    Sheep * sheep0 = new Sheep("white", 5, 90, 1, 5);
    /* You may also use the setter function, but I find it troublesome */
	// sheep0->setHairColor("white");
	// sheep0->setTail(5);
	// sheep0->setWeight(90);
	// sheep0->setHeight(1);
	// sheep0->setAge(5);

    // Create initial instance of a Cow
    Animal * cow0 = new Cow("brown", 20, 790, 2, 8);
    /* You may also use the setter function, but I find it troublesome */
	// cow0->setHairColor("brown");
	// cow0->setTail(20);
	// cow0->setWeight(790);
	// cow0->setHeight(2);
	// cow0->setAge(8);

    // Using cloning method to populate the farm
    vector<Animal *> farm {};
    farm.push_back(sheep0->clone());
    farm.push_back(cow0->clone());

    // Adjust property
    // Note that if sheep0 is a Animal object, it will not has the shearing method
    // Like the cow which does not have any special method using Animal base class
    // for cow0 will do fine
    sheep0->shearing();
    farm[1]->setWeight(1000);

    farm.push_back(sheep0->clone());

    return 0;
}