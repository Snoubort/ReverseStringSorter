#include "StringLib.h"

void String::MemAllocAndCopyData(const char* data, size_t lenght) {
	_strLen = lenght;
	size_t charArrLen = _strLen + 1;
	_data = new char[charArrLen];
	if (_strLen > 0) {
		strcpy_s(_data, charArrLen, data);
	}
	_data[_strLen] = '\0';
}

String::String(const char* inputData) {
	MemAllocAndCopyData(inputData, strlen(inputData));
}

String::String(const String& other) {
	MemAllocAndCopyData(other._data, other._strLen);
}

String::String(String&& other) noexcept {
	this->_data = other._data;
	this->_strLen = other._strLen;
	other._data = nullptr;
	other._strLen = 0;
}

String::~String() noexcept {
	delete[] _data;
	_data = nullptr;
	_strLen = 0;
}

const char* String::getCString() {
	return _data;
}

size_t String::getLenght() {
	return _strLen;
}

char& String::operator[](int ind) {
	if (ind < 0 || ind > this->_strLen) {
		throw std::out_of_range("index in [] out of string index range");
	}
	else {
		return this->_data[ind];
	}
}

const char& String::operator[](int ind) const {
	if (ind < 0 || ind > this->_strLen) {
		throw std::out_of_range("index in [] out of string index range");
	}
	else {
		return this->_data[ind];
	}
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] this->_data;
		this->MemAllocAndCopyData(other._data, other._strLen);
	}
	return *this;
}

String& String::operator=(const char* other) {
	if (_data != nullptr) {
		delete[] this->_data;
		_data = nullptr;
	}
	this->MemAllocAndCopyData(other, strlen(other));
	return *this;
}

String& String::Append(const char* appendableData, size_t appendableSize) {
	size_t newStrLen = this->_strLen + appendableSize;
	size_t newSize = newStrLen + 1;
	char* newData = new char[newSize];

	for (int i = 0; i < this->_strLen; i++) {
		newData[i] = this->_data[i];
	}
	size_t appDataInd;
	for (size_t i = this->_strLen; i < newStrLen; i++) {
		appDataInd = i - _strLen;
		newData[i] = appendableData[appDataInd];
	}
	newData[newStrLen] = '\0';

	this->_strLen = newStrLen;
	delete[] this->_data;
	this->_data = newData;
	newData = nullptr;

	return *this;
}

String& String::operator+=(const String& other) {
	return Append(other._data, other._strLen);
}

String& String::operator+=(const char* other) {
	return Append(other, strlen(other));
}

bool operator==(const String& leftStr, const String& rightStr)
{
	return (strcmp(leftStr._data, rightStr._data) == 0);
}

bool GreaterCaseInsensitive(const String& leftStr, const String& rightStr) {
	return (_stricmp(leftStr._data, rightStr._data) > 0);
}

bool LessCaseInsensitive(const String& leftStr, const String& rightStr) {
	return (_stricmp(leftStr._data, rightStr._data) < 0);
}

bool EqualCaseInsensitive(const String& leftStr, const String& rightStr) {
	return (_stricmp(leftStr._data, rightStr._data) == 0);
}

bool operator>(const String& leftStr, const String& rightStr)
{
	return (strcmp(leftStr._data, rightStr._data) > 0);
}

bool operator<(const String& leftStr, const String& rightStr) {
	return (strcmp(leftStr._data, rightStr._data) < 0);
}

String operator+(const String& left, const String& right) {
	String newString(left);
	return newString += right;
}

String operator+(const String& left, const char* right) {
	String newString(left);
	return newString += right;
}

String operator+(const char* left, const String& right) {
	String newString(left);
	return newString += right;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	return os << str._data;
}

std::istream& operator>>(std::istream& is, String& str)
{
	char* BUFF = new char[2048];

	is.getline(BUFF, sizeof BUFF);
	str = BUFF;

	delete[] BUFF;
	return is;
}