#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

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
        cout << "The GCD for Euclid's Original Algorithm is: " << gcd << endl << endl;
    }
    else {
        cout << "The GCD for Euclid's Original Algorithm is: 0" << endl << endl;
    }
}

void originalEuclid100(int a[100], int b[100], int length) {

    int remainder, quotient;
    double msecs1, msecs2;
    clock_t start1, end1, start2, end2;
    ofstream myFile ("100Euclid.csv");
    if (myFile.is_open()){                      //if the file to save the results in will open
        for (int i = 0; i <= length; i++) {     //i starts at 0 and goes until the length of what is passed in
            do {
                if ((a[i] || b[i]) >= 1){
                    start1 = clock();
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
                    } while (remainder != 0);
                    cout << "The GCD for Euclid's Original Algorithm is: " << a[i] << endl;
                    myFile << "The GCD for Euclid's Original Algorithm is: " << a[i] << endl;
                    end1 = clock();
                    msecs1 = ((double) (end1 - start1)) * 1000 / CLOCKS_PER_SEC;
                    cout << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    i++;
                }
                else {
                    start2 = clock();
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    cout << "The GCD for Euclid's Original Algorithm is: 0" << endl;
                    myFile << "The GCD for Euclid's Original Algorithm is: 0" << endl;
                    end2 = clock();
                    msecs2 = ((double) (end2 - start2)) * 1000 / CLOCKS_PER_SEC;
                    cout << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
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
    if ((a >= b) && (b > 0)) {
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
        cout << "The GCD of Euclid's Improved Algorithm is: " << a << endl;
    }
    else {
        cout <<"The inputs do not successfully pass the precursor. (a >=b)" << endl;
    }
}

void improvedEuclid100(int a[100], int b[100], int length){
    int remainder;
    double msecs1, msecs2;
    clock_t start1, end1, start2, end2, start3, end3, msecs3;
    ofstream myFile ("100improvedEuclid.csv");

    if (myFile.is_open()){
        for (int i = 0; i <= length; i++) {
            do {

                if ((a[i] >= b[i]) && (b[i] > 0)) {
                    start1 = clock();
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    do {
                        remainder = a[i] - b[i];
                        if (remainder > b[i]) {
                            remainder = (remainder - b[i]);
                            if (remainder > b[i]) {
                                remainder = (remainder - b[i]);
                                if (remainder > b[i]) {
                                    remainder = (a[i] - (b[i] * (a[i] / b[i])));
                                }
                            }
                        }
                        a[i] = b[i];
                        b[i] = remainder;
                    } while (remainder != 0);
                    cout << "The GCD of Euclid's Improved Algorithm is: " << a[i] << endl;
                    myFile << "The GCD of Euclid's Improved Algorithm is: " << a[i] << endl;
                    end1 = clock();
                    msecs1 = ((double) (end1 - start1)) * 1000 / CLOCKS_PER_SEC;
                    cout << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    i++;
                }
                else if ((b[i] >= a[i]) && (a[i] > 0)) { // if b is greater from previous if statement, a and b switched utilizing Improved algorithm
                    start2 = clock();
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    cout << "The current value for a: " << a[i] << endl; // cout the current randomly generated value for a
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl; // cout the current randomly generated value for b
                    myFile << "The current value for b: " << b[i] << endl;
                    do { // Improved Euclid algorithm with a and b switched from previously
                        remainder = b[i] - a[i];
                        if (remainder > a[i]) {
                            remainder = (remainder - a[i]);
                            if (remainder > a[i]) {
                                remainder = (remainder - a[i]);
                                if (remainder > a[i]) {
                                    remainder = (b[i] - (a[i] * (b[i] / a[i])));
                                }
                            }
                        }
                        b[i] = a[i];
                        a[i] = remainder;
                    } while (remainder != 0);
                    cout << "The GCD of Euclid's Improved Algorithm is: " << b[i] << endl;
                    myFile << "The GCD of Euclid's Improved Algorithm is: " << b[i] << endl;
                    end2 = clock(); // end time
                    msecs2 = ((double) (end2 - start2)) * 1000 / CLOCKS_PER_SEC; // needed to calculate milliseconds
                    cout << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
                    i++; // incrementing for the for loop
                }
                else {
                    start3 = clock();
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    cout << "The GCD of Euclid's Improved Algorithm is: 0" << endl;
                    myFile << "The GCD of Euclid's Improved Algorithm is: 0" << endl;
                    end3 = clock();
                    msecs3 = ((double) (end3 - start3)) * 1000 / CLOCKS_PER_SEC;
                    cout << "The time it takes is: " << msecs3 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs3 << " milliseconds" << endl << endl;
                    i++;
                }
            } while (i <=99);
            //end = clock();
        }
        myFile.close();
    } else {
        cout << "Could not open the file" << endl;
    }

}

void assignment1(){
    static int randomA[100], randomB[100], randomA_copy[100], randomB_copy[100], randomA_copy1[100], randomB_copy1[100];
    char answer;

    for (int i = 0; i <= 99; ++i){
        randomA[i] = rand() % 100 + 0;
        randomB[i] = rand() % 100 + 0;
    }

    cout << "Would you like to view the random numbers? (y/n): " ;
    cin >> answer;
    cin.ignore();
    cout << endl;
    while (answer) {
        switch (answer) {

            case 'n':
                break;

            case 'y':

                for (int i = 0; i <= 99; ++i){
                    cout << "a" << i <<" is: " << randomA[i];
                    cout << setw(10) << "b" << i <<" is: " << randomB[i];
                    cout << endl;
                }
                break;

            default:
                break;
        };
        break;
    }
    memcpy(&randomA_copy, &randomA, sizeof(randomA));
    memcpy(&randomB_copy, &randomB, sizeof(randomB));
    memcpy(&randomA_copy1, &randomA, sizeof(randomA));
    memcpy(&randomB_copy1, &randomB, sizeof(randomB));
    originalEuclid100(randomA_copy, randomB_copy, 100);
    cout << endl << "****IMPROVED****" << endl << endl;
    improvedEuclid100(randomA_copy1, randomB_copy1, 100);
}

/*
 *merge takes a list and points to the start of it I THINK>!!?#
 * low = 0
 * high changes to merge sorted list
 */
void merge(int *arr, int low, int high) {
    //mid = the floor value of the half the # of elements in the list
    int mid = floor((low + high)/2);
    //these are temporary values to fill the array
    int t1 = 0, t2 = low, t3 = mid + 1;

    //creating a temp array the length of high - low + 1
    int temp[high - low + 1];

    //while loop t2 = low value & t3 = mid + 1
    //high = the highest value of the smallest list (remember, we are merging here)
    while (t2 <= mid && t3 <= high) {
        //if the value at t2 in arr is < value at t3 in arr
        if (arr[t2] < arr[t3]) {
            //t1++ in temp is set to the value of t2++ in arr
            temp[t1++] = arr[t2++];
        }
        //if the value at t2 in arr is > or = the value of t2 in arr
        else {
            //the value of t1++ of temp is set to the value of t3++ in arr
            temp[t1++] = arr[t3++];
        }
    } //end while

    //while the value of t2 <= mid
    //int mid = floor((low + high)/2);
    //pretty sure this is merging the left side of the array
    while (t2 <= mid) {
        //update t1 in temp to t2 in arr until exit condition
        temp[t1++] = arr[t2++];
    }

    //while the value of t3 <= high
    //high is passed in value
    while (t3 <= high) {
        //update temp t1 from temp t3 value until exit condition
        temp[t1++] = temp[t3++];
    }

    //replace the temp values into the original array
    //this is the value that is returned to be printed
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }

}

/*
 * mergesort receives an int and points to the beginning of it I THINK
 * int low is always 0
 * int high is the max amount in the list
 */
void mergeSort(int *arr, int low, int high){
    //if there is more than one element in the list
    if (low < high) {
        //take the floor value of the # of elements in the array / 2 and name it mid
        int mid = floor((low + high) / 2);
        //call mergeSort using the new name of the list (arr) with low = 0 and mid = half the array size
        mergeSort(arr, low, mid);
        //call mergeSort using the same list with low = 0 and mid = 2 (if original high = 9), and high = previous mid
        mergeSort(arr, mid + 1, high);
        //call merge passing the list and the low = 0 and high = 4
        merge(arr, low, high);
    }

}

void assignment2(){

    //creating a list of 10 elements
    int list1[10] = {900, 300, 400, 500, 200, 100, 550, 700, 1000, 2000};

    cout << "List 1 is as stated unsorted: ";
    //printing the unsorted list1
    for (int i=0; i<=9; i++){
        cout << list1[i] << " ";
    }
    cout << endl;

    //calling mergesort with params (array, low, high)
    mergeSort(list1, 0, 9);

    cout << "List 1 is as stated sorted: ";
    //print sorted list1
    for (int i=0; i<=9; i++){
        cout << list1[i] << " ";
    }
    cout << endl << endl;

}



void menu() {
    int input;
    cout << "*CSC 332*\n"
         << "*MENU OPTIONS*\n\n";
    cout << "1 - Fibonacci Exercise\n"
         << "2 - Euclid's Original Algorithm\n"
         << "3 - Euclid's Improved Algorithm\n"
         << "4 - Programming Assignment 1\n"
         << "5 - Programming Assignment 2\n"
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
                break;
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
                assignment1();
                returnMenu();
                break;
            case 5:
                assignment2();
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
