#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isFileExist(string fileName) {
    ifstream file;
    file.open(fileName);
    if (file) {
        return true;
    }
    else {
        char errorMessage[256];
        strerror_s(errorMessage, sizeof(errorMessage), errno);
        cerr << "Error while opening file: " << errorMessage << std::endl;
        return false;
    }
}

vector<int> dataInitialization(string fileName) {
    vector<int> initData;
    ifstream file(fileName);

    string dataString;
    if (!isFileExist(fileName)) {
        throw runtime_error("Errors occurred while opening a file  " + fileName);
    }

    int linesToRead = 2;
    int counter = 0;
    while (getline(file, dataString) && counter < linesToRead) {
        for (auto x : dataString) {
            if (x != ' ') {
                string separateNumber(1, x);
                initData.push_back(stoi(separateNumber));
                counter++;
            }
        }
    }

    file.close();

    return initData;
}

vector<vector<char>> boardInitialization(string fileName, int rowCount, int colCount) {
    vector<vector<char>> initialCells(rowCount, vector<char>(colCount, '.'));
    ifstream file(fileName);

    // Skip the first two lines with board parameters
    string line;
    for (int i = 0; i < 2; i++) {
        getline(file, line);
    }

    for (int i = 0; i < rowCount; i++) {
        if (getline(file, line)) {
            for (int j = 0; j < colCount; j++) {
                if (j < line.length()) {
                    initialCells[i][j] = line[j];
                }
            }
        }
    }

    file.close();
    return initialCells;
}