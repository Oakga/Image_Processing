import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

class main {
    int histogram;
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    int thresholdValue;
    Scanner input;
    PrintWriter output;

    void histogram(File inFile, File outFile, int thresholdValue){
        try{
            output = new PrintWriter(outFile, "UTF-8");
            input = new Scanner(inFile);
            int num;
            this.thresholdValue = thresholdValue;
            numRows = input.nextInt();
            numCols = input.nextInt();
            minVal = input.nextInt();
            maxVal = input.nextInt();

        } catch (IOException e){
            e.printStackTrace();
        }
    }
    public static void main(String args[]) throws FileNotFoundException {
        File inFile = new File(args[0]);
        File outFile = new File(args[1]);
}
}