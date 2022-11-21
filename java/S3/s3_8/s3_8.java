package S3.s3_8;

import java.util.Scanner;

public class s3_8 {
	public static void main(String[] args) {
		stu s =new stu();
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入你的姓名:");
		s.name=sc.next();
		System.out.println("请输入你的学号：");
		s.sno = sc.nextInt();
		card c = new card();
		System.out.println("请输入你的卡号：");
		c.cno=sc.nextInt();
		book b = new book ("三体",01);
		System.out.println("请输入你要借阅的图书：");
		String bn = sc.next();
			if(bn.equals(b.bname)){
				System.out.println("卡号为"+c.cno+"的 "+s.name+"借到了《三体》");
			}
			else {
				System.out.println("卡号为"+c.cno+"的 "+s.name+"没有借到《三体》");
			}
	}
}
