#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main()
{
	int  i = 0, j = 0, Key_Size = 0, str_size = 0, select = 1;
	char str[50] = { 0, }, key[16] = { 0, };

	printf("암호문 또는 평문 을 입력 : ");
	gets(str);

	printf("암호는 1번, 복호는 2번 선택 : ");	// 암복호화를 선택
	scanf("%d", &select);
//	fflush(stdin);
	while (getchar() != '\n');

	printf("키 값 입력(소문자만) : ");				// 키를 입력
	gets(key);

	str_size = strlen(str);
	Key_Size = strlen(key);						// 키 길이를 계산

	for (i = 0; i<str_size; i++)
	{
		j = i % Key_Size;	// 사용되는 키를 선택 

		if (select == 1) {

			if ((str[i] >= 'a') && (str[i] <= 'z'))			/* 입력받은 값이 소문자일 경우 */
			{
				str[i] -= 'a';  key[j] -= 'a';				// 키의 숫자화

				if ((str[i] + key[j]) < 0)					// Vigenere  
					str[i] += 26;

				str[i] = (str[i] + key[j]) % 26;			// Vigenere  
				str[i] += 'a';   key[j] += 'a';				// 키를 원복시킴       
			}
			if ((str[i] >= 'A') && (str[i] <= 'Z'))			/* 입력 받은 값이 대문자일 경우 */
			{
				str[i] -= 'A'; key[j] -= 'a';				// 키의 숫자화

				if ((str[i] + key[j]) < 0)					// Vigenere
					str[i] += 26;

				str[i] = (str[i] + key[j]) % 26;			// Vigenere  
				str[i] += 'A'; key[j] += 'a';				// 키를 원복시킴       
			}
		}

		if (select == 2)
		{
			if ((str[i] >= 'a') && (str[i] <= 'z'))			/* 입력받은 값이 소문자일 경우 */
			{
				str[i] -= 'a';  key[j] -= 'a';				// 키의 숫자화

				if ((str[i] - key[j]) < 0)					// Vigenere
					str[i] += 26;

				str[i] = (str[i] - key[j]) % 26;			// Vigenere  
				str[i] += 'a'; key[j] += 'a';				// 키를 원복시킴                           
			}

			if ((str[i] >= 'A') && (str[i] <= 'Z'))			/* 입력 받은 값이 대문자일 경우 */
			{
				str[i] -= 'A'; key[j] -= 'a';				// 키의 숫자화

				if ((str[i] - key[j]) < 0)					// Vigenere
					str[i] += 26;

				str[i] = (str[i] - key[j]) % 26;			// Vigenere  
				str[i] += 'A'; key[j] += 'a';				// 키를 원복시킴       
			}
		}
	}

	printf("\n암호화 또는 복호화된 결과 출력 : ");
	puts(str);
}