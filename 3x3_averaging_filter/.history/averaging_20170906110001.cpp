#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class averaging
{
public:
    int *histogram;
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    ifstream scan;
    ofstream out;

    averaging(string inFile, string outFile)
    {
        scan.open(inFile);
        scan >> numRows >> numCols >> minVal >> maxVal;
        histogram = new int[maxVal + 1]();
    }

    void computeHistogram()
    {
        scan.clear();
        scan.seekg(0, std::ios::beg);
        int pixel, maxPlus;
        while (scan >> pixel)
        {
            histogram[pixel]++;
        }
        out << numRows << " " << numCols << " " << minVal << " " << maxVal << endl;

        for (int i = 0; i < maxVal; i++)
        {
            out << "(" << i << "):"<< " " << histogram[i];
            if (histogram[i] > 80)
                maxPlus = 80;
            else
                maxPlus = histogram[i];
            for (int j = 0; j < maxPlus; j++)
            {
                out << "+";
            }
            out << endl;
        }
        out << endl;
        scan.close();
        out.close();
    }
};
int main(int argc, char *argv[])
{
    averaging processor(argv[1], argv[2]);
    processor.computeHistogram();
    return 0;
}