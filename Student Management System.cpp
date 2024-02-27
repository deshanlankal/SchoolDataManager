#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Node {
public:
    int roll_no;
    string name, course, quali, phone_no;
    Node* next_add;
};

class Linked_List {
public:
    Node* head = NULL;

    void Insert() {
        fstream file;
        file.open("Student Management System.txt", ios::app);

        int r;
        string n, c, e;
        int ph;

        cout << "\n\n Enter Student ID:";
        cin >> r;
        cout << "\n\n Enter Student NAME:";
        cin >> n;
        cout << "\n\n Enter Last NAME:";
        cin >> c;
        cout << "\n\n Enter Student Qualification:";
        cin >> e;
        cout << "\n\n Enter Student phone NO:";
        cin >> ph;

        file << r << "\n";
        file << n << "\n";
        file << c << "\n";
        file << e << "\n";
        file << ph << "\n";

        Node* new_node = new Node;
        new_node->roll_no = r;
        new_node->name = n;
        new_node->course = c;
        new_node->quali = e;
        new_node->phone_no = to_string(ph);

        if (head == NULL) {
            head = new_node;
        }
        else {
            Node* ptr = head;
            while (ptr->next_add != NULL) {
                ptr = ptr->next_add;
            }
            ptr->next_add = new_node;
        }
        cout << "\n\n New Node Inserted";
    }

    void Search() {
        if (head == NULL) {
            cout << "Link list is Empty";
        }
        else {
            int r;
            int found = 0;
            cout << "\n\n Enter Student Id For Search: ";
            cin >> r;
            Node* ptr = head;
            while (ptr != NULL) {
                if (r == ptr->roll_no) {
                    cout << "\n\n Student ID: " << ptr->roll_no;
                    cout << "\n\n Student Name: " << ptr->name;
                    cout << "\n\n Student Course: " << ptr->course;
                    cout << "\n\n Student Qualification: " << ptr->quali;
                    cout << "\n\n Student Phone NO: " << ptr->phone_no << endl;
                    found++;
                }
                ptr = ptr->next_add;
            }
            if (found == 0) {
                cout << "\n\n Search Student not found";
            }
        }
    }

    void Count() {
        if (head == NULL) {
            cout << "Link list is empty";
        }
        else {
            int count = 0;
            Node* ptr = head;
            while (ptr != NULL) {
                count++;
                ptr = ptr->next_add;
            }
            cout << "\n\n Number of Records: " << count;
        }
    }

    void Update() {
    if (head == NULL) {
        cout << "Link list is empty";
    } else {
        int r;
        int found = 0;
        cout << "\n\n Enter Student ID For Any Updates: ";
        cin >> r;
        Node* ptr = head;
        while (ptr != NULL) {
            if (r == ptr->roll_no) {
                cin.ignore();  // Ignore the newline character left in the buffer
                cout << "\n\n Enter New Student NAME (Press Enter to keep the existing value): ";
                getline(cin, ptr->name);

                cout << "\n\n Enter New Student LastName (Press Enter to keep the existing value): ";
                getline(cin, ptr->course);

                cout << "\n\n Enter New Student Qualification (Press Enter to keep the existing value): ";
                getline(cin, ptr->quali);

                cout << "\n\n Enter New Student Phone NO (Press Enter to keep the existing value): ";
                getline(cin, ptr->phone_no);

                cout << "\n\n Record Updated Successfully";
                found++;
            }
            ptr = ptr->next_add;
        }
        if (found == 0) {
            cout << "Update Student ID " << r << " not found";
        }
    }
}



