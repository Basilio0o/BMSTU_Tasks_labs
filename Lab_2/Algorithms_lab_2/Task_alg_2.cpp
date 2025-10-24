#include <iostream>
#include <cstring>

using namespace std;

void User_input(char* str, int len)
{
	cout << "Введите строку: ";
	cin.getline(str, len);
}

void Split_string(char* str, char words[10][100])
{
	const char delimiters[] = " ";
	char* token = strtok(str, delimiters);
	int i;
	for(i = 0; i < 10 && token != nullptr; i++)
	{
		strcpy(words[i], token);
		token = strtok(nullptr, delimiters);
	}
}

int Start_with_a(char words[10][100])
{
	int c = 0;
	for(int i = 0; i < 10; i++) if('a' == words[i][0]) c++;
	return c;
}

int Min_len(char words[10][100])
{
	int mn = strlen(words[0]);
	int temp;
	for(int i = 1; i < 10; i++)
	{
		temp = strlen(words[i]);
		if(temp < mn) mn = temp;
	}
	return mn;
}

int Count_a_last(char* words)
{
	int c = 0;
	for(size_t i = 0; i < strlen(words); i++) if('a' == words[i]) c++;
	return c;
}

void To_lower(char words[10][100])
{
	for(int i = 0; i < 10; i++)
	{
		for(size_t j = 0; j < strlen(words[i]); j++)
		{
			if(words[i][j] >= 'A' && words[i][j] <= 'Z') words[i][j] = tolower(words[i][j]);
		}
	}
}

int First_eq_last(char words[10][100])
{
	int c = 0;
	int temp = 0;
	for(int i = 0; i < 10; i++)
	{
		temp = strlen(words[i]);
		if(words[i][0] == words[i][temp-1]) c++;
	}
	return c;
}

int Max_substr(char words[10][100])
{
	char max_sb[100] = "";
	char tstr[100] = "";
	int mxln = 0;

	for(int k = 0; k < 10; k++)
	{
		for(int j = k+1; j < 10; j++)
		{
			for(size_t start = 0; start < strlen(words[j]); start++)
			{
				for(size_t end = start; end < strlen(words[j]); end++)
				{
					int len = end-start+1;
					if(len <= mxln) continue;
					strncpy(tstr, words[j] + start, len);
					tstr[len] = '\0';
					if(strstr(words[k], tstr) != nullptr)
					{
						mxln = len;
						strncpy(max_sb, words[j] + start, len);
						max_sb[len] = '\0';
					}
				}
			}
		}
	}
	if(mxln > 0) cout << "Максимальная общая подстрока (пример): "<< max_sb << " ";
	else cout << "Нет общих подстрок";
	return mxln;
}

int main()
{
	char str[100];
	char words[10][100];
	User_input(str, 100);
	Split_string(str, words);
	int cas = Start_with_a(words);
	int minimum = Min_len(words);
	int cal = Count_a_last(words[9]);
	To_lower(words);
	int cfl = First_eq_last(words);

	cout << "Количество слов начинающихся с буквы a: " << cas << endl;
	cout << "Длина самого короткого слова: " << minimum << endl;
	cout << "Количество букв a в последнем слове: " << cal << endl;
	cout << "Строка после приведения к одному регистру: ";
	for(int i = 0; i < 10; i++) cout << words[i] << " ";
	cout << "\nКоличество слов, у которых первая и последняя буквы совпадают: " << cfl << endl;
	int mxsb = Max_substr(words);
	cout << "(" << mxsb << ")" << endl;
	return 0;
}
