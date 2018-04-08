#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <random>

using namespace std;

void menu(), returnMenu(), choice(int input);

void printArray(int arr[], int length) {
    for (int i = 0; i <= length; i++) {
        cout << arr[i] << " ";
    }
}

void printVector(vector <int> vect) {
    for (int i = 0; i <= vect.size(); i++){

        cout << vect[i] << " ";
    }
}

int *createList(int *list(), int sizeList) {
    char choice;
    cout << "Would you like to view the lists? (y/n)" << endl;
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 'y':
            //creates the list
            for (int i = 1; i <= sizeList; i++) {
                int *p;
                //p is set to the value that randomArray returns
                p = list();
                //prints the list
                cout << i << ": ";
                printArray(p, sizeList);
                cout << endl << endl;
            }
            break;
        case 'n':
            for (int i = 1; i <= sizeList; i++) {
                int *p;
                //p is set to the value that randomArray returns
                p = list();
            }
            break;

    } //end nested Switch for choice y
}

void lineBreak() {
    cout << endl << endl;
}

/*
 * function: Fibonacci()
 * purpose: to perform the fib series n iterations
 */
void Fibonacci() {
    int n, logResult, decResult;
    /*
     * int values
     * n = number of iterations
     * logresult = log result
     * decResult = n-1 result for comparison
     */
    double t1 = 0, t2 = 1, nextTerm = 0, finalTerm;
    /*
     * double values
     * temporary values t1 = 0 so we start at 0 & t2 = 1 so the next value is 1
     * nextTerm = 0 is just initialized and a place holder
     * finalTerm holds the last term it calcualates so we know the final value
     *
     */
    cout << "Enter a value for n to be calculated ";
    //n = number of iterations for the fib series
    cin >> n;
    cout << "The Fibonacci Series of " << n << " is: ";
    //starts the fib series
    for (int i = 1; i <= n; ++i) {
        //print 0
        if (i == 1) {
            cout << " " << t1 << " ";
            continue;
        }
        //print 1
        if (i == 2) {
            cout << t2 << " ";
            continue;
        }
        //officially starts the fib series
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        //sets the last nextTerm to finalTerm so we can use it to calculate values
        finalTerm = nextTerm;
        //prints the series
        cout << nextTerm << " ";
    }
    //prints comparison output
    cout << endl << endl << "The number passed through log base 2 is " << finalTerm << endl;
    cout << "The number passed through n-1 is " << n << endl << endl;
    //uses log base 2 with finalTerm value
    logResult = log2(finalTerm);
    //n-1 result for comparison to log base 2 value
    decResult = (n - 1);
    //prints the results
    cout << "Log base 2 of " << finalTerm << " is " << logResult << endl;
    cout << "N-1 of " << n << " is " << decResult << endl << endl;
}

/*
 * function: originalEuclid()
 * purpose: user enters two values and the gcd is found
 * using the original Euclid method
 */
void originalEuclid() {
    int a, b, remainder, quotient, gcd;
    /*
     * int values
     * a & b are the two values to find the gcd
     * remainder is the remainder between divisions
     * gcd is the gcd
     */
    cout << "Please input an integer value for a: ";
    cin >> a;
    cout << "Please input an integer value for b: ";
    cin >> b;
    //starts the original euclid method
    if ((a && b) >= 1) {
        //debug output to make sure program enters
        /*cout << "The current value for a: " << a << endl;
        cout << "The current value for b: " << b << endl;*/

        do {
            quotient = (a / b);
            remainder = (a - quotient * b);
            a = b;
            b = remainder;
            gcd = a;
        } while (remainder != 0);
        cout << "The GCD for Euclid's Original Algorithm is: " << gcd << endl << endl;
    } else {
        cout << "The GCD for Euclid's Original Algorithm is: 0" << endl << endl;
    }
}

/*
 * function: originalEuclid100
 * purpose: runs the original euclid method 100 times with an array of 100 random values from 0-100
 * and takes the time of how long it takes to calculate each gcd = 100 different times
 * takes the array a of 100 elements and array b of 100 elements
 * takes the length of 100 (used as overall length)
 */
