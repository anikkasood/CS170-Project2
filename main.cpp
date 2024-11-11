#include <iostream>
#include <iomanip>

//header files
#include "forwardSelection/a.cpp"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    //user input
    int num_features;
    cout << "Enter the total number of features: ";
    cin >> num_features;

    cout << "\n\nType the number of the algorithm you want to run:\n" 
         << "(1) Forward Selection\n"  
         << "(2) Backward Selection\n"
         << "(3) Group Special Algorithm\n\n";

    int featureSelect;
    cin >> featureSelect;

    //initialize seleciton class
    Selection selector(num_features);

    //output chosen search
    switch(featureSelect) {
        case 0:
            selector.forwardSelection();
            break;
        case 1;
            selector.backwardElimination();
            break;
        case 3:
            //If we wanna add a special Algo for extar credit
            break;
        default:
            selector.forwardSelection();
            break;
    }

    return 0;
}
