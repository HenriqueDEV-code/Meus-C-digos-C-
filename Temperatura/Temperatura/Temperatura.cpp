
#include "pch.h"
#include <iostream>

using namespace std;

float Convert(float);




int main()
{
    float TempFer;
    float TempCel;

    cout << "Please enter the temperature in Fahrenheit: ";
    cin >> TempFer;

    TempCel = Convert(TempFer);

    cout << "\nHere's the temperature in Celsius: ";
    cout << TempCel << endl;
    return 0;

}

// Função para converter Fer para Cel
float Convert(float TempFer) {
    float TempCel;

    TempCel = ((TempFer - 32) * 5) / 9;
    return TempCel;
}
