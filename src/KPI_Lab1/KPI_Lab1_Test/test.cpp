#include "pch.h"
#include "../KPI_Lab1/KPI_Lab1.h"
#include "../KPI_Lab1/Board.cpp"

class AlgorithmTest : public ::testing::Test {
protected:
	string fileName;

	int rowCount;
	int colCount;
	vector<vector<char>> initialCells;

	void SetUp() override {
		if (getenv("GITHUB_ACTIONS")) {
			fileName = "src/KPI_Lab1/KPI_Lab1/data.txt";
		}
		else {
			fileName = "../../../KPI_Lab1/KPI_Lab1/data.txt";
		}

		rowCount = 5;
		colCount = 8;
		initialCells = boardInitialization(fileName, rowCount, colCount);
	}

	void TearDown() override {}
};

TEST_F(AlgorithmTest, CheckFileExistence) {
	EXPECT_EQ(isFileExist(fileName), true);
}

TEST_F(AlgorithmTest, CheckFileNonExistence) {
	EXPECT_EQ(isFileExist(""), false);
	EXPECT_EQ(isFileExist("data.txt"), false);
}
TEST_F(AlgorithmTest, CreateVectorFromFileData) {
	vector<int> initData = dataInitialization(fileName);
	int actualLength = initData.size();

	vector<int> expectedData{ 3, 8, 5 };
	int expectedLength = expectedData.size();

	EXPECT_EQ(actualLength, expectedLength);
	EXPECT_EQ(initData, expectedData);
}

TEST(AlgorithmExeptionTest, ExceptionCreateVectorFromFileData) {
	EXPECT_THROW(dataInitialization("data.txt"), runtime_error);
	EXPECT_THROW(dataInitialization(""), runtime_error);
}
TEST_F(AlgorithmTest, CheckBoardInitialization) {
	vector<vector<char>> actualData = boardInitialization(fileName, rowCount, colCount);
	vector<vector<char>> expectedData{
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} };

	EXPECT_EQ(actualData, expectedData);
}


TEST_F(AlgorithmTest, CheckClassGettersSetters) {
	Board board(rowCount, colCount);
	board.setCells(initialCells);

	vector<vector<char>> actualData = board.getCells();
	vector<vector<char>> expectedData{
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} };

	EXPECT_EQ(actualData, expectedData);
}

TEST_F(AlgorithmTest, CheckClassRowsColsAMount) {
	Board board(rowCount, colCount);
	board.setCells(initialCells);

	int actualRowAmount = board.getRowCount();
	EXPECT_EQ(actualRowAmount, rowCount);

	int actualColAmount = board.getColCount();
	EXPECT_EQ(actualColAmount, colCount);
}
TEST_F(AlgorithmTest, CheckClassCalculatingNextGeneration) {
	int generations = 3;
	Board board(rowCount, colCount);
	board.setCells(initialCells);

	vector<vector<char>> expectedData{
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', 'x', 'x', 'x', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} };

	for (int generation = 0; generation < generations; generation++) {
		vector<vector<char>> currentGeneration = board.getCells();
		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				board.calculateNextGeneration(currentGeneration, row, col);
			}
		}
	}
	vector<vector<char>> actualData = board.getCells();
	EXPECT_EQ(actualData, expectedData);

	string actualOutput = board.toString();
	string expectedOutput = "........\n........\n.xxx....\n........\n........\n";
	EXPECT_EQ(actualOutput, expectedOutput);
}

TEST_F(AlgorithmTest, CheckClassToString) {
	Board board(rowCount, colCount);
	board.setCells(initialCells);

	string actualOutput = board.toString();
	string expectedOutput = "........\n..x.....\n..x.....\n..x.....\n........\n";
	EXPECT_EQ(actualOutput, expectedOutput);
}

TEST_F(AlgorithmTest, ExeptionClassCalculatingNextGeneration) {
	Board board(rowCount, colCount);
	board.setCells(initialCells);

	vector<vector<char>> currentGeneration = board.getCells();
	EXPECT_THROW(board.calculateNextGeneration(currentGeneration, -1, -1), out_of_range);
	EXPECT_THROW(board.calculateNextGeneration(currentGeneration, rowCount + 1, colCount + 1), out_of_range);
}
TEST_F(AlgorithmTest, CheckBoardSizeWithMinValues) {
	// Testing with minimum values
	int minRowCount = 1;
	int minColCount = 1;
	vector<vector<char>> initialCells = boardInitialization(fileName, minRowCount, minColCount);

	Board board(minRowCount, minColCount);
	board.setCells(initialCells);

	int actualRowAmount = board.getRowCount();
	EXPECT_EQ(actualRowAmount, minRowCount);

	int actualColAmount = board.getColCount();
	EXPECT_EQ(actualColAmount, minColCount);
}

TEST_F(AlgorithmTest, CheckBoardSizeWithMaxValues) {
	// Testing with maximum values
	int maxRowCount = 100;
	int maxColCount = 100;
	vector<vector<char>> initialCells = boardInitialization(fileName, maxRowCount, maxColCount);

	Board board(maxRowCount, maxColCount);
	board.setCells(initialCells);

	int actualMaxRowAmount = board.getRowCount();
	EXPECT_EQ(actualMaxRowAmount, maxRowCount);

	int actualMaxColAmount = board.getColCount();
	EXPECT_EQ(actualMaxColAmount, maxColCount);
}

TEST_F(AlgorithmTest, CheckClassCalculatingGenerationBorderHorizontalCase) {
	int generations = 3;
	Board board(rowCount, colCount);

	vector<vector<char>> initialCells{
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'x', '.', '.', '.', '.', '.', '.', '.'},
		{'x', '.', '.', '.', '.', '.', '.', '.'},
		{'x', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} };

	board.setCells(initialCells);

	for (int generation = 0; generation < generations; generation++) {
		vector<vector<char>> currentGeneration = board.getCells();
		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				board.calculateNextGeneration(currentGeneration, row, col);
			}
		}
	}
	vector<vector<char>> actualData = board.getCells();

	vector<vector<char>> expectedData{
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'x', 'x', '.', '.', '.', '.', '.', 'x'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} };
	EXPECT_EQ(actualData, expectedData);
}

TEST_F(AlgorithmTest, CheckClassCalculatingGenerationBorderVerticalCase) {
	int generations = 3;
	Board board(rowCount, colCount);

	vector<vector<char>> initialCells{
		{'.', 'x', 'x', 'x', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'} };

	board.setCells(initialCells);

	for (int generation = 0; generation < generations; generation++) {
		vector<vector<char>> currentGeneration = board.getCells();
		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				board.calculateNextGeneration(currentGeneration, row, col);
			}
		}
	}
	vector<vector<char>> actualData = board.getCells();

	vector<vector<char>> expectedData{
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', 'x', '.', '.', '.', '.', '.'} };
	EXPECT_EQ(actualData, expectedData);
}