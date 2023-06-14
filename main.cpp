    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <iomanip>

    using namespace std;

    struct Contact
    {
        string id; 
        string name;
        string phoneNumber;
        string email;
        string address;
    };

    vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    //Doc thong tin tu danhba.data, tra ve danh sach chua data
    vector<Contact> readContactsFromFile(const string &filename)
    {
        vector<Contact> contacts;
        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                vector<string> tokens = split(line, '|');
                if (tokens.size() == 5)
                {
                    Contact contact;
                    contact.id = tokens[0];
                    contact.name = tokens[1];
                    contact.phoneNumber = tokens[2];
                    contact.email = tokens[3];
                    contact.address = tokens[4];
                    contacts.push_back(contact);
                }
            }
            file.close();
        }
        return contacts;
    }

    //Ghi danh ba vao file danhba.data
    void writeContactsToFile(const string &filename, const vector<Contact> &contacts)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            for (const auto &contact : contacts)
            {
                file << contact.id << " | " << contact.name << " | " << contact.phoneNumber
                    << " | " << contact.email << " | " << contact.address << endl;
            }
            file.close();
        }
    }

    //Hien thi danh ba
    void displayContacts(const vector<Contact> &contacts)
    {
        // Tạo tiêu đề của bảng
        std::cout << std::setw(10) << "ID"
                << std::setw(25) << "Ho va ten"
                << std::setw(20) << "SDT"
                << std::setw(25) << "Email"
                << std::setw(25) << "Dia chi"
                << std::endl;
        std::cout << "===============================================================================================================" << std::endl;
        // cout << "ID\tTen\t\t\tSDT\t\tEmail\t\t\t\tDia chi" << endl;
        for (const auto &contact : contacts)
        {
        std::cout << std::setw(10) << contact.id << "|"
                << std::setw(25) << contact.name << "|"
                << std::setw(20) << contact.phoneNumber << "|"
                << std::setw(25) << contact.email << "|"
                << std::setw(25) << contact.address<< "|"
                << std::endl;
        std::cout << "===============================================================================================================" << std::endl;
        //     cout << contact.id << "\t" << contact.name << "\t" << contact.phoneNumber
        //          << "\t" << contact.email << "\t\t\t" << contact.address << endl;
        }
    }

    //Nhap thong tin them moi danh ba
    void addContact(vector<Contact> &contacts)
    {
        Contact newContact;
        cout << "Nhap thong tin contact moi:" << endl;
        cout << "ID: ";
        cin >> newContact.id;
        cout << "Ten: ";
        cin.ignore();
        getline(cin, newContact.name);
        cout << "SDT: ";
        cin >> newContact.phoneNumber;
        cout << "Email: ";
        cin >> newContact.email;
        cout << "Dia chi: ";
        cin.ignore();
        getline(cin, newContact.address);
        contacts.push_back(newContact);
        cout << "Contact da duoc them vao danh ba." << endl;
    }

    //Tim kiem trong danh ba theo ten
    void searchNameContact(const vector<Contact> &contacts, const string &name)
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (contact.name == name)
            {
                cout << "Thong tin contact duoc tim thay" << endl;
                cout << "ID: " << contact.id << endl;
                cout << "Ten: " << contact.name << endl;
                cout << "SDT: " << contact.phoneNumber << endl;
                cout << "Email: " << contact.email << endl;
                cout << "Dia chi: " << contact.address << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Khong tim thay contact"<<
            name<<  "trong danh ba"<< endl;
        }
    }

    //Tim kiem trong danh ba theo ID
    void searchIDContact(const vector<Contact> &contacts, const string &id)
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (contact.id == id)
            {
                cout << "Thong tin contact duoc tim thay" << endl;
                cout << "ID: " << contact.id << endl;
                cout << "Ten: " << contact.name << endl;
                cout << "SDT: " << contact.phoneNumber << endl;
                cout << "Email: " << contact.email << endl;
                cout << "Dia chi: " << contact.address << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Khong tim thay contact"<<
            id<<  "trong danh ba"<< endl;
        }
    }

    //Tim kiem trong danh ba theo SDT
    void searchPhoneNumberContact(const vector<Contact> &contacts, const string &phoneNumber)
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (contact.phoneNumber == phoneNumber)
            {
                cout << "Thong tin contact duoc tim thay" << endl;
                cout << "ID: " << contact.id << endl;
                cout << "Ten: " << contact.name << endl;
                cout << "SDT: " << contact.phoneNumber << endl;
                cout << "Email: " << contact.email << endl;
                cout << "Dia chi: " << contact.address << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Khong tim thay contact"<<
            phoneNumber<<  "trong danh ba"<< endl;
        }
    }

    //Tim kiem trong danh ba theo Email
    void searchEmailContact(const vector<Contact> &contacts, const string &email)
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (contact.email == email)
            {
                cout << "Thong tin contact duoc tim thay" << endl;
                cout << "ID: " << contact.id << endl;
                cout << "Ten: " << contact.name << endl;
                cout << "SDT: " << contact.phoneNumber << endl;
                cout << "Email: " << contact.email << endl;
                cout << "Dia chi: " << contact.address << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Khong tim thay contact"<<
            email<<  "trong danh ba"<< endl;
        }
    }

    //Tim kiem trong danh ba theo dia chi
    void searchAddressContact(const vector<Contact> &contacts, const string &address)
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (contact.address == address)
            {
                cout << "Thong tin contact duoc tim thay" << endl;
                cout << "ID: " << contact.id << endl;
                cout << "Ten: " << contact.name << endl;
                cout << "SDT: " << contact.phoneNumber << endl;
                cout << "Email: " << contact.email << endl;
                cout << "Dia chi: " << contact.address << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Khong tim thay contact"<<
            address<<  "trong danh ba"<< endl;
        }
    }

    //Chinh sua thong tin trong danh ba
    void editContact(vector<Contact> &contacts, const string &id)
    {
        bool found = false;
        for (auto &contact : contacts)
        {
            if (contact.id == id)
            {
                cout << "Nhap thong tin moi cho contact:" << endl;
                cout << "Ten: ";
                cin.ignore();
                getline(cin, contact.name);
                cout << "SDT: ";
                cin >> contact.phoneNumber;
                cout << "Email: ";
                cin >> contact.email;
                cout << "Dia chi: ";
                cin.ignore();
                getline(cin, contact.address);
                cout << "Thong tin contact đa duoc cap nhat." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Khong tim thay contact co ID "
                << id <<
                    " trong danh ba."
                << endl;
        }
    }

    //Xoa ra khoi danh ba 
    void deleteContact(vector<Contact> &contacts, const string &id)
    {
        auto it = contacts.begin();
        while (it != contacts.end())
        {
            if ((*it).id == id)
            {
                it = contacts.erase(it);
                cout << "Contact co ID "
                        << id <<
                        " da duoc xoa khoi danh ba."
                    << endl;
                return;
            }
            else
            {
                ++it;
            }
        }
        cout << "Khong tim thay contact co ID "
                <<id<<
                " trong danh ba."
            << endl;
    }

    //Thong ke so luong contact torng danh ba
    void countContacts(const vector<Contact> &contacts)
    {
        int count = contacts.size();
        cout << "So luong contact trong danh ba: " << count << endl;
    }

    //Tao mot ban sao luu cua danh ba và ghi vào mot tep tin backup (backup.data).
    void backupContacts(const string &filename, const vector<Contact> &contacts)
    {
        writeContactsToFile(filename, contacts);
        cout << "Du lieu da duoc sao luu thanh cong." << endl;
    }

    //Khoi phuc du lieu tu tep backup va cap nhat vao danh ba
    void restoreContacts(const string &filename, vector<Contact> &contacts)
    {
        contacts = readContactsFromFile(filename);
        cout << "Du lieu da duoc khoi phuc thanh cong." << endl;
    }

    //Ham main
    int main()
    {
        //Doc du lieu tu file danhba.data va sao luu vao vector contact
        vector<Contact> contacts = readContactsFromFile("danhba.data");
        int choice, choice3;
        string id, name, email, phoneNumber, address;
        do
        {
            cout << "--------------- QUAN LY DANH BA ----------------" << endl;
            cout << "1. Hien thi toan bo thong tin danh ba" << endl;
            cout << "2. Them mot contact vao danh ba" << endl;
            cout << "3. Tim contact" << endl;
            cout << "4. Thay doi thong tin cua contact trong danh ba" << endl;
            cout << "5. Xoa mot contact ra khoi danh ba" << endl;
            cout << "6. Thong ke so luong contact trong danh ba" << endl;
            cout << "7. Sao luu du lieu" << endl;
            cout << "8. Khoi phuc du lieu" << endl;
            cout << "0. Thoat chuong trinh" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                displayContacts(contacts);
                break;
            case 2:
                addContact(contacts);
                break;
            case 3:
                cout << "1. Tim contact theo ID" << endl;
                cout << "2. Tim contact theo Ten" << endl;
                cout << "3. Tim contact theo SDT" << endl;
                cout << "4. Tim contact theo Email" << endl;
                cout << "5. Tim contact theo Dia chi" << endl;
                cout << "Nhap lua chon cua ban: ";
                cin >> choice3; 
                    switch (choice3)
                    {
                        case 1:
                            cout << "Nhap ID contact can tim: ";
                            cin.ignore();
                            getline(cin, id);
                            searchIDContact(contacts, id);
                            break;
                        case 2:
                            cout << "Nhap Ten contact can tim: ";
                            cin.ignore();
                            getline(cin, name);
                            searchNameContact(contacts, name);
                            break;
                        case 3:
                            cout << "Nhap SDT contact can tim: ";
                            cin.ignore();
                            getline(cin, phoneNumber);
                            searchPhoneNumberContact(contacts, phoneNumber);
                            break;
                        case 4:
                            cout << "Nhap Email contact can tim: ";
                            cin.ignore();
                            getline(cin, email);
                            searchEmailContact(contacts, email);
                            break;
                        case 5:
                            cout << "Nhap Dia chi contact can tim: ";
                            cin.ignore();
                            getline(cin, address);
                            searchAddressContact(contacts, address);

                            break;
                        default:
                            cout << "Lua chon khong hop le, vui long thu lai!" << endl;
                            break;
                    } 
                    break;
                
                    
                // cout << "Nhap ten contact can tim: ";
                // cin.ignore();
                // getline(cin, name);
                // searchContact(contacts, name);
                // break;
            case 4:
                cout << "Nhap ID cua contact can thay doi: ";
                cin >> id;
                editContact(contacts, id);
                break;
            case 5:
                cout << "Nhap ID cua contact can xoa: ";
                cin >> id;
                deleteContact(contacts, id);
                break;
            case 6:
                countContacts(contacts);
                break;
            case 7:
                backupContacts("backup.data", contacts);
                break;
            case 8:
                restoreContacts("backup.data", contacts);
                break;
            case 0:
                cout << "Cam on ban da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long thu lai!" << endl;
                break;
            }
        } while (choice != 0);
        //Ghi du lieu tu contact vao file danhba.data
        writeContactsToFile("danhba.data", contacts);
        return 0;
    }