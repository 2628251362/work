package S3.s3_7;

import java.util.Scanner;

public class guyuan {
    public String[] number = new String[1024];
    public String[] name = new String[1024];
    public String[] age = new String[1024];
    public String[] pos = new String[1024];
    public String[] dep = new String[1024];
    public int attendance = 0;// 出勤人数
    int n = 0;// 应到人数

    public guyuan() {
    }

    public void information() {
        System.out.println("应到：" + n);
        System.out.println("出勤人数为：" + attendance);
        System.out.println("出勤人员信息：");
        for (int i = 0; i < attendance; i++) {
            System.out.println("编号：" + number[i]);
            System.out.println("姓名：" + name[i]);
            System.out.println("年龄：" + age[i]);
            System.out.println("职务：" + pos[i]);
            System.out.println("部门：" + dep[i]);
        }
    }

    // 签到函数
    public void sign() {
        System.out.println("请输入员工总人数：");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.println("请输入编号：");
            number[i] = sc.next();
            System.out.println("请输入姓名：");
            name[i] = sc.next();
            System.out.println("请输入年龄：");
            age[i] = sc.next();
            System.out.println("请输入职务：");
            pos[i] = sc.next();
            System.out.println("请输入部门：");
            dep[i] = sc.next();
            attendance++;
            System.out.println("你是否是最后一个签到的人，若是，则输入0，否则输入1：");
            int j = 0;
            j = sc.nextInt();
            if (j == 0)
                break;
        }
    }

}