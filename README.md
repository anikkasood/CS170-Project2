# CS170-Project2

## Group Members:

### Jyro Jimenez, Nhan Nguyen, Anika Sood

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



### Code for Nearest Neighbor Validator:


### Normalizing Small Test Dataset:
Choose data set to test (1 or 2): 1<br />
test/small-test-dataset.txt<br />
Normalized Data:<br />
2.000 2.177 0.243 -1.534 -2.349 -0.330 -0.987 1.541 0.352 1.162 0.133 <br />
2.000 1.635 -0.276 1.148 0.521 1.333 1.120 0.072 -0.057 -0.174 -1.071 <br />

<br /> <br />ommitted steps ... <br /><br />

2.000 0.067 1.710 -0.999 0.707 -1.552 -0.729 -0.475 0.702 0.308 0.125 <br />
2.000 0.795 -0.918 1.074 -1.061 0.223 -1.814 -0.366 1.369 -0.094 2.147<br />

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
Feature set {3,5} was best, accuracy is 92.000%<br />
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

## Part 3:
