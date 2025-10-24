#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
void displayMenu();
void addItem();
void deleteItem();
void applyDiscount();
void choosePaymentMode();
void printBill();
char menuItems[10][50] = {"Pathaan", "KGF 2", "Brahmastra", "Drishyam 2", "Aadi
Purush", "Pushpa 2", "Gadar 2", "Chhatrapati", "Farzi", "Avtaar"};
float itemPrices[10] = {350.0, 599.0, 425.0, 199.0, 250.0, 525.0, 275.0, 299.0, 250.0,
399.0};
bool itemAvailable[10] = {true, true, true, true, true, true, true, true, true, true};
float discounts[10] = {0.10, 0.15, 0.05, 0.10, 0.05, 0.15, 0.20, 0.10, 0.05, 0.10};
int numItems = 10;
int cartItems[10] = {0};
int numCartItems = 0;
float totalAmount = 0.0;
float discountAmount = 0.0;
float finalAmount = 0.0;
int paymentMode = 0;
char name[50];
int main() {
printf("\n\n\tPlease Enter Customer Name ---> ");
gets(name);
int choice;
do {
printf("\n\n\t\t------------------Welcome To-----------------\n\n");
printf("\n\t\t========== MOVIE TICKET BOOKING SYSTEM ==========");
printf("\n\t\t1. Display Movies");
printf("\n\t\t2. Book Tickets");
printf("\n\t\t3. Cancel Tickets");
printf("\n\t\t4. Apply Discount");
printf("\n\t\t5. Choose Payment Mode");
printf("\n\t\t6. Print Ticket");
printf("\n\t\t7. Exit");
printf("\n\n\t\tEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
displayMenu();
break;
case 2:
addItem();
break;
case 3:
deleteItem();
break;
case 4:
applyDiscount();
break;
case 5:
choosePaymentMode();
break;
case 6:
printBill();
break;
case 7:
printf("\nThank you for using our Movie Ticket Booking System.
Exiting...\n");
break;
default:
printf("\nInvalid choice. Please try again.\n");
break;
}
} while (choice != 7);
return 0;
}
void displayMenu() {
printf("\n\n\t\t======WELCOME TO COLLEGE THEATER======\n");
printf("\t\t---------------------------------------\n");
for (int i = 0; i < numItems; i++) {
if (itemAvailable[i]) {
printf("\n\t\t%d. %s \t-->\t Rs.%.2f", i + 1, menuItems[i], itemPrices[i]);
}
}
printf("\n\n\n\n");
}
void addItem() {
int itemNumber;
int quantity;
printf("\n\tEnter the movie number to add to cart: ");
scanf("%d", &itemNumber);
if (itemNumber >= 1 && itemNumber <= numItems && itemAvailable[itemNumber -
1]) {
printf("\tEnter the quantity: ");
scanf("%d", &quantity);
cartItems[itemNumber - 1] += quantity;
printf("\n\tMovie(s) added to cart successfully.\n");
} else {
printf("\n\tInvalid item number. Please try again.\n");
}
}
void deleteItem() {
int itemNumber;
int quantity;
printf("\n\tEnter the movie number to delete from cart: ");
scanf("%d", &itemNumber);
if (itemNumber >= 1 && itemNumber <= numItems && cartItems[itemNumber - 1]
> 0) {
printf("\tEnter the quantity: ");
scanf("%d", &quantity);
if (quantity <= cartItems[itemNumber - 1]) {
cartItems[itemNumber - 1] -= quantity;
printf("\n\tMovie(s) deleted from cart successfully.\n");
} else {
printf("\n\tQuantity exceeds the available quantity in cart. Please try
again.\n");
}
} else {
printf("\n\tInvalid movie number or movie not present in cart. Please try again.\n");
}
}
void applyDiscount() {
int itemNumber;
printf("\n\tEnter the movie number to apply discount: ");
scanf("%d", &itemNumber);
if (itemNumber >= 1 && itemNumber <= numItems && cartItems[itemNumber - 1]
> 0) {
float discount = discounts[itemNumber - 1];
discountAmount += (itemPrices[itemNumber - 1] * cartItems[itemNumber - 1] *
discount);
printf("\n\tDiscount applied successfully.\n");
} else {
printf("\n\tInvalid movie number or movie not present in cart. Please try
again.\n");
}
}
void choosePaymentMode() {
printf("\n\t\t========== PAYMENT MODE ==========");
printf("\n\t\t1. Cash");
printf("\n\t\t2. Credit Card");
printf("\n\t\t3. Debit Card");
printf("\n\t\t4. Online Payment");
printf("\n\t\t5. Other");
printf("\n\n\tEnter the payment mode: ");
scanf("%d", &paymentMode);
printf("\n\tPayment mode chosen successfully.\n");
}
void printBill() {
srand(time(0));
int ran=rand();
char filename[50];
printf("\n\tEnter the filename to save the ticket\n\t(Use [ .txt ] at the end of file
name):---> ");
scanf("%s", filename);
FILE* billFile = fopen(filename, "w");
if (billFile == NULL) {
printf("\n\tUnable to create file. Please try again.\n");
return;
}
fprintf(billFile, "\n\n\t\t=========Hall Ticket==========\n");
fprintf(billFile, "\t\t--------------------------------\n");
fprintf(billFile, "\n\t\tCustomer Name: %s\n", name);
fprintf(billFile, "\t\tTicket no: \t\t%d",ran);
fprintf(billFile, "\n\n\t\tMovie\t\tQty\tPrice");
fprintf(billFile, "\n\t\t----\t\t---\t-----\n");
for (int i = 0; i < numItems; i++) {
if (cartItems[i] > 0) {
fprintf(billFile, "\t\t%s\t\t%d\tRs.%.2f\n", menuItems[i], cartItems[i],
itemPrices[i]);
totalAmount += (itemPrices[i] * cartItems[i]);
}
}
fprintf(billFile, "\n\n\t\tDiscount Amount: Rs.%.2f", discountAmount);
finalAmount = totalAmount - discountAmount;
fprintf(billFile, "\n\n\t\tTotal Amount: Rs.%.2f", totalAmount);
fprintf(billFile, "\n\n\t\tFinal Amount: Rs.%.2f", finalAmount);
fprintf(billFile, "\n\n\t\tPayment Mode: ");
switch (paymentMode) {
case 1:
fprintf(billFile, "Cash\n");
break;
case 2:
fprintf(billFile, "Credit Card\n");
break;
case 3:
fprintf(billFile, "Debit Card\n");
break;
case 4:
fprintf(billFile, "Online Payment\n");
break;
case 5:
fprintf(billFile, "Other\n");
break;
default:
fprintf(billFile, "Unknown\n");
Break;
}
fprintf(billFile, "\t\tThank you for watching with us!");
fclose(billFile);
printf("\n\tTicket saved successfully to %s\n", filename);
}