void originalEuclid100(int a[100], int b[100], int length) {
    int remainder, quotient;
    //remainder is the remainder throughout divisions
    //quotient is the quotient throughout divisions
    double msecs1, msecs2;
    //double value because this is a very small decimal value
    //msecs1 is the sta

    clock_t start1, end1, start2, end2;
    /*
     * clock_t uses the clock to keep time
     * using any variables i created start1 for the start1 for the if statements and start 2 for the else
     * end1 for ifs and end2 for else
    */

    //ofstream creates the variable myFile and names it on the computer "100Euclid.csv"
    //csv is an uneditable?iThink? excel file
    ofstream myFile("100Euclid.csv");
    if (myFile.is_open()) {                      //if the file to save the results in will open
        for (int i = 0; i <= length; i++) {     //i starts at 0 and goes until the length of what is passed in
            do {
                //if the element value at a or b of i is >= 1
                if ((a[i] || b[i]) >= 1) {
                    //clock() is started and is set to start1 clock_t value (seconds?)
                    start1 = clock();
                    //prints the current iteration to the console and to the file
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    //prints the beginning value of a and b to the console and to the file
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    //performs euclids original algorithm for the current value of i in array a and b
                    do {
                        quotient = (a[i] / b[i]);
                        remainder = (a[i] - quotient * b[i]);
                        a[i] = b[i];
                        b[i] = remainder;
                    } while (remainder != 0);
                    //prints the gcd value of i to the console and the file
                    cout << "The GCD for Euclid's Original Algorithm is: " << a[i] << endl;
                    myFile << "The GCD for Euclid's Original Algorithm is: " << a[i] << endl;
                    //clock() ends the counting and sets that value to end1
                    end1 = clock();
                    //converts the time from seconds to milliseconds
                    msecs1 = ((double) (end1 - start1)) * 1000 / CLOCKS_PER_SEC;
                    //prints the time it took to the console and the file in milliseconds
                    cout << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    //increments i in all cases
                    i++;
                }
                    //else loop to handle if prerequisites not met
                else {
                    //starts the clock and calls it start2...start2=0
                    start2 = clock();
                    //prints the current iteration to the console and the file
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    //prints the value of i in a and b to the console and the file
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    //since it did not meet the prerequisite the gcd could not be calculated and therefor 0
                    cout << "The GCD for Euclid's Original Algorithm is: 0" << endl;
                    myFile << "The GCD for Euclid's Original Algorithm is: 0" << endl;
                    //ends the clock and sets the value to end2
                    end2 = clock();
                    //converting from seconds to milliseconds and setting that value to msecs2
                    msecs2 = ((double) (end2 - start2)) * 1000 / CLOCKS_PER_SEC;
                    //prints the value of time it took to the console and file
                    cout << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
                    //increments i in all cases
                    i++;
                }
            } while (i <= 99); //performs the loop until the loop has been done 100 times. i started at 0.
        }
        myFile.close(); //closes the file because we are done with it
    }
}

/*
 * function: improvedEuclid()
 * purpose: takes user inputs a and b and runs the improved euclid method
 */
void improvedEuclid() {
    int a, b, remainder;
    //integer values of a, b and remainder

    //prints to the console for the user to input values
    cout << "Please input a integer value for a: ";
    cin >> a;
    cout << "Please input a integer value for b: ";
    cin >> b;
    //starts improved euclid method
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
        } while (remainder != 0);   //continues until the remainder is equal to 0
        //prints to the console the gcd of the algorithm
        cout << "The GCD of Euclid's Improved Algorithm is: " << a << endl;
    }
        //if prerequisite not met
    else {
        //print to the console that the prequisite was not met
        cout << "The inputs do not successfully pass the precursor. (a >=b)" << endl;
    }
}

/*
 * function: improvedEuclid100
 * purpose: runs the improved euclid method 100 times using random array values
 * takes the random array and calls it a of 100 elements, b of 100 elements, and the length of both arrays of 100 elements
 */
