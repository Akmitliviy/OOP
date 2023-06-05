#pragma once

#include <iostream>
#include <vector>
#include "CExceptions.h"
using namespace std;

template<typename T>
class CTable {

	size_t number_of_columns;
	unique_ptr<vector<T>[]> table{ nullptr };
	vector<string> columns_name;
	size_t max_size_of_column;

	void AddColumn(vector<T> column) {
		number_of_columns++;
		unique_ptr<vector<T>[]> new_table(new vector<T>[number_of_columns]);
		try {
			if (new_table == nullptr)
				throw CBadAllocation();
		}
		catch (const CBadAllocation& ex) {
			throw ex;
		}

		int i = 0;

		for (; i < number_of_columns - 1; i++) {
			new_table[i] = table[i];
		}
		new_table[i] = column;

		if (column.size() > max_size_of_column)
			max_size_of_column = column.size();

		if (this->table != nullptr)
			table.reset();
		table.swap(new_table);
	}

	void GetNewColumn(int current_index, istream& is) {
		T foo{ 0 };
		for (int i = 0; i < table[current_index].size(); i++) {
			cout << "\nEnter " << i + 1 << "element: ";

			try {
				is >> foo;
				table[current_index][i] = foo;
			}
			catch (const exception& ex) {
				throw CInputIssue();
			}

		}
	}

public:

	CTable() noexcept : max_size_of_column(0), number_of_columns(0) {}
	CTable(CTable<T>& r_other) : max_size_of_column(r_other.max_size_of_column), number_of_columns(r_other.number_of_columns) {
		unique_ptr<vector<T>[]> new_table(new vector<T>[r_other.number_of_columns]);
		try {
			if (new_table == nullptr)
				throw CBadAllocation();
		}
		catch (const CExceptions& ex) {
			cout << "\n\n" << ex.what() << "\n\n";
		}
		for (int i = 0; i < this->number_of_columns; i++) {
			new_table[i] = r_other.table[i];
		}
		if (this->table != nullptr)
			this->table.reset();

		this->columns_name = r_other.columns_name;
		this->table.swap(new_table);
	}
	CTable(CTable<T>&& rr_other) noexcept : max_size_of_column(rr_other.max_size_of_column), number_of_columns(rr_other.number_of_columns) {

		this->table = unique_ptr<vector<T>[]>(new vector<T>[rr_other.number_of_columns]);
		try {
			if (this->table == nullptr)
				throw CBadAllocation();
		}
		catch (const CBadAllocation& ex) {
			cout << "\n\n" << ex.what() << "\n\n";
		}
		this->columns_name = rr_other.columns_name;
		rr_other.table = nullptr;


	};
	//~CTable();

	CTable<T>& operator= (const CTable<T>& c_table) noexcept {
		this->max_size_of_column = c_table.max_size_of_column;
		this->number_of_columns = c_table.number_of_columns;

		unique_ptr<vector<T>[]> new_table(new vector<T>[number_of_columns]);

		for (int i = 0; i < this->number_of_columns; i++) {
			new_table[i] = c_table.table[i];
		}
		if (this->table != nullptr)
			this->table.reset();

		this->columns_name = c_table.columns_name;
		this->table.swap(new_table);

		return *this;
	}

	friend ostream& operator<<(ostream& os, const CTable<T>& c_table) {
		for (int i = 0; i < c_table.number_of_columns; i++) {
			os << c_table.columns_name[i] << "\t\t";
		}
		os << endl << endl;

		for (int i = 0; i < c_table.max_size_of_column; i++) {

			for (int j = 0; j < c_table.number_of_columns; j++) {

				if (i >= c_table.table[j].size()) {
					os << "  \t\t";
					continue;
				}
				try {

					os << c_table.table[j][i] << "\t\t";
				}
				catch (const exception& ex) {
					throw COutputIssue();
				}
			}

			os << endl;
		}
		os << endl;
		return os;
	}

