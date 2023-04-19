import java.util.*;
class Employee
{
	String name;
	int age;
	long phone;
	String address;
	double salary;
	public void print salary()
	{
		System.out.println("the salary of person:"+this.salary);
	}
	class officer extends Employee
	{
		String specification;
	}
	class manager extends Employe
	{
		String department;
	}
	class 
	{
		public static void main(String a[])
		{
			officer o=new officer();
			manager m=new manager();
			Scanner sc=new Scanner();
			System.out.println("enter the following deatails");
			o.name=sc.nextLine();
			o.age=sc.nextInt();
			o.phone=sc.nextLong();
			sc.nextLine();
			o.address=sc.nextLine();
			sc.nextLine();
			specification sc.nextLine();
			System.out.println("Name"+o.name+"age:"+o.age+"phone:+o.phone+"address:"+o.address+"specialization:"+o.specialization);
			o.printsalary();
			System.out.println("enter the details of manager:");
			m.name=sc.nextLine():
			m.age=sc.nextInt():
			m.phone=sc.nextLong();
			sc.nextLine();
			m.address=sc.nextLine();
			m.salary=sc.nextDouble();
			sc.nextLine():
			m.department=sc.nextLine();
			System.out.println("name:"+m.name+"age:"+m.age+"phone:"+m.phone+"address:"+m.address+"department:"+m.department);
			m1.print salary();
		}
	}
}
