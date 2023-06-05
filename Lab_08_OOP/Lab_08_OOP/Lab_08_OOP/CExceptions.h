#pragma once
#include <iostream>
#include <exception>

using namespace std;

class CExceptions : public exception
{
public:
	CExceptions() = default;

	char const* what() const override;
};

class CBadAllocation : public CExceptions{
public:
	CBadAllocation() = default;

	char const* what() const override;
};

class CInputIssue : public CExceptions{
public:
	CInputIssue() = default;

	char const* what() const override;
};

class COutputIssue : public CExceptions{
public:
	COutputIssue() = default;

	char const* what() const override;
};

class CGetNameOfColumnOutOfRange : public CExceptions {
public:
	CGetNameOfColumnOutOfRange() = default;

	char const* what() const override;
};

class CGetTypeOfColumnOutOfRange : public CExceptions {
public:
	CGetTypeOfColumnOutOfRange() = default;

	char const* what() const override;
};

class CGetValueOfColumnOutOfRange : public CExceptions {
public:
	CGetValueOfColumnOutOfRange() = default;

	char const* what() const override;
};

class CZeroColumnsMultiplication : public CExceptions {
public:
	CZeroColumnsMultiplication() = default;

	char const* what() const override;
};

