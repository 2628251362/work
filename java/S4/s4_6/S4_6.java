package S4.s4_6;

public class S4_6 {
    public static void main(String[] args) {
        Outer.method().intruduce();
    }
}
interface Inner{
    void intruduce();
}
class Outer{
    static Inner method(){
        return new Inner(){
            public void intruduce(){
                System.out.println("我是匿名内部类");
            }
        };
    }
}

