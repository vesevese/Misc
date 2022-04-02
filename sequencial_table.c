#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

/*
* linear table struct:
* int* head, int length, int size
*/
struct seqTable {
    int* head;
    int length;
    int size;
};

struct seqTable createTable(const int size){
    struct seqTable table;
    table.head = malloc(sizeof(int) * size);
    table.length = 0;
    table.size = size;
    return table;
}

int insertElement(int index, int element, struct seqTable* table) {
    //save table head 
    int* orignalHead = table->head;
    
    //returns if the position of inserted element is less than 0 or more than length
    if (index > table->length || index < 0) {
        printf_s("invalid index : %d, valid index range should be 0 - %d\n", index, table->length);
        return 0;
    }

    //expends the table if it is full
    if (table->length == table->size) {
        table->head = realloc(table->head, (table->size + 1) * sizeof(int));

        //keep the original table head if realloc failed
        if (!table->head) {
            table->head = orignalHead;
            return 0;
        }
        else {
            table->size++;
        }
    }

    //swap elements
    for (int i = (table->length); i > index; i--) {
        table->head[i] = table->head[i-1];
    }

    table->head[index] = element;
    table->length++;
}

int delElement(int index, struct seqTable* table) {
    
    //check invalid index
    if (index > table->length - 1 || index < 0) {
        printf_s("invalid index : %d, valid index range should be 0 - %d\n", index, table->length - 1);
        return 0;
    }

    //swap elements and delete
    for (int i = index; i < table->length - 1; i++) {
        table->head[i] = table->head[i + 1];
    }

    table->length--;
}

int searchElement(int element, struct seqTable* table) {
    for (int i = 0; i < table->length; i++) {
        if (table->head[i] == element) {
            return i;
        }
    }

    return -1;
}

int getLength(struct seqTable* table) {
    return table->length;
}
int sort(struct seqTable* table);

void printTable(struct seqTable* table) {
    printf_s("table length : %d\n", table->length);
    printf_s("table size : %d\n", table->size);

    for (int i = 0; i < table->length; i++) {
        printf_s("%d, ", table->head[i]);
    }

    printf_s("\n");
}

int main() {

    struct seqTable table = createTable(SIZE);
    insertElement(0, 1, &table);
    insertElement(0, 2, &table);
    insertElement(0, 3, &table);
    insertElement(0, 4, &table);
    insertElement(0, 5, &table);
    insertElement(0, 6, &table);
    insertElement(0, 7, &table);
    insertElement(0, 8, &table);
    insertElement(5, 0, &table);
    insertElement(5, 0, &table);
    insertElement(5, 0, &table);
    insertElement(5, 0, &table);
    insertElement(16, 0, &table);
    insertElement(12, 13, &table);

    printTable(&table);

    delElement(13, &table);
    delElement(12, &table);
    delElement(5, &table);

    printTable(&table);

    printf_s("\n%d", searchElement(3, &table));

    return 0;
}
