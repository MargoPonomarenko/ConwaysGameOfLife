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
    if (isFileExist(fileName)) {
        int linesToRead = 2;
        int counter = 0;
        while (getline(file, dataString) && counter < linesToRead) {
            for (auto x : dataString) {
                if (x != ' ') {
                    string separateNumber(1, x);
                    initData.push_back(stoi(separateNumber));
                    cout << "Separate number: " << separateNumber << "\n";
                    counter++;
                }
            }
        }
    }

    // добавить обработку ошибки, если файл не удалось открыть
    return initData;
}