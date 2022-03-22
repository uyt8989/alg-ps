#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>

using namespace std;

char c, cur;
stack<char> s;

int main() {
	while ((scanf("%c", &c) != EOF)) {
		if (c == '\n') break;

		if (c >= 'A' && c <= 'Z')
			printf("%c", c);

		else {
			if (c == '(') s.push(c);

			else if (c == '*' || c == '/') {
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					cur = s.top(); s.pop();
					printf("%c", cur);
				}
				s.push(c);
			}

			else if (c == '+' || c == '-') {
				while (!s.empty() && s.top() != '(') {
					cur = s.top(); s.pop();
					printf("%c", cur);
				}
				s.push(c);
			}

			else {
				while (!s.empty() && s.top() != '(') {
					cur = s.top(); s.pop();
					printf("%c", cur);
				}
				s.pop();
			}
		}
	}

	while (!s.empty()) {
		char cur = s.top(); s.pop();
		printf("%c", cur);
	}

	return 0;
}
