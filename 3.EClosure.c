#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100

int epsilon_moves[MAX_STATES][MAX_STATES];
int closure[MAX_STATES][MAX_STATES];
int visited[MAX_STATES];

int num_states, num_epsilon_moves;

void dfs(int state, int closure_state) {
    visited[state] = 1;
    closure[closure_state][state] = 1;

    for (int next = 0; next < num_states; next++) {
        if (epsilon_moves[state][next] && !visited[next]) {
            dfs(next, closure_state);
        }
    }
}

void find_epsilon_closures() {
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            visited[j] = 0;
        }
        dfs(i, i);
    }
}

void print_epsilon_closures() {
    printf("Epsilon-closures for each state:\n");
    for (int i = 0; i < num_states; i++) {
        printf("Epsilon-closure(%d): { ", i);
        for (int j = 0; j < num_states; j++) {
            if (closure[i][j]) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }
}

int main() {
    int from, to;

    printf("Enter the number of states in the NFA: ");
    scanf("%d", &num_states);
    printf("Enter the number of epsilon moves: ");
    scanf("%d", &num_epsilon_moves);

    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            epsilon_moves[i][j] = 0;
            closure[i][j] = 0;
        }
    }

    printf("Enter epsilon moves (from_state to_state):\n");
    for (int i = 0; i < num_epsilon_moves; i++) {
        scanf("%d %d", &from, &to);
        epsilon_moves[from][to] = 1;
    }

    find_epsilon_closures();
    print_epsilon_closures();

    return 0;
}
