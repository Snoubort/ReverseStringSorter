#include <iostream>
#include "..\StringClass\StringLib.h"
#include <list>

bool ReverseOrderCustomStrComporator(const String& leftStr, const String& rightStr);
bool ReverseOrderStlStrComporator(const std::string& leftStr, const std::string& rightStr);
void ReadDataInLists(std::list<String>& customStrings, std::list<std::string>& stlStrings, size_t number);
void sortCustomStrings(std::list<String>& customStrings);
void sortStdStrings(std::list<std::string>& stlStrings);
void ReverseSortingStrings();

int main(int argc, char* argv[])
{
    ReverseSortingStrings();
    return 0;
}

void ReadDataInLists(std::list<String>& customStrings, std::list<std::string>& stlStrings, size_t number) {
    char* s = new char[256];
    for (int i = 0; i < number; i++) {
        std::cin >> s;
        customStrings.push_back(String(s));
        stlStrings.push_back(s);
    }

    delete[] s;
}

bool ReverseOrderCustomStrComporator(const String& leftStr, const String& rightStr) {
    return GreaterCaseInsensitive(leftStr, rightStr);
}

bool ReverseOrderStlStrComporator(const std::string& leftStr, const std::string& rightStr) {
    std::string leftStrNorm = leftStr;
    std::string rightStrNorm = rightStr;
    for (int i = 0; i < leftStrNorm.length(); i++) {
        leftStrNorm[i] = tolower(leftStrNorm[i]);
    }
    for (int i = 0; i < rightStrNorm.length(); i++) {
        rightStrNorm[i] = tolower(rightStrNorm[i]);
    }
    return (leftStrNorm.compare(rightStrNorm) == 1);
}

void sortCustomStrings(std::list<String>& customStrings) {
    customStrings.sort(ReverseOrderCustomStrComporator);
    std::cout << "\n";
    std::cout << "Sort with custom strings" << std::endl;
    for (String& s : customStrings)
    {
        std::cout << s << std::endl;
    }
}

void sortStdStrings(std::list<std::string>& stlStrings) {
    stlStrings.sort(ReverseOrderStlStrComporator);
    std::cout << "\n";
    std::cout << "Sort with stl strings" << std::endl;
    for (std::string s : stlStrings)
    {
        std::cout << s << std::endl;
    }
}

void ReverseSortingStrings() {
    size_t number;
    std::list<String> customStrings;
    std::list<std::string> stlStrings;
    std::cout << "Sort strings in reverse order" << "\n" << std::endl;
    std::cout << "Enter number of strings" << std::endl;

    std::cin >> number;

    std::cout << "Enter strings, see example" << "\n" << std::endl;
    std::cout << "---String---" << "\\n" << std::endl;
    std::cout << "---String---" << "\\n" << std::endl;
    std::cout << "............" << "\n" << std::endl;

    ReadDataInLists(customStrings, stlStrings, number);


    sortCustomStrings(customStrings);
    sortStdStrings(stlStrings);

    customStrings.clear();
    stlStrings.clear();
}
