//NFA
#include <stdio.h>
#include <string.h>

int simulate_nfa(char *input) {
    int state = 0; // Start at q0

    for (int i = 0; i < strlen(input); i++) {
        if (state == 0 && input[i] == 'a') state = 1; // q0 -> q1 on 'a'
        else if (state == 1 && input[i] == 'b') state = 2; // q1 -> q2 on 'b'
        else if (state == 2) return 1; // q2 is accepting state
    }

    return state == 2; // Check if in accepting state
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulate_nfa(input))
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
