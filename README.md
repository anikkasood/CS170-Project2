# CS170-Project2

## Group Members:

### Jyro Jimenez - 862231763
### Nhan Nguyen - 862315577
### Anika Sood - 862283943

## Discussion Time: 2pm

## Part 1:

### Forward Selection Trace:

Enter the total number of features: 4<br />
<br />
<br />
Type the number of the algorithm you want to run:<br />
(1) Forward Selection<br />
(2) Backward Elimination<br />
(3) Group Special Algorithm<br />
<br />
1<br />
Forward Selection:<br />
Using no features and 'random' evaluation, I get an accuracy of 37.9583%<br />
Beginning search.<br />
<br />
Using feature(s) {1} accuracy is 84.2917%<br />
Using feature(s) {2} accuracy is 71.6848%<br />
Using feature(s) {3} accuracy is 65.5623%<br />
Using feature(s) {4} accuracy is 83.9476%<br />
Feature set {1} was best, accuracy is 84.2917%<br />
<br />
Using feature(s) {1,2} accuracy is 36.4699%<br />
Using feature(s) {1,3} accuracy is 80.6486%<br />
Using feature(s) {1,4} accuracy is 35.6107%<br />
Feature set {1,3} was best, accuracy is 80.6486%<br />
<br />
Using feature(s) {1,2,3} accuracy is 57.7928%<br />
Using feature(s) {1,3,4} accuracy is 14.7599%<br />
Feature set {1,2,3} was best, accuracy is 57.7928%<br />
<br />
Using feature(s) {1,2,3,4} accuracy is 80.6055%<br />
Feature set {1,2,3,4} was best, accuracy is 80.6055%<br />
<br />
Finished forward selection!! The best feature subset is {1}, which has an accuracy of 84.2917%<br />

### Backward Elimination Trace:
Enter the total number of features: 4 <br />
<br />
<br />
<br />
Type the number of the algorithm you want to run:<br />
(1) Forward Selection <br />
(2) Backward Elimination<br />
(3) Group Special Algorithm<br />
<br /><br />
2<br />
Backward Elimination:<br />
Using all features and 'random' evaluation, I get an accuracy of 93.488%<br />
Beginning search.<br />

Using feature(s) {2,3,4} accuracy is 32.9713%<br />
Using feature(s) {1,3,4} accuracy is 48.6652%<br />
Using feature(s) {1,2,4} accuracy is 15.331%<br />
Using feature(s) {1,2,3} accuracy is 67.8204%<br />
Feature set {1,2,3} was best, accuracy is 67.8204%<br />
<br />
Using feature(s) {2,3} accuracy is 58.1685%<br />
Using feature(s) {1,3} accuracy is 37.6475%<br />
Using feature(s) {1,2} accuracy is 41.5552%<br />
Feature set {2,3} was best, accuracy is 58.1685%<br />
<br />
Using feature(s) {3} accuracy is 18.1302%<br />
Using feature(s) {2} accuracy is 14.1961%<br />
Feature set {3} was best, accuracy is 18.1302%<br />
<br />
Finished backward elimination!! The best feature subset is {1,2,3}, which has an accuracy of 67.8204%<br />

## Part 2:

