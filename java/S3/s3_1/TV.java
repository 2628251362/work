package S3.s3_1;

public class TV {
    int Switch = 0;
    int Channel = 0;
    int voice = 0;
//开关机
    public void Switch(int Switch) {
        if (Switch == 1) {
            System.out.println("开机成功");
        } else if (Switch == 0) {
            System.out.println("关机成功");
        }
        this.Switch = Switch;
    }
//换台
    public void changeChannel(int channel) {
        if (channel >=1) {
            this.Channel = channel;
            System.out.println("当前频道为：" + channel);
        }
    }
//调音量
    public void Voice(int setvoice) {
        if (setvoice == 1) {
            if (voice <= 3) {
                voice++;
            } else {
                System.out.println("音量已达到最大");
                return;
            }
        } else if (setvoice == 0) {
            if(voice<=0){
                System.out.println("音量已经达到最小");
                return;
            }
            else voice--;
        }
    }
}
