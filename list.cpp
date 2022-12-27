#include "list.h"


using namespace std;


void serialize() {
    ofstream ofs("file.bin", ios::binary);
    List* current = head;
    while (current) {
        ofs.write(current->name, sizeof(current->name));
        ofs.write((char*)&current->average_mark, sizeof(current->average_mark));
        current = current->next;
    }
    ofs.close();
}

void deserialize() {
    ifstream ifs("file.bin", ios::binary);
    char name[20];
    double average_mark;
    while (true) {
        ifs.read(name, sizeof(name));
        ifs.read((char*)&average_mark, sizeof(average_mark));
        if (ifs.eof()) {
            break;
        }
        insert(name, average_mark);
    }
    ifs.close();
}




void search_list() {
    char name[20];
    cout << "Insert name - ";
    cin >> name;
    cout << endl;
    List* current = head;
    while (current) {
        if (!strcmp(current->name, name)) {
            cout << "Name: " << current->name
                << "\naverage mark:" << current->average_mark << endl;
        }
        current = current->next;
    }
}
void insert(char name[], double average_mark) {
    if (head == nullptr) {
        head = new List;
        head->next = nullptr;
        strcpy(head->name, name);
        head->average_mark = average_mark;
        tail = head;
    }
    else {
        tail->next = new List;
        tail = tail->next;
        tail->next = nullptr;
        strcpy(tail->name, name);
        tail->average_mark = average_mark;
    }
}

void insert(std::string& name, double average_mark) {
    if (head == nullptr) {
        head = new List;
        head->next = nullptr;
        strcpy(head->name, name.c_str());
        head->average_mark = average_mark;
        tail = head;
    }
    else {
        tail->next = new List;
        tail = tail->next;
        tail->next = nullptr;
        strcpy(tail->name, name.c_str());
        tail->average_mark = average_mark;
    }
}

void del(int n)
{
    int i = 1;
    List* current = head;
    List* prv = nullptr;
    while (current) {
        if (i == n)
        {
            if (prv == nullptr) {
                head = head->next;
            }
            else {
                prv->next = current->next;
            }
            delete current;
        }
        i++;
        prv = current;
        current = current->next;
    }
}

void print_list() {
    List* current = head;
    while (current) {
        cout << "Name: " << current->name
            << "\naverage mark:" << current->average_mark << endl;
        current = current->next;
    }
}

