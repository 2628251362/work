package S5.S5_1;
import java.util.Scanner;
public class S5_1 {
    public static void main(String[] args) {
        System.out.print("明文:");
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        char [] ch = str.toCharArray();
        System.out.println("********************");
        System.out.println("加密方法：每个字符的ASCII码加1");
        System.out.println("********************");
        System.out.print("密文:");
        for (int i = 0; i < str.length(); i++) {
            ch[i] = str.charAt(i);
            ch[i] = (char) (ch[i] + 1);
            System.out.print(ch[i]);
        }
        System.out.println();
        System.out.println("********************");
        System.out.print("明文:");
        for (int i = 0; i < str.length(); i++) {
            ch[i] = (char) (ch[i] - 1);
            System.out.print(ch[i]);
        }
        System.out.println();

    }
    

}
