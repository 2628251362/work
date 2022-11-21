package S4.s4_1;

public class S4_1 {
    public static void main(String[] args) {
        father f=new father();
        son s=new son();
        f.show();
        s.show(); 
    }
}

class father{//定义父类
    public void show(){
        System.out.println("老师很帅");
    }
}
class son extends father{//定义子类
    public void show(){//方法重写
        System.out.println("老师非常帅");
        super.show();//调用父类

    }
}