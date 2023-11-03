#include "pch.h"
#include "../KPI_Lab1/KPI_Lab1.h"

TEST(AlgorithmTest, CheckFileExistence) {
	char cwd[1024];
	
	std::string dataFileAbsolutePath;
	if (getenv("GITHUB_ACTIONS")) {
		dataFileAbsolutePath = "src/KPI_Lab1/KPI_Lab1/data.txt";
		std::cout << "Running in GitHub Actions." << std::endl;
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			std::cout << "Current working directory: " << cwd << std::endl;
		}
	}
	else {
		dataFileAbsolutePath = "../../../KPI_Lab1/KPI_Lab1/data.txt";
		std::cout << "Running by local path." << std::endl;
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			std::cout << "Current working directory: " << cwd << std::endl;
		}
	}

	EXPECT_EQ(isFileExist(dataFileAbsolutePath), true);
	/*std::string dataFileAbsolutePath = "${{ github.workspace }}/src/KPI_Lab1/KPI_Lab1/data.txt";*/
	/*EXPECT_EQ(isFileExist("${{ github.workspace }}\src\KPI_Lab1\KPI_Lab1\data.txt"), true);*/
	/*EXPECT_EQ(isFileExist("../../../KPI_Lab1/KPI_Lab1/data.txt"), true);*/
	/*EXPECT_EQ(isFileExist("../../KPI_Lab1/data.txt"), true);*/
	/*EXPECT_EQ(isFileExist(dataFileAbsolutePath), true);*/
}

TEST(AlgorithmTest, CheckFileNonExistence) {
	EXPECT_EQ(isFileExist(""), false);
	EXPECT_EQ(isFileExist("data.txt"), false);
}
TEST(AlgorithmTest, CreateVectorFromFileData) {
	std::string dataFileAbsolutePath = "${{ github.workspace }}\src\KPI_Lab1\KPI_Lab1\data.txt";
	vector<int> initData = dataInitialization(dataFileAbsolutePath);
	/*vector<int> initData = dataInitialization("../../KPI_Lab1/data.txt");*/
	int actualLength = initData.size();

	vector<int> expectedData{3, 8, 5};
	int expectedLength = expectedData.size();

	EXPECT_EQ(actualLength, expectedLength);
	EXPECT_EQ(initData, expectedData);
}


