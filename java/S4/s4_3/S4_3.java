package S4.s4_3;

import java.util.Random;

public class S4_3 {
    public static void main(String[] args) {
        graduate g = new graduate();
        student stu=new student();
        int x = g.salary();
        System.out.println("研究生的工资为：" + x);
        if(x<stu.cost){
            System.out.println("撸起袖子加油干");
        }else{
            System.out.println("好好享受生活");
        }
    }
}
class student{
    int cost=1000;
}
interface employee{
    int salary();
}
class graduate extends student implements employee{
        public int salary(){
            int shouru=0;
            Random r=new Random();
            shouru=r.nextInt(2000)+1000;
            return shouru;
    }
}