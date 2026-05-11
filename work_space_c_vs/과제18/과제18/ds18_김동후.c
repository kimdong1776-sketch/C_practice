#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int weight;
    int u;
    int v;
} node;

void insert(node e, node a[], int i) {
    a[0] = e;
    while (e.weight < a[i].weight) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}

void insertionSort(node a[], int n) {
    int j;
    for (j = 2; j <= n; j++) {
        node temp = a[j];
        insert(temp, a, j - 1);
    }
}

int main() {
    fprintf(stdout, "학부:컴퓨터학부 학번:2025003170 이름:김동후\n");

    FILE* in;
    fopen_s(&in, "in.txt", "r");
    if (!in) {
        fprintf(stderr, "file open err\n");
        exit(1);
    }

    int vertex;
    fscanf_s(in, "%d", &vertex);
    int temp;

    int** arr = (int**)calloc(vertex + 1, sizeof(int*));
    for (int i = 0; i <= vertex; i++) {
        arr[i] = (int*)calloc(vertex + 1, sizeof(int));
    }

    for (int i = 1; i < vertex; i++) {
        for (int j = i + 1; j <= vertex; j++) {
            fscanf_s(in, "%d", &temp);
            arr[i][j] = temp;
            arr[j][i] = temp;
        }
    }
    fclose(in);

    int max_edges = vertex * (vertex - 1) / 2;
    node* edgeArray = (node*)calloc(max_edges + 1, sizeof(node));
    int edgeCount = 0;

    for (int i = 1; i <= vertex; i++) {
        for (int j = i + 1; j <= vertex; j++) {
            if (arr[i][j] > 0) {
                edgeCount++;
                edgeArray[edgeCount].weight = arr[i][j];
                edgeArray[edgeCount].u = i;
                edgeArray[edgeCount].v = j;
            }
        }
    }

    insertionSort(edgeArray, edgeCount);

    for (int i = 1; i <= edgeCount; i++) {
        printf("%d (%d,%d)\n", edgeArray[i].weight, edgeArray[i].u, edgeArray[i].v);
    }

    for (int i = 0; i <= vertex; i++) {
        free(arr[i]);
    }
    free(arr);
    free(edgeArray);

    return 0;
}
