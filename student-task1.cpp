// Student class is implemented based on string and does not need any changes

#include <iostream>
#include <string>
#include <cstring>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{ 
    Student students[100];

    char name[100];
    double grade;
    int numStudents = 0; 
    while(true){
        cout << "Enter student " << numStudents+1 << " (name ENTER grade, type \"q\" to finish):\n";
        cin >> name;
        if (name[0] == 'q'){
            cout << "Finished.\n";
            break;
        }
        cin >> grade;
        Student temp(name, grade);
        students[numStudents] = temp;
        numStudents++;
        if(numStudents == 100){
            cout << "Max of 100 students has been reached, moving on.\n";
            break;
        }
    }
    cout << numStudents << " students have been stored.\n";
    for(int j = 0; j<numStudents; j++){
        cout << students[j] << endl;
    }

    cout << "\nNow storing students in a list in order of increasing grade.\n";
    list<Student> classroom;
    list<Student>::iterator index;
    for(int i=0; i<numStudents; i++){
        index = classroom.begin();
        //insert students in order of increasing grade
        while(students[i].getgrade() > (*index).getgrade() && index != classroom.end()){
            ++index;
        }
        classroom.insert(index, students[i]);

    }

    for(index = classroom.begin(); index != classroom.end(); index++){
        cout << *index << endl;
    }

    cout << "\nNow storing students in a list in order of decreasing grade.\n";
    list<Student>::reverse_iterator rev;
    for(rev = classroom.rbegin(); rev != classroom.rend(); rev++){
        cout << *rev << endl;
    }

    return 0;
}
