#include <stdio.h>
#include <stdint.h>
#define MAX 1000
char s[] = "I love Embedded. mr. vu, who is teaching me. i am so excited";
//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa

char *my_strchr(const char *str, int c);
int my_strlen(char s[]);
void my_strrev(char s[]);
void my_strcpy(char str[], char s[]);
void reverse_word(char s[]);
void lowcase(char str[]);
void uppercase(char str[]);
void afterdot(char str[]);

int main(int argc, char const *argv[]) {
    printf("\nString receive: %s\n", s);
    my_strrev(s);
    //reverse_word(s);
    printf("\nString after reverse: %s\n", s);
    my_strrev(s);
    lowcase(s);
    printf("\nString after lowercase: %s\n", s);
    uppercase(s);
    printf("\nString after uppercase: %s\n", s);
    lowcase(s);
    afterdot(s);
    printf("\nString after process: %s\n", s);
    return 0;
}
//Create 'strchr' function
char *my_strchr(const char *str, int c) {
    while (*str != '\0')
    {
        if(*str == c) return (char*) str;
        str++;
    }
    return NULL;
}
//Create 'strlen' function
int my_strlen(char s[]) {
    int i = 0;
    while (1) {
        if(s[i] == '\0') {
            return i;
        }
        i++;
    }
}
//Create 'strrev' function
void my_strrev(char s[]) {
    uint8_t len = my_strlen(s);
    for (uint8_t i = 0; i < (len / 2); i++) {
        s[i] = s[i] ^ s[len - i - 1];
        s[len - i - 1] = s[i] ^ s[len - i - 1];
        s[i] = s[i] ^ s[len - i - 1];
    }
    //Đảo từng ký tự trong chuỗi
    //VD:
    //s[0] = 5  chuyển thành s[0] = 1
    //s[1] = 4  chuyển thành s[1] = 2
    //s[2] = 3  chuyển thành s[2] = 3
    //s[3] = 2  chuyển thành s[3] = 4
    //s[4] = 1  chuyển thành s[4] = 5
    //Hoán vị vị trí s[i] và s[len - i - 1]
}
//Create 'strcpy' function
void my_strcpy(char str[], char s[])
{
	int length = my_strlen(s);
	for(int i = 0; i < length; i++)
	{
		str[i] = s[i];
	}
	str[length] = '\0';
}

void reverse_word(char s[]) {
    uint8_t len = my_strlen(s);
    for (uint8_t i = 0; i < len; i++) {
        s[i] = s[i] ^ s[len - i - 1];
        s[len - i - 1] = s[i] ^ s[len - i - 1];
        s[i] = s[i] ^ s[len - i - 1];
    }
}
//Lowcase
void lowcase(char str[]) {
    for (uint8_t i = 0; i < my_strlen(str); i++)
    {
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
}
void uppercase(char str[]) {
    for (uint8_t i = 0; i < my_strlen(str); i++)
    {
        if(str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
}
void afterdot(char str[]) {
    for (uint8_t i = 0; i < my_strlen(str); i++)
    {
        if(i == 0 || (i > 0 && str[i - 2] == 46)) { // 46 là mã ascii dấu chấm. s[i - 1] là khoảng trắng trước từ đó, s[i - 2] là vị trí của dấu chấm 
            if(str[i] >= 97 && str[i] <= 122) {
                str[i] -= 32;
                i++;
            } else if (str[i] >= 65 && str[i] <= 90)
            {
                break;
            }
        }
    } 
}
    

