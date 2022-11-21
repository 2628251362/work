package S2;
import java.util.Scanner;
public class S2_2_1 {
    public static void main(String[] args){
        int a,b,c;
        Scanner scan=new Scanner(System.in);
        System.out.println("请输入3个整数");
        a=scan.nextInt();
        b=scan.nextInt();
        c=scan.nextInt();
        scan.close();
        int d;
        d=(a>b)?(a>c?a:c):(b>c?b:c);
        System.out.println("三个数的的最大值为"+d);
    }
}
