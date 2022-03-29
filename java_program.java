import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.text.*;


class java_program{
    public static void main(String arg[]){
        File file=new File("input.txt");
        try{
            Scanner scaner=new Scanner(file);
            solve(scaner);
        }catch(FileNotFoundException e){
            System.out.println(e.toString());
        }
    }
    public static void solve(Scanner scanner){
        
        


    }
} 