#include "pch.h"
#include"..\StringClass\StringLib.h"
#include "gtest/gtest.h"

TEST(Inishialize_String, Init_String_Hard_Code_CStr) {
	String s("abc");
	EXPECT_STREQ("abc", s.getCString());
}

TEST(Inishialize_String, Init_String_Empty_CStr) {
	String s2("");
	EXPECT_STREQ("", s2.getCString());
}

TEST(Inishialize_String, Init_String_Pointer_CStr) {
	const char* s = "abc";
	String s2(s);
	EXPECT_STREQ("abc", s2.getCString());
}

TEST(Inishialize_String, Init_String_Other_String) {
	const char* s = "abc";
	String s2(s);
	String s3(s2);
	EXPECT_STREQ("abc", s2.getCString());
	EXPECT_STREQ("abc", s3.getCString());
}

TEST(Get_Methods, Get_CString) {
	String s("abc");
	EXPECT_STREQ("abc", s.getCString());
}

TEST(Get_Methods, Get_LenghtGet) {
	String s("abc");
	EXPECT_EQ(3, s.getLenght());
}

TEST(Taking_Element_By_Index, Get_Element_By_Index) {
	String s("abc");
	EXPECT_EQ('a', s[0]);
}

TEST(Taking_Element_By_Index, Index_Out_Of_Range_Lower) {
	String s("abc");
	EXPECT_THROW(s[-1], std::out_of_range);
}

TEST(Taking_Element_By_Index, Index_Out_Of_Range_Hight) {
	String s("abc");
	EXPECT_THROW(s[10], std::out_of_range);
}

TEST(Taking_Element_By_Index, Set_Element_By_Index) {
	String s("abc");
	s[0] = 'd';
	EXPECT_EQ('d', s[0]);
}

TEST(Taking_Element_By_Index, Get_Element_Const_By_Index) {
	const String s("abc");
	EXPECT_EQ('a', s[0]);
}

TEST(Plus_Equals_Operator, String_Plus_String) {
	String s("abc");
	String s2("def");
	EXPECT_STREQ("abcdef", (s += s2).getCString());
}

TEST(Plus_Equals_Operator, String_Plus_Char) {
	String s("abc");
	EXPECT_STREQ("abcdef", (s+="def").getCString());
}

TEST(Plus_Equals_Operator, String_Plus_Empty_Char) {
	String s("abc");
	EXPECT_STREQ("abc", (s += "").getCString());
}

TEST(Plus_Equals_Operator, String_Plus_Empty_String) {
	String s("abc");
	String s2("");
	EXPECT_STREQ("abc", (s += s2).getCString());
}

TEST(Equel_Operator, String_Eq_Char) {
	String s("abc");
	s = "def";
	EXPECT_STREQ("def", s.getCString());
}

TEST(Equel_Operator, String_Eq_Char_Empty) {
	String s("abc");
	s = "";
	EXPECT_STREQ("", s.getCString());
}

TEST(Equel_Operator, String_Eq_String) {
	String s("abc");
	String s2("def");
	s = s2;
	EXPECT_STREQ("def", s.getCString());
}

TEST(Equel_Operator, String_Eq_String_Empty) {
	String s("abc");
	String s2("");
	s = s2;
	EXPECT_STREQ("", s.getCString());
}

TEST(Equel_Bool_Operator, String_Eq_String) {
	String s("abc");
	String s2("abc");
	EXPECT_TRUE(s==s2);
}

TEST(Equel_Bool_Operator, String_Not_Eq_Strings) {
	String s("abc");
	String s2("ab");
	EXPECT_FALSE(s == s2);
}

TEST(Equel_Bool_Operator, Empty_Eq_Full) {
	String s("abc");
	String s2("");
	EXPECT_FALSE(s == s2);
}

TEST(Greater_Bool_Operator, Left_Greater_Right) {
	String s("b");
	String s2("a");
	EXPECT_TRUE(s > s2);
}

TEST(Greater_Bool_Operator, Left_Not_Greater_Right) {
	String s("a");
	String s2("b");
	EXPECT_FALSE(s > s2);
}

TEST(Greater_Bool_Operator, Left_Greater_Right_Case) {
	String s("a");
	String s2("A");
	EXPECT_TRUE(s > s2);
}

TEST(Less_Bool_Operator, Left_Less_Right) {
	String s("a");
	String s2("b");
	EXPECT_TRUE(s < s2);
}

