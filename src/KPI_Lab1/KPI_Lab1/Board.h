#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board {
public:
    Board(int rowCount, int colCount);

    vector<vector<char>> getCells() const;

    // Set state of the cells of the board
    void setCells(const vector<vector<char>>& cells);

    void calculateNextGeneration(const vector<vector<char>>& currentGeneration, int row, int col);

    // Convert field state to a string
    string toString() const;

    int getRowCount() const;
    int getColCount() const;

private:
    int m_rowCount;
    int m_colCount;
    vector<vector<char>> m_cells;

    int countLiveNeighbors(const vector<vector<char>>& currentGeneration, int row, int col) const;
};
