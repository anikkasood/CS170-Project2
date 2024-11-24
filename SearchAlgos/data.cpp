#include "data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <algorithm>

// Load data from a file
std::vector<DataRow> loadData(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<DataRow> data;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        DataRow row;
        double value;

        ss >> row.label;  // First value is the label
        while (ss >> value) {
            row.features.push_back(value);  // Remaining values are features
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

// Normalize data using Min-Max scaling
void normalizeData(std::vector<DataRow>& data) {
    if (data.empty()) return;

    size_t numFeatures = data[0].features.size();
    std::vector<double> minVals(numFeatures, std::numeric_limits<double>::max());
    std::vector<double> maxVals(numFeatures, std::numeric_limits<double>::lowest());

    // Find min and max for each feature
    for (const auto& row : data) {
        for (size_t i = 0; i < numFeatures; ++i) {
            minVals[i] = std::min(minVals[i], row.features[i]);
            maxVals[i] = std::max(maxVals[i], row.features[i]);
        }
    }

    // Normalize features
    for (auto& row : data) {
        for (size_t i = 0; i < numFeatures; ++i) {
            row.features[i] = (row.features[i] - minVals[i]) / (maxVals[i] - minVals[i]);
        }
    }
}

// Print data to the console
void printData(const std::vector<DataRow>& data) {
    for (const auto& row : data) {
        std::cout << std::fixed << std::setprecision(3) << row.label << " ";
        for (const auto& feature : row.features) {
            std::cout << feature << " ";
        }
        std::cout << std::endl;
    }
}
