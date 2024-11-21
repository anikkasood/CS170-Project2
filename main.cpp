#include <iostream>
#include <iomanip>

//header files
#include "SearchAlgos/search.cpp"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    //user input
    int num_features;
    cout << "Enter the total number of features: ";
    cin >> num_features;

    cout << "\n\nType the number of the algorithm you want to run:\n" 
         << "(1) Forward Selection\n"  
         << "(2) Backward Elimination\n"
         << "(3) Group Special Algorithm\n\n";

    int featureSelect;
    cin >> featureSelect;

    //initialize selection class
    Selection selector(num_features);

    //output chosen search
    switch(featureSelect) {
        case 1:
            selector.forwardSelection();
            break;
        case 2:
            selector.backwardElimination();
            break;
        case 3:
            //If we wanna add a special Algo for extra credit
            break;
        default:
            selector.forwardSelection();
            break;
    }

    return 0;
}
