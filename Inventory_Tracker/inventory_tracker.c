

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int code;
    int quantity;
    float price;
} Item;

void listItems(Item items[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("\n%-5s %-15s %-10s %-8s\n", "Code", "Name", "Quantity", "Price");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s %-10d %-8.2f\n",
               items[i].code, items[i].name, items[i].quantity, items[i].price);
    }
}

void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full.\n");
        return;
    }
    Item it;
    printf("Enter item code (int): ");
    scanf("%d", &it.code);
    getchar(); // clear newline
    printf("Enter item name: ");
    fgets(it.name, NAME_LEN, stdin);
    size_t len = strlen(it.name);
    if (len > 0 && it.name[len - 1] == '\n')
        it.name[len - 1] = '\0';
    printf("Enter quantity: ");
    scanf("%d", &it.quantity);
    printf("Enter price: ");
    scanf("%f", &it.price);

    items[*count] = it;
    (*count)++;
    printf("Item added.\n");
}

void searchByCode(Item items[], int count) {
    if (count == 0) {
        printf("No items to search.\n");
        return;
    }
    int code;
    printf("Enter code to search: ");
    scanf("%d", &code);
    for (int i = 0; i < count; i++) {
        if (items[i].code == code) {
            printf("Found: %d | %s | qty=%d | price=%.2f\n",
                   items[i].code, items[i].name,
                   items[i].quantity, items[i].price);
            return;
        }
    }
    printf("No item with that code.\n");
}

void updateQuantity(Item items[], int count) {
    if (count == 0) {
        printf("No items to update.\n");
        return;
    }
    int code;
    printf("Enter code to update quantity: ");
    scanf("%d", &code);
    for (int i = 0; i < count; i++) {
        if (items[i].code == code) {
            int delta;
            printf("Current qty: %d. Enter change (+/-): ", items[i].quantity);
            scanf("%d", &delta);
            items[i].quantity += delta;
            if (items[i].quantity < 0) items[i].quantity = 0;
            printf("New quantity: %d\n", items[i].quantity);
            return;
        }
    }
    printf("No item with that code.\n");
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Inventory Tracker ===\n");
        printf("1. List items\n");
        printf("2. Add item\n");
        printf("3. Search by code\n");
        printf("4. Update quantity\n");
        printf("5. Exit\n");
        printf("Choose option: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: listItems(items, count); break;
            case 2: addItem(items, &count); break;
            case 3: searchByCode(items, count); break;
            case 4: updateQuantity(items, count); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
