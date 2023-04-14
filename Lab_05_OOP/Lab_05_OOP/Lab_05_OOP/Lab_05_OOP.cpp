#include "Table_Header.h"
#include <iostream>
#include <vector>
#include <variant>

int main()
{
	const size_t size{ 4 }, size2{ 5 };
	CTable table;

	int arr_1[size2]{ 3, 5, 3, 67, 4};
	double arr_2[size]{ 3.43, 5.77, 3.27, 67.43 };
	char arr_3[size2]{ 'd', 'u', '3', 'i', '.'};

	table.CreateNewColumn(arr_1, size2, "ints");
	table.CreateNewColumn(arr_2, size, "doubles");
	table.CreateNewColumn(arr_3, size2, "chars");
	//table.ShowTable();
	cout << table;
	cin >> table;

	cout << table;
	//cout << "Number of Columns: " << table.GetNumOfColumns() << endl;
	//cout << "Number of Rows: " << table.GetNumOfRows() << endl;
	//cout << "Name of firs Column is: " << table.GetNameOfColumn(0) << ", it's type: " << table.GetTypeOfColumn(0) << endl;

	//double d = table.GetValueOfTable<double>(1, 2);
	//cout << "Value of second column and third row: " << d << endl;

}