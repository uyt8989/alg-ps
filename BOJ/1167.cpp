#include <iostream>
#include <cstring>

typedef struct _Node {
	int v;
	int cost;
	_Node* next;
}node;

int V;
node vertex[100001];
bool visit[100001];
int max, max_node;

void DFS(int start, int cost) {
	node* temp = vertex[start].next;
	visit[start] = true;

	while (temp != NULL) {
		if (visit[temp->v] == false) {
			if (cost + temp->cost > max) {
				max = cost + temp->cost;
				max_node = temp->v;
			}
			DFS(temp->v, cost + temp->cost);
		}
		temp = temp->next;
	}
}

int main() {
	int ver, v, cost;
	node* temp;

	std::cin >> V;

	for (int i = 1; i <= V; i++) {
		std::cin >> v;
		vertex[v].next = NULL;
		
		vertex[v].v = v;

		while (1) {
			std::cin >> ver;
			if (ver == -1) break;
			
			std::cin >> cost;

			temp = (node *)malloc(sizeof(node));
			temp->v = ver; temp->cost = cost;
			temp->next = vertex[v].next;
			vertex[v].next = temp;
		}
	}


	memset(visit, false, sizeof(visit));
	DFS(1, 0);
	memset(visit, false, sizeof(visit));
	max = 0;
	DFS(max_node, 0);

	std::cout << max;
	
	for (int i = 1; i <= V; i++) {
		while (vertex[i].next != NULL) {
			temp = vertex[i].next;
			vertex[i].next = (vertex[i].next)->next;
			free(temp);
		}
	}

	return 0;
}
