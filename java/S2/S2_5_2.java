package S2;
public class S2_5_2 {
    public static void main(String[] args) {
        int i;
        for ( i=0; i < 10000; i++)
         {
            if(i%2==1 && i%3==0 && i%4==1 &&  i%5==4 &&  i%6==3 &&  i%7==0 &&  i%8==1 &&  i%9==0 )break;       
        }
        System.out.println("鸡蛋个数："+i);
    }
}