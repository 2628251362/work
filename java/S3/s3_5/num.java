package S3.s3_5;

public class num {
    int x;
    int y;

    public num() {

    }

    public num(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void add(int x, int y) {
        x += 10;
        y += 20;
    }

    public void add(num n) {
        n.x += 10;
        n.y += 20;
    }
}
