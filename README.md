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



## Part 3:
