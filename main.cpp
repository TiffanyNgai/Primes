//
//  Tiffany Ngai
//  20900617
//  121 assignment2 q1
//
//  I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
//  Project: Primes
//  Due Date: 9/10/2020


/*
 Entered 1.1 and 0.9 as the input, find out that if the value of the input is less than 2 and is a decimal value, the program will output infinite "Enter and integer greater than 1: "
 Entered an integer less than 2 (e.g. 1) to test if the loop works (i.e. the program ask the user to input one more time)
 Entered an integer larger than 100000 (e.g. 1000000) to check if the program will check whether the prime is a palindromic prime or the sum of digits is odd
 Entered an integer between 10000 and 100000 (e.g. 50000) to check if the program will check whether the number is a palindromic prime
 Entered 50 (not too much value to check one by one) to check if the outputs are correct
 
 The program works for all value in the range between the maximum and minimum value of integer except for decimal value that is less than 2
 The pro100gram requires three minutes to run when the input is 1000000, input values smaller than or equal to 1000000 would be efficient
 */

#include <iostream>
using namespace std;

//function that find all the primes that are less than the input, indicate palindromic prime values, and sum of digits is odd
//input: target = the target integer, user must enter an integer greater than one
//output: primes less than or equal to the input
void primes() {
    
    //declare and initialize variables
    int target = 0;
    int digit1, digit2, digit3, digit4, digit5;
    int number_of_digits = 0;

    
    //get input from user until the required number is provided
    while (target < 2) {
        cout << "Enter an integer greater than 1: ";
        cin >> target;
    }
    
    //declare and initialize variable divisor, which is a value that help us to check whether a value is a prime; and current_target, where it is the value that we are evaluating if it is a prime
    int divisor = 2;
    int current_target = target;
    
    while (current_target > 1) {
        
        //declare and initialize boolean variables and set boolean values to false at the beginning of every loops
        bool is_prime = false;
        bool is_divisible = false;
        bool is_palindromic_prime = false;
        bool sum_of_digits_is_odd = false;
        
        //determine whether the current target is prime
        is_prime = divisor == current_target;
        
        //check if the number is a palindromic prime
        if (is_prime && current_target < 10000) {
            
            //isolate the digits
            digit1 = current_target / 1000;
            digit2 = current_target % 1000 / 100;
            digit3 = current_target % 100 / 10;
            digit4 = current_target % 10;
            
            //determine the number of digits
            if (digit1 != 0) {
                number_of_digits = 4;
            }
            else if (digit1 == 0 && digit2 != 0) {
                number_of_digits = 3;
            }
            else if (digit1 == 0 && digit2 == 0 && digit3 != 0) {
                number_of_digits = 2;
            }
            else {
                number_of_digits = 1;
            }
            
            //check if the number is a palindromic prime
            if (number_of_digits == 4 && digit1 == digit4 && digit2 == digit3) {
                is_palindromic_prime = true;
            }
            else if (number_of_digits == 3 && digit2 == digit4) {
                is_palindromic_prime = true;
            }
            else if (number_of_digits == 2 && digit3 == digit4) {
                is_palindromic_prime = true;
            }
            else if (number_of_digits == 1) {
                is_palindromic_prime = true;
            }
            else {
                is_palindromic_prime = false;
            }
            
        }
        
        //check if the sum of the digits is odd
        if (is_prime && current_target < 100000) {
            
            //isolate the digits
            digit1 = current_target / 10000;
            digit2 = current_target % 10000 / 1000;
            digit3 = current_target % 1000 / 100;
            digit4 = current_target % 100 / 10;
            digit5 = current_target % 10;
            
            //check if the sum of the digits is odd
            if ((digit1 + digit2 + digit3 + digit4 + digit5) % 2 == 1) {
                sum_of_digits_is_odd = true;
            }
            else {
                sum_of_digits_is_odd = false;
            }
            
        }
        
        //output the results
        if (is_palindromic_prime && sum_of_digits_is_odd) {
            cout << current_target << " is a palindromic prime and its sum of digits is odd" << endl;
        }
        else if (is_palindromic_prime) {
            cout << current_target << " is a palindromic prime" << endl;
        }
        else if (sum_of_digits_is_odd) {
            cout << current_target << " is a prime and its sum of digits is odd" << endl;
        }
        else if (is_prime) {
            cout << current_target << " is a prime" << endl;
        }
        
        //check if the current target is divisible by the current divisor
        is_divisible = current_target % divisor == 0;
        
        //minus the current target by 1 if the current target is divisible by the current divisor
        if (is_divisible && !is_prime) {
            current_target = current_target - 1;
            divisor = 2;
        }
        //divisor is incremented by 1 if the current target is not divisible
        else if (!is_divisible && !is_prime){
            divisor++;
        }
        
        //for primes, minus the current target by 1 and set the divisor back to 2 to allow the loop check the next value
        if (is_prime) {
            divisor = 2;
            current_target = current_target - 1;
        }
    }
}



int main() {

    primes();
    
    return 0;
}