    void Del() {
        if (head == NULL) {
            cout << "Link list is empty";
        }
        else {
            int r;
            int found = 0;
            cout << "\n\n Enter Student ID for Deletion: ";
            cin >> r;
            if (r == head->roll_no) {
                Node* ptr = head;
                head = head->next_add;
                cout << "\n\n Record has been Deleted Successfully";
                found++;
                delete ptr;
            }
            else {
                Node* pre = head;
                Node* ptr = head->next_add;
                while (ptr != NULL) {
                    if (r == ptr->roll_no) {
                        pre->next_add = ptr->next_add;
                        cout << "\n\n Record Deleted Successfully";
                        found++;
                        delete ptr;
                        break;
                    }
                    pre = ptr;
                    ptr = ptr->next_add;
                }
            }
            if (found == 0) {
                cout << "\n\n Delete Student ID " << r << " not found";
            }
        }
    }

    void Sho() {
        if (head == NULL) {
            cout << "Link list is Empty";
        }
        else {
            Node* ptr = head;
            while (ptr != NULL) {
                cout << "\n\n Student ID: " << ptr->roll_no;
                cout << "\n\n Student Name: " << ptr->name;
                cout << "\n\n Student Course: " << ptr->course;
                cout << "\n\n Student Qualification: " << ptr->quali;
                cout << "\n\n Student Phone NO: " << ptr->phone_no << endl;
                ptr = ptr->next_add;
            }
        }
    }

    void ShowFilr() {
        string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;

        ifstream in("Student Management System.txt");
        getline(in, s1);

        getline(in, s2);
        getline(in, s3);
        getline(in, s4);
        getline(in, s5);
        getline(in, s6);
        getline(in, s7);
        getline(in, s8);
        getline(in, s9);
        getline(in, s10);
        getline(in, s11);
        getline(in, s12);

        cout << "\n\n \t First Student Record is Given Below\n\n" << endl;

        cout << "\t\t Student ID IS : " << s1 << endl;
        cout << "\t\t Student NAME IS : " << s2 << endl;
        cout << "\t\t Student LastName IS : " << s3 << endl;
        cout << "\t\t Student Qualification IS : " << s4 << endl;
        cout << "\t\t Student Phone NO IS : " << s5 << endl;

        cout << "\n\n \t Second Student Record is Given Below\n\n" << endl;

        cout << "\t\t Student ID IS : " << s6 << endl;
        cout << "\t\t Student NAME IS : " << s7 << endl;
        cout << "\t\t Student FatherName IS : " << s8 << endl;
        cout << "\t\t Student Qualification IS : " << s9 << endl;
        cout << "\t\t Student Phone NO IS : " << s10 << endl;
    }
};

int main() {
    Linked_List obj;
    int choice;

    do {
        system("cls");
        cout << "\n\n\t\t Welcome To the Student Management System";

        cout << "\n\t\t\t\t\t Operations ::::";
        cout << "\n\t\t\t\t\t 1. Insert Record \t\t Insert Student Record :";
        cout << "\n\t\t\t\t\t 2. Search Record \t\t Search Student Record :";
        cout << "\n\t\t\t\t\t 3. Update Record \t\t Update Student Record :";
        cout << "\n\t\t\t\t\t 4. Delete Record \t\t Delete Student Record :";
        cout << "\n\t\t\t\t\t 5. Show all Records \t\t Show Student Records :";
        cout << "\n\t\t\t\t\t 6. Show Records From File \t\t Show All Student Records From List :";
        cout << "\n\t\t\t\t\t 7. Number Of Students :";
        cout << "\n\t\t\t\t\t 8. Exit" << endl;

        cout << "Enter the Operation: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            obj.Insert();
            break;
        case 2:
            system("cls");
            obj.Search();
            break;
        case 3:
            system("cls");
            obj.Update();
            break;
        case 4:
            system("cls");
            obj.Del();
            break;
        case 5:
            system("cls");
            obj.Sho();
            break;
        case 6:
            system("cls");
            obj.ShowFilr();
            break;
        case 7:
            system("cls");
            obj.Count();
            break;
        case 8:
             exit(0);
        default:
            cout << "\n\n Invalid";
        }

        cout << "\nPress any key to continue...";
        cin.ignore(); // Clear the input buffer
        cin.get();
    } while (choice != 7);

    return 0;
}
