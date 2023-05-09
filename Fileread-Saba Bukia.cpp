#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class User {
    private:
    unsigned int ID, BirthYear, Gender;
    string Name, Surname;
    void set(unsigned int ID, string Name, string Surname, unsigned int BirthYear, unsigned int Gender){
        this -> ID = ID; this -> Name = Name; this -> Surname = Surname; this ->BirthYear = BirthYear; this -> Gender = Gender;
    }
    public:
    User(){
        set(0, "name", "surname", 2000, 0);
    }
    User(unsigned int ID, string Name, string Surname, unsigned int BirthYear, unsigned int Gender){{
            set(ID, Name, Surname, BirthYear, Gender);
        }
    }
    unsigned int GetID() {return ID;}
    string GetName() {return Name;}
    string GetSurname() {return Surname;}
    unsigned int GetBirth() {return BirthYear;}
    unsigned int GetGender() {return Gender;}
};
class Job : public User {
    private:
    unsigned int Salary;
    string Profession;
    void set(unsigned int Salary, string Profession){
        this-> Salary = Salary; this-> Profession = Profession;
    }
    public:
    Job() : User() {
        set (0, "student");
        }
    Job(unsigned int ID, string Name, string Surname, unsigned int BirthYear, unsigned int Gender, string  Profession, unsigned int Salary) : User(ID, Name, Surname, BirthYear, Gender){
        set (Salary, Profession);
    }
    unsigned int GetSalary(){return Salary;}
    string GetProfession(){return Profession;}    
};
void Print(Job& A){
    cout << A.GetID() << " " << A.GetName() << " " << A.GetSurname() << " " << A.GetBirth() << " " << A.GetGender() << " " << A.GetProfession() << " " << A.GetSalary() << endl;
}
void Read_File(Job* Arr){
    int X = 0;
    ifstream inp("D:\\dubidubi.txt");
    if (!inp.is_open()){
        cerr <<"Couldn't find the file";
        exit(1);
    }
    unsigned int Salary, BirthYear, Gender, ID;
    string Name, Surname, Profession;
    while(inp >> ID >> Name >> Surname >> BirthYear >> Gender >> Profession >> Salary) {
        Job tmp(ID, Name, Surname, BirthYear, Gender, Profession, Salary);
        Arr[X] = tmp;
        X++;
    }
}
void FilterBySalary(Job* Arr, unsigned int n, unsigned int Min, unsigned int Max){
for (int i = 0; i < n; i++) {
    if (Arr[i].GetSalary() > Min && Arr[i].GetSalary() < Max) {
        Print(Arr[i]);
        cout << endl;
        }
    }
}
void FilterByGender(Job* Arr, unsigned int n, unsigned int Gender){
    for (int i = 0; i < n; i++){
        if(Arr[i].GetGender() == Gender){
            Print(Arr[i]);
            cout << endl;
        }
    }
}
void DeleteId(Job* Arr, unsigned int n, unsigned int ID){
    for ( int i = 0; i < n; i++){
        int index = -1;
        for ( int i = 0; i < n; i++){
            if ( Arr[i].GetID() == ID){
                index = i;
                break;
            }
        }
        if (index != i){
            for ( int i = index; i < n-1; i++){
                Arr[i] = Arr[i+1];
            }
            Arr[n-1] = Job();
        }
    }
}
void AddToLastPlace(Job* &Arr, Job& user, unsigned int n){
    Job* NewArr = new Job[n + 1];
    for (int i = 0; i < n; i++){
        NewArr[i] = Arr[i];
        cout << endl;
    }
    NewArr[n] = user;
    Arr = NewArr;
}
int main() {
    Job* arr = new Job[5];
    	for (int i = 0; i < 4; i++) {
		    arr[i] = Job();	
			    Read_File(arr);
				        Print(arr[i]);
	                }
	return 0;
}
