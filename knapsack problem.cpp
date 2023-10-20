#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratioA = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;
    if (ratioA > ratioB) return -1; 
    if (ratioA < ratioB) return 1;
    return 0;
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0; 
    int currentWeight = 0;  

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            totalValue += items[i].value * fraction;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    struct Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack: %.2lf\n", maxValue);

    return 0;
}

