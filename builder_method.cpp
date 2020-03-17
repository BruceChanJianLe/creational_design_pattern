/*  Builder Design Pattern

    - Separates construction of complex objects
    - Same construction process for different representation

    Builders share the same *step* to build an object, but objects that are being built can vary.

*/


#include <iostream>
#include <string>


using namespace std;


#pragma region Entrees
// Base Entree Class
class Entree
{
protected:
    string _entree;
public:
    const string getEntree()
    {
        return _entree;
    }
};


// Burger class inherit from Entree
class Burger : public Entree
{
public:
    Burger()
    {
        _entree = "hamburger";
        cout << "\nGrill burger patty, add tomatoes and ";
        cout << " place them in a bun" << endl;
    }
};


// Hotdog class inherit from Entree
class Hotdog : public Entree
{
public:
    Hotdog()
    {
        _entree = "hotdog";
        cout << "\nCook sausage and place it in a bun" << endl;
    }
};
#pragma endregion Entrees

#pragma region Sides
// Base Side class
class Side
{
protected:
    string _side;
public:
    const string getSide()
    {
        return _side;
    }
};


// Fries class inherit from Side
class Fries : public Side
{
public:
    Fries()
    {
        _side = "fries";
        cout << "Fry and season potatoes" << endl;
    }
};


// Salad class inherit from Side
class Salad : public Side
{
public:
    Salad()
    {
        _side = "salad";
        cout  << "Toss greens and dressing together" << endl;
    }
};
#pragma endregion Sides


// Drink class
class Drink
{
protected:
    string _drink;
public:
    Drink()
    {
        _drink = "soda";
        cout << "Fill cup with soda" << endl;
    }
    const string getDrink()
    {
        return _drink;
    }
};


// Complex MealCombo object that contains an Entree, a Side and a Drink object
class mealCombo
{
private:
    Entree * entree;
    Side * side;
    Drink * drink;
    string _bag;
public:
    mealCombo(const string user_input)
    {
        _bag = user_input + " meal combo:";
    }
    void setEntree(Entree * e)
    {
        entree = e;
    }
    void setSide(Side * s)
    {
        side = s;
    }
    void setDrink(Drink * d)
    {
        drink = d;
    }
    const string openMealBag()
    {
        _bag += " " + entree->getEntree() + ", " + side->getSide() + ", " + drink->getDrink();
        return _bag;
    }
};


#pragma region Builders
// Base Builder
class mealBuilder
{
protected:
    mealCombo * _meal;
public:
    virtual void cookEntree() {};
    virtual void cookSide() {};
    virtual void fillDrink() {};
    mealCombo * getMeal()
    {
        return _meal;
    }
};


// Concrete Builder for a Burger Meal which has a burger, fries and drink object
class BurgerMeal : public mealBuilder
{
public:
    BurgerMeal()
    {
        _meal = new mealCombo("burger");
    }
    void cookEntree()
    {
        Entree * burger = new Burger;
        _meal->setEntree(burger);
    }
    void cookSide()
    {
        Side * fries = new Fries;
        _meal->setSide(fries);
    }
    void fillDrink()
    {
        Drink * drink = new Drink;
        _meal->setDrink(drink);
    }
};
// Concrete Builder for a Hotdog Meal which has a hotdog, salad and drink object
class HotdogMeal : public mealBuilder
{
public:
    HotdogMeal()
    {
        _meal = new mealCombo("hotdog");
    }
    void cookEntree()
    {
        Entree * hotdog =  new Hotdog;
        _meal->setEntree(hotdog);
    }
    void cookSide()
    {
        Side * salad = new Salad;
        _meal->setSide(salad);
    }
    void fillDrink()
    {
        Drink * drink = new Drink;
        _meal->setDrink(drink);
    }
};

#pragma endregion Builders


int main(int argc, char ** argv)
{
    // Prompt user for meal selection
    mealBuilder * cook = new mealBuilder;
    mealCombo * meal;
    int choice;

    cout << "Select a meal:" << endl;
    cout << "1. Burger Meal" << endl << "2. Hotdog Meal" << endl;
    cout << "Selection: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cook = new BurgerMeal;
        break;
    case 2:
        cook = new HotdogMeal;
        break;
    default:
        cout << "Invalid selection!" << endl;
        cook = NULL;
        break;
    }

    if(cook != NULL)
    {
        cook->cookEntree();
        cook->cookSide();
        cook->fillDrink();
        meal = cook->getMeal();

        cout << meal->openMealBag() << endl;
    }
    
    return 0;
}