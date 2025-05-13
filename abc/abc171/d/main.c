#include "am.h"
#include <stdio.h>

#define BOX 100000

ii table[BOX];

int main() {
	int key1 = 1;
	int key2 = 2;
	int key3 = 3;
	int key4 = 4;
	int avg = 10;

	insert_ii(table, key1, 1, BOX);
	insert_ii(table, key2, 1, BOX);
	insert_ii(table, key3, 1, BOX);
	insert_ii(table, key4, 1, BOX);

	printf("%d\n", avg);


//search
//if none
//	insert
//else
//	add value
	int value1 = delete_ii(table, 1, BOX);
	//insert_ii(table, 2, value1, BOX);
	table[hash(2)].value += value1;
	avg += (2 - 1) * value1;
	printf("%d\n", avg);

	int value2 = delete_ii(table, 3, BOX);
	insert_ii(table, 4, value2, BOX);
	avg += (4 - 3) * value2;
	printf("%d\n", avg);

	int value3 = delete_ii(table, 2, BOX);
	insert_ii(table, 4, value3, BOX);
	avg += (4 - 2) * value3;
	printf("%d\n", avg);
}
