#include "Table_Header.h"
#include "Table_Header_Unique.h"
#include <iostream>
#include <vector>
#include <variant>

int main()
{
	const size_t size{ 4 }, size2{ 5 };
	CTable table, table_2, table_3, table_4;

	int arr_1[size2]{ 3, 5, 3, 67, 4};
	double arr_2[size]{ 3.43, 5.77, 3.27, 67.43 };
	char arr_3[size2]{ 'd', 'u', '3', 'i', '.'};

	table.CreateNewColumn(arr_1, size2, "ints");
	table.CreateNewColumn(arr_2, size, "doubles");
	table.CreateNewColumn(arr_3, size2, "chars");

	table_2.CreateNewColumn(arr_1, size2, "ints");
	
	//table.ShowTable();


	cout << table;
	
	//cin >> table;
	//cout << table;
	

	//table_2 = table;
	//cout << table_2;


	table_3 = table + table_2;
	cout << table_3;

	table_4 = table * table_2;
	cout << table_4;

	//cout << "Number of Columns: " << table.GetNumOfColumns() << endl;
	//cout << "Number of Rows: " << table.GetNumOfRows() << endl;
	//cout << "Name of firs Column is: " << table.GetNameOfColumn(0) << ", it's type: " << table.GetTypeOfColumn(0) << endl;

	//double d = table.GetValueOfTable<double>(1, 2);
	//cout << "Value of second column and third row: " << d << endl;

}