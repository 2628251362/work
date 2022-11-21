package S4.s4_4;

public class S4_4 {
    public static void main(String[] args) {
        Vehicle vehicle = new Bus(4, 20);
        vehicle.display();
        vehicle = new Motorcycle(2, 2);
        vehicle.display();
    }
}
abstract class Vehicle {
    int wheelNum;
    int seatNum;
    abstract void display();
}
class Bus extends Vehicle {
    public Bus(int wheelNum,int seatNum) {
        this.wheelNum=wheelNum;
        this.seatNum=seatNum;
    }
    void display() {
        System.out.println("Bus has "+wheelNum+" wheels and "+seatNum+" seats.");
    }

}
class Motorcycle extends Vehicle {
    public Motorcycle(int wheelNum,int seatNum){
        this.wheelNum=wheelNum;
        this.seatNum=seatNum;
    }
    void display() {
        System.out.println("Motorcycle has " + wheelNum + "  wheels and " + seatNum + " seats." );
    }
}