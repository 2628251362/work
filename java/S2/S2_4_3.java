package S2;
import java.util.*;
public class S2_4_3 {
    public static void main(String[] args) {
        System.out.println("请输入您的里程数：");
        Scanner scan=new Scanner (System.in);
        double s=scan.nextDouble();
        double sum;
        scan.close();
        if(s<=3) {
            System.out.println(s+"公里的费用是6元");
        }
        else if(s>3&&s<=9) {
            sum=(s-3)*1.3+6;
            System.out.println(s+"公里的费用是"+sum+"元");
        }
        else {
            sum=6+6*1.3+(s-9)*2;
            System.out.println(s+"公里的费用是"+sum+"元");
        }
    
    }
    
}