void improvedEuclid100(int a[100], int b[100], int length) {
    //remainder is an integer value
    int remainder;
    //double because milliseconds are small
    double msecs1, msecs2;
    //clock variables
    clock_t start1, end1, start2, end2, start3, end3, msecs3;

    //creates a variable myFile and uneditable excel file called "100improvedEuclid"
    ofstream myFile("100improvedEuclid.csv");
    //if the file opens
    if (myFile.is_open()) {
        //start at 0 and continue to the passed in length
        for (int i = 0; i <= length; i++) {
            do {
                //prerequisite
                if ((a[i] >= b[i]) && (b[i] > 0)) {
                    //clock starts at 0 and is called start1
                    start1 = clock();
                    //prints the current iteration to the console and the file
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    //prints the current value of i of a and b to the console and the file
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    //start the improved euclid algorithm
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
                    } while (remainder != 0); //loops until the remainder is equal to 0
                    //prints to the gcd to the console and the file
                    cout << "The GCD of Euclid's Improved Algorithm is: " << a[i] << endl;
                    myFile << "The GCD of Euclid's Improved Algorithm is: " << a[i] << endl;
                    //stops the clock and calls the time end1
                    end1 = clock();
                    //converts from seconds to milliseconds
                    msecs1 = ((double) (end1 - start1)) * 1000 / CLOCKS_PER_SEC;
                    //prints the time it took to the console and the file
                    cout << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs1 << " milliseconds" << endl << endl;
                    //iterates all instances of i
                    i++;
                } else if ((b[i] >= a[i]) && (a[i] >
                                              0)) { // if b is greater from previous if statement, a and b switched utilizing Improved algorithm
                    //starts the clock
                    start2 = clock();
                    //prints the current iteration to the console and file
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    //prints the current value of i in a and b to the console and the file
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
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
                    //prints the gcd to the console and the file
                    cout << "The GCD of Euclid's Improved Algorithm is: " << b[i] << endl;
                    myFile << "The GCD of Euclid's Improved Algorithm is: " << b[i] << endl;
                    end2 = clock(); // end time
                    //converts from seconds to milliseconds
                    msecs2 = ((double) (end2 - start2)) * 1000 / CLOCKS_PER_SEC;
                    //prints the time to the console and the file
                    cout << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs2 << " milliseconds" << endl << endl;
                    i++; // incrementing for the for loop
                }
                    //handles all other cases
                else {
                    //stars the clock
                    start3 = clock();
                    //prints the current iteration to the console and the file
                    cout << i << ". " << endl;
                    myFile << i << ". " << endl;
                    //prints the current value of i in a and b to the console and the file
                    cout << "The current value for a: " << a[i] << endl;
                    myFile << "The current value for a: " << a[i] << endl;
                    cout << "The current value for b: " << b[i] << endl;
                    myFile << "The current value for b: " << b[i] << endl;
                    //did not pass prerequisite, so gcd could not be calculated
                    cout << "The GCD of Euclid's Improved Algorithm is: 0" << endl;
                    myFile << "The GCD of Euclid's Improved Algorithm is: 0" << endl;
                    //ends the clock and calls it end3
                    end3 = clock();
                    //converts from seconds to milliseconds
                    msecs3 = ((double) (end3 - start3)) * 1000 / CLOCKS_PER_SEC;
                    //prints to the console and file the time
                    cout << "The time it takes is: " << msecs3 << " milliseconds" << endl << endl;
                    myFile << "The time it takes is: " << msecs3 << " milliseconds" << endl << endl;
                    //increments i
                    i++;
                }
            } while (i <= length); //does it until i equals the passed in length
        }
        //closes the file because we are done with it
        myFile.close();
    }
        //incase the file could not be opened on the users computer
    else {
        cout << "Could not open the file" << endl;
    }
}

/*
 * function: assignment1()
 * purpose: assignment 1 is the name for the function for PROGRAMMING ASSIGNMENT 1
 * its purpose is to run the entirety of what is outlined in programming assignment 1
 */
void assignment1() {
    static int randomA[100], randomB[100], randomA_copy[100], randomB_copy[100], randomA_copy1[100], randomB_copy1[100];
    //static so they are saved in RAM
    //made two copies of each so the original is never modified
    char answer;
    //char answer b/c i felt like asking the user if they wanted to view the random numbers

    //for loop fills randomA and randomB with 100 elements of integer values from 0-100
    for (int i = 0; i <= 99; ++i) {
        randomA[i] = rand() % 100 + 0;
        randomB[i] = rand() % 100 + 0;
    }

    //prompts the user if they would like to see the random numbers, they will be in excel anyways
    cout << "Would you like to view the random numbers? (y/n): ";
    cin >> answer;
    cin.ignore();
    cout << endl;
    //after the answer has been entered, the while loop activates
    while (answer) {
        //switch (answer) allows multiple cases, could be replaced with an IF statement, but this is easier
        switch (answer) {
            //if the user does not want to view the random array values
            case 'n':
                //break from the switch
                break;
                //if the user does want to view the random array values
            case 'y':
                //print the values
                for (int i = 0; i <= 99; ++i) {
                    cout << "a" << i << " is: " << randomA[i];
                    //setw(10) sets the width to 10 spaces, this allows the second array to be printed next to the first one
                    cout << setw(10) << "b" << i << " is: " << randomB[i];
                    cout << endl;
                }
                //break from the case
                break;

            default:
                break;
        };
        //reaches here when answer is n, and breaks from the while loop
        break;
    }
    //memcpy takes randomA, the sizeof randomA and copies it into randomA_copy
    memcpy(&randomA_copy, &randomA, sizeof(randomA));
    //memcpy takes randomB, the sizeof randomB and copies it into randomB_copy
    memcpy(&randomB_copy, &randomB, sizeof(randomB));
    //memcpy takes randomA, the sizeof randomA and copies it into randomA_copy1
    memcpy(&randomA_copy1, &randomA, sizeof(randomA));
    //memcpy takes randomB, the sizeof randomB and copies it into randomB_copy1
    memcpy(&randomB_copy1, &randomB, sizeof(randomB));

    //run the originalEuclid100 with the randomA_copy as int a[] and randomB_copy as int b[], and 100 is the length of both arrays
    originalEuclid100(randomA_copy, randomB_copy, 100);
    cout << endl << "****IMPROVED****" << endl << endl;
    //run the improvedEuclid100 with the randomA_copy1 as int a[] and randomB_copy1 as int b[], and 100 is the length of both arrays
    improvedEuclid100(randomA_copy1, randomB_copy1, 100);
}

