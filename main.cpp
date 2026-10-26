#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;


int getValidatedInt(const string& prompt, int minVal = numeric_limits<int>::min())
{
int value;
while (true) 
{
cout << prompt;
cin >> value;
if (cin.fail()) 
{
cout << "Error: Invalid input! Please enter a valid number.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
} 
else if (value < minVal) 
{
cout << "Error: Value must be at least " << minVal << ". Please try again.\n";
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
else 
{
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return value;
}
}
}


double getValidatedDouble(const string& prompt, double minVal = -numeric_limits<double>::infinity()) 
{
double value;
while (true) 
{
cout << prompt;
cin >> value;
if (cin.fail()) 
{
cout << "Error: Invalid input! Please enter a valid number.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
} 
else if (value < minVal) 
{
cout << "Error: Value must be at least " << minVal << ". Please try again.\n";
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
else 
{
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return value;
}
}
}


class student
{
private: 
int ID; 
string name; 
double Grade1 , Grade2 , Grade3; 
double total;
double Average;
string Status;
public: 

student() 
{
 ID = 0;
 name = "";
 Grade1 = Grade2 = Grade3 = total = Average = 0.0;
 Status = "";
}


void inputData() 
{
 ID = getValidatedInt("Enter ID: ", 1);

 cout << "Enter Name: ";
 getline(cin, name);
 
 Grade1 = getValidatedDouble("Grade1: ", 0.0);
 Grade2 = getValidatedDouble("Grade2: ", 0.0);
 Grade3 = getValidatedDouble("Grade3: ", 0.0);
 
 Gradecalculate(); 
}

void Gradecalculate()
{
 total = Grade1 + Grade2 + Grade3;

 Average = total / 3;

 if(Average >= 50)
  Status = "pass"; 
 else 
  Status = "fail";
}

int getID() const
{ 
 return ID; 
}

double getAverage() const
{ 
 return Average; 
}


void Display() const
{
 cout << "Name: " << name << endl;
 cout << "ID: " << ID << endl;
 cout << "total: " << total << endl;
 cout << "Average: " << Average << endl; 
 cout << "Status: " << Status << endl;
}
    
};




int main() 
{
 vector<student> students;
 
 int countstudent = getValidatedInt("How many students? ", 1); 
 
 for(int i = 0; i < countstudent; i++)
 {
  cout << "\n--- Student " << (i + 1) << " ---\n";
  student st; 
  st.inputData();
  cout << "\n========================\n"; 
  students.push_back(st); 
 }
 
 int targetID = getValidatedInt("\nEnter Student ID to search: ", 1);
 
 auto it = find_if(
 students.begin(),
 students.end(),
 [targetID] (const student& s)
 {
  return s.getID() == targetID;
 });

 if(it != students.end())
 {
  cout << "\n=== Student Found! ===\n";
  it->Display(); 
 }
 else 
  cout << "\nStudent with ID (" << targetID << ") not found!\n";

 if (!students.empty())
 {
  cout << "\n=== Student MaxAverage! ===" << endl;
  student MaxStudent = students[0];
  for (size_t i = 0; i < students.size(); i++)
  {
   if(MaxStudent.getAverage() < students[i].getAverage())
    MaxStudent = students[i];
  }
  MaxStudent.Display(); 
 }

 cout << "\n===Student data===" << endl;
 for (size_t i = 0; i < students.size(); i++)
 {
  students[i].Display();
  cout << "------------------------\n";
 }

 return 0;
}
