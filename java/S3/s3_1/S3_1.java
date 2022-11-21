package S3.s3_1;

import java.util.Scanner;

public class S3_1 {
    public static void main(String[] args) {
        TV tv = new TV();
        System.out.println("1.开机");
        System.out.println("0.关机");
        System.out.println("请输入你的选择:");
        Scanner sc = new Scanner(System.in);
        int Switch = sc.nextInt();
        tv.Switch(Switch);
        while (tv.Switch == 1) {
            System.out.println("1.调节频道");
            System.out.println("2.调节音量");
            System.out.println("0.关机");
            System.out.println("请输入你的选择:");
            Scanner sc1 = new Scanner(System.in);
            int select = sc1.nextInt();
            sc1.close();
            switch (select) {
                case 1:
                    int channel;
                    System.out.println("请输入频道:");
                    Scanner sc2 = new Scanner(System.in);
                    channel = sc2.nextInt();
                    tv.changeChannel(channel);
                    break;
                case 2:
                    int voiceChange;
                    System.out.println("请输入音量调节方式：");
                    voiceChange = sc.nextInt();
                    tv.Voice(voiceChange);
                    System.out.println("现在的音量是：" + tv.voice);
                    break;
                case 0:
                    tv.Switch = 0;
                    System.out.println("关机成功");
                    break;
            }
        }
        sc.close();
    }
}
