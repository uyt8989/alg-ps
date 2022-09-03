#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string.h>

#define HASH_SIZE (1 << 16)
#define DIV (HASH_SIZE - 1)
#define MAX_RECORD 50001
#define RECORD_MAX 21
#define MAX_FIELD 5

using namespace std;

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;

typedef struct _Record {
	bool valid;
	char Field[MAX_FIELD][RECORD_MAX];
	unsigned long HashVal[MAX_FIELD];
} Record;

int DBs;
Record DB[MAX_RECORD];
vector<int> HashTable[MAX_FIELD][HASH_SIZE];

unsigned long getHash(const char* str)
{
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c);
	}
	return hash % HASH_SIZE;
}


void InitDB()
{
	DBs = 0;
	for (int i = 0; i < MAX_FIELD; i++)
		for (int j = 0; j < HASH_SIZE; j++)
			HashTable[i][j].clear();
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	strcpy(DB[DBs].Field[NAME], name);
	HashTable[NAME][getHash(name)].push_back(DBs);

	strcpy(DB[DBs].Field[NUMBER], number);
	HashTable[NUMBER][getHash(number)].push_back(DBs);

	strcpy(DB[DBs].Field[BIRTHDAY], birthday);
	HashTable[BIRTHDAY][getHash(birthday)].push_back(DBs);

	strcpy(DB[DBs].Field[EMAIL], email);
	HashTable[EMAIL][getHash(email)].push_back(DBs);

	strcpy(DB[DBs].Field[MEMO], memo);
	HashTable[MEMO][getHash(memo)].push_back(DBs);

	DB[DBs].valid = true;
	DBs++;

	return;
}

int Delete(FIELD field, char* str)
{
	unsigned long HashValue = getHash(str);
	int size = HashTable[field][HashValue].size();
	int ret = 0;

	for (int i = 0; i < size; i++) {
		int RecordNum = HashTable[field][HashValue][i];
		if (DB[RecordNum].valid && !strcmp(DB[RecordNum].Field[field], str)) {
			DB[RecordNum].valid = false;
			ret++;
		}
	}

	return ret;
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	unsigned long HashValue = getHash(str);
	unsigned long ChangeValue = getHash(changestr);
	int size = HashTable[field][HashValue].size();
	int ret = 0;

	for (int i = 0; i < size; i++) {
		int RecordNum = HashTable[field][HashValue][i];
		
		if (DB[RecordNum].valid && !strcmp(DB[RecordNum].Field[field], str)) {
			DB[RecordNum].HashVal[changefield] = ChangeValue;
			HashTable[changefield][ChangeValue].push_back(RecordNum);
			strcpy(DB[RecordNum].Field[changefield], changestr);
			ret++;
		}
	}

	return ret;
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	unsigned long HashValue = getHash(str);
	int size = HashTable[field][HashValue].size();
	RESULT result;
	result.count = 0;
	int idx;

	for (int i = 0; i < size; i++) {
		int RecordNum = HashTable[field][HashValue][i];
		
		if (DB[RecordNum].valid && !strcmp(DB[RecordNum].Field[field], str)) {
			idx = i;
			result.count++;
		}
	}

	if (result.count == 1) {
		int RecordNum = HashTable[field][HashValue][idx];
		strcpy(result.str, DB[RecordNum].Field[ret_field]);
	}

	return result;
}
