typedef struct _User {
	int uID;
	int income;
}User;

int list_size;
User list[10];

void init()
{
	for (int i = 0; i < 10; i++) {
		list[i].income = -1;
		list[i].uID = -1;
	}

	list_size = 0;
}

void addUser(int uID, int income)
{
	if (list_size < 10) list_size++;
	for (int i = 0; i < list_size; i++) {
		if (list[i].income < income) {
			for (int j = list_size - 1; j > i; j--) {
				list[j] = list[j - 1];
			}
			list[i].uID = uID;
			list[i].income = income;

			break;
		}
	}
}

int getTop10(int result[10])
{
	for (int i = 0; i < list_size; i++) {
		result[i] = list[i].uID;
	}
	return list_size;
}