	friend istream& operator>> (istream& is, CTable<T>& c_table) {
		c_table.number_of_columns = 0;

		cout << "Enter number of columns: ";
		is >> c_table.number_of_columns;
		cout << endl;

		if (c_table.number_of_columns <= 0) {
			c_table.number_of_columns = 0;
			return is;
		}

		if (c_table.table != nullptr)
			c_table.table.reset();

		c_table.table = unique_ptr<vector<T>[]>(new vector<T>[c_table.number_of_columns]);
		c_table.columns_name.clear();
		c_table.columns_name.resize(c_table.number_of_columns);
		c_table.max_size_of_column = 0;

		int num_of_elements{ 0 };
		string type{ 0 };
		for (int i = 0; i < c_table.number_of_columns; i++) {
			cout << "\n\nEnter number of elements in " << i + 1 << "column: ";
			is >> num_of_elements;
			cout << endl;

			if (c_table.max_size_of_column < num_of_elements)
				c_table.max_size_of_column = num_of_elements;

			try {
				c_table.GetNewColumn(i, is);
			}
			catch (const CInputIssue& ex) {
				throw ex;
			}

			c_table.columns_name[i] = type;
			num_of_elements = 0;
		}

		cout << endl << endl;
		return is;
	}

	CTable<T> operator+(const CTable<T>& r_other) noexcept {
		CTable<T> c_result_table;

		c_result_table.table = unique_ptr<vector<T>[]>(new vector<T>[number_of_columns]);

		int i = 0;
		for (int j = 0; j < this->number_of_columns; j++, i++) {
			c_result_table.AddColumn(this->table[j]);
			c_result_table.columns_name.push_back(this->columns_name[j]);
		}

		i--;
		for (int j = 0; j < r_other.number_of_columns; j++, i++) {
			c_result_table.AddColumn(r_other.table[j]);
			c_result_table.columns_name.push_back(r_other.columns_name[j]);
		}

		return c_result_table;
	}
	CTable<T> operator*(const CTable<T>& r_other) {

		CTable<T> additional_table;

		try {
			if (this->number_of_columns == 0 || r_other.number_of_columns == 0)
				throw CZeroColumnsMultiplication();
		}
		catch (const CZeroColumnsMultiplication& ex) {
			throw ex;
		}

		for (int i = 0; i < r_other.number_of_columns; i++) {
			for (int j = 0; j < r_other.table[i].size(); j++) {
				vector<T> new_column;
				for (int k = 0; k < this->max_size_of_column; k++) {
					new_column.push_back(r_other.table[i][j]);
				}

				additional_table.AddColumn(new_column);
				additional_table.columns_name.push_back(r_other.columns_name[i]);
				new_column.clear();
			}
		}

		return *this + additional_table;
	}

	void CreateNewColumn(T arr[], size_t number_of_elements, string column_name) {
		if (number_of_elements > max_size_of_column)
			max_size_of_column = number_of_elements;

		vector<T> new_column(number_of_elements);

		for (int i = 0; i < number_of_elements; i++) {
			new_column[i] = arr[i];
		}
		AddColumn(new_column);

		columns_name.push_back(column_name);
	}

	T GetValueOfTable(int column, int row) const {
		T result{ 0 };
		try {
			table[column].at(row);
			result = table[column][row];
		}
		catch (const exception& issue) {
			throw CGetValueOfColumnOutOfRange();
		}

		return result;
	}


	void ShowTable() const noexcept {
		for (int i = 0; i < number_of_columns; i++) {
			cout << columns_name[i] << "\t\t";
		}
		cout << endl << endl;

		for (int i = 0; i < max_size_of_column; i++) {

			for (int j = 0; j < number_of_columns; j++) {

				if (i >= table[j].size()) {
					cout << "  \t\t";
					continue;
				}

				cout << table[j][i] << "\t\t";
			}

			cout << endl;
		}

	}
	int GetNumOfColumns() const noexcept {
		return number_of_columns;
	}
	int GetNumOfRows() const noexcept {
		return max_size_of_column;
	}
	string GetNameOfColumn(int index) const {
		string name{ 0 };

		try {
			name = columns_name.at(index);
		}
		catch (const exception& ex) {
			throw CGetNameOfColumnOutOfRange();
		}

		return name;
	}
	string GetTypeOfColumn(int index) const {
		string result = "unknown";

		if (const T* value = &table[index][0]) {

			result = typeid(*value).name();
		}
		else {
			try {
				throw CGetTypeOfColumnOutOfRange();
			}
			catch (const CGetTypeOfColumnOutOfRange& ex) {
				throw ex;
			}
		}
		return result;
	}
};
