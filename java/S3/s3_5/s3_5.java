package S3.s3_5;

public class s3_5 {
    public static void main(String[] args) {
        int x = 1, y = 2;
        num n1=new num();
        num n2=new num(1,2);
        num n3=new num(1,2);
        num n4=new num(1,2);
        n1.add(x, y);
        System.out.println("add之后的x和y：" + x + "," + y);
        n2.add(n2);
        System.out.println("第二次add之后的x和y：" + n2.x + "," + n2.y);
        n3.add(n4);
        System.out.println("n3的值：" + n3.x + "," + n3.y);
        System.out.println("第三次add之后的x和y：" + n4.x + "," + n4.y);
    }
}
