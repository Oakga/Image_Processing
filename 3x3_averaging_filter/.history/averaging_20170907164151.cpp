#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Averaging
{
public:
    int **mirrorFramedAry;
    int **tempAry;
    int neighborAry[9];
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    int newMin;
    int newMax;
    ifstream scan;
    ofstream out;

    Averaging(string inFile, string outFile)
    {
        scan.open(inFile);
        out.open(outFile);
        scan >> numRows >> numCols >> minVal >> maxVal;
        newMin=0;newMax=0;
        mirrorFramedAry = new int*[numRows+2];
        tempAry = new int*[numRows+2];
        for(int i = 0; i < numRows+2; i++){
            mirrorFramedAry[i] = new int[numCols+2];
            tempAry[i] = new int[numCols+2];
        }
    }
    ~Averaging(){
        for (int i = 0; i < numRows+2; i++) {
            delete [] mirrorFramedAry[i];
            delete [] tempAry[i];
        }
        delete[] mirrorFramedAry;
        delete [] tempAry;
        out.close();
        scan.close();
    }
    void loadImage()
    {
        for(int i = 1;i < numRows+1;i++){
            for(int j=1;j< numCols+1;j++){
                scan >> mirrorFramedAry[i][j];
                }
        }
    }
    void mirrorFramed(){
        //columns first
        for(int i=1;i<numRows+1;i++){
            mirrorFramedAry[i][0]=mirrorFramedAry[i][1];//left
            mirrorFramedAry[i][numCols+1]=mirrorFramedAry[i][numCols];//right
        };

        //rows
        for(int i=0;i<numCols+2;i++){
            mirrorFramedAry[0][i]=mirrorFramedAry[1][i];//top
            mirrorFramedAry[numRows+1][i]=mirrorFramedAry[numRows][i];//bottom
        };

        processedMirrorFramed();
        printtempAry();
    }
    void processedMirrorFramed(){
        int average;
        for(int i=1;i<numRows+1;i++){
            for(int j=1;j<numCols+1;j++){
                loadNeighbors(i,j);
                average=computeAverage();
                if(average>newMax)newMax=average;
                if(average<newMin)newMin=average;
                int* num=new int(average);
                cout << *num<<endl;
                tempAry[i,j]= num;
            }
        }
        cout<< "this is "<<tempAry[3,3]<<endl;
    }

private:
    void loadNeighbors(int row,int column){
        int count=0;
        for(int i=row-1;i<=row+1;i++){
            for(int j=column-1;j<=column+1;j++){
                neighborAry[count]= mirrorFramedAry[i][j];
                count++;
            }
        }
    }
    int computeAverage(){
        int sum=0;
        for(int i=0;i<9;i++){
            sum+=neighborAry[i];
        }
        sum=sum/9;
        return sum;
    }
    void printtempAry(){
        for(int i = 1;i < numRows+1;i++){
            for(int j=1;j< numCols+1;j++){
                out << tempAry[i][j]<<" ";
                }
                out<< endl;
        }
    }
    void printNeightbors(){
        for(int i=0;i<=9;i++){
            cout<< neighborAry[i]<<" ";
        }
    }
    void print(){
        for(int i = 0;i < numRows+2;i++){
            for(int j=0;j< numCols+2;j++){
                out << mirrorFramedAry[i][j]<<" ";
                }
                out<< endl;
        }
    }

};
int main(int argc, char *argv[])
{
    Averaging processor(argv[1], argv[2]);
    processor.loadImage();
    processor.mirrorFramed();
    return 0;
}