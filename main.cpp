#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

void menu(), returnMenu(), choice(int input);

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
    for (int i = 1; i <= n; ++i)
    {
        //print 0
        if(i == 1)
        {
            cout << " " << t1 << " ";
            continue;
        }
        //print 1
        if(i == 2)
        {
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
    decResult = (n-1);
    //prints the results
    cout << "Log base 2 of " << finalTerm << " is " << logResult << endl;
    cout << "N-1 of " << n << " is " << decResult << endl << endl;
}

/*
 * function: originalEuclid()
 * purpose: user enters two values and the gcd is found
 * using the original Euclid method
 */
void originalEuclid(){
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
    if ((a && b) >= 1){
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
    }
    else {
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
    ofstream myFile ("100Euclid.csv");
    if (myFile.is_open()){                      //if the file to save the results in will open
        for (int i = 0; i <= length; i++) {     //i starts at 0 and goes until the length of what is passed in
            do {
                //if the element value at a or b of i is >= 1
                if ((a[i] || b[i]) >= 1){
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
        cout <<"The inputs do not successfully pass the precursor. (a >=b)" << endl;
    }
}

/*
 * function: improvedEuclid100
 * purpose: runs the improved euclid method 100 times using random array values
 * takes the random array and calls it a of 100 elements, b of 100 elements, and the length of both arrays of 100 elements
 */
void improvedEuclid100(int a[100], int b[100], int length){
    //remainder is an integer value
    int remainder;
    //double because milliseconds are small
    double msecs1, msecs2;
    //clock variables
    clock_t start1, end1, start2, end2, start3, end3, msecs3;

    //creates a variable myFile and uneditable excel file called "100improvedEuclid"
    ofstream myFile ("100improvedEuclid.csv");
    //if the file opens
    if (myFile.is_open()){
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
                }
                else if ((b[i] >= a[i]) && (a[i] > 0)) { // if b is greater from previous if statement, a and b switched utilizing Improved algorithm
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
void assignment1(){
    static int randomA[100], randomB[100], randomA_copy[100], randomB_copy[100], randomA_copy1[100], randomB_copy1[100];
    //static so they are saved in RAM
    //made two copies of each so the original is never modified
    char answer;
    //char answer b/c i felt like asking the user if they wanted to view the random numbers

    //for loop fills randomA and randomB with 100 elements of integer values from 0-100
    for (int i = 0; i <= 99; ++i){
        randomA[i] = rand() % 100 + 0;
        randomB[i] = rand() % 100 + 0;
    }

    //prompts the user if they would like to see the random numbers, they will be in excel anyways
    cout << "Would you like to view the random numbers? (y/n): " ;
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
                for (int i = 0; i <= 99; ++i){
                    cout << "a" << i <<" is: " << randomA[i];
                    //setw(10) sets the width to 10 spaces, this allows the second array to be printed next to the first one
                    cout << setw(10) << "b" << i <<" is: " << randomB[i];
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
            //t1 in temp is set to the value of t2 in arr and index is incremented
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

/*
 * function: assignment2()
 * purpose: assignment2 is the name for PROGRAMMING ASSINGMENT 2
 * its purpose is to do the entirety of what is outlined in the requirements
 * for programming assignment 2
 */
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
