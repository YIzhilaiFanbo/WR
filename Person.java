public class Person {
    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setAge(int age) {
        this.age = age;
    }
    public int getAge() {
        return age;
    }

    public void setSchool(String school) {
        this.school = school;
    }

    public String getSchool() {
        return school;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    public String getMajor() {
        return major;
    }

    Person(){
        name="麻子";
        age=18;
    }
    Person(String n,int a){
        name=n;
        age=a;
}
    Person(String n, int a, String s){
        name=n;
        age=a;
        school=s;
    }
    Person(String n, int a, String s,String m){
        name=n;
        age=a;
        school=s;
        major=m;
    }

    private String name;
    private int age;
    private String school;
    private String major;
}
