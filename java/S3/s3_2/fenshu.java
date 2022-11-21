package S3.s3_2;

public class fenshu {
    public int fson;
    public int fmom;

    public static int gongyue(int a, int b) {
        if (a < b) {
            int c = b;
            b = a;
            a = c;
        }
        int r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        if (b < 1)
            b = -b;
        return b;
    }

    public void add(int fson1, int fmom1, int fson2, int fmom2) {
        int fm = fmom1 * fmom2;
        int fs = fson1 * fmom2 + fson2 * fmom1;
        int g = gongyue(fs, fm);
        fs /= g;
        fm /= g;
        System.out.println("两数相加结果为:" + fs + "/" + fm);
    }

    public void sub(int fson1, int fmom1, int fson2, int fmom2) {

        int fm = fmom1 * fmom2;
        int fs = fson1 * fmom2 - fson2 * fmom1;
        int g = gongyue(fs, fm);
        fs /= g;
        fm /= g;
        System.out.println("两数相加结果为:" + fs + "/" + fm);
    }

    public void mul(int fson1, int fmom1, int fson2, int fmom2) {
        int fm = fmom1 * fmom2;
        int fs = fson1 * fson2;
        int g = gongyue(fs, fm);
        fs /= g;
        fm /= g;
        System.out.println("两数相乘的结果为；" + fs + "/" + fm);
    }

    public void chu(int fson1, int fmom1, int fson2, int fmom2) {
        int fm = fmom1 * fson2;
        int fs = fson1 * fmom2;
        int g = gongyue(fs, fm);
        fs /= g;
        fm /= g;
        System.out.println("两数相除的结果为；" + fs + "/" + fm);
    }
}
