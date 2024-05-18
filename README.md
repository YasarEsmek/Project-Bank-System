This C++ program is a simple banking system that allows users to create accounts, log in, deposit and withdraw money, and apply for loans. Additionally, it includes an admin interface for setting the interest rate for loans. The program features a menu-driven interface for ease of use.

             Components

1-Account Class

The Account class represents a user's bank account.
It includes attributes for the username, password, balance, and loan amount.
It has a constructor to initialize these attributes.

2-BankSystem Class

The BankSystem class manages all accounts and handles banking operations.
It uses an unordered_map to store accounts with the username as the key.
It has a default interest rate for loans, which can be updated by the admin.
Methods include:
createAccount(): Allows a new user to create an account.
login(): Allows an existing user to log in.
deposit(): Adds money to the user's balance.
withdraw(): Subtracts money from the user's balance if sufficient funds are available.
applyLoan(): Allows the user to apply for a loan and calculates the total amount to be repaid based on the interest rate and loan term.
setInterestRate(): Allows the admin to set a new interest rate.

3-Admin Menu

The adminMenu() function provides the admin with options to update the interest rate or exit.
It uses a simple menu-driven interface to perform these operations.

4-User Menu

The userMenu() function provides logged-in users with options to deposit money, withdraw money, apply for a loan, or exit.
It uses a simple menu-driven interface to perform these operations.

5-Main Function

The main() function provides the initial menu for creating an account, logging in, or accessing the admin interface.
It continues to display the menu until the user chooses to exit.

6-Key Points

Account Management: Users can create accounts, log in, and manage their balance and loans.
Loan Application: Users can apply for loans, and the system calculates the total repayment based on the current interest rate and loan term.
Admin Control: Admins can update the interest rate, which affects all new loan applications.
Menu Interface: The program uses a simple text-based menu system to interact with the user and admin, making it easy to navigate and use.
 
This system was designed by: Yaşar Berat Esmek 231504046
