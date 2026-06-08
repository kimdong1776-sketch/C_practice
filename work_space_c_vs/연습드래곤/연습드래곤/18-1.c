#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// 간선 정보를 담을 구조체
typedef struct {
    int u;
    int v;
    int weight;
} Edge;

int parent[MAX_VERTICES];
Edge edges[MAX_EDGES];
int num_edges = 0;

// qsort를 위한 오름차순 비교 함수 (가중치 기준)
int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// 1. Collapsing Find 함수
int collapsingFind(int i) {
    int root, trail, lead;

    // root 찾기
    for (root = i; parent[root] >= 0; root = parent[root])
        ;

    // 찾아가는 경로에 있는 모든 노드의 부모를 root로 변경
    for (trail = i; trail != root; trail = lead) {
        lead = parent[trail];
        parent[trail] = root;
    }

    return root;
}

// 2. Weighted Union 함수
void weightedUnion(int i, int j) {
    int temp = parent[i] + parent[j];

    // 개수가 더 적은 쪽이 자식으로 들어감 (음수이므로 >= 로 비교)
    if (parent[i] >= parent[j]) {
        parent[i] = j;       // j를 새로운 루트로 설정
        parent[j] = temp;    // j의 노드 개수 갱신
    }
    else {
        parent[j] = i;       // i를 새로운 루트로 설정
        parent[i] = temp;    // i의 노드 개수 갱신
    }
}

// Kruskal 알고리즘 메인 함수
void kruskal(int n) {
    int edge_accepted = 0;

    // 1. 가중치(weight)에 대해 오름차순으로 edge들을 정렬한다.
    qsort(edges, num_edges, sizeof(Edge), compareEdges);

    // 2. 가중치가 작은 edge부터 차례대로 선택하여 T에 추가 결정
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // 양 끝점의 root를 찾음
        int root_u = collapsingFind(u);
        int root_v = collapsingFind(v);

        // Find(a) != Find(b) 인 경우에만 T에 추가 (사이클 방지)
        if (root_u != root_v) {
            // 출력 조건: (a, b) where a < b
            int a = (u < v) ? u : v;
            int b = (u > v) ? u : v;

            // 해당 정보 weight (a, b) 차례대로 화면 출력
            printf("%d (%d, %d)\n", w, a, b);

            // Union(Find(a), Find(b)) 수행
            weightedUnion(root_u, root_v);
            edge_accepted++;

            // Spanning Tree는 n-1개의 간선을 가지면 완성됨
            if (edge_accepted == n - 1) {
                break;
            }
        }
    }
}

int main() {
    FILE* fp = fopen("in.txt", "r");
    if (!fp) {
        printf("in.txt 파일을 열 수 없습니다.\n");
        return -1;
    }

    int n;
    // 첫 줄: 정점의 개수 n 읽기 (정점은 0부터 n-1 번호라고 가정)
    if (fscanf(fp, "%d", &n) != 1) return -1;

    // parent 배열 초기화 (-1)
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    // 파일에서 간선 정보 읽기 (u, v, 가중치)
    // 입력 파일 형식이 다를 경우 이 부분을 과제#18에 맞춰 수정하시면 됩니다.
    while (fscanf(fp, "%d %d %d", &edges[num_edges].u, &edges[num_edges].v, &edges[num_edges].weight) != EOF) {
        num_edges++;
    }
    fclose(fp);

    printf("학부: 컴퓨터공학부 학번: 00000000 이름: 홍길동\n");
    printf("[추가된 간선 목록]\n");

    // 크루스칼 알고리즘 실행
    kruskal(n);

    return 0;
}