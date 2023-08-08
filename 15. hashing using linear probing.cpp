#include <stdio.h>
#define SIZE 10
int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    int numValues;
    printf("Enter the number of values to insert: ");
    scanf("%d", &numValues);
    for (int i = 0; i < numValues; i++) {
        int value;
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insert(hashTable, value);
    }
    display(hashTable);
    return 0;
}