TEST(Less_Bool_Operator, Left_Not_Less_Right) {
	String s("b");
	String s2("a");
	EXPECT_FALSE(s < s2);
}

TEST(Less_Bool_Operator, Left_Less_Right_Case) {
	String s("A");
	String s2("a");
	EXPECT_TRUE(s < s2);
}

TEST(Equel_Bool_Operator_Case_Insensitive, String_Eq_String_No_Case) {
	String s("abc");
	String s2("abc");
	EXPECT_TRUE(EqualCaseInsensitive(s, s2));
}

TEST(Equel_Bool_Operator_Case_Insensitive, String_Eq_String) {
	String s("abc");
	String s2("ABC");
	EXPECT_TRUE(EqualCaseInsensitive(s, s2));
}

TEST(Equel_Bool_Operator_Case_Insensitive, String_Not_Eq_String_No_Case) {
	String s("abc");
	String s2("ab");
	EXPECT_FALSE(EqualCaseInsensitive(s, s2));
}

TEST(Equel_Bool_Operator_Case_Insensitive, String_Not_Eq_String) {
	String s("abc");
	String s2("AB");
	EXPECT_FALSE(EqualCaseInsensitive(s, s2));
}

TEST(Equel_Bool_Operator_Case_Insensitive, Empty_And_Full) {
	String s("abc");
	String s2("");
	EXPECT_FALSE(EqualCaseInsensitive(s, s2));
}

TEST(Greater_Bool_Operator_Case_Insensitive, Left_Greater_Right_No_Case) {
	String s("b");
	String s2("a");
	EXPECT_TRUE(GreaterCaseInsensitive(s, s2));
}

TEST(Greater_Bool_Operator_Case_Insensitive, Left_Greater_Right) {
	String s("B");
	String s2("a");
	EXPECT_TRUE(GreaterCaseInsensitive(s, s2));
}

TEST(Greater_Bool_Operator_Case_Insensitive, Left_Not_Greater_Right_No_Case) {
	String s("a");
	String s2("b");
	EXPECT_FALSE(GreaterCaseInsensitive(s, s2));
}

TEST(Greater_Bool_Operator_Case_Insensitive, Left_Not_Greater_Right) {
	String s("a");
	String s2("B");
	EXPECT_FALSE(GreaterCaseInsensitive(s, s2));
}

TEST(Greater_Bool_Operator_Case_Insensitive, Left_Greater_Right_Case) {
	String s("a");
	String s2("A");
	EXPECT_FALSE(GreaterCaseInsensitive(s, s2));
}

TEST(Less_Bool_Operator_Case_Insensitive, Left_Less_Right_No_Case) {
	String s("a");
	String s2("b");
	EXPECT_TRUE(LessCaseInsensitive(s, s2));
}

TEST(Less_Bool_Operator_Case_Insensitive, Left_Less_Right) {
	String s("a");
	String s2("B");
	EXPECT_TRUE(LessCaseInsensitive(s, s2));
}

TEST(Less_Bool_Operator_Case_Insensitive, Left_Not_Less_Right_No_Case) {
	String s("b");
	String s2("a");
	EXPECT_FALSE(LessCaseInsensitive(s, s2));
}

TEST(Less_Bool_Operator_Case_Insensitive, Left_Not_Less_Right) {
	String s("b");
	String s2("A");
	EXPECT_FALSE(LessCaseInsensitive(s, s2));
}

TEST(Less_Bool_Operator_Case_Insensitive, Left_Less_Right_Case) {
	String s("A");
	String s2("a");
	EXPECT_FALSE(LessCaseInsensitive(s, s2));
}

TEST(Plus_Operator, String_Plus_String) {
	String s("abc");
	String s2("def");
	EXPECT_STREQ("abcdef", (s + s2).getCString());
}

TEST(Plus_Operator, String_Plus_Char) {
	String s("abc");
	EXPECT_STREQ("abcdef", (s + "def").getCString());
}

TEST(Plus_Operator, Char_Plus_String) {
	String s("abc");
	EXPECT_STREQ("defabc", ("def" + s).getCString());
}

TEST(Plus_Operator, String_Plus_String_Empty) {
	String s("abc");
	String s2("");
	EXPECT_STREQ("abc", (s + s2).getCString());
}

TEST(Plus_Operator, String_Plus_Char_Empty) {
	String s("abc");
	EXPECT_STREQ("abc", (s + "").getCString());
}

TEST(Plus_Operator, Char_Plus_String_Empty) {
	String s("abc");
	EXPECT_STREQ("abc", ("" + s).getCString());
}