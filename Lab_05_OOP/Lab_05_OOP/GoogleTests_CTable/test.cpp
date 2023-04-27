#include "pch.h"

TEST(CTableTest, CreateNewColumn) {
	CTable c_table;
	int arr[] = { 1, 2, 3, 4, 5 };
	size_t number_of_elements = 5;
	string column_name = "test_column";
	c_table.CreateNewColumn(arr, number_of_elements, column_name);

	EXPECT_EQ(c_table.GetNumOfColumns(), 1);
	EXPECT_EQ(c_table.GetNumOfRows(), 5);
	EXPECT_EQ(c_table.GetNameOfColumn(0), column_name);
	EXPECT_EQ(c_table.GetValueOfTable<int>(0, 2), 3);
}

TEST(CTableTest, OperatorMultiplication) {
	CTable c_table1, c_table2, c_table3;
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 7, 8, 9, 10 };
	int arr3[] = { 11, 12, 13, 14, 15 };
	c_table1.CreateNewColumn(arr1, 5, "column1");
	c_table1.CreateNewColumn(arr2, 5, "column2");
	c_table2.CreateNewColumn(arr2, 5, "column2");
	c_table2.CreateNewColumn(arr3, 5, "column3");

	c_table3 = c_table1 * c_table2;

	EXPECT_EQ(c_table3.GetNumOfColumns(), 12);
	EXPECT_EQ(c_table3.GetNumOfRows(), 5);
	EXPECT_EQ(c_table3.GetNameOfColumn(0), "column1");
	EXPECT_EQ(c_table3.GetNameOfColumn(1), "column2");
	EXPECT_EQ(c_table3.GetNameOfColumn(2), "column2");
	EXPECT_EQ(c_table3.GetNameOfColumn(3), "column2");
	EXPECT_EQ(c_table3.GetNameOfColumn(4), "column2");
	EXPECT_EQ(c_table3.GetNameOfColumn(5), "column2");
	EXPECT_EQ(c_table3.GetNameOfColumn(6), "column2");
	EXPECT_EQ(c_table3.GetNameOfColumn(7), "column3");
	EXPECT_EQ(c_table3.GetNameOfColumn(8), "column3");
	EXPECT_EQ(c_table3.GetNameOfColumn(9), "column3");
	EXPECT_EQ(c_table3.GetNameOfColumn(10), "column3");
	EXPECT_EQ(c_table3.GetNameOfColumn(11), "column3");
	EXPECT_EQ(c_table3.GetValueOfTable<int>(0, 2), 3);
	EXPECT_EQ(c_table3.GetValueOfTable<int>(1, 2), 8);
	EXPECT_EQ(c_table3.GetValueOfTable<int>(2, 2), 6);
}

TEST(CTableTest, OverloadCout) {
    CTable t1;
    int arr[] = { 1, 2, 3, 4 };
    t1.CreateNewColumn(arr, 4, "Column 1");
    double arr2[] = { 2.5, 3.6, 7.8, 9.2 };
    t1.CreateNewColumn(arr2, 4, "Column 2");

    std::ostringstream oss;
    oss << t1;
    std::string expected_output = "Column 1\t\tColumn 2\t\t\n\n1\t\t2.5\t\t\n2\t\t3.6\t\t\n3\t\t7.8\t\t\n4\t\t9.2\t\t\n\n";
    EXPECT_EQ(oss.str(), expected_output);
}

TEST(CTableTest, OperatorAddition) {
	CTable t1;
	int arr[] = { 1, 2, 3, 4 };
	t1.CreateNewColumn(arr, 4, "Column 1");
	double arr2[] = { 2.5, 3.6, 7.8, 9.2 };
	t1.CreateNewColumn(arr2, 4, "Column 2");

	CTable t2;
	int arr3[] = { 1, 2, 3, 4 };
	t2.CreateNewColumn(arr3, 4, "Column 1");
	double arr4[] = { 2.5, 3.6, 7.8, 9.2 };
	t2.CreateNewColumn(arr4, 4, "Column 2");

	CTable t3 = t1 + t2;

	EXPECT_EQ(t3.GetValueOfTable<int>(0, 2), 3);
	EXPECT_DOUBLE_EQ(t3.GetValueOfTable<double>(1, 2), 7.8);
	EXPECT_EQ(t3.GetValueOfTable<int>(2, 3), 4);
	EXPECT_DOUBLE_EQ(t3.GetValueOfTable<double>(3, 1), 3.6);
}