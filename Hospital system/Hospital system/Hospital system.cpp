#include<iostream>
using namespace std;
const int Max_Number_of_Specializations = 20;
const int Max_Number_of_patients_in_one_specialization = 5;
string Patients_in__each_specialization[Max_Number_of_Specializations][Max_Number_of_patients_in_one_specialization];
int Number_of_current_patients_in_each_specialization[Max_Number_of_Specializations]{ 0 };
//------------------------------------------------------------------------------------------------------------------------
void shift_left(string arr[], int index)
{
	for (int i = 0; i < index; i++)
	{
		arr[i] = arr[i + 1];
	}
}
void shift_right(string arr[], int index)
{
	for (int i = index; i >= 0; i--)
	{
		arr[i + 1] = arr[i];
	}
}
void Add_new_patient()
{
	cout << "Enter Specialization_number , Name , Statis(if urgent press 1 , if regular press 0: \n";
	int Specialization;
	cin >> Specialization;
	if (Number_of_current_patients_in_each_specialization[Specialization - 1] == Max_Number_of_patients_in_one_specialization)
	{
		cout << "Sorry this Specialization is full , we can not serve you\n";
		return;
	}
	string Name;
	cin >> Name;

	string statis;
	cin >> statis;

	Name = Name + "+" + statis;

	if (statis == "0")
	{
		Patients_in__each_specialization[Specialization - 1][Number_of_current_patients_in_each_specialization[Specialization - 1]] = Name;
	}
	else
	{
		for (int i = Number_of_current_patients_in_each_specialization[Specialization - 1] - 1; i >= 0; i--)
		{
			Patients_in__each_specialization[Specialization - 1][i + 1] = Patients_in__each_specialization[Specialization - 1][i];
		}
		Patients_in__each_specialization[Specialization - 1][0] = Name;
	}
	Number_of_current_patients_in_each_specialization[Specialization - 1]++;
}
void print_all_patients()
{
	cout << "Please ; Enter the number of specialization :  ";
	int spec;
	cin >> spec;

	cout << "There are " << Number_of_current_patients_in_each_specialization[spec - 1] << " in specialization " << spec << "\n";
	for (int i = 0; i < Number_of_current_patients_in_each_specialization[spec - 1]; i++)
		cout << Patients_in__each_specialization[spec - 1][i] << "\n";
}
void Get_next_patient()
{
	int spec;
	cin >> spec;
	if (Number_of_current_patients_in_each_specialization[spec - 1] == 0)
	{
		cout << "There is no patients now ; take a rest\n";
		return;
	}
	cout << Patients_in__each_specialization[spec - 1][0] << "\n";
	shift_left(Patients_in__each_specialization[spec - 1], Number_of_current_patients_in_each_specialization[spec - 1] - 1);

	Number_of_current_patients_in_each_specialization[spec - 1]--;
}
void Hospital_system()
{

	cout << "Enter your choice: \n";
	cout << "1) Add new patient.\n";
	cout << "2) Print all patients.\n";
	cout << "3) Get next patient.\n";

	//--------------------------------------------------------------
	int choice = -1;
	while (choice == -1)
	{
		cin >> choice;
		if (!(choice > 0 && choice < 4))
			cout << "Please ; Enter a valid choice\n", choice = -1;
		switch (choice)
		{
		case 1:
		{
			Add_new_patient();
			break;
		}
		case 2:
		{
			print_all_patients();
			break;
		}
		case 3:
		{
			Get_next_patient();
			break;
		}
		}
	}

}
int main()
{
	while (true)
	{
		Hospital_system();
		cout << "********************\n";
	}
	return 0;
}