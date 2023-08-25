// Created by Ostapenko Artem
// GitHub account https://github.com/Krahjotdaan
// This repository licensed as Open Source under MIT License
// This algoritm described by Hans Peter Luhn, U.S. Patent No. 2,950,048, granted on August 23, 1960
#include <iostream>
using namespace std;
bool luhn_algorithm(long long sequence) {

    // determining the number of digits in a sequence
    int numbers_amount = 0;
    long long tmp = sequence;
    while (tmp > 0) {
        numbers_amount++;
        tmp /= 10;
    }

    // creating array of digits from sequence 
    int sequence_array[numbers_amount];
    for (int i = numbers_amount - 1; i >= 0; i--) {
        sequence_array[i] = sequence % 10;
        sequence /= 10;
    }

    /* Starting from the first digit of the sequence on 
    the left and after one digit if the number of digits 
    in the sequence is odd and one control, if the number 
    of digits is even and one control, starting from the 
    second digit of the sequence after one digit, a check 
    is made: if 2 * x > 9 , then 9 is subtracted from the 
    product, otherwise the product 2 * x is left unchanged, 
    where x is the current digit. */
    if (numbers_amount % 2 == 0) {
        for (int i = 0; i < numbers_amount - 1; i += 2) {
            if (sequence_array[i] * 2 > 9) {
                sequence_array[i] = sequence_array[i] * 2 - 9;
            }
            else {
                sequence_array[i] = sequence_array[i] * 2;
            }
        }
    }
    else {
        for (int i = 1; i < numbers_amount - 1; i += 2) {
            if (sequence_array[i] * 2 > 9) {
                sequence_array[i] = sequence_array[i] * 2 - 9;
            }
            else {
                sequence_array[i] = sequence_array[i] * 2;
            }
        }
    }

    // Then all the numbers obtained in the previous step are added
    int control_sum = 0;
    for (int i = 0; i < numbers_amount; i++) {
        control_sum += sequence_array[i];
    }

    // If the resulting sum is a multiple of 10, then the sequence is correct
    if (control_sum % 10 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    long long sequence;
    cin >> sequence;
    if (luhn_algorithm(sequence) == true) {
        cout << "Sequence " << sequence << " is correct";
    }
    else {
        cout << "Sequence " << sequence << " is incorrect";
    }
}
