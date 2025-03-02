#include <iostream>
using namespace std;

void convertTemperature() {
    double celsius, fahrenheit;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    fahrenheit = (celsius * 9/5) + 32;
    cout << "Temperature in Fahrenheit: " << fahrenheit << "°F\n";
}

void convertLength() {
    double meters, feet;
    cout << "Enter length in meters: ";
    cin >> meters;
    feet = meters * 3.28084;
    cout << "Length in feet: " << feet << " ft\n";
}

void convertWeight() {
    double kilograms, pounds;
    cout << "Enter weight in kilograms: ";
    cin >> kilograms;
    pounds = kilograms * 2.20462;
    cout << "Weight in pounds: " << pounds << " lbs\n";
}

int main() {
    int choice;
    do {
        cout << "\n========================\n";
        cout << "  UNIT CONVERTER  \n";
        cout << "========================\n";
        cout << "1. Convert Temperature (Celsius to Fahrenheit)\n";
        cout << "2. Convert Length (Meters to Feet)\n";
        cout << "3. Convert Weight (Kilograms to Pounds)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input! Please enter a valid choice.\n";
            continue;
        }
        cout << "\n";
        switch (choice) {
            case 1: convertTemperature(); break;
            case 2: convertLength(); break;
            case 3: convertWeight(); break;
            case 4: cout << "Exiting the program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
