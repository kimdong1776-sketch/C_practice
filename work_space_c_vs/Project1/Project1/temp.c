#include <stdio.h>
#include <stdlib.h>

// 단계 9에서 사용할 qsort용 오름차순 비교 함수
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // 단계 1: 학과, 학번, 이름 출력
    printf("컴퓨터학부 2025003170 김동후\n");

    FILE* fp = NULL;
    // 단계 2: 파일 in.txt 열기 및 n값 읽기 (Visual Studio 권장 fopen_s 사용)
    if (fopen_s(&fp, "in.txt", "r") != 0 || fp == NULL) {
        printf("in.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    int n = 0;
    fscanf_s(fp, "%d", &n);

    // 단계 3: n값 화면 출력
    printf("단계 3: %d\n", n);

    // 단계 4: n개를 저장할 공간 malloc 할당 (배열 L)
    int* L = (int*)malloc(sizeof(int) * n);
    if (L == NULL) {
        printf("메모리 할당 실패\n");
        fclose(fp);
        return 1;
    }

    // 단계 5: 파일에서 n개의 정수 읽어서 L에 저장
    for (int i = 0; i < n; i++) {
        fscanf_s(fp, "%d", &L[i]);
    }
    fclose(fp); // 파일 읽기 완료 후 닫기

    // 단계 6: 배열 L 출력
    printf("단계 6: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");

    // 단계 7: 최소값 발견 후 출력 (O(N))
    int min_val = L[0];
    for (int i = 1; i < n; i++) {
        if (L[i] < min_val) {
            min_val = L[i];
        }
    }
    printf("단계 7: %d\n", min_val);

    // 단계 8: 최소값보다 큰 수 중 가장 작은 수 출력 (O(N))
    int second_min = -1;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] > min_val) {
            if (!found || L[i] < second_min) {
                second_min = L[i];
                found = 1; // 조건을 만족하는 값을 최초로 찾았음을 표시
            }
        }
    }
    if (found) {
        printf("단계 8: %d\n", second_min);
    }

    // 단계 9: 배열 L에서 중복된 값 출력 (정렬 알고리즘 활용 O(N log N))
    printf("단계 9: ");

    // 원본 배열 L의 순서를 훼손하지 않기 위해 임시 배열 복사
    int* copy_L = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        copy_L[i] = L[i];
    }

    // 정렬 수행
    qsort(copy_L, n, sizeof(int), compare);

    int has_duplicate = 0;
    for (int i = 0; i < n - 1; i++) {
        // 현재 값과 다음 값이 같으면 중복
        if (copy_L[i] == copy_L[i + 1]) {
            // "50 50 50" 처럼 3번 이상 중복될 때 여러 번 출력되는 것을 방지
            if (i == 0 || copy_L[i] != copy_L[i - 1]) {
                printf("%d ", copy_L[i]);
                has_duplicate = 1;
            }
        }
    }

    if (!has_duplicate) {
        printf("중복 없음");
    }
    printf("\n");

    // 동적 할당 메모리 해제
    free(copy_L);
    free(L);

    return 0;
}