#include <stdio.h>
/******************************************************************************
# Author:           Liam Campbell
# Lab:              Assignment #5
# Date:             October 24th, 2023
# Description:      Track your stocks
# Input:            char menuOption, int stockIdNums[], double stockPrices[]                       int stockToUpdate,
                    double udatePrice, pricePoint, 
# Output:           int stockIdNums[], double stockPrices
# Sources:          None
#******************************************************************************/
int main(void) {
  int stockIdNums[5];
  double stockPrices[5];
  char menuOption[2];
  double updatePrice, pricePoint = 0.00;
  int stockToUpdate;
  /*Set menu option as o so stock 
  list will appear first time through*/
  menuOption[1] = 'o';
  
  printf("Welcome to the Stock Price Portfolio Program!\n");
  //gather 5 stock prices and ids 
  for(int i = 0; i < 5; i++){
    printf("Enter Stock ID number: \n");
    scanf(" %d", &stockIdNums[i]);
    printf("Enter Stock Price $: \n");
    scanf(" %lf", &stockPrices[i]);
  }

  do {
    
    switch (menuOption[1]) {
      // allow user to input capitol or lowercase
      case 'o':
      case 'O':
        // if price point is set above 0.00 display it.
        if(pricePoint == 0.00){
          printf("\tStock List\n");
        } else {
          printf("Stocks above $%0.2lf\n", pricePoint);
        }
        // displays all stocks if pricePoint set to 0.00
        for(int i = 0; i < 5; i++){
          if(stockPrices[i] > pricePoint){
            printf("Stock %d -- ID number: %d, Price: %0.2lf\n", i, stockIdNums[i], stockPrices[i]);
          }
        }
        // reset price point and return to menu
        pricePoint = 0.00;
        menuOption[1] = 'm';
        break;
      case 'a':
      case 'A':
        // get the price point to display stocks above
        printf("Enter a price $: \n");
        scanf("%lf", &pricePoint);
        // go to option o to display prices
        menuOption[1] = 'o';
        break;
      case 'u':
      case 'U':
        // gather user input for which stock and price to update
        printf("Enter a Stock ID number: \n");
        scanf(" %d", &stockToUpdate);
        printf("Enter a new price for this stock\n");
        scanf("%lf", &updatePrice);
        // use for loop to identify correct stock
        for(int i = 0; i < 5; i++){
          if(stockIdNums[i] == stockToUpdate){
            stockPrices[i] = updatePrice;
            break;
          }
        }
        printf("Stock price updated!\n");
        menuOption[1] = 'm';
        break;
      case 'm': 
      case 'M':
        // display menu options
        printf("\tMENU\n");
        printf("u - Update Stock price\n");
        printf("a - Output Stocks above a price\n");
        printf("o - Output Stocks list with ID numbers and price\n");
        printf("q - Quit\n\n");
        printf("Choose an option: \n");
        scanf(" %c", &menuOption[1]);
        break;
      default: 
        printf("Invalid option! Please try again\n");
        //send back to menu
        menuOption[1] = 'm';
        break;
      
    }
  } while (menuOption[1] != 'q');
  return 0;
}