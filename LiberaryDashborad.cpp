#include <iostream>
#include <cstdlib>
using namespace std;

class person{
    string fname;
    string lname;
    string email;
public:
    person(){};
    person(string fname, string lname, string email) : fname(fname), lname(lname), email(email){};
    string getFname() { return fname; };
    string getLname() { return lname; };
    string getEmail() { return email; };
    void setFname(){
        cout << "First name: ";
        cin>>fname;
    };
    void setLname(){
        cout << "Last name: ";
        cin>>lname;
    };
    void setEmail(){
        cout<< "Email: ";
        cin>>email;
    };
    void retrivefName(string f, string l, string e){
        fname = f; lname = l; email = e;
    }
    void retriveEmail(string e){
        email = e;
    }
};

class lecturer : public person{
    string acadamic_title;
public:
    lecturer(){};
    lecturer(string f, string l, string e, string aT):person(f,l,e),acadamic_title(aT){};
    string getAcadamic_title() { return acadamic_title; };
};

class students : public person{
    int matriculation_number;
    string university;
    int N_courses;
public:
    students(){};
    int getMatriculation_number(){return matriculation_number;};
    string getUniversity(){return university;};
    int getNcourses(){return N_courses;};
    void setMatriculation_number(){
        cout<<"Matriculation Number : ";
        cin>>matriculation_number;
    };
    void setUniversity(){
        cout<<"University : ";
        cin>>university;
    };
    void registerNcourses(){ N_courses++; };
    void retrivedStudentData(students s);
};

void students::retrivedStudentData(students s){
    matriculation_number = s.getMatriculation_number();
    university = s.getUniversity();
    N_courses = s.getNcourses() + 1;
    retrivefName(s.getFname(),s.getLname(),s.getEmail());
}

class courses{
    string name;
    lecturer lec;
    students participants[10];
    int N_participants=0;
    bool status= false;
public:
    courses(){};
    courses(string n, lecturer l):name(n),lec(l){};
    string getName(){return name;};
    lecturer getlecturer(){return lec;};
    void printAllParticipants();
    void msgCourseStatus();
    void msgCourseAvailability();
    void msgEndEnrollment();
    bool getStatus(){return status;};
    int registration(students student[], int TotalStudents);
};

void courses::printAllParticipants(){
    cout<<"Course name: "<<name<<endl;
    cout<<"This is list participants of " <<name<< " course as follows"<<endl;
    cout<<"[No] - First name - Last name - matriculation_number - University - Email address "<< endl;
    if(N_participants==0){
        cout<<"No participants enrolled at instance"<<endl<<endl;
        return;
    }
    else{
        for(int i=0;i<N_participants;i++){
            cout<<"["<<i+1<<"] "<<participants[i].getFname()<<" "<<participants[i].getLname()<<" -\t"<<participants[i].getMatriculation_number()<<" -\t"<<participants[i].getUniversity()<<" -\t"<<participants[i].getEmail()<<endl;
        }
    }
}

void courses::msgCourseStatus(){
    if(status==false){cout<<"Not Enough Participants. Add " <<4-N_participants <<" to initiate course.";}
    else if(N_participants==10){cout<<"Not Enough seats for Enrollment";}
    else{cout<<"There are "<<10-N_participants<<" places available for enrollment";}
    cout<<endl<<endl;
}

void courses::msgCourseAvailability(){
    if(status==true){return;}
    cout<<"Course name: "<<name<<endl;
    cout<<"Lecturer: "<<lec.getAcadamic_title()<<" "<<lec.getFname()<<" "<<lec.getLname()<<" \tEmail of lecturer : "<<lec.getEmail()<<endl;
    cout<<"Number of participants enrolled: "<<N_participants<<endl;
    cout<<"Number of participants required for initiate the course : "<<10-N_participants<<endl<<endl;
}

void courses::msgEndEnrollment(){
    if(status==true){return;}
    cout<<"The "<<name<<" course is not going to take place inform below related course members"<<endl;
    cout<<"Lecturer :- "<<endl;
    cout<<lec.getAcadamic_title()<<" "<<lec.getFname()<<" "<<lec.getLname()<<" \tEmail of lecturer : "<<lec.getEmail()<<endl<<endl;
    cout<<"Students participants : -";
    for(int i=0;i<N_participants;i++){
        cout<<"["<<i+1<<"] "<<participants[i].getFname()<<" "<<participants[i].getLname()<<"-\t"<<participants[i].getEmail()<<endl;
    }
}

