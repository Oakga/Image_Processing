import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class histogram {
    int histogram;
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    int thresholdValue;
    Scanner input;
    PrintWriter out1;

    histogram(File inFile, File outFile, int thresholdValue){
        try{
            output = new PrintWriter(outFile, "UTF-8");
            input = new Scanner(inFile);
            int num;
            this.thresholdValue = thresholdValue;
            numRows = input.next();
            numCols = input.next();
            minVal = input.next();
            maxVal = input.next();

        } catch (IOException e){
            e.printStackTrace();
        }
    }
}

public static void main(String args[]) throws FileNotFoundException {
        File inFile = new File(args[0]);
        File outFile = new File(args[1]);
}