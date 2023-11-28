import java.util.Scanner;
public class Caculate {
    public static void main(String args[]){
        int y[]=new int[4];
        char x;
        Scanner input=new Scanner(System.in);
        String s=input.nextLine();
        int l=s.length()-1;
        while(l>=0){
            x= s.charAt(l);
            if ((x-'a'>=0&&x-'a'<26) || (x-'A'>=0&&x-'A'<26)){
                y[0]++;
            }
            else
            if (x-'0'<10&&x-'0'>0){
                y[1]++;
            }
            else
            if (x==' '){
                y[2]++;
            }
            else
                y[3]++;
            l--;
        }
        for (int i=0;i<4;i++){
            System.out.println(y[i]);
        }
    }
}
