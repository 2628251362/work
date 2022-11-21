package S3.s3_6;

public class student {
    public String number;
    public static int age;
 
    public student() {
 
    }
 
    public student(String number, int age) {
        this.number = number;
        this.age = age;
    }
 
    public void show1() {
        System.out.println("该学生的学号为：" + number + ",该学生的年龄为：" + age);
    }
 
    public static void show2() {
        System.out.println("该学生的年龄为" + age);
    }
}
