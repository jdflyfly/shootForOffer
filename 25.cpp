#include<stdio.h>
#include<vector>

using namespace std;

typedef struct Node {
	int idx;
	int val;
	int leftIdx;
	int rightIdx;
} Node;

Node nodes[10005];
vector<vector<int> > paths;

void dfs(Node node, int sum, vector<int> path, int k) {

	if (sum + node.val == k && node.leftIdx == -1 && node.rightIdx == -1) {
		path.push_back(node.idx);
		paths.push_back(path);
		path.pop_back();

	}
	//travel the smaller node first
	if (node.leftIdx <= node.rightIdx) {
		if (node.leftIdx != -1) {
			path.push_back(node.idx);
			dfs(nodes[node.leftIdx], sum + node.val, path, k);
			path.pop_back();
		}
		if (node.rightIdx != -1) {
			path.push_back(node.idx);
			dfs(nodes[node.rightIdx], sum + node.val, path, k);
			path.pop_back();
		}
	} else {
		if (node.rightIdx != -1) {
			path.push_back(node.idx);
			dfs(nodes[node.rightIdx], sum + node.val, path, k);
			path.pop_back();
		}
		if (node.leftIdx != -1) {
			path.push_back(node.idx);
			dfs(nodes[node.leftIdx], sum + node.val, path, k);
			path.pop_back();
		}
	}

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		paths.clear();
		int i;
		for (i = 1; i <= n; i++) {
			scanf("%d%d%d", &nodes[i].val, &nodes[i].leftIdx,
					&nodes[i].rightIdx);
////for lex order, swap two children when left > right
//			if (nodes[i].leftIdx > nodes[i].rightIdx) {
//				int tmp = nodes[i].leftIdx;
//				nodes[i].leftIdx = nodes[i].rightIdx;
//				nodes[i].rightIdx = tmp;
//			}
			nodes[i].idx = i;
		}

		vector<int> path;
		dfs(nodes[1], 0, path, k);
		printf("result:\n");
		unsigned int p, q;
		for (p = 0; p < paths.size(); p++) {
			printf("A path is found:");
			for (q = 0; q < paths[p].size(); q++)
				printf(" %d", paths[p][q]);
			printf("\n");
		}

	}

	return 0;
}
