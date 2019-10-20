public class Person {
   private String name;
   private int age;

   public Person(String n, int a){
      this.name = n;
      this.age = a;
   }

   public String toString(){
       return "Name:" + this.name + " Age: " + this.age;
   }

   public void setAge(int n){
       if (n < 0){
           // this line is a comment, we want to finish method and not modify the age
           return;
       }
       this.age = n;

    }
}
