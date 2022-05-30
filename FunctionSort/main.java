import java.util.*;
public class main{
    static class Student implements Comparable<Student>{
        int id;
        String name;
        int age;
        public Student(int id, String name, int age){
            this.id = id;
            this.name = name;
            this.age = age;
        }
        @Override
        public String toString(){
            return "Student [id=" + id + ", name=" + name + ", age=" + age + "]";
        }
        @Override
        public int compareTo(Student o){
            Student s = (Student)o;
            if(this.age > s.age){
                return 1;
            }else if(this.age < s.age){
                return -1;
            }
            return 0;
        }
    }
    public static void main(String[] args) {
        // int[] a=new int[]{1,-100,3,4,5};
        // Arrays.sort(a);
        // System.out.println(Arrays.toString(a));
        // String[] s=new String[]{"g","h","c","d","e"};
        // Arrays.sort(s);
        // System.out.println(Arrays.toString(s));
        Student[] stu=new Student[]{new Student(1,"a",20),new Student(2,"b",21),new Student(3,"c",22)};
        Arrays.sort(stu,new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.age-o2.age;
            }
        });
        System.out.println(Arrays.toString(stu));



    }
}