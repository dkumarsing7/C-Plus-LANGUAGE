#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>

class book {
    char bno[6];
    char bname[50];
    char aname[20];
public:
    void create_book() {
        std::cout << "\nNEW BOOK ENTRY...\n";
        std::cout << "\nEnter The book no.";
        std::cin >> bno;
        std::cout << "\n\nEnter The Name of The Book ";
        std::cin.ignore();
        std::cin.getline(bname, 50);
        std::cout << "\n\nEnter The Author's Name ";
        std::cin.getline(aname, 20);
        std::cout << "\n\n\nBook Created..";
    }

    void show_book() {
        std::cout << "\nBook no. : " << bno;
        std::cout << "\nBook Name : ";
        puts(bname);
        std::cout << "Author Name : ";
        puts(aname);
    }

    void modify_book() {
        std::cout << "\nBook no. : " << bno;
        std::cout << "\nModify Book Name : ";
        std::cin.ignore();
        std::cin.getline(bname, 50);
        std::cout << "\nModify Author's Name of Book : ";
        std::cin.getline(aname, 20);
    }

    char* retbno() {
        return bno;
    }

    void report() {
        std::cout << bno << " " << bname << " " << aname << std::endl;
    }
};

class student {
    char admno[6];
    char name[20];
    char stbno[6];
    int token;
public:
    void create_student() {
        std::cout << "\nNEW STUDENT ENTRY...\n";
        std::cout << "\nEnter The admission no. ";
        std::cin >> admno;
        std::cout << "\n\nEnter The Name of The Student ";
        std::cin.ignore();
        std::cin.getline(name, 20);
        token = 0;
        stbno[0] = '/0';
        std::cout << "\n\nStudent Record Created..";
    }

    void show_student() {
        std::cout << "\nAdmission no. : " << admno;
        std::cout << "\nStudent Name : ";
        puts(name);
        std::cout << "\nNo of Book issued : " << token;
        if (token == 1)
            std::cout << "\nBook No " << stbno;
    }

    void modify_student() {
        std::cout << "\nAdmission no. : " << admno;
        std::cout << "\nModify Student Name : ";
        std::cin.ignore();
        std::cin.getline(name, 20);
    }

    char* retadmno() {
        return admno;
    }

    char* retstbno() {
        return stbno;
    }

    int rettoken() {
        return token;
    }

    void addtoken() {
        token = 1;
    }

    void resettoken() {
        token = 0;
    }

    void getstbno(char t[]) {
        strcpy(stbno, t);
    }

    void report() {
        std::cout << "\t" << admno << "\t" << name << "\t" << token << std::endl;
    }
};

std::fstream fp, fp1;
book bk;
student st;

