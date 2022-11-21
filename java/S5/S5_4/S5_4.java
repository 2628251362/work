package S5.S5_4;
import java.util.Scanner;
public class S5_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个字符串：");
        String str = sc.nextLine();
        StringBuffer sb = new StringBuffer(str);
        sb.reverse();
        System.out.println("反转后的字符串为：" + sb);
        char[] ch = { 'h', 'e', 'l', 'l', 'o', ' ', ' ', 'w', 'o', 'r', 'l', 'd' };

        for (int i = 0; i < ch.length; i++) {
            System.out.print(ch[i]);
        }
        System.out.println();
        String str1 = new String(ch);
        System.out.println("字符数组通过Sting拼接后str1为：" + str1);
        StringBuffer sb1 = new StringBuffer();
        for (int i = 0; i < ch.length; i++) {
            sb1.append(ch[i]);
        }
        System.out.println("字符数组通过StingBuffer拼接后sb1为：" + sb1);
    }
}