### Code for Nearest Neighbor Classifier:
```
class Classifier {
private:
    vector<DataRow> training;  // Store training data

    DataRow test;              // Store test data

public:
    // Constructor with optional parameters to initialize training data and test data
    Classifier(const vector<DataRow>& trainingData = {}, const DataRow& testData = {}) {
        training = trainingData;  // Initialize training data
        test = testData;          // Initialize test data
    }

    // Training function that takes training data as argument
    void train(const vector<DataRow>& trainingData) {
        cout << "Training the classifier..." << endl;
        training = trainingData;  // Store the provided training data
    }

     double calc_dist(const DataRow& a, const DataRow& b) {
        double sum = 0.0;
        for (size_t i = 0; i < a.features.size(); ++i) {
            double diff = a.features[i] - b.features[i];
            sum += diff * diff;
        }
        return sqrt(sum);  // Euclidean distance
    }

    // Method to predict the label of the test row
    int predict(const DataRow& test_row, const vector<DataRow>& training_data) {
        double min_dist = numeric_limits<double>::max();
        int predicted_label = -1;

        // Find the closest training row
        for (const auto& training_row : training_data) {
            double dist = calc_dist(training_row, test_row);
            if (dist < min_dist) {
                min_dist = dist;
                predicted_label = training_row.label;
            }
        }
        return predicted_label;
    }
};
```
### Code for Nearest Neighbor Validator:
```
//evaluation function
double eval(const set<int>& features, const vector<DataRow>& data_a00) {
    vector<DataRow> data_0;
    Classifier classifier;
    // Prepare the data by extracting the features specified in 'features'
    for (const auto& row : data_a00) {
        DataRow new_row = row;
        vector<double> features_test;

        for (const int feature_index : features) {
            if (feature_index >= 0 && feature_index - 1 < new_row.features.size()) {
                features_test.push_back(new_row.features[feature_index - 1]);  // Adjusted for 1-based indexing
            }
        }

        new_row.features = features_test;
        data_0.push_back(new_row);
    }

    int correct_predictions = 0;

    // Perform leave-one-out cross-validation
    for (size_t i = 0; i < data_0.size(); ++i) {
        DataRow test_data = data_0[i];

        // Prepare the training data by leaving out the current test data
        vector<DataRow> training_data;
        for (size_t j = 0; j < data_0.size(); ++j) {
            if (j != i) {
                training_data.push_back(data_0[j]);
            }
        }

        // Predict the label for the test data
        int predicted_label = classifier.predict(test_data, training_data);

        // Compare the predicted label with the true label
        if (predicted_label == test_data.label) {
            ++correct_predictions;
        }
    }

    // Calculate and return the accuracy
    double accuracy = static_cast<double>(correct_predictions) / data_0.size();
    return accuracy * 100;  // Return the accuracy as a percentage
}
```

### Normalizing Small Test Dataset:
Choose data set to test (1 or 2): 1<br />
test/small-test-dataset.txt<br />
Normalized Data:<br />
2.000 2.177 0.243 -1.534 -2.349 -0.330 -0.987 1.541 0.352 1.162 0.133 <br />
2.000 1.635 -0.276 1.148 0.521 1.333 1.120 0.072 -0.057 -0.174 -1.071
<br />
<br /> ommitted steps ... <br />
<br />
2.000 0.067 1.710 -0.999 0.707 -1.552 -0.729 -0.475 0.702 0.308 0.125 <br />
2.000 0.795 -0.918 1.074 -1.061 0.223 -1.814 -0.366 1.369 -0.094 2.147<br />

### Normalizing Large Test Dataset:
Choose data set to test (1 or 2): 2<br />
test/large-test-dataset.txt<br />
Normalized Data:<br />
2.000 -0.504 -1.895 0.625 -0.853 0.861 1.456 0.570 0.077 0.860 -1.725 1.259 1.789 -1.035 -0.787 0.621 0.710 0.645 0.792 0.205 1.965 -2.398 -2.972 0.210 0.467 2.323 -0.314 -0.443 -1.587 1.227 -0.023 1.416 -0.311 0.388 0.034 0.153 0.906 1.326 -1.269 -0.278 0.109 <br />
2.000 0.089 -1.923 -0.037 -0.661 -0.239 0.241 0.110 0.773 0.052 0.885 -0.476 0.822 -1.054 -0.276 -1.205 -0.982 -1.066 1.311 -1.643 -0.316 -1.310 0.578 0.712 -1.385 -2.189 0.025 -1.209 -0.281 -1.098 0.535 -0.051 -0.280 0.161 -0.843 -0.514 -1.061 0.487 -1.543 0.268 0.604
<br />
<br /> ommitted steps ... <br />
<br />
1.000 -0.193 -0.106 -0.087 -0.802 2.693 0.658 0.872 1.465 0.924 -1.547 1.167 0.116 -1.290 1.581 0.862 0.616 0.338 0.651 -1.262 0.082 0.174 0.934 1.915 0.163 0.902 -0.150 0.559 0.778 -0.170 1.091 0.340 1.787 -0.401 -0.615 -0.712 -0.075 0.564 -0.095 0.358 1.396 <br />
2.000 0.980 0.626 2.002 -2.000 -2.092 -0.229 0.725 -0.437 0.839 -0.704 0.001 0.786 -0.294 -1.714 -0.975 -0.644 -0.717 0.733 1.817 -0.973 0.702 -0.320 -0.898 0.651 -0.092 -0.055 0.439 -1.071 -1.417 -0.381 -0.385 -1.320 0.325 0.010 1.070 0.713 -1.393 -0.476 -2.081 -1.125 <br />

