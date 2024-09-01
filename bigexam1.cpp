#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*------------------------------MANAGE STUDENT-------------------------------*/
// fuction to turn ',' and ' ' into ' '
string processLine(const string &line)
{
    string processedLine = line;
    for (char &ch : processedLine)
    {
        if (ch == ',' || ch == ' ')
        {
            ch = ' ';
        }
    }
    return processedLine;
}

// Input student from file
void loadStudentFromFile(const string &filename, vector<string> &listname, vector<vector<float>> &listScores)
{
    ifstream file(filename);
    string line;
    cout << "Student list: " << endl;
    while (getline(file, line))
    {
        string processedLine = processLine(line);
        stringstream splitData(processedLine);
        string name;
        float math, english, literature, average;

        // Đọc dữ liệu từ chuỗi tách ra
        splitData >> name >> math >> literature >> english >> average;
        listname.push_back(name);
        listScores.push_back({math, literature, english, average});
    }

    file.close();
}

// Show student
void showStudentList(const vector<string> &listname, vector<vector<float>> &listScores)
{
    if (listname.empty())
    {
        cout << "List is empty. Please add student" << endl;
        return;
    }

    for (int i = 0; i < listname.size(); ++i)
    {
        cout << "student name: " << listname[i] << ", ";
        cout << "Math: " << listScores[i][0] << ", ";
        cout << "Literature: " << listScores[i][1] << ", ";
        cout << "English: " << listScores[i][2] << " , ";
        // Average point
        double average = (listScores[i][0] + listScores[i][1] + listScores[i][2]) / 3.0;
        cout << "Average: " << average << endl;
    }
}

void ouputStudentList(const vector<string> &listname, vector<vector<float>> &listScores)
{
    ofstream outputFile("studentDB.txt");
    for (int i = 0; i < listname.size(); ++i)
    {
        outputFile << listname[i] << ", ";
        outputFile << listScores[i][0] << ", ";
        outputFile << listScores[i][1] << ", ";
        outputFile << listScores[i][2] << " , ";
        // Average point
        double average = (listScores[i][0] + listScores[i][1] + listScores[i][2]) / 3.0;
        outputFile << average << endl;
    }
    outputFile.close();
}

// Add student
void addStudent(vector<string> &names, vector<vector<float>> &scores)
{
    string name;
    vector<float> studentScores(3);

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    names.push_back(name);

    // enterponit
    cout << "Enter Math score: ";
    cin >> studentScores[0];
    cout << "Enter Literature score: ";
    cin >> studentScores[1];
    cout << "Enter English score: ";
    cin >> studentScores[2];
    scores.push_back(studentScores);

    cout << "Add new student completed...." << endl;
}

// remove student
void removeStudent(vector<string> &listname, vector<vector<float>> &listScores)
{
    string name;
    cout << "Enter student name you want to erase: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < listname.size(); ++i)
    {
        if (listname[i] == name)
        {
            listname.erase(listname.begin() + i);
            listScores.erase(listScores.begin() + i);
            cout << "Student" << name << "is erased success" << endl;
        }
        else
        {
            cout << "student not exist in the list";
        }
    }
}

// Search student
void searchStudent(vector<string> &listname, vector<vector<float>> &listScores)
{
    string name;
    cout << "Enter student name you want to find: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < listname.size(); ++i)
    {
        int sum = 0;
        if (listname[i] == name)
        {
            cout << "---Student information---" << endl;
            cout << "Student name: " << listname[i] << ", ";
            cout << "Math: " << listScores[i][0] << ", ";
            cout << "Literature: " << listScores[i][1] << ", ";
            cout << "English: " << listScores[i][2] << endl;
            // Average point
            double average = (listScores[i][0] + listScores[i][1] + listScores[i][2]) / 3.0;
            cout << "Average: " << average << endl;
            return;
        }
    }
    cout << "student not exist in the list" << endl;
}

// UpdateStudent
// void updateStudent(vector<string> &listname, vector<vector<int>> &listScores)
// {
//     string name;
//     cout << "Enter student name you want to update: ";
//     cin.ignore();
//     getline(cin, name);

//     for (int i = 0; i < listname.size(); ++i)
//     {
//         if (listname[i] == name)
//         {
//             string nameUpdate;
//             int newScore;
//             vector<int> newStudentScores(3);
//             cout << "Enter new student name ";
//             cin.ignore();
//             getline(cin, nameUpdate);

//             cout << "Update Math score: ";
//             cin >> newScore;
//             newStudentScores[0] = newScore;

//             cout << "Update Literature score: ";
//             cin >> newScore;
//             newStudentScores[1] = newScore;

//             cout << "Update English score: ";
//             cin >> newScore;
//             newStudentScores[2] = newScore;
//             cout << "Update student completed....";
//             return;
//         }
//     }
//     cout << "student not exist in the list";
// }

// Show student had average < 5
void showStudentsBelowAverage(vector<string> &listname, vector<vector<float>> &listScores)
{
    cout << "---List student had score Below 5";
    for (int i = 0; i < listname.size(); ++i)
    {
        double average = (listScores[i][0] + listScores[i][1] + listScores[i][2]) / 3.0;
        if (average < 5)
        {
            cout << "Name: " << listname[i] << endl;
            cout << "Math " << listScores[i][0] << ", ";
            cout << "Literature: " << listScores[i][1] << ", ";
            cout << "English: " << listScores[i][2] << ", ";
            cout << "Average point: " << average << endl;
        }
    }
}

