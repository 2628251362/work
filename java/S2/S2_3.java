package S2;
import java.util.Scanner;
public class S2_3 {
    public static void main(String[] args)
    {
        int a=0;
        Scanner scan=new Scanner(System.in);
        scan.close();
        for(int i=0;i<10;i++)
        {
            a+=scan.nextInt();           
        }
        System.out.println("这10个数的和为"+a);
    }
}