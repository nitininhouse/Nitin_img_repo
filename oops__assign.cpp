#include <bits/stdc++.h>
using namespace std;

class IMG_Member
{
private:
protected:
    string gmail;

public:
    string name;
    string enroll_no;

    virtual void add_details() = 0;
    virtual void show_details() = 0;
    IMG_Member(){};
};
class Assignment
{
protected:
    int iteration_no = 0;
    string title, content, status, remark;

public:
    Assignment(){};
    Assignment(string title, string content, string status = "Pending", string remark = "", int iteration_no = 0)
    {
        this->title = title;
        this->content = content;
        this->status = status;
        this->remark = remark;
        this->iteration_no = iteration_no;
    }
    string get_title() { return title; }
    string get_status() { return status; }
    vector<string> assig_details()
    {
        vector<string> v = {title, content, status, remark};
        return v;
    }
    void get_assig_details()
    {
        cout << "Assignment Title: " << title << endl;
        cout << "Content: " << content << endl;
        cout << "Assignment Status: " << status << endl;
        cout << "Remark: " << remark << endl;
        cout << "Iterations: " << iteration_no << endl;
    }
    int iter_ret()
    {
        return iteration_no;
    }
    void inc_iter() { iteration_no++; }
    void update_info(string s1, string s2)
    {
        status = s1;
        remark = s2;
    }
};

vector<Assignment> base_assignment;

class Student : public IMG_Member
{
private:
    string password;
    vector<Assignment> assignments;

public:
    Student(){};
    Student(string name, string enrollment, string gmail, string password)
    {
        this->name = name;
        this->gmail = gmail;
        enroll_no = enrollment;
        this->password = password;
    }

    void add_details()
    {
        string name;
        string enroll_no;
        string gmail;
        string password;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Name: ";
        cin >> name;
        this->name = name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enrollment Number: ";
        cin >> enroll_no;
        this->enroll_no = enroll_no;

        cout << "Enter Password: ";
        cin >> password;
        this->password = password;

        cout << "Gmail ID: ";
        cin >> gmail;
        this->gmail = gmail;

        assignments = base_assignment;
    }

    void show_details()
    {
        cout << "Name: " << name << endl;
        cout << "Enrollment No.: " << enroll_no << endl;
        cout << "Gmail: " << gmail << endl;
        cout << "Total assignments: " << assignments.size() << endl;
        int ctr = 0;
        for (auto it : assignments)
        {
            if (it.get_status() == "Pending")
            {
                ctr++;
            }
        }
        cout << "Pending assignments: " << ctr << endl;
    }

    void add_assig(string a, string b)
    {
        Assignment assig(a, b);
        assignments.push_back(assig);
    };

    string check_pass() { return password; };
    vector<string> get_details()
    {
        vector<string> v = {name, enroll_no, gmail};
        return v;
    };
    vector<Assignment> get_assignments() { return assignments; }
    void load_assignments(vector<Assignment> assignments)
    {
        this->assignments = assignments;
    }
};
class Reviewer : public IMG_Member
{
private:
    string password;
    vector<pair<string, string>> iteration_requests;

public:
    Reviewer(){};
    Reviewer(string name, string enrollment, string gmail, string password)
    {
        this->name = name;
        this->gmail = gmail;
        enroll_no = enrollment;
        this->password = password;
    }

    void add_details()
    {
        string name;
        string enroll_no;
        string gmail;
        string password;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Name: ";
        getline(cin, name);
        this->name = name;

        cout << "Enrollment Number: ";
        cin >> enroll_no;
        this->enroll_no = enroll_no;

        cout << "Enter Password: ";
        cin >> password;
        this->password = password;

        cout << "Gmail ID: ";
        cin >> gmail;
        this->gmail = gmail;
    }

    void show_details()
    {
        cout << "Name: " << name << endl;
        cout << "Enrollment No.: " << enroll_no << endl;
        cout << "Gmail: " << gmail << endl;
        cout << "Iteration Requests: " << iteration_requests.size() << endl;
    }

