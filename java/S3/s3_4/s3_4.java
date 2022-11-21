package S3.s3_4;

import java.util.Scanner;
public class s3_4 {
    public static void main(String[] args) {
        System.out.println("现在进行两整数最大值比较");
        int a = twoMax();
        System.out.println("两整数数最大值为:" + a);
        System.out.println("现在进行三整数最大值比较");
        int b = threeMax();
        System.out.println("三整数最大值为:" + b);
        System.out.println("现在进行三小数最大值比较");
        float c = threemax();
        System.out.println("三小数最大值为:" + c);
    }
//两整数最大值
    public static int twoMax() {
        int a, b, r = 0;
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入2个整数");
        a = scan.nextInt();
        b = scan.nextInt();
        if (a > b) {
            r = a;
        } else if (a < b) {
            r = b;
        }
        return r;
    }
//三整数数最大值
    public  static int threeMax(){
        int a,b,c,r=0;
        Scanner scan=new Scanner(System.in);
        System.out.println("请输入3个整数");
        a=scan.nextInt();
        b=scan.nextInt();
        c=scan.nextInt();
        r=(a>b)?(a>c?a:c):(b>c?b:c);
        return r;
    }
//三小数最大值
    public static float threemax()
    {
        float a,b,c,r=0;
        Scanner scan=new Scanner(System.in);
        System.out.println("请输入3个小数");
        a=scan.nextFloat();
        b=scan.nextFloat();
        c=scan.nextFloat();
        r=(a>b)?(a>c?a:c):(b>c?b:c);
        return r;
    }
}
