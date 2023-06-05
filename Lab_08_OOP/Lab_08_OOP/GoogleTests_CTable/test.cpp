#include "pch.h"

//TEST(CTableTest, AllocationFault) {
//	CTable c_table;
//	const size_t number_of_elements = 100000;
//	double arr[number_of_elements];
//
//	for (int i = 0; i < number_of_elements; i++) {
//		arr[i] = i;
//	}
//
//	string column_name = "test_column";
//
//	for (int i = 0; i < 10000000; i++) {
//		try {
//			c_table.CreateNewColumn(arr, number_of_elements, column_name);
//		}
//		catch (const CBadAllocation& ex) {
//			EXPECT_EQ(ex.what(), string("Your shit doesn't work cause your compiler is suck in allocating merely few bytes of memory :)"));
//		}
//	}
//}

TEST(CTableTest, MultiplicationByZeroColumns) {
	CTable c_table1, c_table2, c_table3;
	int arr3[] = { 11, 12, 13, 14, 15 };
	c_table2.CreateNewColumn(arr3, 5, "column3");

		try
		{
			c_table3 = c_table1 * c_table2;
		}
		catch (const CExceptions& ex) {
			EXPECT_EQ( ex.what(), string("You're hopeless fatty clown. Just fuck off."));
		}
}

TEST(CTableTest, GetType) {
	CTable table;
	int arr[] = { 1, 2, 3, 4, 5 };
	size_t number_of_elements = 5;
	string column_name = "test_column";

	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);


	try {
		table.GetTypeOfColumn(-2);
	}
	catch (const CExceptions& ex) {
		EXPECT_EQ(ex.what(), string("Hey man, I'm with you. No, really, bein imbecile is a heavy burden, and I'll try to help you, you should only ask :)"));
	}
}

TEST(CTableTest, GetName) {
	CTable table;
	int arr[] = { 1, 2, 3, 4, 5 };
	size_t number_of_elements = 5;
	string column_name = "test_column";

	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);

	try {
		table.GetNameOfColumn(-2);
	}
	catch (const CExceptions& ex) {
		EXPECT_EQ(ex.what(), string("Moron. There is no such a column your index as big as my dick. That's to much. Or you stupid enough to enter negative number, comparable with size of your stuff in pants?"));
	}
}

TEST(CTableTest, GetValue) {
	CTable table;
	int arr[] = { 1, 2, 3, 4, 5 };
	size_t number_of_elements = 5;
	string column_name = "test_column";

	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);
	table.CreateNewColumn(arr, number_of_elements, column_name);

	double d{ 0 };
	string s{ 0 };

	try{
		d = table.GetValueOfTable<double>(1, -2);
		s = table.GetValueOfTable<string>(1, 2);
	}
	catch (const CGetValueOfColumnOutOfRange& ex) {
		EXPECT_EQ(ex.what(), string("Now you come to me and say: \"Code, give me normal result\", but you don't ask with respect."));
	}
}