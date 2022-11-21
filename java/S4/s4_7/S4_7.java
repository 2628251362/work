package S4.s4_7;

import java.util.Scanner;

public class S4_7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入学生性别");
        Student stu = new Student();
        String gender = input.next();
        try {
            stu.setGender(gender);
        } catch (MyException e) {
            System.out.println(e.getMessage());
        }
    }

    static class MyException extends Exception {
        public MyException(String message) {
            super(message);
        }
    }

    static class Student {
        private String name;
        private int age;
        private String gender;

        private String getGender() {
            return gender;
        }

        public void setGender(String gender) throws MyException {
            if (gender.equals("男") | gender.equals("女")) {
                this.gender = gender;
            } else {
                throw new MyException("性别输入错误");
            }
        }
    }

}