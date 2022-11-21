package work;

import java.util.Scanner;

public class test2 {
    public static void main(String[] args) {
        user u = new user();
        u.name();
    }
}

class user {
    String name;
    String password;
    String newpassword;

    public void name() {
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