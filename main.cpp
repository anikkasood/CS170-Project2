#include <iostream>
#include <iomanip>
// measure time
#include <chrono>

//header files
#include "SearchAlgos/search.cpp"
#include "SearchAlgos/data.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    //input which data set to test
    int test = 0;
    cout << "Choose data set to test (1, 2 or 3): ";
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
            break;
        case 3:
            //test titanic dataset
            filename = "test/titanic-test-dataset.txt";
            break;
        default:
            filename = "test/small-test-dataset.txt";
            break;
    }

    //see file name is right
    cout << filename << endl;

    // Load data from file
    vector<DataRow> data = loadData(filename);

    // Get starting timepoint for normalizing data
    auto normalizeStart = high_resolution_clock::now();

    // Normalize data
    zNormalizeData(data);

    // Get ending timepoint for normalizing data
    auto normalizeStop = high_resolution_clock::now();

    //get duration for normalization
    auto normalizationDuration = duration_cast<microseconds>(normalizeStop - normalizeStart);

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

    // Get starting timepoint for computing accuracy
    auto accuracyStart = high_resolution_clock::now();

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

    // Get ending timepoint for computing accuracy
    auto accuracyStop = high_resolution_clock::now();

    //get duration for computing accuracy
    auto accuracyDuration = duration_cast<microseconds>(accuracyStop - accuracyStart);

    //output time for normalization and computing accuracy
    cout << "\nNormalization time       : " << normalizationDuration.count() << " microseconds" << endl;
    cout << "Accuracy Computation time: " << accuracyDuration.count() << " microseconds" << endl;

    return 0;
}