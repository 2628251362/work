package S2;
public class S2_5_1_2 {
        public static void main(String[] args) 
        {
            double sum=0;
            int a=1;
            for(int i=1;i<=20;i++)
            {
                a*=i;
                sum+=1.0/a;
            }
            System.out.println("1+1/2!+1/3!+1/4!+…的前20项之和为"+sum);
        }
    }