int courses::registration(students student[], int T){
    string email;
    cout<<"Enter Student Email: ";
    cin >> email;
    for(int i=0;i<T;i++){
        if(student[i].getEmail()==email){
            if( student[i].getUniversity() != "DIT" ||
                student[i].getUniversity() != "Deggendorf Institute of Technology" ||
                student[i].getUniversity() != "Techniche Hochschule Deggendorf" ||
                student[i].getUniversity() != "THD" )
            {
                if( student[i].getNcourses() == 1){
                    cout<<"Student is not allowed due to Entrollment in multiple courses"<< endl;
                    system("pause");
                    return T;
                }
            }
            else{
                for(int i=0; i<N_participants; i++){
                    if(participants[i].getEmail() == email){
                        cout<<"Student is aleready enrolled"<< endl;
                        system("pause");
                        return T;
                    }
                }
            }
            participants[N_participants].retrivedStudentData(student[i]);
            N_participants++;
            cout<<"Student Sucessfully Updated"<< endl;
            system("pause");
            return T;
        }
    }
    student[T].retriveEmail(email);
    student[T].setFname();
    student[T].setLname();
    student[T].setMatriculation_number();
    student[T].setUniversity();
    student[T].registerNcourses();
    participants[N_participants].retrivedStudentData(student[T]);
    cout<<"Student is successfully enrolled"<< endl;
    T++;
    N_participants++;
    if(N_participants>3){
        status = true;
    }
    system("pause");
    return T;
}

int mainMenu(){
    int selector;
    system("cls");
    cout << "Welcome to the student registration platform"<<endl;
    cout << "--------------------------------------------"<<endl<<endl;
    cout << "************** Main page **************" << endl;
    cout << "[1] Register for a course" << endl;
    cout << "[2] Show a course" << endl;
    cout << "[3] Show all courses" << endl;
    cout << "[4] Exit & Show all courses that are not fully booked" << endl;
    cout << "Select the option to proceed (type a number and press enter) : ";
    cin >> selector;
    system("cls");
    return selector;
}

int course_selector(){
    int selector;
    cout << "[1] Programming course"<< endl;
    cout << "[2] Databses course"<< endl;
    cout << "[3] Software Engineering course"<< endl;
    cout << "[4] All course"<< endl;
    cout << "[0] Exit to main menu"<< endl;
    cout << "Select Course From above: ";
    cin >> selector;
    system("cls");
    return selector;
}

int participantsPrintMenu(){
    int selector;
    cout << "[1] Programming course participants"<< endl;
    cout << "[2] Databses course participants"<< endl;
    cout << "[3] Software Engineering course participants"<< endl;
    cout << "[4] Show all courses and their participants"<<endl;
    cout << "[0] Exit to main menu"<< endl;
    cout << "Select Course From above: ";
    cin >> selector;
    system("cls");
    return selector;
}

int main(){
    int selector = 1, registredStudent = 0;
    lecturer lec[3];
    lec[0] = lecturer("patel","shiv","patel121@gmail.com","Doc.");
    lec[1] = lecturer("jaiswal", "shub", "doctor2091@gmail.com", "Prof.");
    lec[2] = lecturer("ishana", "julia", "theishana@gmail.com","Prof.");
    courses course[3];
    course[0] = courses("Programming", lec[0]);
    course[1] = courses("Databases", lec[1]);
    course[2] = courses("Software Engineering", lec[2]);
    students student[30];
    while(selector!=4){
        selector = mainMenu();
        switch (selector)
        {
        case 1:
            selector = course_selector();
            switch (selector)
            {
            case 1:
                {
                    registredStudent = course[0].registration(student, registredStudent);
                    break;
                }
            case 2:
                {
                    registredStudent = course[1].registration(student, registredStudent);
                    break;
                }
            case 3:
                {
                    registredStudent = course[2].registration(student, registredStudent);
                    break;
                }
            case 0:
                {
                    selector = 1;
                    break;
                }
            default:
                {
                    cout<<"You have selected wrong option";
                    selector = 1;
                    system("pause");
                    break;
                }
            }
            break;
        case 2:
            selector = course_selector();
            switch (selector)
            {
            case 1:
                {
                    course[0].printAllParticipants();
                    course[0].msgCourseStatus();
                    system("pause");
                    break;
                }
            case 2:
                {
                    course[1].printAllParticipants();
                    course[1].msgCourseStatus();
                    system("pause");
                    break;
                }
            case 3:
                {
                    course[2].printAllParticipants();
                    course[2].msgCourseStatus();
                    system("pause");
                    break;
                }
            case 4:
                {
                    course[0].printAllParticipants();
                    course[0].msgCourseStatus();
                    course[1].printAllParticipants();
                    course[1].msgCourseStatus();
                    course[2].printAllParticipants();
                    course[2].msgCourseStatus();
                    system("pause");
                    break;
                }
            case 0:
                {
                    selector = 1;
                    break;
                }
            default:
                {
                    cout<<"You have selected wrong option";
                    selector = 1;
                    system("pause");
                    break;
                }
            }
            break;
        case 3:
            system("cls");
            course[0].msgCourseAvailability();
            course[1].msgCourseAvailability();
            course[2].msgCourseAvailability();
            system("pause");
            break;
        case 4:
            cout<<"This is end of the enrollment process"<<endl;
            cout<<"Courses below are not going to take place: "<<endl;
            course[0].msgEndEnrollment();
            course[1].msgEndEnrollment();
            course[2].msgEndEnrollment();
            system("pause");
            system("Exit");
            break;
        default:
            {
                cout<<"You have selected wrong option"<<endl;
                selector = 1;
                system("pause");
            }
            break;
        }
    }


}
