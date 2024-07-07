## Build & Run project

To build the project, set the current directory to: `\src\KPI_Lab1` and execute the following command:

```bash
  msbuild KPI_Lab1.sln
```
To run the project, navigate to the directory: `\src\KPI_Lab1\x64\Debug`
by using the following command:
```bash
  start KPI_Lab1.exe
```
To execute the program, provide the path to a .txt file containing the problem statement. After execution, the program will generate an output file named `output.txt`, saved in the project's current directory.

Here is an example file path from the repository: `../../../KPI_Lab1/KPI_Lab1/data.txt` 

## Run Tests
To run the tests, navigate to the directory: `\src\KPI_Lab1\x64\Debug`
by using the following command:
```bash
  KPI_Lab1_Test.exe
```

## Task demonstration
- GitHub Actions configuration was performed on branches [integrations](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/tree/integrations) and [integrations-2](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/tree/integrations-2)
- [Pull Request](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/pull/2) with unit test that have successfully passed in GitHub Actions.
- [Pull Request #2](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/pull/3) with unit tests that have failed in GitHub Actions.
