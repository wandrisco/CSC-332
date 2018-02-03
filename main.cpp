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

void originalEuclid100(int a[100], int b[100], int length) {
    //int a, b;

    int remainder, quotient;
    double msecs;
    clock_t start, end;
    ofstream myFile ("100Euclid.csv");
    if (myFile.is_open()){                      //if the file to save the results in will open
        for (int i = 0; i <= length; i++) {     //i starts at 0 and goes until the length of what is passed in
            start = clock();
            //a = rand() % 100 + 1;
            //b = rand() % 99 + 1;

            do {
                if ((a[i] || b[i]) >= 1){
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    do {
                        quotient = (a[i] / b[i]);
                        remainder = (a[i] - quotient * b[i]);
                        a[i] = b[i];
                        b[i] = remainder;
                        //gcd[i] = a[i];
                    } while (remainder != 0);
                    cout << "The GCD for Euclid's Original Algorithm is: " << a[i] << endl;
                    myFile << "The GCD for Euclid's Original Algorithm is: " << a[i] << endl;
                    end = clock();
                    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    cout << "The time it takes is: " << msecs << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs << " milliseconds" << endl << endl;
                    i++;
                }
                else {
                    start = clock();
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    cout << "The GCD for Euclid's Original Algorithm is: 0" << endl << endl;
                    myFile << "The GCD for Euclid's Original Algorithm is: 0" << endl << endl;
                    end = clock();
                    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    cout << "The time it takes is: " << msecs << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs << " milliseconds" << endl << endl;
                    i++;
                }
            } while (i <= 99);
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

/*
 * RANDOM100NUMBERS fills two arrays with random ints and passes into euclidoriginal100
 * for some reason, when passing the values, only passing the first elements of the arrays into euclidoriginal100
 */

void random100Numbers(){
    static int randomA[100], randomB[100];
    int a[100], b[100], i = 0;

    for (int i = 0; i <= 99; ++i){
        randomA[i] = rand() % 100 + 0;
        randomB[i] = rand() % 100 + 0;
        cout << "The random value for a" << i <<" is: " << randomA[i] << endl;
        cout << "The random value for b" << i <<" is: " << randomB[i] << endl;
    }
    cout << endl;
    while (i <= 100) {
        a[i] = randomA[i];
        b[i] = randomB[i];
        //cout << "random a: " << randomA[55];
        originalEuclid100(randomA, randomB, 100);
        //i++;
    }
}



/*
 * this is displayed when main is ran.
 * the CHOICE function coordinates with the menu function.
*/
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
/*
 * RETURNMENU ask the user if they would like to return to the MENU function
 * if the user hits N, the function is repeated
 */
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

/*
 * this coordinates with the MENU function
 * case 'x' means that is the key you enter to call that function
 */
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
    menu(); //this calls the menu function, which displays the possible menu options
    return 0;
}