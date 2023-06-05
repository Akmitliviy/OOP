#include "Table_Header_Unique.h"
CTable::CTable()  noexcept : max_size_of_column(0), number_of_columns(0) {};
CTable::CTable(CTable&& rr_other) noexcept : max_size_of_column(rr_other.max_size_of_column), number_of_columns(rr_other.number_of_columns) {

	this->table = unique_ptr<vector<variant<int, double, char, string>>[]>(new vector<variant<int, double, char, string>>[rr_other.number_of_columns]);
	try {
		if (this->table == nullptr)
			throw CBadAllocation();
	}
	catch (const CBadAllocation& ex) {
		throw ex;
	}
	this->columns_name = rr_other.columns_name;
	rr_other.table = nullptr;


};
CTable::CTable(CTable& r_other) : max_size_of_column(r_other.max_size_of_column), number_of_columns(r_other.number_of_columns) {
	unique_ptr<vector<variant<int, double, char, string>>[]> new_table(new vector<variant<int, double, char, string>>[r_other.number_of_columns]);
	try {
		if (new_table == nullptr)
			throw CBadAllocation();
	}
	catch (const CBadAllocation& ex) {
		throw ex;
	}
	for (int i = 0; i < this->number_of_columns; i++) {
		new_table[i] = r_other.table[i];
	}
	if (this->table != nullptr)
		this->table.reset();

	this->columns_name = r_other.columns_name;
	this->table.swap(new_table);
}
//CTable::~CTable() {
//	if (this->table != nullptr)
//		this->table.reset();
//	this->table = nullptr;
//
//}

ostream& operator<<(ostream& os, const CTable& c_table) {
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

			if (auto value = get_if<int>(&c_table.table[j][0])) {

				os << *get_if<int>(&c_table.table[j][i]) << "\t\t";
			}
			else if (auto value = get_if<double>(&c_table.table[j][0])) {

				os << *get_if<double>(&c_table.table[j][i]) << "\t\t";
			}
			else if (auto value = get_if<char>(&c_table.table[j][0])) {

				os << *get_if<char>(&c_table.table[j][i]) << "\t\t";
			}
			else if (auto value = get_if<string>(&c_table.table[j][0])) {

				os << *get_if<string>(&c_table.table[j][i]) << "\t\t";
			}
			else {
				try {
					throw COutputIssue();
				}
				catch(const COutputIssue& ex){
					throw ex;
				}
			}
		}

		os << endl;
	}
	os << endl;
	return os;
}
istream& operator>> (istream& is, CTable& c_table) {
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

	c_table.table = unique_ptr<vector<variant<int, double, char, string>>[]>(new vector<variant<int, double, char, string>>[c_table.number_of_columns]);
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

		cout << "Enter type of elements in this column: ";
		is >> type;
		cout << endl;

		c_table.table[i].resize(num_of_elements);

		if (type == "int" || type == "Int" || type == "INT" || type == "Int32") {
			int foo{ 0 };
			c_table.GetNewColumn(foo, i, is);
		}
		else if (type == "double" || type == "Double" || type == "DOUBLE") {
			double foo{ 0 };
			c_table.GetNewColumn(foo, i, is);
		}
		else if (type == "char" || type == "Char" || type == "CHAR") {
			char foo{ 0 };
			c_table.GetNewColumn(foo, i, is);
		}
		else if (type == "string" || type == "String" || type == "STRING") {
			string foo{ "\0" };
			c_table.GetNewColumn(foo, i, is);
		}
		else {
			cout << "\n\nWrong type, try again: \n\n";
			i--;
			continue;
		}

		c_table.columns_name[i] = type;
		num_of_elements = 0;
	}

	cout << endl << endl;
	return is;
}
CTable& CTable::operator= (const CTable& c_table) noexcept {
	this->max_size_of_column = c_table.max_size_of_column;
	this->number_of_columns = c_table.number_of_columns;

	unique_ptr<vector<variant<int, double, char, string>>[]> new_table(new vector<variant<int, double, char, string>>[number_of_columns]);

	for (int i = 0; i < this->number_of_columns; i++) {
		new_table[i] = c_table.table[i];
	}
	if (this->table != nullptr)
		this->table.reset();

	this->columns_name = c_table.columns_name;
	this->table.swap(new_table);

	return *this;
}
CTable CTable::operator+(const CTable& r_other) noexcept {
	CTable c_result_table;

	c_result_table.table = unique_ptr<vector<variant<int, double, char, string>>[]>(new vector<variant<int, double, char, string>>[number_of_columns]);

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
CTable CTable::operator*(const CTable& r_other) {

	CTable additional_table;

	try {
		if (this->number_of_columns == 0 || r_other.number_of_columns == 0)
			throw CZeroColumnsMultiplication();
	}
	catch(const CZeroColumnsMultiplication& ex){
		throw ex;
	}

	for (int i = 0; i < r_other.number_of_columns; i++) {
		for (int j = 0; j < r_other.table[i].size(); j++) {
			vector<variant<int, double, char, string>> new_column;
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

void CTable::ShowTable() const noexcept {
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

			if (auto value = get_if<int>(&table[j][0])) {

				cout << *get_if<int>(&table[j][i]) << "\t\t";
			}
			else if (auto value = get_if<double>(&table[j][0])) {

				cout << *get_if<double>(&table[j][i]) << "\t\t";
			}
			else if (auto value = get_if<char>(&table[j][0])) {

				cout << *get_if<char>(&table[j][i]) << "\t\t";
			}
			else if (auto value = get_if<string>(&table[j][0])) {

				cout << *get_if<string>(&table[j][i]) << "\t\t";
			}
			else break;
		}

		cout << endl;
	}

}
int CTable::GetNumOfColumns() const noexcept {
	return number_of_columns;
}
int CTable::GetNumOfRows() const noexcept {
	return max_size_of_column;
}
string CTable::GetNameOfColumn(int index) const {
	string name{ 0 };
	try {

		try {
			name = columns_name.at(index);
		}
		catch(const exception& ex){
			throw CGetNameOfColumnOutOfRange();
		}
	}
	catch(const CGetNameOfColumnOutOfRange& issue){
		throw issue;
	}

	return name;
}
string CTable::GetTypeOfColumn(int index) const {
	string result = "unknown";

	if (auto value = get_if<int>(&table[index][0])) {

		result = typeid(*value).name();
	}
	else if (auto value = get_if<double>(&table[index][0])) {

		result = typeid(*value).name();
	}
	else if (auto value = get_if<char>(&table[index][0])) {

		result = typeid(*value).name();
	}
	else if (auto value = get_if<string>(&table[index][0])) {

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

void CTable::AddColumn(vector<variant<int, double, char, string>> column) {
	number_of_columns++;
	unique_ptr<vector<variant<int, double, char, string>>[]> new_table(new vector<variant<int, double, char, string>>[number_of_columns]);
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