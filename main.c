#include <stdio.h>

int main() {
    int choice;
    int n = 0;
    int a[50];

    while (1) {
        printf("Array Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Sort\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("How many values you want to insert: ");
                scanf("%d", &n);
                printf("Enter %d values: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                break;
            }
            case 2: {
                int index, value;
                printf("Enter index and the value: ");
                scanf("%d %d", &index, &value);
                if (index < 0 || index > n) {
                    printf("Invalid index!\n");
                }
                else {
                    for (int i = n; i > index; i--) {
                        a[i] = a[i - 1];
                    }
                    a[index] = value;
                    n++;
                }
                break;
            }
            case 3: {
                int index;
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("Invalid index!\n");
                }
                else {
                    for (int i = index; i < n - 1; i++) {
                        a[i] = a[i + 1];
                    }
                    n--;
                }
                break;
            }
            case 4: {
                printf("Current array state: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            }
            case 5: {
                int temp, sortChoice;
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Choose sorting order: ");
                scanf("%d", &sortChoice);
                if (sortChoice == 1) {
                    for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (a[i] > a[j]) {
                                temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;
                            }
                        }
                    }
                }
                else if (sortChoice == 2) {
                    for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (a[i] < a[j]) {
                                temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;
                            }
                        }
                    }
                }
                else {
                    printf("Invalid sort choice.\n");
                }
                break;
            }
            case 6: {
                int m, found = 0;
                printf("Enter value to search: ");
                scanf("%d", &m);
                for (int i = 0; i < n; i++) {
                    if (a[i] == m) {
                        printf("Value found at index %d.\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Value not found.\n");
                }
                break;
            }
            case 7: {
                printf("Exit program.\n");
                return 0;
            }
            default:
                printf("Invalid input. Choose between 1 and 7.\n");
        }
        if ((choice >= 1 && choice <= 6) && choice != 4) {
            printf("Current array state: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
