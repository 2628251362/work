package S2;
import java.util.Scanner;
public class S2_4_1 {
    public static void main(String[] args)
    {
        int a;
        Scanner scan=new Scanner(System.in);
        a=scan.nextInt();
        scan.close();
        if(a>12||a<0)
        {
            System.out.println("请输入正确的月份");
        }else
        {
            switch(a)
            {
                case 3:
                case 4:
                case 5:System.out.println("春季");
                case 6: 
                case 7:
                case 8:System.out.println("夏季");
                case 9: 
                case 10:
                case 11:System.out.println("秋季");
                case 12:
                case 1:
                case 2: System.out.println("冬季");
            }
        }
    }
}
