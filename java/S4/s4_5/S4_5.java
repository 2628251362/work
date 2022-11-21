package S4.s4_5;

public class S4_5 {
    public static void main(String[] args) {
        stuff s = new stuff("小明", 18, 12120, 2000, 3);
        s.salary();
        manager m = new manager("李强", 18, 12121, 4000, 4);
        m.salary();
    }

}

class stuff {
    protected String name;
    protected int age;
    protected int number;
    protected double salary;
    protected int wage;

    public stuff(String name, int age, int number, double salary, int wage) {
        this.name = name;
        this.age = age;
        this.number = number;
        this.salary = salary;
        this.wage = wage;
    }

    void salary() {
        this.salary = salary * (1 + 0.1);
        System.out.println(name + "员工的工资为：" + salary);
    }
}

class manager extends stuff {
    public manager(String name, int age, int number, double salary, int wage) {
        super(name, age, number, salary, wage);
    }
    void salary() {
        this.salary = salary * (1 + 0.2);
        System.out.println(name + "经理的工资为：" + salary);
    }
}