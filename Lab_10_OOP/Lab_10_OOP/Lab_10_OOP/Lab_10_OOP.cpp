#include "Table_Header_Unique.h"
#include "CExceptions.h"

int main()
{
	const size_t size{ 4 }, size2{ 5 };
	CTable<int> int_table, int_table_2;
	CTable<double> double_table;
	CTable<char> char_table, char_table_2;
	CTable<bool> bool_table;

	int arr_1[size2]{ 3, 5, 3, 67, 4 };
	int arr_new[size2]{ 6, 3, 93, 226, 28 };
	double arr_2[size]{ 3.43, 5.77, 3.27, 67.43 };
	char arr_3[size2]{ 'd', 'u', '3', 'i', '.' };
	bool arr_4[size2]{ false, true, true, false, true };

	int_table.CreateNewColumn(arr_1, size2, "ints");
	int_table_2.CreateNewColumn(arr_new, size2, "new");

	double_table.CreateNewColumn(arr_2, size, "doubles");
	double_table.CreateNewColumn(arr_2, size, "doubles");

	char_table.CreateNewColumn(arr_3, size2, "chars");
	char_table_2.CreateNewColumn(arr_3, size2, "chars");

	bool_table.CreateNewColumn(arr_4, size2, "bools");
	CTable<int> t(int_table);
	//table.ShowTable();


	int_table.ShowTable();

	//cin >> table;


	//table_2 = table;
	//cout << table_2;


	int_table = int_table + int_table_2;
	cout << int_table;
	int_table.Reverse();
	cout << int_table;

	char_table_2 = char_table * char_table_2;
	cout << char_table_2; 

	cout << "Name of firs Column is: " << int_table.GetNameOfColumn(1) << ", it's type: " << int_table.GetTypeOfColumn(1) << endl;

	int d = int_table.GetValueOfTable(1, 2);
	cout << "Value of second column and third row: " << d << endl;

}