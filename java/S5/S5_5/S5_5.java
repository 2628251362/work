package S5.S5_5;
import java.util.Random;
import java.util.Scanner;
public class S5_5 {
    public static void main(String[] args) {
        String str="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        char[] ch=str.toCharArray();
        StringBuffer sb=new StringBuffer();
        Random r=new Random();
        for(int i=0;i<6;i++){
            int index=(int)(r.nextInt(62));
            sb.append(ch[index]);
        }
        System.out.println("6位随机验证码为："+sb);
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入验证码：");
        String str1=sc.nextLine();
        if(str1.equals(sb.toString())){
            System.out.println("恭喜验证成功！");
    }
        else{
            System.out.println("验证码错误！");
        }
    }
}
