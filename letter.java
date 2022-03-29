import java.util.*;
import java.io.*;
public class letter {
    public static void main(String arg[]){
        File file=new File("letter.txt");
        String arr[][]=new String[128][8];
        try{
            Scanner scanner=new Scanner(file);
            for(int i=0; i<26; i++){
                String c=scanner.next();
                int ind=c.charAt(0);
                for(int j=0; j<8; j++) arr[ind][j]=scanner.nextLine();
            }
        }catch(FileNotFoundException e){
            System.out.println("File Error");
        }
        Scanner scanner=new Scanner(System.in);
        String name="I love My India";
        String exit="exit";
        while(!name.equals(exit)){
            String value=name.toUpperCase();
            for(int i=0; i<value.length(); i++){
                int ind=value.charAt(i);
                if(ind>64 && ind<91) for(int j=0; j<8; j++) System.out.println(arr[ind][j]);
                else System.out.println("\n\n\n\n\n\n");
                System.out.println(" ");
            }
            name=scanner.nextLine();
        }

    }
}
