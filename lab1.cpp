#include "list.h"

using namespace std;



int main() {
    string choose;
    int chooseI;
    while (1)
    {
        cout << endl << "Choose menu" << endl << "1: Add name and marks" << endl << "2: Delete first student " <<
            endl << "3: Serialize" << endl << "4: Deserialize" << endl << "5: Print list" << endl << "6: Search" << endl;
        while (true)
        {
            std::cin >> choose;
            bool isValid = true;
            for (auto& x : choose)
            {
                if (!isdigit(x))
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
            {
                chooseI = stoi(choose);
                break;
            }

        }
        std::string name;
        string markI;
        switch (chooseI)
        {
        case 1:
            int mark;
            cout << "Name: ";
            name.erase();
            cin >> name;
            cout << endl << "Marks: ";
            while (true)
            {
                cin >> markI;
                bool isValid = true;
                for (auto& x : markI)
                {
                    if (!isdigit(x))
                    {
                        isValid = false;
                        break;
                    }
                }
                if (isValid)
                {
                    mark = stoi(markI);
                    break;
                }

            }
            cout << endl;
            insert(name, mark);
            break;
        case 2:
            int n;
            cin >> n;
            del(n);
            break;
        case 3:
            serialize();
            break;
        case 4:
            deserialize();
            break;
        case 5:
            print_list();
            break;
        case 6:
            search_list();
            break;
        default:
            break;
        }
    }
}