#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;

class person {
public:
    string name;
    string id;

    void see_student_record();
    void see_timetable();
    void see_attendence();
};

class teacher : public person {
public:
    void teacher_login(string name, string pass);
    void acess_teacher();
    void take_attendence();
    void create_quiz();
};

int main() {
    person p;
    char opt;
    string pas;
    int role;

    do {
        system("cls");
        cout << "Press 2 to login as a teacher" << endl;
        cout << "Option: ";
        cin >> role;

        if (role == 2) {
            teacher t;
            cin.ignore();
            cout << "Enter your name: ";
            cin >> p.name;
            cout << "Enter your password: ";
            cin >> pas;
            t.teacher_login(p.name, pas);
        }
        else {
            cout << "!! Invalid option !!" << endl;
        }
        cout << "Press y to continue: ";
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');

    system("pause");
}

void teacher::teacher_login(string name, string pass) {
    ifstream fin;
    string n, p, c;
    fin.open("teacher-login.txt");
    bool flag = false;

    while (fin >> n >> c >> p) {
        if (name == n && pass == p) {
            flag = true;
            break;
        }
    }
    fin.close();

    if (flag) {
        acess_teacher();
    }
    else {
        cout << "!! Wrong username or password !!" << endl;
    }
}

void teacher::acess_teacher() {
    char ch;
    int opt;
    teacher t;

    do {
        system("cls");
        cout << "Press 1 to view student record" << endl;
        cout << "Press 2 to view time table" << endl;
        cout << "Press 3 to view attendance record" << endl;
        cout << "Press 4 to take attendance" << endl;
        cout << "Press 5 to create quiz" << endl;
        cout << "Choice: ";
        cin >> opt;

        system("cls");
        if (opt == 1) {
            t.see_student_record();
        }
        else if (opt == 2) {
            t.see_timetable();
        }
        else if (opt == 3) {
            t.see_attendence();
        }
        else if (opt == 4) {
            t.take_attendence();
        }
        else if (opt == 5) {
            t.create_quiz();
        }
        else {
            cout << "Invalid input" << endl;
        }

        cout << "Press y to continue: ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void teacher::take_attendence() {
    int k;
    ifstream finp("colindex.txt");
    finp >> k;
    finp.close();

    ofstream fiout("colindex.txt");
    fiout << ++k;
    fiout.close();

    string a[10][k], line;

    ifstream fin("attendence-practice.txt");
    stringstream sep;

    for (int i = 0; i < 10; i++) {
        getline(fin, line);
        sep.clear();
        sep.str(line);

        for (int j = 0; j < k; j++) {
            getline(sep, a[i][j], '|');
        }
    }
    fin.close();

    ofstream fout("attendence-practice.txt");
    char aten;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < k; j++) {
            if (j > k - 2) {
                cout << "Enter attendance of roll no " << a[i][1] << " (P/A): ";
                cin >> aten;
                if (aten == 'a' || aten == 'A' || aten == 'p' || aten == 'P') {
                    a[i][j] = toupper(aten);
                }
                else {
                    cout << "Wrong input, try again" << endl;
                }
            }
            fout << a[i][j] << "|";
        }
        fout << endl;
    }
    fout.close();
    system("cls");
}

    
void person::see_student_record() {
    ifstream fin("practice.txt");
    string line;

    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void person::see_timetable() {
    cout << "\n\n\t\t\tTIME TABLE:\n\n";

    ifstream fin("timetable2.txt");
    string line;

    while (getline(fin, line)) {
        cout << "\t\t" << line << endl;
    }
    fin.close();
}

void person::see_attendence() {
    ifstream fin("attendence-practice.txt");
    string line;

    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
    
    
}
void teacher::create_quiz(){
            string  pen;
		int  i,correct ;
        char complete;
			ofstream cre, ans ;
			cre.open ("create.txt") ;
			ans.open("ans.txt");
			i = 0 ;
			cout << "\n-------Create Quiz-------" << endl ;
			cin.ignore();
			do
			{
				cout << "Q" << i+1 << "." ;
				getline(cin,pen) ;
				cre << "Q" << i+1 << "." << pen << endl ;
				
				cout << "Option 1." ;
				getline (cin,pen) ;			
				cre << "1." << pen ;
				
				cout << "Option 2." ;
				getline (cin,pen) ;
				cre << "\t2." << pen ;
				
				cout << "Option 3." ;
				getline (cin,pen) ;
				cre << "\t3." << pen ;
				
				cout << "Option 4." ;
				getline (cin,pen) ;
				cre << "\t4." << pen << endl ;	
				
				cout << "Correct Option: " ;
				cin>>correct;
				ans<<correct<<endl;
				cre << "Correct Option for Q" << i+1 << "." <<correct<< endl ;

				i++ ;
				cout << "Enter y to end quiz : " ;
				cin>>complete;
                cin.ignore();
				cout << endl ;
			}while(complete!='y');
			cre.close();
			ans.close();
}
void student::solve_quiz(){
    string  pen, complete ;
		int CorrectAns, i,UserOption,answer[20] ;
        system ("cls") ;
			int linesprint = 1 ;
			CorrectAns = 0 ;
			ifstream ifs,ans;
			i = 0 ;
			ifs.open ("create.txt") ;
			ans.open("ans.txt");
			while(ans>>answer[i]){
            i++; 
            cout<<answer[i]<<endl;
			}
			ans.close();
			i=0;
			cout<<"\n\n-------Quiz Started-------"<<endl;
			while (getline (ifs,pen))
			{
				if (linesprint%3!=0)
				{
					cout << pen ;
					cout << endl ;
				}
				else
				{
					cin.ignore();
					cout << "\nEnter Correct Option : " ;
					cin >> UserOption ;
					
					if (UserOption == answer[i])
					{
						CorrectAns++ ;
					}
					cout << endl ;
					i++ ;
				}
				linesprint++ ;
			}
			ifs.close() ;
            float avg ;
			avg = (CorrectAns/(float)i) * 100 ;
			cout << "\n\n-------Result-------" << endl ;
			cout << "Your Total Score is " << CorrectAns <<" out  of " << i << endl ;
			cout << "Average of Your Score is : " << avg << "%" << endl ;
}

    
