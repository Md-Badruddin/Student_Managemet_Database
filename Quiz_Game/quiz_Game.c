
#include <stdio.h>

#define MAX_QUESTIONS 5

typedef struct {
    const char *question;
    const char *optionA;
    const char *optionB;
    const char *optionC;
    const char *optionD;
    char correct;  // 'A', 'B', 'C', or 'D'
} Question;

int main() {
    Question quiz[MAX_QUESTIONS] = {
        {
            "Which language is mainly used for system programming?",
            "A) Python",
            "B) C",
            "C) HTML",
            "D) JavaScript",
            'B'
        },
        {
            "What does CPU stand for?",
            "A) Central Processing Unit",
            "B) Computer Personal Unit",
            "C) Central Print Unit",
            "D) Control Process Unit",
            'A'
        },
        {
            "Which of these is a loop in C?",
            "A) repeat-until",
            "B) foreach",
            "C) for",
            "D) loop",
            'C'
        },
        {
            "Which symbol is used for single-line comments in C?",
            "A) //",
            "B) #",
            "C) <!-- -->",
            "D) ;;",
            'A'
        },
        {
            "Which header is needed for printf?",
            "A) stdbool.h",
            "B) stdio.h",
            "C) stdlib.h",
            "D) string.h",
            'B'
        }
    };

    int score = 0;
    char answer;

    printf("=== C Quiz Game ===\n\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Q%d: %s\n", i + 1, quiz[i].question);
        printf("%s\n", quiz[i].optionA);
        printf("%s\n", quiz[i].optionB);
        printf("%s\n", quiz[i].optionC);
        printf("%s\n", quiz[i].optionD);
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);

        if (answer >= 'a' && answer <= 'z') {
            answer = answer - 'a' + 'A';  // make uppercase
        }

        if (answer == quiz[i].correct) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! Correct answer: %c\n\n", quiz[i].correct);
        }
    }

    printf("You scored %d out of %d.\n", score, MAX_QUESTIONS);

    if (score == MAX_QUESTIONS) {
        printf("Excellent! Perfect score!\n");
    } else if (score >= 3) {
        printf("Good job! Keep practicing.\n");
    } else {
        printf("Keep learning and try again!\n");
    }

    return 0;
}