/*------------------------------MANAGE CLASS-------------------------------*/
// Show class
void showClassList(vector<string> &listClass)
{
    if (listClass.empty())
    {
        cout << "List Class is empty. Please add class" << endl;
        return;
    }
    cout << "Class list: " << endl;
    for (int i = 0; i < listClass.size(); ++i)
    {
        cout << "Class name: " << listClass[i] << endl;
    }
}

// Add class
void addClass(vector<string> &classes)
{
    string nameClass;
    cout << "Enter class name ";
    cin.ignore();
    getline(cin, nameClass);
    classes.push_back(nameClass);
    cout << "Add class completed...." << endl;
}

// remove class
void removeClass(vector<string> &classes)
{
    string nameClass;
    cout << "Enter class name you want to erase: ";
    cin.ignore();
    getline(cin, nameClass);

    for (int i = 0; i < classes.size(); ++i)
    {
        if (classes[i] == nameClass)
        {
            classes.erase(classes.begin() + i);
            cout << "Class" << nameClass << "is erased success" << endl;
        }
        else
        {
            cout << "Class not exist in the list" << endl;
        }
    }
}

// Search class
void searchClass(vector<string> &listClass)
{
    string nameClass;
    cout << "Enter class name you want to find: ";
    cin.ignore();
    getline(cin, nameClass);

    for (int i = 0; i < listClass.size(); ++i)
    {
        int sum = 0;
        if (listClass[i] == nameClass)
        {
            cout << "---Student information---" << endl;
            cout << "Class: " << nameClass;
            return;
        }
    }
    cout << "class not exist in the list" << endl;
}

int main()
{
    vector<string> className;
    vector<string> studentName;
    vector<vector<float>> studentScores;
    // Load data from file
    loadStudentFromFile("studentDB.txt",studentName,studentScores);

    // Menu program
    char option;
    cout << "------School Program------" << endl;
    cout << "1. Manage student" << endl;
    cout << "2. Manage classes" << endl;
    cout << "q. Quit" << endl;

    while (true)
    {
        cout << "Enter your option: ";
        cin >> option;
        option = tolower(option);
        bool isQuitProgram = false;
        switch (option)
        {
        case '1':
            char optionManageStudent;
            cout << "Manage student" << endl;
            cout << "1. Show student" << endl;
            cout << "2. Add student" << endl;
            cout << "3. Remove student" << endl;
            cout << "4. Update student" << endl;
            cout << "5. Search student by name" << endl;
            cout << "6. View top students" << endl;
            cout << "7. View failed students" << endl;
            cout << "q. Quit" << endl;
            while (true)
            {
                cout << "Enter you option: ";
                cin >> optionManageStudent;
                optionManageStudent = tolower(optionManageStudent);
                bool isQuitManageStudentProgram = false;
                switch (optionManageStudent)
                {
                case '1':
                    showStudentList(studentName, studentScores);
                    break;
                case '2':
                    addStudent(studentName, studentScores);
                    break;
                case '3':
                    removeStudent(studentName, studentScores);
                    break;
                case '4':
                    // updateStudent(studentName, studentScores);
                    break;
                case '5':
                    searchStudent(studentName, studentScores);
                    break;
                case '6':
                    // show top student
                    break;
                case '7':
                    showStudentsBelowAverage(studentName, studentScores);
                    break;
                case 'q':
                    cout << "Existing manage student program. Turn back to homepage" << endl;
                    isQuitManageStudentProgram = true;
                    break;

                default:
                    cout << "Invalid option" << endl;
                    break;
                }
                if (isQuitManageStudentProgram)
                {
                    cout << "------School Program------" << endl;
                    cout << "1. Manage student" << endl;
                    cout << "2. Manage classes" << endl;
                    cout << "q. Quit" << endl;
                    break;
                }
            }

            break;

        case '2':
            char optionManageClass;
            cout << "Manage Class" << endl;
            cout << "1. Show Class" << endl;
            cout << "2. Add Class" << endl;
            cout << "3. Remove Class" << endl;
            cout << "4. Update Class" << endl;
            cout << "5. Search Class by name" << endl;
            cout << "q. Quit" << endl;
            while (true)
            {
                cout << "Enter you option: ";
                cin >> optionManageClass;
                optionManageClass = tolower(optionManageClass);
                bool isQuitManageClassProgram = false;
                switch (optionManageClass)
                {
                case '1':
                    showClassList(className);
                    break;
                case '2':
                    addClass(className);
                    break;
                case '3':
                    removeClass(className);
                    break;
                case '4':
                    // updateStudent(studentName, studentScores);
                    break;
                case '5':
                    searchClass(className);
                    break;
                case '6':
                    // show top student
                    break;
                case 'q':
                    cout << "Existing manage class program. Turn back to homepage" << endl;
                    isQuitManageClassProgram = true;
                    break;

                default:
                    cout << "Invalid option" << endl;
                    break;
                }
                if (isQuitManageClassProgram)
                {
                    cout << "------School Program------" << endl;
                    cout << "1. Manage student" << endl;
                    cout << "2. Manage classes" << endl;
                    cout << "q. Quit" << endl;
                    break;
                }
            }
            break;

        case 'q':
            cout << "Existing...";
            isQuitProgram = true;
            // write in DB
            ouputStudentList(studentName, studentScores);
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
        if (isQuitProgram)
        {
            break;
        }
    }

    return 0;
}