package S3.s3_6;

public class s3_6 {

    public static void main(String[] args) {
        student.age = 18;
        student.show2();
        student stu = new student("1111", 18);
        stu.show1();
        stu.show2();
        System.out.println("第一次用类名调用静态方法：");
        student.show2();
        System.out.println("第二次用类名调用静态方法，但是通过对象对age值进行过修改：");
        stu.age = 33;
        student.show2();
    }
}