### Small Test Dataset trace using forward selection:
Type the number of the algorithm you want to run: <br />
(1) Forward Selection<br />
(2) Backward Elimination<br />
(3) Group Special Algorithm<br />
<br />
1<br />
<br />
Forward Selection:<br />
Using no features and 'random' evaluation, I get an accuracy of 75.000%<br />
Beginning search.<br />

Using feature(s) {1} accuracy is 57.000%<br />
Using feature(s) {2} accuracy is 54.000%<br />
Using feature(s) {3} accuracy is 68.000%<br />
Using feature(s) {4} accuracy is 65.000%<br />
Using feature(s) {5} accuracy is 75.000%<br />
Using feature(s) {6} accuracy is 61.000%<br />
Using feature(s) {7} accuracy is 62.000%<br />
Using feature(s) {8} accuracy is 60.000%<br />
Using feature(s) {9} accuracy is 66.000%<br />
Using feature(s) {10} accuracy is 64.000%<br />
Feature set {5} was best, accuracy is 75.000%<br />

Using feature(s) {1,5} accuracy is 76.000%<br />
Using feature(s) {2,5} accuracy is 80.000%<br />
Using feature(s) {3,5} accuracy is 92.000%<br />
Using feature(s) {4,5} accuracy is 75.000%<br />
Using feature(s) {5,6} accuracy is 79.000%<br />
Using feature(s) {5,7} accuracy is 80.000%<br />
Using feature(s) {5,8} accuracy is 77.000%<br />
Using feature(s) {5,9} accuracy is 73.000%<br />
Using feature(s) {5,10} accuracy is 82.000%<br />
Feature set {3,5} was best, accuracy is 92.000%
<br />
<br /> ommitted steps ... <br />
<br />
Using feature(s) {1,2,3,5,6,7,8,9} accuracy is 70.000%<br />
Using feature(s) {1,3,4,5,6,7,8,9} accuracy is 64.000%<br />
Using feature(s) {1,3,5,6,7,8,9,10} accuracy is 67.000%<br />
Feature set {1,2,3,5,6,7,8,9} was best, accuracy is 70.000%<br />
<br />
Using feature(s) {1,2,3,4,5,6,7,8,9} accuracy is 70.000%<br />
Using feature(s) {1,2,3,5,6,7,8,9,10} accuracy is 68.000%<br />
Feature set {1,2,3,4,5,6,7,8,9} was best, accuracy is 70.000%<br />
<br />
Using feature(s) {1,2,3,4,5,6,7,8,9,10} accuracy is 65.000%<br />
Feature set {1,2,3,4,5,6,7,8,9,10} was best, accuracy is 65.000%<br />
<br />
Finished forward selection!! The best feature subset is {3,5}, which has an accuracy of 92.000%<br />

