package S5.S5_3;
import java.util.Scanner;
public class S5_3 {
    public static void main(String[] args) {
        System.out.println("请输入一个字符串：");
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        char ch[]=str.toCharArray();
        int da,xiao,shu,qita;
        da=xiao=shu=qita=0;
        for(int i=0;i<ch.length;i++){
            if(ch[i]>='A'&&ch[i]<='Z')
                da++;
            else if(ch[i]>='a'&&ch[i]<='z')
                xiao++;
            else if(ch[i]>='0'&&ch[i]<='9')
                shu++;
            else
                qita++;
        }
        System.out.println("大写字母个数："+da);
        System.out.println("小写字母个数："+xiao);
        System.out.println("数字个数："+shu);
        System.out.println("其他字符个数："+qita);

    } 
}
