#include<iostream>

using namespace std;

void menu(), returnMenu(), choice(int i);

void printAdjList(int e, int v);

void getInfo() {
    int v, e, choice;

    // take the input of the number of vertex and edges.
    cout << "Enter the number of vertexes of the graph: ";
    cin >> v;
    cout << "Enter the number of edges of the graph: ";
    cin >> e;
    cout << endl << endl;

    cout << "Select a List to View: " << endl;
    cout << "1 - Adjacency List " << endl;
    cout << "2 - Adjacency Matrix" << endl;
    cin >> choice;

    if (choice == 1) {
        printAdjList(e, v);
    }
    else if (choice == 2) {
        //printAdjMatrix(e, v);
    }
    else {
        returnMenu();
    }

}

void printAdjList(int e, int v) {
    int edge[e][2];

    // Take the input of the adjacent vertex pairs of the given graph.
    for(int i = 0; i < e; i++) {
        cout<<"Enter the vertex pair for edge "<<i+1;
        cout<<"V(1): ";
        cin>>edge[i][0];
        cout<<"V(2): ";
        cin>>edge[i][1];
    }
    cout << endl << endl;

    // Print the adjacency list representation of the graph.
    cout<<"The adjacency list representation for the given graph: ";
    for(int i = 0; i < v; i++) {
        int count = 0;
        // For each vertex print, its adjacent vertex.
        cout<<"\n\t"<<i+1<<"-> { ";
        for(int j = 0; j < e; j++)
        {
            if(edge[j][0] == i+1)
            {
                cout<<edge[j][1]<<"  ";
                count++;
            }
            else if(edge[j][1] == i+1)
            {
                cout<<edge[j][0]<<"  ";
                count++;
            }
            else if(j == e-1 && count == 0)
                cout<<"Isolated Vertex!";
        }
        cout<<" }";
    } //end for
}

void printAdjMatrix() {

}

int main() {

}

void menu() {
    int input;
    cout << "*CSC 332*\n"
         << "*MENU OPTIONS*\n\n";
    cout << "1 - Generate Graph\n"
         << "4 - View DFS\n";
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
                getInfo();
                returnMenu();
                break;
            case 2:
                returnMenu();
                break;
            case 3:
                returnMenu();
                break;
            case 4:
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