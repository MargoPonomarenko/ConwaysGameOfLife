#include "Board.h"

Board::Board(int rowCount, int colCount) : m_rowCount(rowCount), m_colCount(colCount) {
    int value = rowCount * colCount;
    m_cells.resize(value);
}

vector<vector<char>> Board::getCells() const {
    return m_cells;
}

int Board::getRowCount() const {
    return m_rowCount;
}

int Board::getColCount() const {
    return m_colCount;
}

void Board::setCells(const vector<vector<char>>& cells) {
    m_cells = cells;
}

void Board::calculateNextGeneration(const vector<vector<char>>& currentGeneration, int row, int col) {
    if (row < 0 || row >= m_rowCount || col < 0 || col >= m_colCount) {
        throw out_of_range("Invalid values of variables 'row'/'col'");
    }
    vector<vector<char>> tempBoard = m_cells;

    for (int row = 0; row < m_rowCount; row++) {
        for (int col = 0; col < m_colCount; col++) {
            int liveNeighbors = countLiveNeighbors(currentGeneration, row, col);
            char cell = m_cells[row][col];

            if (cell == 'x') {
                // Alive cell
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    // Dies due to lack or overabundance of neighbors
                    tempBoard[row][col] = '.';
                }
            }
            else {
                // Dead cell
                if (liveNeighbors == 3) {
                    // Revived because of the three neighbors
                    tempBoard[row][col] = 'x';
                }
            }
        }
    }

    // Updating the main board
    m_cells = tempBoard;
}

string Board::toString() const {
    string result;
    for (int row = 0; row < m_rowCount; row++) {
        for (int col = 0; col < m_colCount; col++) {
            result += m_cells[row][col];
        }
        result += '\n';
    }
    return result;
}

int Board::countLiveNeighbors(const vector<vector<char>>& currentGeneration, int row, int col) const {
    int liveNeighbors = 0;
    int rowSize = m_rowCount;
    int colSize = m_colCount;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            // Processing for cyclic borders (if on an edge, return to the opposite side)
            int rowIndex = (i + rowSize) % rowSize;
            int colIndex = (j + colSize) % colSize;

            if ((i == row && j == col) || rowIndex < 0 || colIndex < 0 || rowIndex >= rowSize || colIndex >= colSize) {
                // Skip cells outside the field boundaries
                continue;
            }

            // Checking the correctness of indexes
            if (rowIndex >= 0 && rowIndex < currentGeneration.size() &&
                colIndex >= 0 && colIndex < currentGeneration[0].size()) {
                // Check that currentGeneration[rowIndex][colIndex] exists
                if (currentGeneration[rowIndex][colIndex] == 'x') {
                    liveNeighbors++;
                }
            }
        }
    }

    return liveNeighbors;
}