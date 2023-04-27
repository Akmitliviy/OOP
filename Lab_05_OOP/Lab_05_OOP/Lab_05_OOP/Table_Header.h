#pragma once

#include <iostream>
#include <vector>
#include <variant>

using namespace std;

class CTable {

	size_t number_of_columns;
	vector<variant<int, double, char, string>>* table{nullptr};
	vector<string> columns_name;
	size_t max_size_of_column; 

	void AddColumn(vector<variant<int, double, char, string>> column);

	template <class T>
	void GetNewColumn(T foo, int current_index, istream& is) {

		for (int i = 0; i < table[current_index].size(); i++) {
			cout << "\nEnter " << i + 1 << "element: ";
			is >> foo;
			table[current_index][i] = foo;
		}
	}

public:
	
	CTable();
	CTable(CTable& r_other);
	CTable(CTable&& rr_other) noexcept;
	~CTable();

	CTable& operator= (const CTable& r_other);
	friend ostream& operator<< (ostream& os, const CTable& r_other);
	friend istream& operator>> (istream& os, CTable& r_other);
	CTable operator+(const CTable& r_other);
	CTable operator*(const CTable& r_other);

	template <class T>
	void CreateNewColumn(T arr[], size_t number_of_elements, string column_name) {
		if (number_of_elements > max_size_of_column)
			max_size_of_column = number_of_elements;

		vector<variant<int, double, char, string>> new_column(number_of_elements);

		for (int i = 0; i < number_of_elements; i++) {
			new_column[i] = arr[i];
		}
		AddColumn(new_column);

		columns_name.push_back(column_name);
	}
	template<class T>
	T GetValueOfTable(int column, int row) const {
		T result{ 0 };

		if (const T* value_2 = get_if<T>(&table[column][row])) {
			result = *value_2;
		}

		return result;
	}

	void ShowTable() const;
	int GetNumOfRows() const;
	int GetNumOfColumns() const;
	string GetNameOfColumn(int index) const;
	string GetTypeOfColumn(int index) const;
};