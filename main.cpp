/*
Created by Evan Ungles on 2/10/2026 for the Variable Assignment in the Technology Solutions course.
This program starts with a box volume calculator, then the user can choose between 3 different cost calculators:
A calculator for the cost of a pizza
A calculator for the cost of a car trip
A calculator for the cost of a recipe
*/

/*
C++ data type examples:

Character: stores one character
    char varName = 'T';

String: stores text
    string varName = "text";

Integer: stores a whole number
    int varName = 1;

Float: stores a number with a decimal (32 bits)
    float varName = 1.2;

Double: stores a number with a decimal (64 bits)
    double varName = 1.2;

Boolean: stores a number with a decimal (32 bits)
    bool varName = true;

Array: stores several values of a given data type (the number of elements can't be changed)
    int varName[3] = {1, 2, 3};
*/



#include <iostream>
using namespace std;

void boxCalc() {
    cout << "\nFirst, we will calculate the volume of your favorite box!" << endl;

    string name;
    cout << "What is your box's name?" << endl;
    getline(cin, name);

    float length, width, height;
    cout << "What is " << name << "'s length?" << endl;
    cin >> length;
    cout << "What is " << name << "'s width?" << endl;
    cin >> width;
    cout << "What is " << name << "'s height?" << endl;
    cin >> height;

    float volume = length * width * height;
    cout << name << " has a volume of " << volume << endl;
}

void pizzaOrderCalc() {
    //Stores pizza size, number of toppings, delivery fee, and tip amount. Then, calculates the total bill.

    int size, numToppings;
    cout << "What size in inches ($1.00 per inch)?" << endl;
    cin >> size;
    cout << "How many toppings ($1.50 per topping)?" << endl;
    cin >> numToppings;

    float deliveryFee, tipAmount;
    cout << "What is the delivery fee?" << endl;
    cin >> deliveryFee;
    cout << "What percentage do you plan to tip?" << endl;
    cin >> tipAmount;

    float totalCost = (size + (1.5*numToppings) + deliveryFee) * (tipAmount/100.0 + 1);
    cout << "Your pizza will cost $" << totalCost;
}

void carTripCalc() {
    //Stores distance, car's miles per gallon, gas price per gallon, and toll costs. Then, calculates total trip cost.

    float distance, milesPerGallon, pricePerGallon, tollCosts;
    cout << "How many miles will you travel?" << endl;
    cin >> distance;
    cout << "How many miles per gallon does your car get?" << endl;
    cin >> milesPerGallon;
    cout << "What is the price per gallon?" << endl;
    cin >> pricePerGallon;
    cout << "What is the cost from tolls?" << endl;
    cin >> tollCosts;

    float gasCost = (distance/milesPerGallon) * pricePerGallon;
    float totalCost = gasCost + tollCosts;
    cout << "Your trip will cost $" << totalCost;
}

void recipeCostCalc() {
    //Stores ingredient names and costs for a simple recipe. Then, calculates the total cost to make the dish.

    int numIngredients;
    cout << "How many ingredients are in the recipe?" << endl;
    cin >> numIngredients;

    string ingredientList;
    float totalCost;

    for (int i = 1; i <= numIngredients; i++) {
        cin.ignore();

        string ingredient;
        cout << "What is the name of ingredient #"<<i<<"?" << endl;
        getline(cin, ingredient);

        if (numIngredients > 2 && i != 1) {
            ingredientList += ",";
        }
        if (i == numIngredients && numIngredients >= 2) {
            ingredientList += " and";
        }
        ingredientList += " " + ingredient;



        float cost;
        cout << "How much does " << ingredient << " cost?" << endl;
        cin >> cost;

        totalCost += cost;
    }

    cout << "Your recipe with" << ingredientList << " will cost $" << totalCost;
}

int main() {
    boxCalc();

    int requestedCalc;
    cout << "\n\nEnter the number for the calculator you would like to use:" << endl;
    cout << "1. Pizza Order Calculator\n2. Car Trip Calculator\n3. Recipe Cost Calculator" << endl;
    cin >> requestedCalc;

    cout << endl;

    if (requestedCalc == 1) {
        pizzaOrderCalc();
    }
    else if (requestedCalc == 2) {
        carTripCalc();
    }
    else {
        recipeCostCalc();
    }

    cout << endl;
}