### Small Test Dataset trace using backward selection:
Type the number of the algorithm you want to run:<br />
(1) Forward Selection<br />
(2) Backward Elimination<br />
(3) Group Special Algorithm<br />
<br />
2<br />
<br />
Backward Elimination:<br />
Using all features and 'random' evaluation, I get an accuracy of 65.000%<br />
Beginning search.<br />
<br />
Using feature(s) {2,3,4,5,6,7,8,9,10} accuracy is 69.000%<br />
Using feature(s) {1,3,4,5,6,7,8,9,10} accuracy is 66.000%<br />
Using feature(s) {1,2,4,5,6,7,8,9,10} accuracy is 75.000%<br />
Using feature(s) {1,2,3,5,6,7,8,9,10} accuracy is 68.000%<br />
Using feature(s) {1,2,3,4,6,7,8,9,10} accuracy is 71.000%<br />
Using feature(s) {1,2,3,4,5,7,8,9,10} accuracy is 69.000%<br />
Using feature(s) {1,2,3,4,5,6,8,9,10} accuracy is 61.000%<br />
Using feature(s) {1,2,3,4,5,6,7,9,10} accuracy is 70.000%<br />
Using feature(s) {1,2,3,4,5,6,7,8,10} accuracy is 67.000%<br />
Using feature(s) {1,2,3,4,5,6,7,8,9} accuracy is 70.000%<br />
Feature set {1,2,4,5,6,7,8,9,10} was best, accuracy is 75.000%
<br />
<br /> ommitted steps ... <br />
<br />
Using feature(s) {5,7} accuracy is 80.000%<br />
Using feature(s) {2,7} accuracy is 55.000%<br />
Using feature(s) {2,5} accuracy is 80.000%<br />
Feature set {5,7} was best, accuracy is 80.000%<br />
<br />
Using feature(s) {7} accuracy is 62.000%<br />
Using feature(s) {5} accuracy is 75.000%<br />
Feature set {5} was best, accuracy is 75.000%<br />
<br />
Finished backward elimination!! The best feature subset is {2,4,5,7,10}, which has an accuracy of 82.000%<br />

