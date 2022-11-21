package work;

import java.util.Scanner;
import java.math.*;
public class test1 {
    public static void main(String[] args) {
        double s;
        System.out.println("输入边长");
        Scanner sc=new Scanner(System.in);
        s=sc.nextInt();
        double q;
        q=(6*Math.sqrt(s))/(4*(Math.tan(Math.PI/6)));
        
        System.out.println("六边形面积为"+q);      
    }
}