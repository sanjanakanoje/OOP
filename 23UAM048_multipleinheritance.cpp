#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    // Constructor 
    Person(string n, int a) : name(n), age(a) {}

    // Virtual function display() 
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class Student from Person
class Student : public virtual Person {
protected:
    int rollNumber;
    string branch;
    float marks[5];
    float CGPA;

public:
    Student(string n, int a, int roll, string br, float m[5]) : Person(n, a), rollNumber(roll), branch(br) {
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }
        calculateCGPA();
    }

    // Function to calculate CGPA
    void calculateCGPA() {
        float totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            totalMarks += marks[i];
        }
        CGPA = totalMarks / 5.0;  
    }

    // Overridden
    void display() override {
        Person::display();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Branch: " << branch << endl;
        cout << "CGPA: " << CGPA << endl;
    }
    friend class Administration;
};

// Derived class Faculty from Person
class Faculty : public virtual Person {
protected:
    int facultyID;
    string department;
    float salary;

public:
    Faculty(string n, int a, int id, string dept, float sal) : Person(n, a), facultyID(id), department(dept), salary(sal) {}

    // Overridden
    void display() override {
        Person::display();
        cout << "Faculty ID: " << facultyID << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
    friend class Administration;

};

// Derived class TeachingAssistant (Multiple Inheritance)
class TeachingAssistant : public Student, public Faculty {
public:
    TeachingAssistant(string n, int a, int roll, string br, float m[5], int id, string dept, float sal)
        : Person(n, a), Student(n, a, roll, br, m), Faculty(n, a, id, dept, sal) {}

    // Overridden 
    void display() override {
        Student::display();
        Faculty::display();
    }
};

// Administration class with friend function
class Administration {
public:
    // Friend function 
    void displayProtectedDetails(Student& s, Faculty& f) {
        cout << "Accessing Protected Details from Administration" << endl;
        cout << "Student " << s.name <<" from " <<s.branch<<" scored "<<s.CGPA<<" CGPA"<<endl;
        cout << "Faculty teaches "<< f.department<<endl;
    }
};

int main() {
    float studentMarks[5] = {8.6, 8.2, 8.4, 7.9, 9.0};
    
    Student s1("Sanjana Kanoje", 20, 48, "CSE(AI-ML)", studentMarks);
    Faculty f1("ABC", 38, 207, "Computer Science(Artificial Intelligence & Machine Learning)", 90000);
    TeachingAssistant ta1("xyz", 30, 212, "AI-ML", studentMarks, 1002, "AI-ML", 60000);
    
    cout << "Student Details: " << endl;
    s1.display();
    cout << endl;
    
    cout << "Faculty Details: " << endl;
    f1.display();
    cout << endl;
    
    cout << "Teaching Assistant Details: " << endl;
    ta1.display();
    cout << endl;
    
    // Using Administration class 
    Administration admin;
    admin.displayProtectedDetails(s1, f1);

    return 0;
}