### Large Test Dataset trace using forward selection:
Type the number of the algorithm you want to run:<br />
(1) Forward Selection<br />
(2) Backward Elimination<br />
(3) Group Special Algorithm<br />
<br />
1<br />
<br />
Forward Selection:<br />
Using no features and 'random' evaluation, I get an accuracy of 81.000%<br />
Beginning search.<br />
<br />
Using feature(s) {1} accuracy is 73.800%<br />
Using feature(s) {2} accuracy is 71.000%<br />
Using feature(s) {3} accuracy is 67.300%<br />
Using feature(s) {4} accuracy is 67.800%<br />
Using feature(s) {5} accuracy is 69.200%<br />
Using feature(s) {6} accuracy is 69.500%<br />
Using feature(s) {7} accuracy is 70.600%<br />
Using feature(s) {8} accuracy is 71.200%<br />
Using feature(s) {9} accuracy is 68.000%<br />
Using feature(s) {10} accuracy is 69.100%<br />
Using feature(s) {11} accuracy is 70.500%<br />
Using feature(s) {12} accuracy is 68.000%<br />
Using feature(s) {13} accuracy is 65.800%<br />
Using feature(s) {14} accuracy is 70.900%<br />
Using feature(s) {15} accuracy is 69.500%<br />
Using feature(s) {16} accuracy is 67.500%<br />
Using feature(s) {17} accuracy is 67.300%<br />
Using feature(s) {18} accuracy is 70.400%<br />
Using feature(s) {19} accuracy is 69.600%<br />
Using feature(s) {20} accuracy is 67.700%<br />
Using feature(s) {21} accuracy is 68.300%<br />
Using feature(s) {22} accuracy is 68.500%<br />
Using feature(s) {23} accuracy is 70.200%<br />
Using feature(s) {24} accuracy is 67.200%<br />
Using feature(s) {25} accuracy is 69.300%<br />
Using feature(s) {26} accuracy is 67.700%<br />
Using feature(s) {27} accuracy is 84.700%<br />
Using feature(s) {28} accuracy is 66.400%<br />
Using feature(s) {29} accuracy is 69.900%<br />
Using feature(s) {30} accuracy is 70.900%<br />
Using feature(s) {31} accuracy is 69.900%<br />
Using feature(s) {32} accuracy is 69.500%<br />
Using feature(s) {33} accuracy is 70.100%<br />
Using feature(s) {34} accuracy is 68.200%<br />
Using feature(s) {35} accuracy is 69.900%<br />
Using feature(s) {36} accuracy is 69.800%<br />
Using feature(s) {37} accuracy is 70.500%<br />
Using feature(s) {38} accuracy is 70.400%<br />
Using feature(s) {39} accuracy is 71.000%<br />
Using feature(s) {40} accuracy is 70.300%<br />
Feature set {27} was best, accuracy is 84.700%<br />
<br />
Using feature(s) {1,27} accuracy is 95.500%<br />
Using feature(s) {2,27} accuracy is 84.200%<br />
Using feature(s) {3,27} accuracy is 82.500%<br />
Using feature(s) {4,27} accuracy is 82.600%<br />
Using feature(s) {5,27} accuracy is 82.000%<br />
Using feature(s) {6,27} accuracy is 84.200%<br />
Using feature(s) {7,27} accuracy is 82.300%<br />
Using feature(s) {8,27} accuracy is 84.800%<br />
Using feature(s) {9,27} accuracy is 84.100%<br />
Using feature(s) {10,27} accuracy is 82.400%<br />
Using feature(s) {11,27} accuracy is 81.700%<br />
Using feature(s) {12,27} accuracy is 82.900%<br />
Using feature(s) {13,27} accuracy is 82.200%<br />
Using feature(s) {14,27} accuracy is 83.200%<br />
Using feature(s) {15,27} accuracy is 84.600%<br />
Using feature(s) {16,27} accuracy is 82.900%<br />
Using feature(s) {17,27} accuracy is 83.700%<br />
Using feature(s) {18,27} accuracy is 83.300%<br />
Using feature(s) {19,27} accuracy is 83.100%<br />
Using feature(s) {20,27} accuracy is 81.900%<br />
Using feature(s) {21,27} accuracy is 83.000%<br />
Using feature(s) {22,27} accuracy is 84.100%<br />
Using feature(s) {23,27} accuracy is 83.800%<br />
Using feature(s) {24,27} accuracy is 81.300%<br />
Using feature(s) {25,27} accuracy is 81.400%<br />
Using feature(s) {26,27} accuracy is 83.100%<br />
Using feature(s) {27,28} accuracy is 81.800%<br />
Using feature(s) {27,29} accuracy is 83.300%<br />
Using feature(s) {27,30} accuracy is 82.100%<br />
Using feature(s) {27,31} accuracy is 82.600%<br />
Using feature(s) {27,32} accuracy is 82.800%<br />
Using feature(s) {27,33} accuracy is 82.200%<br />
Using feature(s) {27,34} accuracy is 82.100%<br />
Using feature(s) {27,35} accuracy is 81.600%<br />
Using feature(s) {27,36} accuracy is 82.500%<br />
Using feature(s) {27,37} accuracy is 85.000%<br />
Using feature(s) {27,38} accuracy is 81.900%<br />
Using feature(s) {27,39} accuracy is 84.900%<br />
Using feature(s) {27,40} accuracy is 82.600%<br />
Feature set {1,27} was best, accuracy is 95.500%
<br />
<br /> ommitted steps ... <br />
<br />
Using feature(s) {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 69.500%<br />
Feature set {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} was best, accuracy is 69.500%<br />
<br />
Finished forward selection!! The best feature subset is {1,27}, which has an accuracy of 95.500%<br />

### Large Test Dataset trace using backward selection:
Type the number of the algorithm you want to run:<br />
(1) Forward Selection<br />
(2) Backward Elimination<br />
(3) Group Special Algorithm<br />
<br />
2<br />
<br />
Backward Elimination:<br />
Using all features and 'random' evaluation, I get an accuracy of 69.500%<br />
Beginning search.<br />
<br />
Using feature(s) {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 70.400%<br />
Using feature(s) {1,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 67.700%<br />
Using feature(s) {1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 68.000%<br />
Using feature(s) {1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 69.600%<br />
Using feature(s) {1,2,3,4,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 68.600%<br />
Using feature(s) {1,2,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 69.900%<br />
Using feature(s) {1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 70.000%<br />
Using feature(s) {1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 70.300%<br />
Using feature(s) {1,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 69.500%<br />
Using feature(s) {1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 69.500%<br />
Using feature(s) {1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 69.600%<br />
Using feature(s) {1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 68.500%<br />
Using feature(s) {1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 69.100%<br />
Using feature(s) {1,2,3,4,5,6,7,8,9,10,11,12,13,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} accuracy is 70.200%
<br />
<br /> ommitted steps ... <br />
<br />
Using feature(s) {16,20,27,30} accuracy is 79.400%<br />
Using feature(s) {2,20,27,30} accuracy is 80.000%<br />
Using feature(s) {2,16,27,30} accuracy is 79.000%<br />
Using feature(s) {2,16,20,30} accuracy is 69.300%<br />
Using feature(s) {2,16,20,27} accuracy is 82.300%<br />
Feature set {2,16,20,27} was best, accuracy is 82.300%<br />
<br />
Using feature(s) {16,20,27} accuracy is 82.300%<br />
Using feature(s) {2,20,27} accuracy is 83.200%<br />
Using feature(s) {2,16,27} accuracy is 84.200%<br />
Using feature(s) {2,16,20} accuracy is 70.600%<br />
Feature set {2,16,27} was best, accuracy is 84.200%<br />
<br />
Using feature(s) {16,27} accuracy is 82.900%<br />
Using feature(s) {2,27} accuracy is 84.200%<br />
Using feature(s) {2,16} accuracy is 69.200%<br />
Feature set {2,27} was best, accuracy is 84.200%<br />
<br />
Using feature(s) {27} accuracy is 84.700%<br />
Using feature(s) {2} accuracy is 71.000%<br />
Feature set {27} was best, accuracy is 84.700%<br />
<br />
Finished backward elimination!! The best feature subset is {27}, which has an accuracy of 84.700%<br />

## Part 3:
### Challenges:
**Feature Subset Evaluation:** Ensuring the eval method accurately predicts and calculates the accuracy using leave-one-out cross-validation was a key challenge. Debugging and verifying the correctness of the feature evaluation process required careful thought.

**Data Preparation:** Preprocessing the data, including loading, normalizing, and handling missing values, presented challenges. Incorrectly formatted data could lead to runtime errors or incorrect results.

**Algorithm Design:** Implementing forward selection and backward elimination algorithms efficiently while ensuring clarity in logic and handling edge cases (e.g., no features, all features) was a significant challenge.

**Computational Complexity:** Both forward selection and backward elimination algorithms involve a combinatorial evaluation of subsets, leading to potential performance bottlenecks on larger datasets.

**Interpretability:** Determining which features meaningfully separate classes and analyzing their impact on accuracy required domain knowledge and statistical interpretation.

### Your design (objects and methods):
**Objects:**
- DataRow: Represents a single row of data with a label and a vector of feature values.
- Selection: Implements feature selection algorithms (forwardSelection and backwardElimination) and contains methods for evaluating subsets.
**Methods:**
- eval: Evaluates a feature subset using leave-one-out cross-validation.
- forwardSelection: Greedily adds features that improve accuracy.
- backwardElimination: Iteratively removes features to maintain or improve accuracy.
**Key Components:**
- Data Preparation: Handles loading, normalization, and formatting via utility functions (loadData, normalizeData).
- Classifier Integration: A separate Classifier object predicts labels for test data.
- Accuracy Calculation: Accuracy is computed as the percentage of correctly predicted labels over all test cases.

### Optimizing The Code:
**Special Data Structures:**
- Used std::set to manage feature subsets efficiently, ensuring uniqueness and enabling logarithmic time complexity for insertions and deletions.
- Used std::vector for storing data rows, which supports efficient sequential access and iteration.
**Algorithmic Improvements:**
- Limited the search space by pruning subsets that do not improve accuracy.
- Avoided redundant computations by caching intermediate results where possible.
**Normalization:**
- Ensured all features were on the same scale to improve classifier performance and reduce sensitivity to feature magnitude differences.

### Comparison of different algorithms on different datasets and discussion:
In this project, we implemented two search algorithms: forward selection and backward elimination. Forward selection greedily adds features that improve accuracy. The implementation for this is O(n^2), but because it begins with no features, this algorithm runs faster at the beginning and slows down at the end (as more features are considered). Backward elimination also has an O(n^2) complexity but, because it begins with all features, it begins slow and speeds up towards the end of the evaluation. Similarly, the memory usage of backward elimination begins large and becomes smaller (because features are being eliminated from consideration) and the memory usage of forward elimination begins small and becomes larger (because features are being added to consideration).

### References:
- Slides
- Online documentation
- https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ for time stamp
- https://www.w3schools.com/python/matplotlib_scatter.asp for scatter plots

### Contribution of each student in the group:
- Jyro Jimenez: READ.me, UI, Scatter plot analysis
- Nhan Nguyen: data normalization, forward selection, classifier.
- Anika Sood: Backward elimination, UI, performance evaluation
