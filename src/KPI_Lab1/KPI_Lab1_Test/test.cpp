#include "pch.h"
#include "../KPI_Lab1/KPI_Lab1.h"

TEST(AlgorithmTest, CreateVectorFromFileData) {
	std::string dataFileAbsolutePath = "${{ github.workspace }}/src/KPI_Lab1/KPI_Lab1/data.txt";
	vector<int> initData = dataInitialization(dataFileAbsolutePath);
	/*vector<int> initData = dataInitialization("../../KPI_Lab1/data.txt");*/
	int actualLength = initData.size();

	vector<int> expectedData{3, 8, 5};
	int expectedLength = expectedData.size();

	EXPECT_EQ(actualLength, expectedLength);
	EXPECT_EQ(initData, expectedData);
}

TEST(AlgorithmTest, CheckFileExistence) {
	std::string dataFileAbsolutePath = "${{ github.workspace }}/src/KPI_Lab1/KPI_Lab1/data.txt";
	/*EXPECT_EQ(isFileExist("../../KPI_Lab1/data.txt"), true);*/
	EXPECT_EQ(isFileExist(dataFileAbsolutePath), true);
}
TEST(AlgorithmTest, CheckFileNonExistence) {
	EXPECT_EQ(isFileExist(""), false);
	EXPECT_EQ(isFileExist("data.txt"), false);
}
