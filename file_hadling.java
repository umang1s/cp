import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class file_hadling {

    public static void main(String argv[]){
        File file = new File("my_file.txt");
        if(file.exists()){ 
            System.out.println("File is available");
            try{
                Scanner scanner =new Scanner(file);
                System.out.println("Reading the data from file");
                while(scanner.hasNextLine()){
                    String str= scanner.nextLine();
                    System.out.println(str);
                }
            }catch(Exception e){
                System.out.println(e);
            }


        }
        else{
            System.out.println("File not found");
            try{
                file.createNewFile();
            }catch(Exception e){
                System.out.println("Failed to create files");
            }
            
        }
        System.out.println(file.getAbsolutePath());
        System.out.println("Read : "+file.canRead());
        System.out.println("Write : "+file.canWrite());
        System.out.println("FileName : "+file.getName());
        System.out.println("Length : "+file.length());
        //file.mkdir() for making directory.
        //file.delete() for deleting the file.

        try{
            FileWriter fileWriter= new FileWriter(file.getName());
            fileWriter.write("Hey man My name is Umang  dsff fdsfs sfs");
            fileWriter.close();
        }catch(IOException e){
            System.out.println(e);
        }

    }
    
}
