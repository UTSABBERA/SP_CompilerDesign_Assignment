//Program to design of a Lexical Analyzer (for C)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isDelimiter(char ch) {
	char delemiters[] = {' ', '+', '-', '*', '/', ',', ';', '>', '<', '=', '(', ')' ,'[', ']', '{', '}'};
	for (int i = 0; i < sizeof(delemiters)/sizeof(delemiters[0]); i++) 
        if (ch == delemiters[i]) return true;
    return false;
}

bool isOperator(char ch) {
	char operators[] = {'+', '-', '*', '/', '>', '<', '='};
	for (int i = 0; i < sizeof(operators)/sizeof(operators[0]); i++) 
        if (ch == operators[i]) return true;
    return false;
}

bool validIdentifier(char* str) {
	char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (isDelimiter(str[0])) return false;
	for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
        if (str[0] == numbers[i]) return false;
    return true;
}

bool isKeyword(char* str) {
char keywords[][10] = { "auto","break","case","char","const","continue","default",
                        "do","double","else","enum","extern","float","for","goto",
                        "if","int","long","register","return","short","signed",
                        "sizeof","static","struct","switch","typedef","union",
                        "unsigned","void","volatile","while" };
	for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) 
        if (!strcmp(keywords[i], str)) return true;
    return false;
}

bool isNumber(char* str) {
	char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
	int i, len = strlen(str);
	if (len == 0 || (str[i] == '-' && i > 0)) return false;
	for (i = 0; i < len; i++) {
		for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
            if (str[0] != numbers[i]) return false;
	}
	return true;
}

char* subString(char* str, int left, int right) {
	int i;
	char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
	for (i = left; i <= right; i++) subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

void parse(char* str) {
	int left = 0, right = 0;
	int len = strlen(str);
	while (right <= len && left <= right) {
		if (!isDelimiter(str[right])) right++;
		if (isDelimiter(str[right]) && left == right) {
			if (isOperator(str[right]) == true) 
                printf("'%c' IS AN OPERATOR\n", str[right]);
			right++;
			left = right;
		} else if (isDelimiter(str[right]) && left != right || (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);

			if (isKeyword(subStr))
				printf("'%s' IS A KEYWORD\n", subStr);

			else if (isNumber(subStr))
				printf("'%s' IS AN INTEGER\n", subStr);

			else if (validIdentifier(subStr) && isDelimiter(str[right - 1]))
				printf("'%s' IS A VALID IDENTIFIER\n", subStr);

			else if (validIdentifier(subStr) && isDelimiter(str[right - 1]))
				printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
			left = right;
		}
	}
	return;
}

int main() {
	char line[100] = "int a = b + 1c; ";
	parse(line); // parsing the line of program

	return (0);
}