/*
 *merge takes a list and points to the start of it I THINK>!!?#
 * low = 0
 * high changes to merge sorted list
 */
void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1, i, j, k;       /*n1 is the size of L[]*/
    int n2 = r - q;               /*n2 is the sixe of R[]*/
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }

    i = 0, j = 0;

    for (k = p; i < n1 && j < n2; k++) {
        if (L[i] < R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }

    while (i <
           n1) {             /*If L[] has more elements than R[] then it will put all the reamining elements of L[] into A[]*/
        A[k++] = L[i++];
    }

    while (j <
           n2) {         /*If R[] has more elements than L[] then it will put all the reamining elements of R[] into A[]*/
        A[k++] = R[j++];
    }
}

/*
 * mergesort receives an int and points to the beginning of it I THINK
 * int low is always 0
 * int high is the max amount in the list
 */
void mergeSort(int A[], int p, int r) {
    //if there is more than one element in the list
    int q;

    if (p < r) {
        q = (p + r) / 2;                      /*q is the middle element to divide the array*/
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int *randomArray(int arrSize, int numArr, int minRange, int maxRange) {

    //creates numArr amount of arrays
    for (int h = 1; h <= numArr; h++) {
        int *p;
        p = new int[arrSize];

        //fills the array
        for (int i = 0; i <= arrSize; i++) {
            p[i] = rand() % maxRange + minRange;
        }

        return p;
        //returns *p to whatever calls randomArray
    }
}

int *Array(int arrSize, int numArr) {

    //creates numArr amount of arrays
    for (int i = 1; i <= numArr; i++) {
        static int *p;
        p = new int [arrSize];

        cout << "Array " << i << endl;
        for (int j = 0; j <= arrSize; j++) {
            cout << "Element " << j << ": ";
            cin >> p[j];

        }
        cout << endl;

    }
}



void ArrayHandler() {

    char userInput;
    int arrSize;
    int numArr;
    int minRange;
    int maxRange;

    cout << "Would you like to create a Random list? (y/n)" << endl;
    cin >> userInput;
    cout << endl;

    switch (userInput) {
        case 'y':
            cout << "Number of Arrays: ";
            cin >> numArr;
            cout << "Array Size: ";
            cin >> arrSize;
            arrSize = arrSize - 1;
            cout << "Random Integer Min Range: ";
            cin >> minRange;
            cout << "Random Integer Max Range: ";
            cin >> maxRange;
            cout << endl;

            createList(randomArray, numArr);

/*            char choice;
            cout << "Would you like to view the lists? (y/n)" << endl;
            cin >> choice;
            cout << endl;

*//*            switch (choice) {
                case 'y':
                    //creates the list
                    for (int i = 1; i <= numArr; i++) {
                        int *p;
                        //p is set to the value that randomArray returns
                        p = randomArray(arrSize, numArr, minRange, maxRange);
                        //prints the list
                        cout << i << ": ";
                        printArray(p, arrSize);
                        lineBreak();
                    }
                    break;
                case 'n':
                    for (int i = 1; i <= numArr; i++) {
                        int *p;
                        //p is set to the value that randomArray returns
                        p = randomArray(arrSize, numArr, minRange, maxRange);
                    }
                    break;

            } //end nested Switch for choice y*/
            break;
        case 'n':

            char choice2;

            cout << "Would you like to enter the elements of the list? (y/n)" << endl;
            cin >> choice2;
            cout << endl;

            switch (choice2) {
                case 'y':
                    cout << "Number of Arrays: ";
                    cin >> numArr;
                    cout << "Array Size: ";
                    cin >> arrSize;
                    arrSize = arrSize - 1;
                    cout << endl;

                    for (int i = 1; i <= numArr; i++) {
                        int *p;
                        //p is set to the value that randomArray returns
                        p = Array(arrSize, numArr);

                        char choice3;

                        cout << "Confirm List? (y/n)" << endl;
                        cin >> choice3;
                        if ('y') {
                            //print the array that the Array function returns
                            cout << i << ": ";
                            printArray(p, arrSize);
                            lineBreak();
                        }
                        else {
                            cout << "you chose no" << endl;
                        }


                    }


                    //char choice;
                    //cout << "Would you like to view the lists? (y/n)" << endl;
                    //cin >> choice;
                    //cout << endl;


                    break;

                case 'n':
                    cout << "No list created. Cannot continue with Program.";
                    lineBreak();
                    break;

            } //end nested Switch for choice n

            break;
    } //end Switch
} //end ArrayHandler

/*
 * function: assignment2()
 * purpose: assignment2 is the name for PROGRAMMING ASSINGMENT 2
 * its purpose is to do the entirety of what is outlined in the requirements
 * for programming assignment 2
 */
void assignment2() {

    clock_t start1, start2, start3, start4, start5, start6, start7, start8, start9, end1, end2, end3, end4, end5, end6, end7, end8, end9;
    double msecs1, msecs2, msecs3, msecs4, msecs5, msecs6, msecs7, msecs8, msecs9;

    int n;

    cout << "Size of the lists to create: ";
    cin >> n;
    cout << endl;

    //creating a list of 10 elements
    int array1[n], array1Sorted[n];
    int array2[n], array2Sorted[n];
    int array3[n], array3Sorted[n];
    int array4[n], array4Sorted[n];
    int array5[n], array5Sorted[n];
    int array6[n], array6Sorted[n];
    int array7[n], array7Sorted[n];
    int array8[n], array8Sorted[n];
    int array9[n], array9Sorted[n];

    //user input
    char input;

    for (int i = 0; i <= n; i++) {
        array1[i] = rand() % 1000 + 0;
        array2[i] = rand() % 1000 + 0;
        array3[i] = rand() % 1000 + 0;
        array4[i] = rand() % 1000 + 0;
        array5[i] = rand() % 1000 + 0;
        array6[i] = rand() % 1000 + 0;
        array7[i] = rand() % 1000 + 0;
        array8[i] = rand() % 1000 + 0;
        array9[i] = rand() % 1000 + 0;
    }


    //filling array1Sorted with array1, and the the entire contents of array1
    //we want to save the originals per requirements
    memcpy(array1Sorted, array1, sizeof(array1));
    memcpy(array2Sorted, array2, sizeof(array2));
    memcpy(array3Sorted, array3, sizeof(array3));
    memcpy(array4Sorted, array4, sizeof(array4));
    memcpy(array5Sorted, array5, sizeof(array5));
    memcpy(array6Sorted, array6, sizeof(array6));
    memcpy(array7Sorted, array7, sizeof(array7));
    memcpy(array8Sorted, array8, sizeof(array7));
    memcpy(array9Sorted, array9, sizeof(array8));


    //calling mergesort with params (array, low, high)
    start1 = clock();
    mergeSort(array1Sorted, 0, n);
    end1 = clock();
    msecs1 = ((double) (end1 - start1)) * 1000 / CLOCKS_PER_SEC;

    start2 = clock();
    mergeSort(array2Sorted, 0, n);
    end2 = clock();
    msecs2 = ((double) (end2 - start2)) * 1000 / CLOCKS_PER_SEC;

    start3 = clock();
    mergeSort(array3Sorted, 0, n);
    end3 = clock();
    msecs3 = ((double) (end3 - start3)) * 1000 / CLOCKS_PER_SEC;

    start4 = clock();
    mergeSort(array4Sorted, 0, n);
    end4 = clock();
    msecs4 = ((double) (end4 - start4)) * 1000 / CLOCKS_PER_SEC;

    start5 = clock();
    mergeSort(array5Sorted, 0, n);
    end5 = clock();
    msecs5 = ((double) (end5 - start5)) * 1000 / CLOCKS_PER_SEC;

    start6 = clock();
    mergeSort(array6Sorted, 0, n);
    end6 = clock();
    msecs6 = ((double) (end6 - start6)) * 1000 / CLOCKS_PER_SEC;

    start7 = clock();
    mergeSort(array7Sorted, 0, n);
    end7 = clock();
    msecs7 = ((double) (end7 - start7)) * 1000 / CLOCKS_PER_SEC;

    start8 = clock();
    mergeSort(array8Sorted, 0, n);
    end8 = clock();
    msecs8 = ((double) (end8 - start8)) * 1000 / CLOCKS_PER_SEC;

    start9 = clock();
    mergeSort(array9Sorted, 0, n);
    end9 = clock();
    msecs9 = ((double) (end9 - start9)) * 1000 / CLOCKS_PER_SEC;

    cout << "View Unsorted Arrays? (y/n)" << endl;
    cin >> input;
    cin.ignore();
    cout << endl;

    switch (input) {
        case 'y':
            int input;
            cout << "Select an Unsorted Array to View: " << endl << endl;
            cout << "1 - Array1" << endl;
            cout << "2 - Array2" << endl;
            cout << "3 - Array3" << endl;
            cout << "4 - Array4" << endl;
            cout << "5 - Array5" << endl;
            cout << "6 - Array6" << endl;
            cout << "7 - Array7" << endl;
            cout << "8 - Array8" << endl;
            cout << "9 - Array9" << endl;
            cin >> input;
            cin.ignore();
            cout << endl;

            switch (input) {

                case 1:
                    cout << "Unsorted Array 1: ";
                    printArray(array1, n);
                    cout << endl;
                    cout << "Sorted Array 1: ";
                    printArray(array1Sorted, n);
                    cout << endl << endl;
                    break;
                case 2:
                    cout << "Unsorted Array 2: ";
                    printArray(array2, n);
                    cout << endl;
                    cout << "Sorted Array 2: ";
                    printArray(array2Sorted, n);
                    cout << endl << endl;
                    break;
                case 3:
                    cout << "Unsorted Array 3: ";
                    printArray(array3, n);
                    cout << endl;
                    cout << "Sorted Array 3: ";
                    printArray(array3Sorted, n);
                    cout << endl << endl;
                    break;
                case 4:
                    cout << "Unsorted Array 4: ";
                    printArray(array4, n);
                    cout << endl;
                    cout << "Sorted Array 4: ";
                    printArray(array4Sorted, n);
                    cout << endl;
                    cout << endl;
                    break;
                case 5:
                    cout << "Unsorted Array 5: ";
                    printArray(array5, n);
                    cout << endl;
                    cout << "Sorted Array 5: ";
                    printArray(array5Sorted, n);
                    cout << endl;
                    cout << endl;
                    break;
                case 6:
                    cout << "Unsorted Array 6: ";
                    printArray(array6, n);
                    cout << endl;
                    cout << "Sorted Array 6: ";
                    printArray(array6Sorted, n);
                    cout << endl;
                    cout << endl;
                    break;
                case 7:
                    cout << "Unsorted Array 7: ";
                    printArray(array7, n);
                    cout << endl;
                    cout << "Sorted Array 7: ";
                    printArray(array7Sorted, n);
                    cout << endl;
                    cout << endl;
                    break;
                case 8:
                    cout << "Unsorted Array 8: ";
                    printArray(array8, n);
                    cout << endl;
                    cout << "Sorted Array 8: ";
                    printArray(array8Sorted, n);
                    cout << endl;
                    cout << endl;
                    break;
                case 9:
                    cout << "Unsorted Array 9: ";
                    printArray(array9, n);
                    cout << endl;
                    cout << "Sorted Array 9: ";
                    printArray(array9Sorted, n);
                    cout << endl;
                    cout << endl;
                    break;
            }
            break;

        case 'n':
            break;

        default:
            break;
    }

    char input2;

    cout << "Continue with Programming Assignment 2? (y/n)";
    cin >> input2;
    cin.ignore();
    cout << endl;

    ofstream myFile("Mergesort_Time.csv");
    if (myFile.is_open()) {

        switch (input2) {
            case 'y':
                int logResult;
                double divResult1, divResult2, divResult3, divResult4, divResult5, divResult6, divResult7, divResult8, divResult9;

                logResult = (log10(n) * n);

                myFile << "Input Size 'n' for Array, Value of n*logn, Time Spent (ms), Value of n*logn/Time Spent"
                       << endl;
                myFile << n << ", " << logResult << ", " << msecs1 << ", " << divResult1 << endl;
                myFile << n << ", " << logResult << ", " << msecs2 << ", " << divResult2 << endl;
                myFile << n << ", " << logResult << ", " << msecs3 << ", " << divResult3 << endl;
                myFile << n << ", " << logResult << ", " << msecs4 << ", " << divResult4 << endl;
                myFile << n << ", " << logResult << ", " << msecs5 << ", " << divResult5 << endl;
                myFile << n << ", " << logResult << ", " << msecs6 << ", " << divResult6 << endl;
                myFile << n << ", " << logResult << ", " << msecs7 << ", " << divResult7 << endl;
                myFile << n << ", " << logResult << ", " << msecs8 << ", " << divResult8 << endl;
                myFile << n << ", " << logResult << ", " << msecs9 << ", " << divResult9 << endl;
                break;
            case 'n':
                break;

        }

        myFile << endl << endl;

        switch (input2) {
            case 'y':
                myFile << "Unsorted Array 1: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array1[i] << " ";
                }
                myFile << endl;

                myFile << "Unsorted Array 2: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array2[i] << " ";
                }
                myFile << endl;

                myFile << "Unsorted Array 3: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array3[i] << " ";
                }
                myFile << endl;

                myFile << "Unsorted Array 4: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array4[i] << " ";
                }
                myFile << endl;

                myFile << "Unsorted Array 5: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array5[i] << " ";
                }
                myFile << endl;

                myFile << "Unsorted Array 6: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array6[i] << " ";
                }
                myFile << endl;

                myFile << "Unsorted Array 7: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array7[i] << " ";
                }
                myFile << endl;


                myFile << "Unsorted Array 8: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array8[i] << " ";
                }
                myFile << endl;


                myFile << "Unsorted Array 9: ";
                for (int i = 0; i <= 9; i++) {
                    myFile << array9[i] << " ";
                }
                myFile << endl;
                myFile << endl;

                int logResult;
                double divResult1, divResult2, divResult3, divResult4, divResult5, divResult6, divResult7, divResult8, divResult9;

                logResult = (log10(n) * n);

                cout << "Sorted Array 1: ";
                myFile << "Sorted Array 1: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array1[i] << " ";
                    myFile << array1[i] << " ";
                }
                cout << endl << "Time: " << msecs1 << " ms" << endl;
                myFile << "Time: " << msecs1 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult1 = logResult / msecs1;
                cout << scientific << "The value of n*logn / time (ms): " << divResult1 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult1 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 2: ";
                myFile << "Sorted Array 2: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array2[i] << " ";
                    myFile << array2[i] << " ";
                }
                cout << endl << "Time: " << msecs2 << " ms" << endl;
                myFile << "Time: " << msecs2 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult2 = logResult / msecs2;
                cout << scientific << "The value of n*logn / time (ms): " << divResult2 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult2 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 3: ";
                myFile << "Sorted Array 3: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array3[i] << " ";
                    myFile << array3[i] << " ";
                }
                cout << endl << "Time: " << msecs3 << " ms" << endl;
                myFile << "Time: " << msecs3 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult3 = logResult / msecs3;
                cout << "The value of n*logn / time (ms): " << scientific << divResult3 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult3 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 4: ";
                myFile << "Sorted Array 4: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array4[i] << " ";
                    myFile << array4[i] << " ";
                }
                cout << endl << "Time: " << msecs4 << " ms" << endl;
                myFile << "Time: " << msecs4 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult4 = logResult / msecs4;
                cout << scientific << "The value of n*logn / time (ms): " << divResult4 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult4 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 5: ";
                myFile << "Sorted Array 5: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array5[i] << " ";
                    myFile << array5[i] << " ";
                }
                cout << endl << "Time: " << msecs5 << " ms" << endl;
                myFile << "Time: " << msecs5 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult5 = logResult / msecs5;
                cout << scientific << "The value of n*logn / time (ms): " << divResult5 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult5 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 6: ";
                myFile << "Sorted Array 6: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array6[i] << " ";
                    myFile << array6[i] << " ";
                }
                cout << endl << "Time: " << msecs6 << " ms" << endl;
                myFile << "Time: " << msecs6 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult6 = logResult / msecs6;
                cout << scientific << "The value of n*logn / time (ms): " << divResult6 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult6 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 7: ";
                myFile << "Sorted Array 7: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array7[i] << " ";
                    myFile << array7[i] << " ";
                }
                cout << endl << "Time: " << msecs7 << " ms" << endl;
                myFile << "Time: " << msecs7 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult7 = logResult / msecs7;
                cout << scientific << "The value of n*logn / time (ms): " << divResult7 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult7 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 8: ";
                myFile << "Sorted Array 8: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array8[i] << " ";
                    myFile << array8[i] << " ";
                }
                cout << endl << "Time: " << msecs8 << " ms" << endl;
                myFile << "Time: " << msecs8 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult8 = logResult / msecs8;
                cout << scientific << "The value of n*logn / time (ms): " << divResult8 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult8 << endl;
                cout << endl;
                myFile << endl;

                cout << "Sorted Array 9: ";
                myFile << "Sorted Array 9: ";
                //print sorted list1
                for (int i = 0; i <= 9; i++) {
                    cout << array9[i] << " ";
                    myFile << array9[i] << " ";
                }
                cout << endl << "Time: " << msecs9 << " ms" << endl;
                myFile << "Time: " << msecs9 << " ms" << endl;
                cout << "The value passed into n*logn: 10" << endl;
                myFile << "The value passed into n*logn: 10" << endl;
                cout << "The value of n*logn: " << logResult << endl;
                myFile << "The value of n*logn: " << logResult << endl;
                divResult9 = logResult / msecs9;
                cout << scientific << "The value of n*logn / time (ms): " << divResult9 << endl;
                myFile << "The value of n*logn / time (ms): " << divResult9 << endl;
                cout << endl;
                myFile << endl;
                break;
            case 'n':
                cout << "Returning to main menu" << endl;
                menu();
                break;
            default:
                cout << "Invalid Entry. Returning to main menu" << endl;
                menu();
                break;

        }
        myFile.close();
    } else {
        cout << "The excel file failed to open. Returning to main menu." << endl;
        menu();
    }
}

