#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Selection {
private:
    int num_features;
    double best_accuracy;
    set<int> best_subset;

public:
    Selection(int num_features) : num_features(num_features), best_accuracy(0.0) {

    }

    //evaluation function
    double eval(const set<int>& features) {
        return static_cast<double>(rand()) / RAND_MAX * 100;
    }

    // Forward selection algorithm
    void forwardSelection() {
        set<int> cur_features;
        cout << "Forward Selection:" << endl;
        cout << "Using no features and 'random' evaluation, I get an accuracy of "
             << eval(cur_features) << "%" << endl;
        cout << "Beginning search.\n" << endl;

        for (int i = 1; i <= num_features; ++i) {
            double best_accuracy_for_round = 0.0;
            int best_feature = -1;


            for (int feature = 1; feature <= num_features; ++feature) {
                if (cur_features.find(feature) == cur_features.end()) {
                    set<int> test_features = cur_features;
                    test_features.insert(feature);

                    double accuracy = eval(test_features);
                    cout << "Using feature(s) {";
                    for (auto it = test_features.begin(); it != test_features.end(); ++it) {
                        cout << *it;
                        if (next(it) != test_features.end()) cout << ",";
                    }
                    cout << "} accuracy is " << accuracy << "%" << endl;

                    if (accuracy > best_accuracy_for_round) {
                        best_accuracy_for_round = accuracy;
                        best_feature = feature;
                    }
                }
            }

            if (best_feature != -1) {
                cur_features.insert(best_feature);
                cout << "Feature set {";
                for (auto it = cur_features.begin(); it != cur_features.end(); ++it) {
                    cout << *it;
                    if (next(it) != cur_features.end()) cout << ",";
                }
                cout << "} was best, accuracy is "  << best_accuracy_for_round << "%\n" << endl;

                
                if (best_accuracy_for_round > best_accuracy) {
                    best_accuracy = best_accuracy_for_round;
                    best_subset = cur_features;
                }
            } 
        }

        cout << "Finished forward selection!! The best feature subset is {";
        for (auto it = best_subset.begin(); it != best_subset.end(); ++it) {
            cout << *it;
            if (next(it) != best_subset.end()) cout << ",";
        }
        cout << "}, which has an accuracy of "  << best_accuracy << "%" << endl;
    }

    void backwardElimination() {
        
    }


};





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






















