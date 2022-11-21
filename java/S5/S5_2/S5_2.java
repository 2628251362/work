package S5.S5_2;

import java.io.IOException;
import java.util.Scanner;

public class S5_2 {
    public static void main(String[] agrs) {
        user u = new user();
        u.user();
        login l = new login();
        if (l.login() == 1) {
            System.out.println("登录成功");
            // 打开文件
            try {
                Runtime.getRuntime().exec("calc.exe");
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}

class user {
    static String name;
    static String password;
    String newpassword;

    public void user() {
        System.out.println("现在进行用户注册");
        System.out.println("请输入用户名");
        Scanner sc = new Scanner(System.in);
        name = sc.next();
        while (name.length() < 3) {
            System.out.println("name长度不够");
            System.out.println("请重新输入用户名");
            name = sc.next();
        }
        System.out.println("请输入密码");
        password = sc.next();
        while (password.length() < 6) {
            System.out.println("password长度不够");
            System.out.println("请重新输入密码");
            password = sc.next();
        }
        System.out.println("请再次输入密码");
        newpassword = sc.next();

        while (password.equals(newpassword) == false) {
            System.out.println("两次密码不一致");
            System.out.println("请重新输入密码");
            newpassword = sc.next();
        }
        System.out.println("注册成功");
    }
}

class login {
    String name1;
    String password1;

    public int login() {
        int flag = 0;
        System.out.println("现在进行用户登录");
        for (int i = 0; i < 3; i++) {

            System.out.println("请输入用户名");
            Scanner sc = new Scanner(System.in);
            name1 = sc.next();
            System.out.println("请输入密码");
            password1 = sc.next();
            if (name1.equals(user.name) && password1.equals(user.password)) {
                flag = 1;
                break;
            } else {
                System.out.println("用户名或密码错误");
                if (i == 2) {
                    System.out.println("你已经输错三次，程序退出");
                    System.exit(0);
                }
            }
        }
        return flag;
    }
}
