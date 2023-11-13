#include <iostream>
#include "KPI_Lab1.h"
#include "Board.h"

using namespace std;

int main()
{
    string fileName;
    cout << "Enter name of the file with condition: ";
    cin >> fileName;
    vector<int> initData = dataInitialization(fileName);

    int generations = 0;
    int colCount = 0;
    int rowCount = 0;
    if (initData.size() >= 3) {
        generations = initData[0];
        colCount = initData[1];
        rowCount = initData[2];
    }
    else {
        cerr << "Error: not enough data in initData vector. Expected size: 3; got " << initData.size() << " instead" << endl;
    }

    vector<vector<char>> initialCells = boardInitialization(fileName, rowCount, colCount);

    // Creating an object of the Board class and set the initial state
    Board board(rowCount, colCount);
    board.setCells(initialCells);

    // Calculating generations
    for (int generation = 0; generation < generations; generation++) {
        vector<vector<char>> currentGeneration = board.getCells();
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                board.calculateNextGeneration(currentGeneration, row, col);
            }
        }
    }

    // Output the final state of the field to the output file
    ofstream output("output.txt");
    output << board.toString();
    output.close();
}
