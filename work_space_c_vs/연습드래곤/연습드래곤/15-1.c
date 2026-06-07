#include <stdio.h>
#include <stdlib.h>

int* parent;

// Weighted Union 함수
void weightedUnion(int i, int j) {
    /* i와 j는 루트 노드. 음수 값으로 트리의 노드 개수를 가짐 */
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

// Collapsing Find 함수
int collapsingFind(int i) {
    int root, trail, lead;

    // 1. root 찾기
    for (root = i; parent[root] >= 0; root = parent[root])
        ;

    // 2. 찾아가는 경로에 있는 모든 노드의 부모를 root로 변경 (Collapsing)
    for (trail = i; trail != root; trail = lead) {
        lead = parent[trail];
        parent[trail] = root;
    }

    return root;
}

void printArray(int n) {
    for (int i = 0; i <= n; i++) {
        printf("%2d ", parent[i]);
    }
    printf("\n");
}

int main() {
    FILE* fp = fopen("in.txt", "r");
    if (!fp) {
        printf("in.txt 파일을 열 수 없습니다. 파일 위치를 확인해주세요.\n");
        return -1;
    }

    int n;
    if (fscanf(fp, "%d", &n) != 1) {
        fclose(fp);
        return -1;
    }

    // 집합 S = {0, 1, 2, ..., n} 이므로 배열 크기는 n + 1
    parent = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        parent[i] = -1; // 초기화
    }

    // 초기 정보 출력 (본인 정보로 수정해서 사용하세요)
    printf("학부: 컴퓨터공학부 학번: 00000000 이름: 홍길동\n");

    char cmd;
    // 파일의 끝(EOF)에 도달할 때까지 명령어 읽기
    while (fscanf(fp, " %c", &cmd) != EOF) {
        if (cmd == 'U') {
            int x, y;
            fscanf(fp, "%d %d", &x, &y);
            weightedUnion(x, y);

            printf("U %d %d: ", x, y);
            printArray(n);
        }
        else if (cmd == 'F') {
            int x;
            fscanf(fp, "%d", &x);

            // Find를 수행하면서 배열의 값(경로)이 Collapsing 됨
            int root = collapsingFind(x);

            // 간격 정렬을 위해 띄어쓰기 추가 ("F 0:    ")
            printf("F %d:    ", x);
            printArray(n);
            printf("%d\n", root); // 루트 출력
        }
    }

    // 동적 할당 해제 및 파일 닫기
    free(parent);
    fclose(fp);

    return 0;
}