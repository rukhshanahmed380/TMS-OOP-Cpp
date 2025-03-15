#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

class Bus{
	public:
        void bus1(){
        	cout<<"Bus 1    (Cant to Daska)       (7:45__8:30)"<<endl;
		}
		void bus2(){
        	cout<<"Bus 2    (Pasrur to Daska)     (7:35__8:30)"<<endl;
		}
		void bus3(){
        	cout<<"Bus 3    (Sambrayal to Daska)  (7:40__8:30)"<<endl;
		}
		void bus4(){
        	cout<<"Bus 4    (Gujranwala to Daska)  (7:00__8:30)"<<endl;
		}
		void bus5(){
        	cout<<"Bus 5    (Wazirabad to Daska)   (7:15__8:30)"<<endl;
		}
		void bus6(){
        	cout<<"Bus 6    (Headmarala to Daska)  (7:30__8:30)"<<endl;
		}
		viewBusData(){
			bus1();
			bus2();
			bus3();
			bus4();
			bus5();
			bus6();
		}
};
class Student :public Bus{
public:
	void Interface(){
        cout<<"---------------------|--------|----------------------"<<endl;
        cout<<"-------------------|------------|--------------------"<<endl;
        cout<<"-----------------|*STUDENT PORTAL*|------------------"<<endl;
        cout<<"-------------------|------------|--------------------"<<endl;
        cout<<"---------------------|--------|----------------------"<<endl;
	}
    void run() {
    	Interface();
        int studentChoice;
        while (true) {
            cout<<"\n=== Student Portal ==="<<endl;
            cout<<"1. Fill Student Form"<<endl;
            cout<<"2. Give Feedback"<<endl;
            cout<<"3. View Bus Data"<<endl;
            cout<<"0. Go back"<<endl;
            cout<<" Enter your choice: ";
            cin>>studentChoice;
            switch (studentChoice) {
                case 1:
                    fillStudentForm();
                    break;
                case 2:
                    giveFeedback();
                    break;
                case 3:
                    viewBusData();
                    break;
                case 0:
                    return;
                default:
                    cout<<" Invalid choice. Please try again."<<endl;
            }
        }
    }
    void fillStudentForm() {
    	int id;
		int phone;
        string name;
        string fatherName;
		string address;
		string dropofflocation;
        cout<<"\n=== Student Form ==="<<endl;
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter your Father name: ";
        cin>>fatherName;
        cout<<"Enter your ID: ";
        cin>>id;
        cout<<"Enter your phone number: ";
        cin>>phone;
        cin.ignore();
        cout<<"Enter your address: ";
        getline(cin, address);
        cout<<"Enter your Drop Off Location: ";
        getline(cin, dropofflocation);
        cout<<"Student form submitted successfully!"<<endl;
        ofstream file("student_forms.txt", ios::app);
        file<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";
        file<<"Name: "<<name<<" "<<fatherName<<"\tID: "<<id<<"\tPhone Number: "<<phone<<"\tAddress: "<<address<<"\tDrop Off Location: "<<dropofflocation<<endl;
        file<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";
		file.close();
		viewBusData();
		selectBus();
    }
    void selectBus()
	{
    	int busChoice;
    	ofstream file("student_forms.txt",ios::app);
        cout<<"Enter your bus choice (1-6): ";
        cin>>busChoice;

    switch (busChoice) {
        case 1:
            cout<<"You have chosen \n";
			bus1();
            cout<<"The rent of this bus is 6000 \n";
            file<<"You have chosen Bus 1 (cant to Daska)\n";
            file<<"The rent of this bus is 6000 \n";
            break;
        case 2:
            cout<<"You have chosen ";
			bus2();
            cout<<"The rent of this bus is 7000 \n";
            file<<"You have chosen Bus 2 (Pasrur to Daska)";
            file<<"The rent of this bus is 7000 \n";
            break;
        case 3:
            cout<<"You have chosen ";
			bus3();
            cout<<"The rent of this bus is 9000 \n";
            file<<"You have chosen Bus 3 (sambrayal to Daska)";
            file<<"The rent of this bus is 9000 \n";
            break;
        case 4:
            cout<<"You have chosen ";
			bus4();
            cout<<"The rent of this bus is 10000 \n";
            file<<"You have chosen Bus 4 (Gujranwala to Daska)";
            file<<"The rent of this bus is 10000 \n";
            break;
        case 5:
            cout<<"You have chosen ";
			bus5();
	        cout<<"The rent of this bus is 11000 \n";
	        file<<"You have chosen Bus 5 (Wazirabad to Daska)";
			bus5();
	        file<<"The rent of this bus is 11000 \n";
            break;
        case 6:
            cout<<"You have chosen ";
			bus6();
            cout<<"The rent of this bus is 13000 \n";
            file<<"You have chosen Bus 6 (Headmarala to Daska)";
            file<<"The rent of this bus is 13000 \n";
            break;
        default:
            cout<<"Invalid bus choice!\n";
            break;
		}
		file.close();
	}
    void giveFeedback(){
    	int ratings[5];
    	string satisfaction;
        string feedback;
        int choice;
        cout<<"Do you want to give feedback or rating it\n";
        cout<<"Press 1 for feedback \nPress 2 for rating\n";
        cin>>choice;
        if(choice==1)
		{
            cout<<"\n=== Feedback Form ==="<<endl;
            cout<<"Enter your feedback: ";
            cin.ignore();
            getline(cin, feedback);
            cout<<"Thank you for your feedback!"<<endl;
            cout<<"______________________________\n";
            ofstream file("feedback1.txt", ios::app);
            file<<feedback<<endl;
            file.close();
        }
        else if(choice==2){
            cout<<"1. Comfort: ";
            cin>>ratings[0];
            cout<<"2. Punctuality: ";
            cin>>ratings[1];
            cout<<"3. Cleanliness: ";
            cin>>ratings[2];
            cout<<"4. Staff Behavior: ";
            cin>>ratings[3];
            cout<<"5. Safety: ";
            cin>>ratings[4];
            int totalRating = 0;
            for (int i = 0; i < 5; i++) {
            totalRating += ratings[i];
        }
        double averageRating = totalRating / 5.0;
        satisfaction = (averageRating >= 3.0) ? "satisfied" : "not satisfied";
	    cout<<"Overall Satisfaction: "<<satisfaction<<endl;
        cout<<"Thank you for your feedback!"<<endl;
        ofstream file("feedback2.txt", ios::app);
        file<<" ------------------------------------------\n";
        file<<"Comfort: "<<ratings[0]<<"                 "<<endl;
        file<<"Punctuality: "<<ratings[1]<<"             "<<endl;
        file<<"Cleanliness: "<<ratings[2]<<"             "<<endl;
        file<<"Staff Behavior: "<<ratings[3]<<"          "<<endl;
        file<<"Safety: "<<ratings[4]<<"                  "<<endl;
        file<<"Overall Satisfaction: "<<satisfaction<<"  "<<endl;
        file<<" ------------------------------------------\n";
        file.close();
	    }
	}
};
class Teacher :public Bus{
public:
	void Interface(){
    cout<<"---------------------|----------|----------------------"<<endl;
    cout<<"-------------------|--------------|--------------------"<<endl;
    cout<<"------------------|*TEACHER PORTAL*|-------------------"<<endl;
    cout<<"-------------------|--------------|--------------------"<<endl;
    cout<<"---------------------|----------|----------------------"<<endl;
	}
	void run() {
        int teacherChoice;
        Interface();
        while (true) {
            cout<<"\n=== Teacher Portal ==="<<endl;
            cout<<"1. Fill Teacher Form"<<endl;
            cout<<"2. Give Feedback"<<endl;
            cout<<"3. View Bus Data"<<endl;
            cout<<"0. Go back"<<endl;
            cout<<"Enter your choice: ";
            cin>>teacherChoice;
            cin.ignore();
            switch (teacherChoice) {
                case 1:
                    fillTeacherForm();
                    break;
                case 2:
                    giveFeedback();
                    break;
                case 3:
                    viewBusData();
                    break;
                case 0:
                    return;
                default:
                    cout<<"Invalid choice. Please try again."<<endl;
            }
        }
    }
    void fillTeacherForm() {
    	int id;
		int phone;
        string name;
        string fatherName;
		string address;
		string dropofflocation;
        cout<<"\n=== Teacher Form ==="<<endl;
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter your Father name: ";
        cin>>fatherName;
        cout<<"Enter your ID: ";
        cin>>id;
        cout<<"Enter your phone number: ";
        cin>>phone;
        cout<<"Enter your address: ";
        cin.ignore();
        getline(cin, address);
        cout<<"Enter your Drop Off Location: ";
        getline(cin, dropofflocation);
        cout<<"Teacher form submitted successfully!"<<endl;
        ofstream file("teacher_forms.txt", ios::app);
        file<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";
        file<<"Name: "<<name<<" "<<fatherName<<"\tID: "<<id<<"\tPhone Number: "<<phone<<"\tAddress: "<<address<<"\tDrop Off Location: "<<dropofflocation<<endl;
        file<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";
		file.close();
		viewBusData();
		selectBus();
    }
    void selectBus(){
    	int rent;
    	int busChoice;
    	ofstream file("teacher_forms.txt",ios::app);
        cout<<"Enter your bus choice (1-6): ";
        cin>>busChoice;
    switch (busChoice) {
        case 1:
            cout<<"You have chosen ";
			bus1();
            cout<<"The rent of this bus is 6000 \n";
            rent=(6000/100)*50;
            cout<<"After 50% concession for the teachers\nYour rent is "<<rent<<endl;
            file<<"You have chosen Bus 1 (cant to Daska)\n";
            file<<"The rent of this bus is "<<rent<<endl;
            break;
        case 2:
            cout<<"You have chosen ";
			bus2();
            cout<<"The rent of this bus is 7000 \n";
            rent=(7000/100)*50;
            cout<<"After 50% concession for the teachers\nYour rent is "<<rent<<endl;
            file<<"You have chosen Bus 2 (Pasrur to Daska)";
            file<<"The rent of this bus is "<<rent<<endl;
            break;
        case 3:
            cout<<"You have chosen ";
			bus3();
            cout<<"The rent of this bus is 9000 \n";
            rent=(9000/100)*50;
            cout<<"After 50% concession for the teachers\nYour rent is "<<rent<<endl;
            file<<"You have chosen Bus 3 (samrayal to Daska)";
            file<<"The rent of this bus is "<<rent<<endl;
            break;
        case 4:
            cout<<"You have chosen ";
			bus4();
            cout<<"The rent of this bus is 10000 \n";
            rent=(10000/100)*50;
            cout<<"After 50% concession for the teachers\nYour rent is "<<rent<<endl;
            file<<"You have chosen Bus 4 (Gujranwala to Daska)";
            file<<"The rent of this bus is "<<rent<<endl;
            break;
        case 5:
            cout<<"You have chosen ";
			bus5();
	        cout<<"The rent of this bus is 11000 \n";
	        rent=(11000/100)*50;
            cout<<"After 50% concession for the teachers\nYour rent is "<<rent<<endl;
	        file<<"You have chosen Bus 5 (Wazirabad to Daska)";
	        file<<"The rent of this bus is "<<rent<<endl;
            break;
        case 6:
            cout<<"You have chosen ";
			bus6();
            cout<<"The rent of this bus is "<<rent<<endl;
            rent=(13000/100)*50;
            cout<<"After 50% concession for the teachers\nYour rent is "<<rent<<endl;
            file<<"You have chosen Bus 6 (Headmarala to Daska)";
            file<<"The rent of this bus is "<<rent<<endl;
            break;
        default:
            cout<<"Invalid bus choice!\n";
            break;
		}
		file.close();
	}
    void giveFeedback() {
        Student student;
        student.giveFeedback();
    }
};
class Driver{
	public:
        string name;
        int licenseNumber;
        int idNumber;
    public:
	    Driver(string n,int l,int i)
		{
		name=n;
		licenseNumber=l;
		idNumber=i;
	    }
};
class Administrator {
public:
	void Interface(){
    cout<<"---------------------|----------------|--------------------"<<endl;
    cout<<"-------------------|-------------------|-------------------"<<endl;
    cout<<"-----------------|*ADMINISTRATOR PORTAL*|------------------"<<endl;
    cout<<"-------------------|-------------------|-------------------"<<endl;
    cout<<"---------------------|----------------|--------------------"<<endl;
	}
    void run() {
        string password;
        Interface();
        cout << "\n=== Administrator Portal ===" << endl;
        cout << "Enter the password: ";
        getline(cin, password);
        if (password == "****") {
            int adminChoice;
            while (true) {
                cout<<"\n=== Administrator Options ==="<<endl;
                cout<<" --------------------------------\n";
                cout<<"|1. Read Student Forms           |"<<endl;
                cout<<"|2. Read Teacher Forms           |"<<endl;
                cout<<"|3. Read Feedback                |"<<endl;
                cout<<"|4. Show Driver's Information    |"<<endl;
                cout<<"|0. Go back                      |"<<endl;
                cout<<" --------------------------------\n";
                cout<<"Enter your choice: ";
                cin>>adminChoice;
                cin.ignore();
                switch (adminChoice) {
                    case 1:
                        readStudentForms();
                        break;
                    case 2:
                        readTeacherForms();
                        break;
                    case 3:
                        readFeedback1();
                        readFeedback2();
                        break;
                    case 4:
                        showDriverInfo();
                        break;
                    case 0:
                        return;
                    default:
                        cout<<"Invalid choice. Please try again."<<endl;
                }
            }
        }
		else
		{
            cout<<"Incorrect password. Access denied."<<endl;
            cout<<"_____________________________________\n";
        }
    }
    void readStudentForms() {
        ifstream file("student_forms.txt");
        if (file.is_open()) {
            string line;
            cout<<"\n=== Student Forms ==="<<endl;
            while (getline(file, line)) {
                cout<<line<<endl;
            }
            file.close();
        }
		else
		{
            cout<<"No student forms found."<<endl;
            cout<<"__________________________\n";
        }
    }
    void readTeacherForms() {
        ifstream file("teacher_forms.txt");
        if (file.is_open()) {
            string line;
            cout<<"\n=== Teacher Forms ==="<<endl;
            while (getline(file, line)) {
                cout<<line<<endl;
            }
            file.close();
        }
		else
		{
            cout<<"No teacher forms found."<<endl;
            cout<<"_________________________\n";
        }
    }
    void readFeedback1() {
        ifstream file("feedback1.txt");
        if (file.is_open()) {
            string line;
            cout<<"\n=== Feedback ==="<<endl;
            while (getline(file, line)) {
                cout<<line<<endl;
            }
            file.close();
        }
		else
		{
            cout<<"No feedback found."<<endl;
        }
    }
    void readFeedback2() {
        ifstream file("feedback2.txt");
        if (file.is_open()) {
            string line;
            cout<<"\n=== Feedback ==="<<endl;
            while (getline(file, line)) {
                cout<<line<<endl;
            }
            file.close();
        }
		else
		{
            cout<<"No feedback found."<<endl;
        }
    }
    void showDriverInfo(){
        Driver d1("Ali", 123,1);
        Driver d2("Arman", 456,2);
        Driver d3("Nabil", 789,3);
        Driver d4("Shah G", 135,4);
        Driver d5("Noman", 246,5);
        Driver d6("Mehmood", 978,6);
        cout<<"---------------------|--------------|--------------------"<<endl;
        cout<<"-------------------|-----------------|-------------------"<<endl;
        cout<<"-----------------|*DRIVER INFORMATION*|------------------"<<endl;
        cout<<"-------------------|-----------------|-------------------"<<endl;
        cout<<"---------------------|--------------|--------------------"<<endl;
        cout<<"Driver 1 [NAME: "<<d1.name<<"\tLicenseNumber: "<<d1.licenseNumber
		<<"\tID: "<<d1.idNumber<<"]"<<"\t[Route: Cantt to Daska\t\t(7:45__8:30)]  [ST9015]"<<endl;
        cout<<"Driver 2 [NAME: "<<d2.name<<"\tLicenseNumber: "<<d2.licenseNumber
		<<"\tID: "<<d2.idNumber<<"]"<<"\t[Route: Sambrayal to Daska\t(7:35__8:30)]  [FS3457]"<<endl;
        cout<<"Driver 3 [NAME: "<<d3.name<<"\tLicenseNumber: "<<d3.licenseNumber
		<<"\tID: "<<d3.idNumber<<"]"<<"\t[Route: Pasrur to Daska\t\t(7:40__8:30)]  [IS2784]"<<endl;
        cout<<"Driver 4 [NAME: "<<d4.name<<"\tLicenseNumber: "<<d4.licenseNumber
		<<"\tID: "<<d4.idNumber<<"]"<<"\t[Route: Gujranwala to Daska\t(7:00__8:30)]  [KR1098]"<<endl;
        cout<<"Driver 5 [NAME: "<<d5.name<<"\tLicenseNumber: "<<d5.licenseNumber
		<<"\tID: "<<d5.idNumber<<"]"<<"\t[Route: Wazirabad to Daska\t(7:15__8:30)]  [SE6530]"<<endl;
        cout<<"Driver 6 [NAME: "<<d6.name<<"\tLicenseNumber: "<<d6.licenseNumber
		<<"\tID: "<<d6.idNumber<<"]"<<"\t[Route: Headmarala to Daska\t(7:30__8:30)]  [UO0281]"<<endl;
        cout<<endl;
        }
};
class UniversityManagementSystem {
public:
    void run() {
        int portalChoice;
        while (true) {
        	system("CLS");
        	Sleep(100);
        	cout<<"\t\t -------------------------------------------------------------------------\n";
            cout<<"\t\t|**********WELCOME TO THE UNIVERSITY TRANSPORT MANAGEMENT SYSTEM**********|"<<endl;
            cout<<"\t\t -------------------------------------------------------------------------\n";
            Sleep(100);
            cout<<" Please select a portal: "<<endl;
            Sleep(100);
            cout<<" -------------------------\n";
            cout<<"|1. Student Portal        |"<<endl;Sleep(100);
            cout<<"|2. Teacher Portal        |"<<endl;Sleep(100);
            cout<<"|3. Administrator Portal  |"<<endl;Sleep(100);
            cout<<"|0. Exit                  |"<<endl;Sleep(100);
            cout<<" -------------------------\n";Sleep(100);
            cout<<" Enter your choice: ";Sleep(100);
            cin>>portalChoice;
            cin.ignore();
            switch (portalChoice) {
                case 1: {
                    Student student;
                    student.run();
                    break;
                }
                case 2: {
                    Teacher teacher;
                    teacher.run();
                    break;
                }
                case 3: {
                    Administrator administrator;
                    administrator.run();
                    break;
                }
                case 0:
                	cout<<" ------------------------\n";
                    cout<<"| Exiting the program!!! |\n";
                    cout<<" ------------------------\n";
                    return;
                default:
                    cout<<"Invalid choice. Please try again."<<endl;
            }
        }
    }
};
int main() {
    UniversityManagementSystem system;
    system.run();
    return 0;
}
