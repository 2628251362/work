package S4.s4_2;

public class S4_2 {
    public static void main(String[] args) {
    test2 t2 = new test2();
    test1 t1 = new test1();
    
    t1.method();
    t2.method();
}}

class test1 {
    public final int AGE=10;
    public void method() {
        System.out.println("成功运行"+AGE);
    }
}

class test2 extends test1 {

    public void method() {
        System.out.println("子类重写" + AGE);
    }

}
