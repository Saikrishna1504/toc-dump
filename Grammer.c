//GRAMMAR
#include <stdio.h>
#include <string.h>

// Function to check if a string contains only '0' and '1'
int checkGrammar(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0; // Invalid character found
        }
    }
    return 1; // String belongs to the grammar
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // String is a palindrome
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (checkGrammar(str)) {
        printf("The string belongs to the grammar.\n");
        if (isPalindrome(str)) {
            printf("The string is a palindrome.\n");
        } else {
            printf("The string is not a palindrome.\n");
        }
    } else {
        printf("The string does not belong to the grammar.\n");
    }

    return 0;
}