void assignmentExtra() {

}

/*
 * function: menu()
 * prupose: the menu function displays a menu for the user to see when the program is ran
 * it asks the user to enter an integer input (0-9)
 * and maps the integer to a function
 */
void menu() {

    int input;
    //input will be the int that the user enters to select a menu item

    //display the menu options for the user to choose from
    cout << "*CSC 332*\n"
         << "*MENU OPTIONS*\n\n";
    cout << "1 - Fibonacci Exercise\n"
         << "2 - Euclid's Original Algorithm\n"
         << "3 - Euclid's Improved Algorithm\n"
         << "4 - Programming Assignment 1\n"
         << "5 - Programming Assignment 2\n"
         << "6 - Programming Assignment 2.5\n"
         << "9 - Terminate Program\n\n";
    //ask the user to input a menu option
    cout << "Enter a menu option: ";
    //user inputs menu option
    cin >> input;
    cin.ignore();   //ignore anything after the int input
    cout << endl;
    //choice is a function created to take the input and map it to the option
    choice(input);
}

/*
 * function: returnMenu()
 * purpose: displays an option for the user to enter if to return to the main menu or not
 * if the user decides not to return to the main menu, the previous program is reran
 */
void returnMenu() {
    char input;
    //char input is used for the user to select y for yes and n for no
    cout << "Return to Main Menu? (y/n)\n";
    cin >> input;
    cout << endl;
    //after the user has entered an input, the while loop runs
    while (input) {
        switch (input) {
            case 'y':
                //if yes, return to main menu
                menu();
                break;

            case 'n':
                //if no, break from switch
                break;

                //default handles any other input not mentioned above. If an invalid input is entered, return to main menu
            default:
                cout << "Invalid Input. Returning to main menu.\n";
                //returns to main menu
                menu();
                break;
        }
        //if 'n' break from while loop
        break;
    }
}

