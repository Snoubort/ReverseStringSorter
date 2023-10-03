#pragma once
#include <memory>
#include <iostream>
#include <stdexcept>

class String {
public:
	String(const char* inputData);
	String(const String& other);
	String(String&& other) noexcept;
	~String();

	const char* getCString();
	size_t getLenght();

	char& operator[](int ind);
	const char& operator[](int ind) const;

	String& operator+=(const String& other);
	String& operator+=(const char* other);
	String& operator=(const String& other);
	String& operator=(const char* other);
	friend bool operator==(const String& left, const String& right);
	friend bool operator>(const String& lhs, const String& rhs);
	friend bool operator<(const String& lhs, const String& rhs);
	friend bool GreaterCaseInsensitive(const String& leftStr, const String& rightStr);
	friend bool LessCaseInsensitive(const String& leftStr, const String& rightStr);
	friend bool EqualCaseInsensitive(const String& leftStr, const String& rightStr);
	friend String operator+(const String& left, const String& right);
	friend String operator+(const String& left, const char* right);
	friend String operator+(const char* left, const String& right);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);

private:
	char* _data = nullptr;
	size_t _strLen = 0;

	void MemAllocAndCopyData(const char* data, size_t lenght);
	String& Append(const char* appendableData, size_t appendableSize);
};