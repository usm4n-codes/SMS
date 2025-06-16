#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

class person {
public:
    string name;
    string id;
    virtual void view_record() = 0;
    virtual ~person() {}
};

class admin : public person {
public:
    string subject, pass;
    float salary;

    void view_record() override;
    void add_std();
    void edit_std();
    void del_std();
    void add_tea();
    void edit_tea();
    void del_tea();
    void edit_timetable();
    void acess_admin();
    void admin_login(string name, string pass);
};

// ───────────────────── Admin Functions ─────────────────────

void admin::view_record() {
    string line;
    ifstream fin("admin_login.txt");
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void admin::add_std() {
    ofstream fout("practice.txt", ios::app);
    cout << "Enter roll number: "; cin >> id;
    cout << "Enter name: "; cin >> name;
    cout << "Enter section: "; string semester; cin >> semester;
    cout << "Enter score: "; int score; cin >> score;

    fout << left << setw(2) << id << "|" << setw(7) << name << "|"
         << setw(8) << semester << "|" << setw(6) << score << "|" << endl;
    fout.close();
}

void admin::edit_std() {
    cout << "Enter roll number to edit: "; cin >> id;
    ifstream fin("practice.txt");
    ofstream fout("temp.txt");
    string line, roll;

    while (getline(fin, line)) {
        istringstream iss(line);
        getline(iss, roll, '|');
        if (roll == id) {
            cout << "Enter new roll number: "; cin >> id;
            cout << "Enter new name: "; cin >> name;
            cout << "Enter new section: "; string semester; cin >> semester;
            cout << "Enter new score: "; int score; cin >> score;
            fout << left << setw(2) << id << "|" << setw(7) << name << "|"
                 << setw(8) << semester << "|" << setw(6) << score << "|" << endl;
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("practice.txt");
    rename("temp.txt", "practice.txt");
}

void admin::del_std() {
    cout << "Enter ID to delete: "; cin >> id;
    ifstream fin("practice.txt");
    ofstream fout("temp.txt");
    string line, roll;

    while (getline(fin, line)) {
        istringstream iss(line);
        getline(iss, roll, '|');
        if (roll != id) {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("practice.txt");
    rename("temp.txt", "practice.txt");
}

void admin::add_tea() {
    ofstream fout("teacher_record.txt", ios::app);
    cout << "Enter ID: "; cin >> id;
    cout << "Enter name: "; cin >> name;
    cout << "Enter subject: "; cin >> subject;
    cout << "Enter salary: "; cin >> salary;

    fout << left << setw(2) << id << "|" << setw(8) << name << "|"
         << setw(7) << subject << "|" << setw(7) << salary << "|" << endl;
    fout.close();
}

void admin::edit_tea() {
    cout << "Enter ID to edit: "; cin >> id;
    ifstream fin("teacher_record.txt");
    ofstream fout("temp.txt");
    string line, roll;

    while (getline(fin, line)) {
        istringstream iss(line);
        getline(iss, roll, '|');
        if (roll == id) {
            cout << "Enter new ID: "; cin >> id;
            cout << "Enter new name: "; cin >> name;
            cout << "Enter new subject: "; cin >> subject;
            cout << "Enter new salary: "; cin >> salary;
            fout << left << setw(2) << id << "|" << setw(8) << name << "|"
                 << setw(7) << subject << "|" << setw(7) << salary << "|" << endl;
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("teacher_record.txt");
    rename("temp.txt", "teacher_record.txt");
}

void admin::del_tea() {
    cout << "Enter ID to delete: "; cin >> id;
    ifstream fin("teacher_record.txt");
    ofstream fout("temp.txt");
    string line, roll;

    while (getline(fin, line)) {
        istringstream iss(line);
        getline(iss, roll, '|');
        if (roll != id) {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("teacher_record.txt");
    rename("temp.txt", "teacher_record.txt");
}

void admin::edit_timetable() {
    string days, line, tem_line;
    cin.ignore();
    cout << "Enter day to edit (e.g. Mon): ";
    getline(cin, days);

    ifstream fin("timetable2.txt");
    ofstream fout("temp1.txt");
    string lac1, lac2, lac3, lac4;

    while (getline(fin, line)) {
        istringstream is(line);
        getline(is, tem_line, '|');
        if (days == tem_line) {
            cout << "Enter lecture 1: "; cin >> lac1;
            cout << "Enter lecture 2: "; cin >> lac2;
            cout << "Enter lecture 3: "; cin >> lac3;
            cout << "Enter lecture 4: "; cin >> lac4;

            fout << left << setw(4) << tem_line << "|" << setw(4) << lac1 << "|"
                 << setw(4) << lac2 << "|" << setw(4) << lac3 << "|" << setw(4) << lac4 << "|" << endl;
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("timetable2.txt");
    rename("temp1.txt", "timetable2.txt");
}

void admin::admin_login(string name, string pass) {
    ifstream fin("admin_login.txt");
    string n, p, c;
    bool flag = false;

    while (fin >> n >> c >> p) {
        if (name == n && pass == p) {
            flag = true;
            break;
        }
    }

    fin.close();
    if (flag) {
        acess_admin();
    } else {
        cout << "❌ Incorrect admin credentials!" << endl;
    }
}

void admin::acess_admin() {
    int n;
    char opt;
    do {
        system("cls");
        cout << "\n📋 Admin Menu\n";
        cout << "1. Add Teacher\n";
        cout << "2. Edit Teacher\n";
        cout << "3. Delete Teacher\n";
        cout << "4. Add Student\n";
        cout << "5. Edit Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Edit Timetable\n";
        cout << "Choice: ";
        cin >> n;

        switch (n) {
            case 1: add_tea(); break;
            case 2: edit_tea(); break;
            case 3: del_tea(); break;
            case 4: add_std(); break;
            case 5: edit_std(); break;
            case 6: del_std(); break;
            case 7: edit_timetable(); break;
            default: cout << "❗ Invalid input\n"; break;
        }

        cout << "Press y to continue: ";
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');
}

// ───────────────────── Main Function ─────────────────────

int main() {
    system("color 71");
    admin a;
    string username, password;
    char retry;

    do {
        system("cls");
        cout << "🔐 Admin Login\n";
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        a.admin_login(username, password);

        cout << "Try again? (y/n): ";
        cin >> retry;
    } while (retry == 'y' || retry == 'Y');

    return 0;
}
