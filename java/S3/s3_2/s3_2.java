package S3.s3_2;

import java.util.Scanner;

public class s3_2 {
    public static void main(String[] args) {

        fenshu fenshu = new fenshu();

        System.out.println("请输入第一个分数的分子：");
        Scanner sc1 = new Scanner(System.in);
        int fson1 = sc1.nextInt();

        System.out.println("请输入第一个分数的分母：");
        Scanner sc2 = new Scanner(System.in);
        int fmom1 = sc2.nextInt();

        System.out.println("请输入第二个分数的分子：");
        Scanner sc3 = new Scanner(System.in);
        int fson2 = sc3.nextInt();

        System.out.println("请输入第二个分数的分母：");
        Scanner sc4 = new Scanner(System.in);
        int fmom2 = sc4.nextInt();

        fenshu.add(fson1, fmom1, fson2, fmom2);
        fenshu.sub(fson1, fmom1, fson2, fmom2);
        fenshu.mul(fson1, fmom1, fson2, fmom2);
        fenshu.chu(fson1, fmom1, fson2, fmom2);
        sc1.close();
        sc2.close();
        sc3.close();
        sc4.close();
    }
}
