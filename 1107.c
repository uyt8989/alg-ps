#include <stdio.h>
#include <stdlib.h>

#define INF 987654321;

int N, M;
int now = 100;
int broken[11] = { 0, };
int up_change = 0;
int down_change = 0;
int up, down, up_sign = 0, down_sign = 0;
int digit_len;
int ten;
int up_len;
int down_len;

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

int avail(int a) {
	int i = 10;
	int digit[7];
	digit_len = 0;

	if (a < 10)
		digit[digit_len++] = a;
	else {
		while (i <= a * 10) {
			digit[digit_len++] = ((a % i) - (a % (i / 10))) / (i / 10);
			i = i * 10;
		} 
	}

	for (int k = digit_len - 1; k >= 0; k--) {
		for (int j = 0; j < M; j++)
			if (digit[k] == broken[j]) {
				ten = k;
				return 0;
			}
	}
	
	return 1; 
}

void updown(int a) {
	int temp, temp2;

	up = a;
	down = a;

	while (!up_sign && up <= 1000000) {
		//printf("uping: % d\n", up);

		if (!up_sign && avail(up))
			up_sign = 1;
		if (!up_sign) {
			temp = 1;
			for (int i = 0; i < ten; i++)
				temp = temp * 10;
			temp2 = up;
			up = ((up + temp) / temp) * temp;
			up_change += up - temp2;
		}
	}

	while (!down_sign && down >= 0) {
		//printf("downing : %d\n", down);
		
		if (!down_sign && down >= 0)
			if (avail(down))
				down_sign = 1;
		if (!down_sign) {
			temp = 1;
			for (int i = 0; i < ten; i++)
				temp = temp * 10;
			temp2 = down;
			down = (down / temp) * temp - 1;
			down_change += temp2 - down;
		}
	}

	//printf("up : %d down : %d \n", up, down);
} 


int main() {
	int up_len = 1;
	int down_len = 1;
	
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &broken[i]);

	if (N == 100) {
		printf("0\n");
		return 0;
	}

	if (M == 10) {
		printf("%d\n", abs(N - now));
		return 0;
	} 

	updown(N);

	if (!down_sign && !up_sign)
		printf("%d\n", abs(N - now));
	if (!down_sign && up_sign) {
		while (up / 10 != 0) {
			up = up / 10;
			up_len++;
		}
		printf("%d\n", MIN(up_change + up_len, abs(N - now)));
	}
	if (down_sign && !up_sign) {
		while (down / 10 != 0) {
			down = down / 10;
			down_len++;
		}
		printf("%d\n", MIN(down_change + down_len, abs(N - now)));
	}
	if (up_sign && down_sign) {
		while (up / 10 != 0) {
			up = up / 10;
			up_len++;
		}
		while (down / 10 != 0) {
			down = down / 10;
			down_len++;
		}
		printf("%d\n", MIN(MIN(up_change + up_len , down_change + down_len), abs(N - now)));
	}

	return 0;
}
