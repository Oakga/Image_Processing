import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class main{
    public static void main(String args[]) throws FileNotFoundException {
            File inFile = new File(args[0]);
            File outFile = new File(args[1]);

            Scanner in = new Scanner(System.in);
            System.out.println("thresholdValue:");
            int thresholdValue = in.nextInt();
            in.close();

            histogram processor = new histogram(inFile, outFile, thresholdValue);
            processor.computeHistogram();
    }
}
class histogram {
    int[] histogram;
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    int thresholdValue;
    File inFile;
    File outFile;
    histogram(File inFile, File outFile, int thresholdValue){
        try{
            this.inFile = inFile;
            this.outFile = outFile;
            this.thresholdValue = thresholdValue;
            numRows = input.nextInt();
            numCols = input.nextInt();
            minVal = input.nextInt();
            maxVal = input.nextInt();
            histogram = new int[maxVal+1];
            input.close(); 
            computeHistogram();
        } catch (IOException e){
            e.printStackTrace();
        }
    }
    void computeHistogram(){
        try{
        int pixel, maxPlus;
        PrintWriter output = new PrintWriter(outFile, "UTF-8");
        Scanner input = new Scanner(inFile);
        input.nextInt();
        System.out.print(input.next());
        while(input.hasNextInt()){
            pixel = input.nextInt();
            histogram[pixel]++;
        }
        output.write(numRows+" "+numCols+" "+minVal+" "+maxVal+"\n");
        for(int i=0;i< maxVal;i++){
            output.write("(" +i+"): "+ histogram[i]);
            if(histogram[i]> 80) maxPlus = 80;
            else maxPlus = histogram[i];
            for(int j = 0; j< maxPlus; j++){
                output.write("+");
            };
            output.write("\n");
        }
        output.write("\n");
        input.close();
        output.close();
    } catch (IOException e){
        e.printStackTrace();
    }
    }

    void computeThreshold(){
        int[][] binaryImage = new int[numRows][numCols];
        int pixel = 0;
    }
}