    void add_iter(string n, string s)
    {
        iteration_requests.push_back({n, s});
    }
    string check_pass() { return password; };
    vector<string> get_details()
    {
        vector<string> v = {name, enroll_no, gmail};
        return v;
    };
    vector<pair<string, string>> get_iter_req() { return iteration_requests; };
    void del_iter_req(int n)
    {
        iteration_requests.erase(iteration_requests.begin() + n - 1);
    }
};

map<string, Student> student_details;
map<string, Reviewer> reviewer_details;

void Thank_you_message()
{
    cout << "-------------------------------------------------------------\n";
    cout << "\n\n THANK YOU!!!\n\n";
    cout << "-------------------------------------------------------------\n";
}
void login()
{
    cout << "-------------------------------------------------------------\n";
    cout << "1. Student Login\n";
    cout << "2. Reviewer Login\n";
    cout << "3. Go back\n";
    cout << "4. Exit\n";
    cout << "-------------------------------------------------------------\n";
}
void add_member()
{
    cout << "-------------------------------------------------------------\n";
    cout << "1. Add Student\n";
    cout << "2. Add Reviewer\n";
    cout << "3. Go back \n";
    cout << "4. Exit \n";
    cout << "-------------------------------------------------------------\n";
}

void base_login()
{
    while (true)
    {
        cout << "-------------------------------------------------------------\n";
        cout << "1. Already an IMGian\n";
        cout << "2. Add new IMGian\n";
        cout << "3. Exit\n\n";
        cout << "(Press 1/2/3)\n";
        cout << "-------------------------------------------------------------\n";
        int key;
        cout << "Enter: ";
        cin >> key;
        if (key == 1)
        {
            login();
            int key2;
            cout << "Enter: ";
            cin >> key2;
            if (key2 == 4)
            {
                Thank_you_message();
                break;
            }
            else if (key2 == 3)
            {
                continue;
            }
            else if (key2 == 1)
            {
                cout << "-------------------------------------------------------------\n";
                string enr, pass;
                cout << "Enter your Enrollment Number: ";
                cin >> enr;
                cout << "Enter your password: ";
                cin >> pass;
                if (student_details.find(enr) != student_details.end() && student_details[enr].check_pass() == pass)
                {
                    while (true)
                    {
                        cout << "-------------------------------------------------------------\n";
                        cout << "Welcome " << student_details[enr].name << endl
                             << endl;
                        cout << "What would you like to do?\n\n";
                        cout << "1. View Your Details\n";
                        cout << "2. View assignment details\n";
                        cout << "3. Request for iteration\n";
                        cout << "4. Delete user\n";
                        cout << "5. Exit" << endl;
                        cout << "-------------------------------------------------------------\n";
                        int key3;
                        cout << "Enter: ";
                        cin >> key3;
                        if (key3 == 1)
                        {
                            cout << "-------------------------------------------------------------\n";
                            student_details[enr].show_details();
                        }
                        else if (key3 == 2)
                        {
                            vector<Assignment> v;
                            v = student_details[enr].get_assignments();
                            if (v.size() == 0)
                            {
                                cout << "-------------------------------------------------------------\n";
                                cout << "No Assignments are currently assigned" << endl;
                            }
                            else
                            {
                                for (auto it : v)
                                {
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                    it.get_assig_details();
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                }
                            }
                        }
                        else if (key3 == 3)
                        {
                            if (student_details[enr].get_assignments().size() != 0)
                            {
                                string str_name, str_assig, str_enroll;
                                cout << "-------------------------------------------------------------\n";
                                cout << "Enter the reviewer name: ";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin, str_name);
                                cout << "Enter the reviewer enrollment number: ";
                                cin >> str_enroll;
                                cout << "Enter the assignment Title: ";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin, str_assig);

                                unordered_set<string> sett;
                                for (auto ind : student_details[enr].get_assignments())
                                {
                                    sett.insert(ind.get_title());
                                }
                                if (reviewer_details.find(str_enroll) != reviewer_details.end() && sett.find(str_assig) != sett.end())
                                {
                                    Reviewer rev = reviewer_details[str_enroll];
                                    rev.add_iter(enr, str_assig);
                                    reviewer_details[str_enroll] = rev;
                                    cout << endl;
                                    cout << "Submitted for iteration successfully!!" << endl;
                                }
                                else
                                {
                                    cout << endl;
                                    cout << "Wrong Enrollment number/ title given please revef assignment details to views the correct title\n";
                                }
                            }
                            else
                            {
                                cout << "NO Assignment is there for iteration" << endl;
                            }
                        }
                        else if (key3 == 4)
                        {
                            student_details.erase(student_details[enr].enroll_no);
                            cout << "Student deleted successfully!!" << endl;
                        }
                        else if (key3 == 5)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Please Enter correct key" << endl;
                        }
                        cout << "-------------------------------------------------------------\n";
                    }
                }
                else
                {
                    cout << endl;
                    cout << "WRONG DETAILS !!" << endl;
                    cout << "USER NOT FOUND !!" << endl;
                }
                cout << "-------------------------------------------------------------\n";
            }
            else if (key2 == 2)
            {
                cout << "-------------------------------------------------------------\n";
                string enr, pass;
                cout << "Enter your Enrollment Number: ";
                cin >> enr;
                cout << "Enter your password: ";
                cin >> pass;
                if (reviewer_details.find(enr) != reviewer_details.end() && reviewer_details[enr].check_pass() == pass)
                {
                    while (true)
                    {
                        Reviewer rev = reviewer_details[enr];
                        cout << "-------------------------------------------------------------\n";
                        cout << "Welcome " << reviewer_details[enr].name << endl
                             << endl;
                        cout << "what would you like to do?\n\n";
                        cout << "1. View Your Details\n";
                        cout << "2. Add assignment\n";
                        cout << "3. View Students and their assignment status\n";
                        cout << "4. View Students and their pending assignments\n";
                        cout << "5. View assignment list of a particular student\n";
                        cout << "6. View and review iteration requests\n";
                        cout << "7. Exit\n";
                        cout << "-------------------------------------------------------------\n";
                        int key3;
                        cout << "Enter: ";
                        cin >> key3;
                        if (key3 == 1)
                        {
                            cout << "-------------------------------------------------------------\n";
                            reviewer_details[enr].show_details();
                        }
                        else if (key3 == 2)
                        {
                            cout << "-------------------------------------------------------------\n";
                            string assig_name, assig_content;
                            cout << "Enter the title of the Assignment: ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(cin, assig_name);
                            cout << "Enter the Assignment content: ";
                            getline(cin, assig_content);
                            Assignment asig2(assig_name, assig_content);
                            base_assignment.push_back(asig2);
                            for (auto it : student_details)
                            {
                                it.second.add_assig(assig_name, assig_content);
                                student_details[it.first] = it.second;
                            }
                            cout << endl;
                            cout << "Assignments added successfully!!" << endl;
                        }
                        else if (key3 == 3)
                        {
                            cout << "-------------------------------------------------------------\n";
                            if (student_details.size() == 0)
                            {
                                cout << "No student is currently added..." << endl;
                            }
                            else
                            {
                                for (auto it : student_details)
                                {
                                    Student stu = it.second;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                    cout << "Student Name: " << stu.name << endl
                                         << endl;
                                    cout << "Assignmet Name------->Status" << endl;
                                    for (auto i : stu.get_assignments())
                                    {
                                        cout << i.get_title() << "------->" << i.get_status() << endl;
                                    }
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                }
                            }
                        }
                        else if (key3 == 4)
                        {
                            cout << "-------------------------------------------------------------\n";
                            if (student_details.size() == 0)
                            {
                                cout << "No student is currently added..." << endl;
                            }
                            else
                            {
                                for (auto it : student_details)
                                {
                                    Student stu = it.second;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                    cout << "Student Name: " << stu.name << endl
                                         << endl;
                                    cout << "Assignmet Name------->Status" << endl;
                                    for (auto i : stu.get_assignments())
                                    {
                                        if (i.get_status() == "Pending" || i.get_status() == "pending")
                                        {
                                            cout << i.get_title() << "--------->" << i.get_status() << endl;
                                        }
                                    }
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                }
                            }
                        }
                        else if (key3 == 5)
                        {
                            cout << "-------------------------------------------------------------\n";
                            string enroll;
                            cout << "Enter the enrollment number of the student: ";
                            cin >> enroll;
                            if (student_details.find(enroll) != student_details.end())
                            {
                                cout << "Name: " << student_details[enroll].name << endl;
                                for (auto it : student_details[enroll].get_assignments())
                                {
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                    it.get_assig_details();
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                }
                            }
                            else
                            {
                                cout << "Enter the correct Enrollment number" << endl;
                            }
                        }
                        else if (key3 == 6)
                        {
                            cout << "-------------------------------------------------------------\n";
                            if (reviewer_details[enr].get_iter_req().size() == 0)
                            {
                                cout << "No iterations are currently assigned" << endl;
                            }
                            else
                            {
                                while (true)
                                {
                                    int i = 1;
                                    for (auto it : reviewer_details[enr].get_iter_req())
                                    {
                                        cout << i << ". " << it.first << "  " << it.second << endl;
                                        i++;
                                    }
                                    cout << "-------------------------------------------------------------\n";
                                    cout << "Enter the S.no. of the request you want to serve (-1 to exit): ";
                                    int n;
                                    cin >> n;
                                    if (n != -1)
                                    {
                                        string s1, s2;
                                        s1 = reviewer_details[enr].get_iter_req()[n - 1].first;
                                        s2 = reviewer_details[enr].get_iter_req()[n - 1].second;
                                        Student st = student_details[s1];
                                        cout << "-------------------------------------------------------------\n";
                                        cout << "Name of the student: " << st.name << endl;
                                        vector<Assignment> asig = st.get_assignments();
                                        int f = 0;
                                        for (int i = 0; i < asig.size(); i++)
                                        {
                                            if (asig[i].get_title() == s2)
                                            {
                                                cout << "-------------------------------------------------------------\n";
                                                cout << "Assignment Title: " << asig[i].get_title() << endl;
                                                int k;
                                                string str1, str2;
                                                cout << "Enter the status (0 for pending/1 for completed): ";
                                                cin >> k;
                                                if (k == 1)
                                                {
                                                    str1 = "Completed";
                                                }
                                                else if (k == 2)
                                                {
                                                    str1 = "Pending";
                                                }
                                                else
                                                {
                                                    cout << "Enter correct input" << endl;
                                                    f = 1;
                                                    break;
                                                }
                                                cout << "Enter Remark: ";
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                getline(cin, str2);
                                                asig[i].update_info(str1, str2);
                                                asig[i].inc_iter();
                                                st.load_assignments(asig);
                                                student_details[s1] = st;
                                                break;
                                            }
                                        }
                                        if (!f)
                                        {
                                            reviewer_details[enr].del_iter_req(n);
                                            cout << "The iteration Updated successfully" << endl;
                                        }
                                    }
                                    else if (n == -1)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "enter correct number!!!" << endl;
                                    }
                                }
                            }
                        }
                        else if (key3 == 7)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Enter the correct key" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "WRONG DETAILS !!" << endl;
            }
            cout << "-------------------------------------------------------------\n";
        }

        else if (key == 2)
        {
            add_member();
            int key2;
            cout << "Enter: ";
            cin >> key2;
            if (key2 == 4)
            {
                Thank_you_message();
                break;
            }
            else if (key2 == 3)
            {
                continue;
            }
            else if (key2 == 2)
            {
                Reviewer r;
                r.add_details();
                reviewer_details.insert({r.enroll_no, r});
                cout << "\nNew Reviewer Added Successfully!!\n";
            }
            else if (key2 == 1)
            {
                Student s;
                s.add_details();
                student_details.insert({s.enroll_no, s});
                cout << endl;
                cout << "New Student Added Successfully!!\n";
            }
        }
        else if (key == 3)
        {
            Thank_you_message();
            break;
        }
        else
        {
            break;
        }
    }
}
void store()
{
    ofstream fout;
    fout.open("student_data.txt");
    for (auto it : student_details)
    {
        Student s = it.second;
        for (auto i : s.get_details())
        {
            fout << i << ',';
        }
        fout << s.check_pass() << '{';
        for (auto i : s.get_assignments())
        {
            for (auto ik : i.assig_details())
            {
                fout << ik << '|';
            }

            fout << i.iter_ret() << '|' << '~';
        }
        fout << '}';
    }
    fout.close();

    ofstream fout2;
    fout2.open("reviewer_data.txt");
    for (auto it : reviewer_details)
    {
        Reviewer r = it.second;
        for (auto i : r.get_details())
        {
            fout2 << i << ',';
        }
        fout2 << r.check_pass() << '{';
        for (auto i : r.get_iter_req())
        {
            fout2 << i.first << '|' << i.second << '|';
        }
        fout2 << '}';
    }
    fout2.close();

    ofstream fout3;
    fout3.open("base_assig.txt");
    for (auto it : base_assignment)
    {
        Assignment assig = it;
        for (auto i : assig.assig_details())
        {
            fout3 << i << '|';
        }
        fout3 << assig.iter_ret() << '|';
        fout3 << '~';
    }
    fout3.close();
}
void load()
{
    ifstream fin("student_data.txt");
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string name, enroll_no, gmail, password, item;
        vector<Assignment> assignments;

        getline(ss, name, ',');
        getline(ss, enroll_no, ',');
        getline(ss, gmail, ',');
        getline(ss, password, '{');

        Student s(name, enroll_no, gmail, password);

        string assignments_str;
        getline(ss, assignments_str, '}');
        stringstream ss_assignments(assignments_str);
        while (getline(ss_assignments, item, '~'))
        {
            if (item.empty())
                continue;
            stringstream ss_assignment(item);
            string title, content, status, remark, iter_no_str;
            int iteration_no;

            getline(ss_assignment, title, '|');
            getline(ss_assignment, content, '|');
            getline(ss_assignment, status, '|');
            getline(ss_assignment, remark, '|');
            getline(ss_assignment, iter_no_str, '|');

            iteration_no = stoi(iter_no_str);

            Assignment a(title, content, status, remark, iteration_no);
            assignments.push_back(a);
        }

        s.load_assignments(assignments);
        student_details.insert({enroll_no, s});
    }
    fin.close();

    ifstream fin2("reviewer_data.txt");
    string line2;
    while (getline(fin2, line2))
    {
        stringstream ss(line2);
        string name, enroll_no, gmail, password, item;
        vector<pair<string, string>> iteration_requests;

        getline(ss, name, ',');
        getline(ss, enroll_no, ',');
        getline(ss, gmail, ',');
        getline(ss, password, '{');

        Reviewer r(name, enroll_no, gmail, password);

        string iterations_str;
        getline(ss, iterations_str, '}');
        stringstream ss_iterations(iterations_str);
        while (getline(ss_iterations, item, '|'))
        {
            if (item.empty())
                continue;
            string student_name = item;

            if (!getline(ss_iterations, item, '|'))
                break; // Ensure there is another item for the assignment
            string assignment_title = item;

            r.add_iter(student_name, assignment_title);
        }
        reviewer_details.insert({enroll_no, r});
    }
    fin2.close();

    ifstream fin3("base_assig.txt");
    if (fin3.is_open())
    {
        string line3;
        while (getline(fin3, line3))
        {
            stringstream ss(line3);
            string item;
            vector<string> assignment_details;

            // Parsing assignment details separated by '|'
            while (getline(ss, item, '|'))
            {
                assignment_details.push_back(item);
            }

            if (!assignment_details.empty())
            {
                string title = assignment_details[0];
                string content = assignment_details[1];
                string status = assignment_details[2];
                string remark = assignment_details[3];
                int iteration_no = stoi(assignment_details[4]);

                Assignment assignment(title, content, status, remark, iteration_no);
                base_assignment.push_back(assignment);
            }
        }
    }
    fin3.close();
}

int main()
{
    load();
    base_login();
    store();
}