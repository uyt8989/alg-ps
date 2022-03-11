#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char team[5][20];
char A[20], B[20];
double W, D, L;
double stat[7][5] = { 0, };
double win_rate[7][3]; //i번째 경기의 승률
int match_result[7]; //i번째 경기의 승패
double finals[5] = { 0, };

int team_number(char name[]) { // 들어오는 순서대로 팀에 번호 부여 1~4
	for (int i = 1; i <= 4; i++)
		if (!strcmp(name, team[i]))
			return i;
	return 0;
}

void sort() { //상대하는 팀의 따라서 경기에 번호 부여 1~6
	int match_num;
	
	for (int j = 1; j <= 6; j++) {
		if (stat[j][0] == 1) {
			if (stat[j][1] == 2)//1 vs 2
				match_num = 1;
			else if (stat[j][1] == 3) //1 vs 3
				match_num = 2;
			else //1 vs 4
				match_num = 3;
		}
		else if (stat[j][0] == 2) {
			if (stat[j][1] == 3) //2 vs 3
				match_num = 4;
			else //2 vs 4
				match_num = 5;
		}
		else //3 vs 4
			match_num = 6;
		for (int i = 0; i < 3; i++)
			win_rate[match_num][i] = stat[j][i + 2];
	}
}

void calc_vp(int vp[]) { //승점 계산
	if (match_result[1] == 0) vp[1] += 3;
	else if (match_result[1] == 1) {
		vp[1] += 1; vp[2] += 1;
	}
	else vp[2] += 3;

	if (match_result[2] == 0) vp[1] += 3;
	else if (match_result[2] == 1) {
		vp[1] += 1; vp[3] += 1;
	}
	else vp[3] += 3;

	if (match_result[3] == 0) vp[1] += 3;
	else if (match_result[3] == 1) {
		vp[1] += 1; vp[4] += 1;
	}
	else vp[4] += 3;

	if (match_result[4] == 0) vp[2] += 3;
	else if (match_result[4] == 1) {
		vp[2] += 1; vp[3] += 1;
	}
	else vp[3] += 3;

	if (match_result[5] == 0) vp[2] += 3;
	else if (match_result[5] == 1) {
		vp[2] += 1; vp[4] += 1;
	}
	else vp[4] += 3;

	if (match_result[6] == 0) vp[3] += 3;
	else if (match_result[6] == 1) {
		vp[3] += 1; vp[4] += 1;
	}
	else vp[4] += 3;
}

void get_rank(int vp[], int vp_rank[]) { //각 팀의 등수 구하기
	int max, maxpos;

	for(int k = 1; k <= 4; k++){
		max = 0;
		for (int i = 1; i <= 4; i++) {
			if (max < vp[i]) {
				max = vp[i];
				maxpos = i;
			}
		}
		for (int i = 1; i <= 4; i++) {
			if (max == vp[i]) {
				vp_rank[i] = k;
				vp[i] = -1;
			}
		}
	}
}

void calc_finals(double rate, int vp_rank[], int rank_num[]) {
	if (rank_num[1] == 4) { // 1등 1등 1등 1등
		finals[1] += rate * ((double)1 / (double)2);
		finals[2] += rate * ((double)1 / (double)2);
		finals[3] += rate * ((double)1 / (double)2);
		finals[4] += rate * ((double)1 / (double)2);
	}
	else if (rank_num[1] == 3) { //1등 1등 1등
		for (int i = 1; i <= 4; i++) {
			if (vp_rank[i] == 1)
				finals[i] += rate * ((double)2 / (double)3);
		}
	}
	else if (rank_num[1] == 2) { //1등 1등
		for (int i = 1; i <= 4; i++) {
			if (vp_rank[i] == 1)
				finals[i] += rate;
		}
	}
	else if (rank_num[1] == 1 && rank_num[2] == 3) { //1등 2등 2등 2등
		for (int i = 1; i <= 4; i++) {
			if (vp_rank[i] == 1)
				finals[i] += rate;
			else if (vp_rank[i] == 2)
				finals[i] += rate * ((double)1 / (double)3);
		}
	}
	else if (rank_num[1] == 1 && rank_num[2] == 2) { //1등 2등 2등
		
		for (int i = 1; i <= 4; i++) {
			if (vp_rank[i] == 1)
				finals[i] += rate;
			else if (vp_rank[i] == 2)
				finals[i] += rate * ((double)1 / (double)2);
		}
	}
	else {
		for (int i = 1; i <= 4; i++) { //1등 2등
			if (vp_rank[i] == 1)
				finals[i] += rate;
			else if (vp_rank[i] == 2)
				finals[i] += rate;
		}
	}
}

void match(int i) {
	double total_win_rate = 1;
	int vp[5] = { 0, }; //승점의 합
	int vp_rank[5] = { 0, }; //각 팀의 순위
	int rank_num[5] = { 0, }; //각 순위의 팀 개수

	if (i == 6) {
		for (int i = 1; i <= 6; i++)
			total_win_rate *= (double)win_rate[i][match_result[i]];	
			//이번 경우의 수의 확률
	
		if (total_win_rate > 0) {
			calc_vp(vp);//승점 계산
			get_rank(vp, vp_rank);//승점에 따른 순위 계산
		
			for (int i = 1; i <= 4; i++) //각 순위의 개수 계산
				rank_num[vp_rank[i]]++;
	
			calc_finals(total_win_rate, vp_rank, rank_num);//확률 계산
		}
	}
	
	else { //다음 경기의 결과 선택
		match_result[i + 1] = 0; //win
		match(i + 1);
		match_result[i + 1] = 1; //draw
		match(i + 1);
		match_result[i + 1] = 2; //lose
		match(i + 1);
	}

	return;
}

int main() {
	int team_A, team_B, in_temp;
	double do_temp;

	for (int i = 1; i <= 4; i++)
		scanf("%s", team[i]);

	for (int i = 1; i <= 6; i++) {
		scanf("%s %s %lf %lf %lf", A, B, &W, &D, &L);
		team_A = team_number(A); team_B = team_number(B);
		if (team_A > team_B) {
			in_temp = team_A; team_A = team_B; team_B = in_temp;
			do_temp = W; W = L; L = do_temp;
		}
		stat[i][0] = (double)team_A; stat[i][1] = (double)team_B;
		stat[i][2] = W; stat[i][3] = D; stat[i][4] = L;
	}
	
	sort();
	match(0);

	for (int i = 1; i <= 4; i++)
		printf("%.10lf\n", finals[i]);

	return 0;
}
