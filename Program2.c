#include <stdio.h>
#include <stdbool.h>

int getItemPrice(char itemPrefix, int applePrice, int orangePrice, int pearPrice);
displayMenu(int applePrice, int orangePrice, int pearPrice);
withinBudget(int budget, char itemPrefix, int applePrice, int orangePrice, int pearPrice);
purchaseItem(int budget, char itemPrefix, int applePrice, int orangePrice, int pearPrice);

int main(void) {

	int orangePrice, applePrice, pearPrice, budget;  // main intigers that will be used to represent prices of products as well as the budget of a customer.
	char itemPrefix;  // requests the character that will be used to display purchase.
	bool proceed = true;  // bool type that will be used within the loop to decide if program should proceed with repeating functions. 

	printf("*****************\n");
	printf("Item prefixes\n");
	printf("A: Apple\n");
	printf("O: Orange\n");
	printf("P: Pear\n");
	printf("*****************\n\n");


	printf("***************\n");
	printf("*** MyStore ***\n");
	printf("***************\n\n");

	printf("**** SHOPKEEPER PANEL ****\n");

	printf("Welcome to the store. Please enter the prices for the following products: \n");
	printf("Please enter the price for the Orange: \x9C");
	scanf_s("%d", &orangePrice);						// Requests the shopkeeper to enter price of Oranges.
	printf("Please enter the price for the Apple: \x9C");
	scanf_s("%d", &applePrice);							// Requests the shopkeeper to enter price of Apples.
	printf("Please enter the price for the Pear: \x9C");
	scanf_s("%d", &pearPrice);							// Requests the shopkeeper to enter price of Pears.
	printf("\n\n");

	displayMenu(applePrice, orangePrice, pearPrice);	// Calls on the function that will display previously set prices by a shopkeeper.

	printf("**** Customer menu ****\n");
	printf("Please enter your budget: \x9C");
	scanf_s("%d", &budget);			// Requests the customer to enter their budget for purchases.



	while (proceed) {	// This loop will repeat purchasing aspect of the program if a user chooses to do so.
		printf("Please enter the item you would like to purchase using the item Prefix: ");
		scanf_s(" %c", &itemPrefix, 1);		// Requests user to enter the prefix of the item they want to purchase.
		printf("\n\n");
		getItemPrice(itemPrefix, applePrice, orangePrice, pearPrice);	// Calls on a function that has prices of items assigned to a specific prefixes.
		withinBudget(budget, itemPrefix, applePrice, orangePrice, pearPrice);		// Calls on a function that checks if the customers choice is within the budget.
		budget = purchaseItem(budget, itemPrefix, applePrice, orangePrice, pearPrice);		// Calls on function that provides receipt, sets the remaining balance as the budget for next purchase.
		bool isValid = false; // This bool will be used to check if the character inserted is correct

		while (!isValid) {	// This loop will check the validity of the user input.
			printf("Would you like to purchase anything else? enter [Y / N]\n");
			char answer;	// Character for validity check
			scanf_s(" %c", &answer, 1); // Requests character for the validity check
			printf("\n"); // Add a break between the lines.
			if (answer == 'Y' || answer == 'y') {	// Checks if answer is 'Y'
				proceed = true;	// if answer is 'Y' proceed and repeat the loop
				isValid = true; // if answer is 'Y' the character is valid and proceeding of loop is allowed

			}
			else if (answer == 'N' || answer == 'n') {	// Checks if answer is 'N'
				proceed = false; // if answer is 'N' program won't proceed and terminate the program
				isValid = true; // if answer is 'N' the character is valid
			}
			else { // If entered a character other than Y or N, the program will force the user to make the right choice.
				printf("Please enter a valid answer\n");
				isValid = false;	// Validity of user input will be false and above message will display, requesting user to make another choice.
			}
		}
	}
	return 0;
}




int getItemPrice(char itemPrefix, int applePrice, int orangePrice, int pearPrice)	// Checks the itemPrefix against the price of the item
{

	if (itemPrefix == 'A' || itemPrefix == 'a') { // if user inputs 'A' as a itemPrefix the program will return the price of an item.
		return applePrice;  // returns price of an Apple that was set by a shopkeeper.
	}
	else if (itemPrefix == 'O' || itemPrefix == 'o') {	// if user inputs 'O' as a itemPrefix the program will return the price of an item.
		return orangePrice;	// returns price of an Oranges that was set by a shopkeeper.
	}
	else if (itemPrefix == 'P' || itemPrefix == 'p') {	// if user inputs 'P' as a itemPrefix the program will return the price of an item.
		return pearPrice;	// returns price of an Pears that was set by a shopkeeper.
	}
	else {
		return -1;	// Any other prefix used apart from A, O or P, will be invalid.
	}

	return 0;
}

displayMenu(int applePrice, int orangePrice, int pearPrice)		// Displays prices of items in the shop
{

	printf("**** Shop Menu ****\n");
	printf("Item:\t\tPrice\n");
	printf("A:\t\t\x9C%d\n", applePrice);	// Displays price of Apples that have been set by a shopkeeper
	printf("O:\t\t\x9C%d\n", orangePrice);	// Displays price of Oranges that have been set by a shopkeeper
	printf("P:\t\t\x9C%d\n", pearPrice);	// Displays price of Pears that have been set by a shopkeeper
	printf("\n\n");
}

withinBudget(int budget, char itemPrefix, int applePrice, int orangePrice, int pearPrice)	// Checks if the user choice is within the budget set by a customer
{
	int itemPrice = getItemPrice(itemPrefix, applePrice, orangePrice, pearPrice);	// Sets variable itemPrice to be a function that takes itemPrefix and price.
	bool withinBudget; // Checks if the product is within the budget

	if (itemPrice == -1)	// If item price is invalid, the product is not within the budget.
	{
		withinBudget = false;
	}
	else if (itemPrice > budget) // If the item price is more than the customers budget, the product is not within the budget.
	{
		withinBudget = false;
		itemPrice = -1;
	}
	else	// If above fail, the product will be within the budget and will perform calculation.
	{
		withinBudget = true;
	}

	return withinBudget;
}

purchaseItem(int budget, char itemPrefix, int applePrice, int orangePrice, int pearPrice) // Function looks if purchase was successful or not, displays message according to the outcome.
{
	int remBudget = budget; // sets remaining budget to be re-used.
	int purchase = withinBudget(budget, itemPrefix, applePrice, orangePrice, pearPrice); // variable purchase checks if item chosen is within the chosen budget.
	int priceOfItem = getItemPrice(itemPrefix, applePrice, orangePrice, pearPrice); // variable gets price of item based on the prefix.

	if (purchase == 1) { // checks if the purchase is within budget and executes below code if it is.
		remBudget = (remBudget - priceOfItem); // calculates remaining budget by subtracting the price of item from the budget.
		printf("Purchase was a success!\n");
		printf("Purchase details\n");
		printf("----------------------\n");
		printf("Item: %c\n", itemPrefix); // Displays the prefix of an item bought.
		printf("Price: \x9C%d\n", priceOfItem); // Displays price of the item user have chosen.
		printf("Remaining budget: \x9C%d\n\n", remBudget); // Displays the remaining budget after the purchase.
		printf("Thanks for shopping with us!\n\n");
	}
	else {
		purchase = -1;
	}

	if (purchase == -1) { // if the purchase isn't within budget below message will be shown.
		printf("Purchase FAILED!\n");
		printf("Low budget or invalid item!\n\n");
		printf("Thanks for shopping with us!\n\n");
	}

	return remBudget;
};