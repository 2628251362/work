package S2;
import java.util.Scanner;
public class S2_2_2 {
    public static void main(String[] args){
        int a,b;
        Scanner scan=new Scanner(System.in);
        System.out.println("请输入2个整数");
        a=scan.nextInt();
        b=scan.nextInt();
        scan.close();
        if(a>b){
            System.out.println(b+" "+a);
        }else if(a<b){
            System.out.println(a+" "+b);
        }
        System.out.println();
    }
}
