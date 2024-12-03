#include <iostream>
#include <iomanip>

//header files
#include "SearchAlgos/search.cpp"
#include "SearchAlgos/data.h"

using namespace std;

int main(int argc, char* argv[]) {
    //input which data set to test
    int test = 0;
    cout << "Choose data set to test (1 or 2): ";
    cin >> test;

    //get file name
    //string filename = argv[1];
    string filename;
    switch(test) {
        case 1:
            //test small dataset
            filename = "test/small-test-dataset.txt";
            break;
        case 2:
            //test large dataset
            filename = "test/large-test-dataset.txt";
        default:
            filename = "test/small-test-dataset.txt";
    }

    //see file name is right
    cout << filename << endl;

    // Load data from file
    vector<DataRow> data = loadData(filename);

    // Normalize data
    zNormalizeData(data);

    // Print normalized data
    std::cout << "Normalized Data:" << std::endl;
    printData(data);

    cout << "\n\nType the number of the algorithm you want to run:\n" 
         << "(1) Forward Selection\n"  
         << "(2) Backward Elimination\n"
         << "(3) Group Special Algorithm\n\n";

    int featureSelect;
    cin >> featureSelect;

    //initialize selection class
    Selection selector(data[0].features.size(), data);

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