void write_book() {
    char ch;
    fp.open("book.dat", std::ios::out | std::ios::app);
    do {
        bk.create_book();
        fp.write((char*)&bk, sizeof(book));
        std::cout << "\n\nDo you want to add more record..(y/n?)";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

void write_student() {
    char ch;
    fp.open("student.dat", std::ios::out | std::ios::app);
    do {
        st.create_student();
        fp.write((char*)&st, sizeof(student));
        std::cout << "\n\ndo you want to add more record..(y/n?)";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

void display_spb(char n[]) {
    std::cout << "\nBOOK DETAILS\n";
    int flag = 0;
    fp.open("book.dat", std::ios::in);
    while (fp.read((char*)&bk, sizeof(book))) {
        if (strcmpi(bk.retbno(), n) == 0) {
            bk.show_book();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        std::cout << "\n\nBook does not exist";
}

void display_sps(char n[]) {
    std::cout << "\nSTUDENT DETAILS\n";
    int flag = 0;
    fp.open("student.dat", std::ios::in);
    while (fp.read((char*)&st, sizeof(student))) {
        if ((strcmpi(st.retadmno(), n) == 0)) {
            st.show_student();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        std::cout << "\n\nStudent does not exist";
}

void modify_book() {
    char n[6];
    int found = 0;
    std::cout << "\n\n\tMODIFY BOOK REOCORD.... ";
    std::cout << "\n\n\tEnter The book no. of The book";
    std::cin >> n;
    fp.open("book.dat", std::ios::in | std::ios::out);
    while (fp.read((char*)&bk, sizeof(book)) && found == 0) {
        if (strcmpi(bk.retbno(), n) == 0) {
            bk.show_book();
            std::cout << "\nEnter The New Details of book" << std::endl;
            bk.modify_book();
            int pos = -1 * sizeof(bk);
            fp.seekp(pos, std::ios::cur);
            fp.write((char*)&bk, sizeof(book));
            std::cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        std::cout << "\n\n Record Not Found ";
}

void modify_student() {
    char n[6];
    int found = 0;
    std::cout << "\n\n\tMODIFY STUDENT RECORD... ";
    std::cout << "\n\n\tEnter The admission no. of The student";
    std::cin >> n;
    fp.open("student.dat", std::ios::in | std::ios::out);
    while (fp.read((char*)&st, sizeof(student)) && found == 0) {
        if (strcmpi(st.retadmno(), n) == 0) {
            st.show_student();
            std::cout << "\nEnter The New Details of student" << std::endl;
            st.modify_student();
            int pos = -1 * sizeof(st);
            fp.seekp(pos, std::ios::cur);
            fp.write((char*)&st, sizeof(student));
            std::cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        std::cout << "\n\n Record Not Found ";
}

void delete_student() {
    char n[6];
    int flag = 0;
    std::cout << "\n\n\n\tDELETE STUDENT...";
    std::cout << "\n\nEnter The admission no. of the Student You Want To Delete : ";
    std::cin >> n;
    fp.open("student.dat", std::ios::in | std::ios::out);
    fp1.open("Temp.dat", std::ios::out);
    fp.seekg(0, std::ios::beg);
    while (fp.read((char*)&st, sizeof(student))) {
        if (strcmpi(st.retadmno(), n) != 0)
            fp1.write((char*)&st, sizeof(student));
        else
            flag = 1;
    }
    fp1.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    if (flag == 1)
        std::cout << "\n\n\tRecord Deleted ..";
    else
        std::cout << "\n\nRecord not found";
}

void delete_book() {
    char n[6];
    std::cout << "\n\n\n\tDELETE BOOK ...";
    std::cout << "\n\nEnter The Book no. of the Book You Want To Delete : ";
    std::cin >> n;
    fp.open("book.dat", std::ios::in | std::ios::out);
    std::fstream fp2;
    fp2.open("Temp.dat", std::ios::out);
    fp.seekg(0, std::ios::beg);
    while (fp.read((char*)&bk, sizeof(book))) {
        if (strcmpi(bk.retbno(), n) != 0) {
            fp2.write((char*)&bk, sizeof(book));
        }
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat", "book.dat");
    std::cout << "\n\n\tRecord Deleted ..";
}

void display_alls() {
    fp.open("student.dat", std::ios::in);
    if (!fp) {
        std::cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        return;
    }
    std::cout << "\n\n\t\tSTUDENT LIST\n\n";
    std::cout << "==================================================================\n";
    std::cout << "\tAdmission No." << "\t" << "Name" << "\t\t" << "Book Issued\n";
    std::cout << "==================================================================\n";
    while (fp.read((char*)&st, sizeof(student))) {
        st.report();
    }
    fp.close();
}

void display_allb() {
    fp.open("book.dat", std::ios::in);
    if (!fp) {
        std::cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        return;
    }
    std::cout << "\n\n\t\tBook LIST\n\n";
    std::cout << "=========================================================================\n";
    std::cout << "Book Number" << "\t" << "Book Name" << "\t\t" << "Author\n";
    std::cout << "=========================================================================\n";
    while (fp.read((char*)&bk, sizeof(book))) {
        bk.report();
    }
    fp.close();
}

void book_issue() {
    char sn[6], bn[6];
    int found = 0, flag = 0;
    std::cout << "\n\nBOOK ISSUE ...";
    std::cout << "\n\n\tEnter The student's admission no.";
    std::cin >> sn;
    fp.open("student.dat", std::ios::in | std::ios::out);
    fp1.open("book.dat", std::ios::in | std::ios::out);
    while (fp.read((char*)&st, sizeof(student)) && found == 0) {
        if (strcmpi(st.retadmno(), sn) == 0) {
            found = 1;
            if (st.rettoken() == 0) {
                std::cout << "\n\n\tEnter the book no. ";
                std::cin >> bn;
                while (fp1.read((char*)&bk, sizeof(book)) && flag == 0) {
                    if (strcmpi(bk.retbno(), bn) == 0) {
                        flag = 1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                        int pos = -1 * sizeof(st);
                        fp.seekp(pos, std::ios::cur);
                        fp.write((char*)&st, sizeof(student));
                        std::cout << "\n\n\t Book issued successfully\n\nPlease Note: Write the current date in backside of your book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                }
                if (flag == 0)
                    std::cout << "Book no does not exist";
            } else
                std::cout << "You have not returned the last book ";
        }
    }
    if (found == 0)
        std::cout << "Student record not exist...";
    fp.close();
    fp1.close();
}

void book_deposit() {
    char sn[6], bn[6];
    int found = 0, flag = 0, day, fine;
    std::cout << "\n\nBOOK DEPOSIT ...";
    std::cout << "\n\n\tEnter The student's admission no.";
    std::cin >> sn;
    fp.open("student.dat", std::ios::in | std::ios::out);
    fp1.open("book.dat", std::ios::in | std::ios::out);
    while (fp.read((char*)&st, sizeof(student)) && found == 0) {
        if (strcmpi(st.retadmno(), sn) == 0) {
            found = 1;
            if (st.rettoken() == 1) {
                while (fp1.read((char*)&bk, sizeof(book)) && flag == 0) {
                    if (strcmpi(bk.retbno(), st.retstbno()) == 0) {
                        flag = 1;
                        bk.show_book();
                        std::cout << "\n\nBook deposited in no. of days";
                        std::cin >> day;
                        if (day > 15) {
                            fine = (day - 15) * 1;
                            std::cout << "\n\nFine has to deposited Rs. " << fine;
                        }
                        st.resettoken();
                        int pos = -1 * sizeof(st);
                        fp.seekp(pos, std::ios::cur);
                        fp.write((char*)&st, sizeof(student));
                        std::cout << "\n\n\t Book deposited successfully";
                    }
                }
                if (flag == 0)
                    std::cout << "Book no does not exist";
            } else
                std::cout << "No book is issued..please check!!";
        }
    }
    if (found == 0)
        std::cout << "Student record not exist...";
    fp.close();
    fp1.close();
}

void admin_menu() {
    int ch2;
    std::cout << "\n\n\n\tADMINISTRATOR MENU";
    std::cout << "\n\n\t1.CREATE STUDENT RECORD";
    std::cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    std::cout << "\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    std::cout << "\n\n\t4.MODIFY STUDENT RECORD";
    std::cout << "\n\n\t5.DELETE STUDENT RECORD";
    std::cout << "\n\n\t6.CREATE BOOK ";
    std::cout << "\n\n\t7.DISPLAY ALL BOOKS ";
    std::cout << "\n\n\t8.DISPLAY SPECIFIC BOOK ";
    std::cout << "\n\n\t9.MODIFY BOOK ";
    std::cout << "\n\n\t10.DELETE BOOK ";
    std::cout << "\n\n\t11.BACK TO MAIN MENU";
    std::cout << "\n\n\tPlease Enter Your Choice (1-11) ";
    std::cin >> ch2;
    switch (ch2) {
    case 1:
        write_student();
        break;
    case 2:
        display_alls();
        break;
    case 3:
        char num[6];
        std::cout << "\n\n\tPlease Enter The Admission No. ";
        std::cin >> num;
        display_sps(num);
        break;
    case 4:
        modify_student();
        break;
    case 5:
        delete_student();
        break;
    case 6:
        write_book();
        break;
    case 7:
        display_allb();
        break;
    case 8: {
        char num[6];
        std::cout << "\n\n\tPlease Enter The book No. ";
        std::cin >> num;
        display_spb(num);
        break;
    }
    case 9:
        modify_book();
        break;
    case 10:
        delete_book();
        break;
    case 11:
        return;
    default:
        std::cout << "\a";
    }
    admin_menu();
}

int main() {
    int ch;
    do {
        std::cout << "\n\n\n\tMAIN MENU";
        std::cout << "\n\n\t01. BOOK ISSUE";
        std::cout << "\n\n\t02. BOOK DEPOSIT";
        std::cout << "\n\n\t03. ADMINISTRATOR MENU";
        std::cout << "\n\n\t04. EXIT";
        std::cout << "\n\n\tPlease Select Your Option (1-4) ";
        std::cin >> ch;
        switch (ch) {
        case 1:
            book_issue();
            break;
        case 2:
            book_deposit();
            break;
        case 3:
            admin_menu();
            break;
        case 4:
            exit(0);
        default:
            std::cout << "\a";
        }
    } while (ch != 4);
    return 0;
}