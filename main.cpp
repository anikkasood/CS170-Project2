#include <iostream>
#include <iomanip>

//header files
#include "forwardSelection/a.cpp"

using namespace std;

int main() {
    
    
    srand(static_cast<unsigned>(time(nullptr)));

    int num_features;
    cout << "enter the total number of features: ";
    cin >> num_features;

    Selection selector(num_features);
    selector.forwardSelection();
    selector.backwardElimination();

    return 0;
}
