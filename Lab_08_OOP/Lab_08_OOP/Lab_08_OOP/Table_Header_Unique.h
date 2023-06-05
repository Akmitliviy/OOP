#pragma once

#include <iostream>
#include <vector>
#include <variant>
#include "CExceptions.h"
using namespace std;

class CTable {

	size_t number_of_columns;
	unique_ptr<vector<variant<int, double, char, string>>[]> table{ nullptr };
	vector<string> columns_name;
	size_t max_size_of_column;

	void AddColumn(vector<variant<int, double, char, string>> column);

	template <class T>
	void GetNewColumn(T foo, int current_index, istream& is) {

		for (int i = 0; i < table[current_index].size(); i++) {
			cout << "\nEnter " << i + 1 << "element: ";
			try {
				try {
					is >> foo;
				}
				catch (const exception& ex) {
					throw CInputIssue();
				}
			}
			catch (const CInputIssue& issue) {
				throw issue;
			}
			table[current_index][i] = foo;
		}
	}

public:

	CTable() noexcept;
	CTable(CTable& r_other);
	CTable(CTable&& rr_other) noexcept;
	//~CTable();

	CTable& operator= (const CTable& r_other) noexcept;
	friend ostream& operator<< (ostream& os, const CTable& r_other);
	friend istream& operator>> (istream& os, CTable& r_other);
	CTable operator+(const CTable& r_other) noexcept;
	CTable operator*(const CTable& r_other);

	template <class T>
	void CreateNewColumn(T arr[], size_t number_of_elements, string column_name) {
		if (number_of_elements > max_size_of_column)
			max_size_of_column = number_of_elements;

		try {
			vector<variant<int, double, char, string>> new_column(number_of_elements);

			AddColumn(new_column);

			columns_name.push_back(column_name);

			for (int i = 0; i < number_of_elements; i++) {
				new_column[i] = arr[i];
			}
		}
		catch (const exception& ex) {
			throw CBadAllocation();
		}
	}
	template<class T>
	T GetValueOfTable(int column, int row) const {
		T result{ 0 };

		try {

			table[column].at(row);
			if (const T* value_2 = get_if<T>(&table[column][row])) {
				result = *value_2;
			}
			else {
				try {
					throw CGetValueOfColumnOutOfRange();
				}
				catch (const CGetValueOfColumnOutOfRange& ex) {
					throw ex;
				}
			}
		}
		catch (const exception issue) {
			throw CGetValueOfColumnOutOfRange();
		}

		return result;
	}

	void ShowTable() const noexcept;
	int GetNumOfRows() const noexcept;
	int GetNumOfColumns() const noexcept;
	string GetNameOfColumn(int index) const;
	string GetTypeOfColumn(int index) const;
};