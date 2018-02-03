#include <iostream>
#include <math.h>
#include <stdlib.h> //included for rand
#include <time.h> //included for time
#include <fstream>
#include <ctime>

using namespace std;

void menu(), returnMenu(), choice(int input);





void Fibonacci() {
    int n, logResult, decResult;
    double t1 = 0, t2 = 1, nextTerm = 0, finalTerm;
    cout << "Enter a value for n to be calculated ";
    cin >> n;
    cout << "The Fibonacci Series of " << n << " is: ";

    for (int i = 1; i <= n; ++i)
    {
        // Prints the first two terms
        if(i == 1)
        {
            cout << " " << t1 << " ";
            continue;
        }
        if(i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        finalTerm = nextTerm;
        cout << nextTerm << " ";
    }
    cout << endl << endl << "The number passed through log base 2 is " << finalTerm << endl;
    cout << "The number passed through n-1 is " << n << endl << endl;
    logResult = log2(finalTerm);
    decResult = (n-1);
    cout << "Log base 2 of " << finalTerm << " is " << logResult << endl;
    cout << "N-1 of " << n << " is " << decResult << endl << endl;
}

void originalEuclid(){
    int a, b, remainder, quotient, gcd;
    cout << "Please input an integer value for a: ";
    cin >> a;
    cout << "Please input an integer value for b: ";
    cin >> b;

    if ((a && b) >= 1){
        /*cout << "The current value for a: " << a << endl; //debug cout
        cout << "The current value for b: " << b << endl;*/
        do {
            quotient = (a / b);
            remainder = (a - quotient * b);
            a = b;
            b = remainder;
            gcd = a;
        } while (remainder != 0);
        cout << "The GCD for Euclid's Original Algorithm is: " << gcd << endl;
    }
    else {
        cout << "The GCD for Euclid's Original Algorithm is: 0" << endl << endl;
    }
}

void originalEuclid100(int a, int b) {
    //int a, b;

    int remainder, quotient, gcd;
    double msecs;
    clock_t start, end;
    ofstream myFile ("100Euclid.csv");
    if (myFile.is_open()){
        for (int i = 0; i <= 100; ++i) {
            start = clock();
            //a = rand() % 100 + 1;
            //b = rand() % 99 + 1;
            if ((a || b) >= 1){
                cout << i << ". " << endl;
                myFile << i << ". " << endl;
                cout << "The current value for a: " << a << endl;
                myFile << "The current value for a: " << a << endl;
                cout << "The current value for b: " << b << endl;
                myFile << "The current value for b: " << b << endl;
                do {
                    quotient = (a / b);
                    remainder = (a - quotient * b);
                    a = b;
                    b = remainder;
                    gcd = a;
                } while (remainder != 0);
                cout << "The GCD for Euclid's Original Algorithm is: " << gcd << endl;
                myFile << "The GCD for Euclid's Original Algorithm is: " << gcd << endl;
                end = clock();
                msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                cout << "The time it takes is: " << msecs << " milliseconds" << endl << endl;
                myFile << "The time it takes is: " << msecs << " milliseconds" << endl << endl;
            }
            else {
                cout << "The GCD for Euclid's Original Algorithm is: 0" << endl << endl;
                myFile << "The GCD for Euclid's Original Algorithm is: 0" << endl << endl;
            }
        }
        myFile.close();
    }
}

void improvedEuclid() {
    int a, b, remainder;
    cout << "Please input a integer value for a: ";
    cin >> a;
    cout << "Please input a integer value for b: ";
    cin >> b;

    if (a >= b > 0) {
        do {
            remainder = a - b;
            if (remainder > b) {
                remainder = (remainder - b);
                if (remainder > b) {
                    remainder = (remainder - b);
                    if (remainder > b) {
                        remainder = (a - (b * (a / b)));
                    }
                }
            }
            a = b;
            b = remainder;
        } while (remainder != 0);
        cout << "The GCD of Euclid's Advanced Algorithm is: " << a << endl;
    }
    else {
        cout <<"The inputs do not successfully pass the precursor. (a >=b)" << endl;
    }
}

void improvedEuclid100(){

}



void random100Numbers(){
    static int randomA[100], randomB[100];
    int a, b, i = 0;
    for (int i = 0; i <= 99; ++i){
        randomA[i] = rand() % 100 + 0;
        randomB[i] = rand() % 100 + 0;
        cout << "The random value for a" << i <<" is: " << randomA[i] << endl;
        cout << "The random value for b" << i <<" is: " << randomB[i] << endl;
    }
    cout << endl;
    while (i <= 100) {
        a = randomA[i];
        b = randomB[i];
        i++;
        originalEuclid100(a, b);
    }
    cout << "the fucking value of i: " << i;


}




void menu() {
    int input;
    cout << "*CSC 332*\n"
         << "*MENU OPTIONS*\n\n";
    cout << "1 - Fibonacci Exercise\n"
         << "2 - Euclid's Original Algorithm\n"
         << "3 - Euclid's Improved Algorithm\n"
         << "4 - Euclid's Original 100 Times\n"
         << "5 - Random Numbers\n"
         << "9 - Terminate Program\n\n";
    cout << "Enter a menu option: ";
    cin >> input;
    cin.ignore();
    cout << endl;
    choice(input);
}

void returnMenu() {
    char input;
    cout << "Return to Main Menu? (y/n)\n";
    cin >> input;
    cout << endl;
    while (input) {
        switch (input) {
            case 'y':
                menu();
                break;

            case 'n':
                break;

            default:
                cout << "Invalid Input. Returning to main menu.\n";
                menu();
        }
        break;
    }
}

void choice(int input) {
    while (input) {
        switch (input) {
            case 1:
                Fibonacci();
                returnMenu();
                break;
            case 2:
                originalEuclid();
                returnMenu();
                break;
            case 3:
                improvedEuclid();
                returnMenu();
                break;
            case 4:
                //originalEuclid100();
                returnMenu();
                break;
            case 5:
                random100Numbers();
                returnMenu();
                break;
            case 9:
                exit(1);
            default:
                cout << "Invalid Menu Option. Please enter new option: ";
                cin >> input;
                choice(input);
                cin.ignore();
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}