/*
 * function: choice
 * purpose: takes an integer value and maps it to a function using a switch statement
 */
void choice(int input) {
    //while an input has been entered
    while (input) {
        //case '#' maps the integer value to whatever is in the case
        switch (input) {
            case 1:
                //entering integer value of 1 runs the Fibonacci() function
                Fibonacci();
                //once the function is completed it returns here, and then runs the returnMenu() function
                returnMenu();
                break;
            case 2:
                //entering integer value of 2 runs the originalEuclid() function
                originalEuclid();
                //once the function is completed it returns here, and then runs the returnMenu() function
                returnMenu();
                break;
            case 3:
                //entering integer value of 3 runs the improvedEuclid() function
                improvedEuclid();
                //once the function is completed it returns here, and then runs the returnMenu() function
                returnMenu();
                break;
            case 4:
                //entering integer value of 4 runs the entirety of PROGRAMMING ASSIGNMENT 1
                assignment1();
                //once the function is completed it returns here, and then runs the returnMenu() function
                returnMenu();
                break;
            case 5:
                //entering integer value of 5 runs the entirety of PROGRAMMING ASSIGNMENT 2
                assignment2();
                //once the function is completed it returns here, and then runs the returnMenu() function
                returnMenu();
                break;
            case 6:
                ArrayHandler();
                cout << "you have exited the array handler" << endl;
                returnMenu();
                break;
            case 9:
                //entering integer value of 9 TERMINATEs the entire program
                exit(1);
                //if by somehow an invalid option is entered, default handles every case not mentioned above
            default:
                cout << "Invalid Menu Option. Please enter new option: ";
                cin >> input;
                choice(input);
                cin.ignore();
                break;
        }
    }
}

/*
 * function: main()
 * purpose: to run the program
 */
int main() {
    //when the program is ran, it opens the menu() function
    menu();
    //once the user is done using the program, the program quits
    return 0;
}