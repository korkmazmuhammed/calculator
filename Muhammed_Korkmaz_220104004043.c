#include <stdio.h>

// Function to check if the user wants to return to the main menu
int menu_checker() {
    char c;
    scanf("%c", &c);

    if (c == 'r' || c == 'R') {
        return 1;
    }

    return 0;
}

// Function to add two numbers
float adding(float a, float b) {
    float result = a + b;
    return result;
}

// Function to subtract two numbers
float subtracting(float a, float b) {
    float result = a - b;
    return result;
}

// Function to multiply two numbers
float multiplying(float a, float b) {
    float result = a * b;
    return result;
}

// Function to divide two numbers
float dividing(float a, float b) {
    float result = a / b;
    return result;
}

// Function to calculate the Nth power of a number
float nthpower(float a, float b) {
    float temp = 0;
    float total_value = 1;
    temp = b;
    if (b < 0) {
        b = b * -1;
    }

    for (int i = 0; i < b; i++) {
        total_value = total_value * a;
    }
    b = temp;
    if (b > 0) {
        return total_value;
    } else {
        return (1 / total_value);
    }
}

// Function to calculate the average of numbers entered by the user
float average(void) {
    float number = 0.0;
    float counter = 0.0;
    float total = 0.0;
    float sonuc = 0.0;
    int m_checker = 0;
    int s_controller = 0;

    printf("Please press 'r' or 'R' to return to the menu\n");

    for (; m_checker == 0; counter++) {
        s_controller = scanf("%f", &number);

        if (s_controller == 0) {
            m_checker = menu_checker();

            if (m_checker == 0) {
                printf("Please enter a number or press 'r' or 'R' to return to the menu\n");
            }

            counter--;

            continue;
        }

        total += number;
    }

    if (!(counter > 0)) {
        counter++;
    }

    sonuc = total / counter;
    return sonuc;
}

// Function to find the maximum of numbers entered by the user
void maxvalue(void) {
    float number;
    float max = 0;
    int m_checker = 0;
    int s_controller = 0;

    printf("Please press 'r' or 'R' to see the result and return to the menu\n");
    scanf("%f", &number);
    max = number;

    while (m_checker == 0) {
        s_controller = scanf("%f", &number);
        if (s_controller == 0) {
            m_checker = menu_checker();

            if (m_checker == 0) {
                printf("Please press 'r' or 'R' to see the result and return to the menu\n");
            }

            continue;
        }
        if (max < number) {
            max = number;
        }
    }
    printf("%.2f\n", max);
}

// Function to display the menu and perform operations based on user input
void operand() {
    printf("%%%% WELCOME TO GTU CALCULATOR MACHINE %%%%\n");
    printf("%%%% STUDENT NAME: MUHAMMED KORKMAZ    %%%%\n");
    printf("%%%% PLEASE SELECT FROM THE FOLLOWING  %%%%\n");
    printf("%%%% MENU :                            %%%%\n");
    printf("(1) ADD TWO NUMBERS\n(2) SUBTRACT TWO NUMBERS\n(3) MULTIPLY TWO NUMBERS\n");
    printf("(4) DIVIDE TWO NUMBERS\n(5) TAKE THE NTH POWER OF A NUMBER\n(6) FIND AVERAGE OF NUMBERS ENTERED\n");
    printf("(7) FIND THE MAXIMUM OF NUMBERS ENTERED\n(0) EXIT\n");
    printf("PLEASE SELECT:\n");

    int operation = -1;
    float result;
    float number1;
    float number2;

    if (scanf("%d", &operation) != 1) {
        char c;
        scanf("%c", &c);
        operation = -1;
    }

    if (operation == 0) {
        printf("You are leaving!\n");
        return;
    } else if (operation == 1) {
        printf("Please enter 2 numbers\n");
        scanf("%f\n%f", &number1, &number2);
        result = adding(number1, number2);
        printf("%.2f\n", result);
    } else if (operation == 2) {
        printf("Please enter 2 numbers\n");
        scanf("%f\n%f", &number1, &number2);
        result = subtracting(number1, number2);
        printf("%.2f\n", result);
    } else if (operation == 3) {
        printf("Please enter 2 numbers\n");
        scanf("%f\n%f", &number1, &number2);
        result = multiplying(number1, number2);
        printf("%.2f\n", result);
    } else if (operation == 4) {
        printf("Please enter 2 numbers\n");
        scanf("%f\n%f", &number1, &number2);
        result = dividing(number1, number2);
        printf("%.2f\n", result);
    } else if (operation == 5) {
        printf("Please enter 2 numbers\n");
        scanf("%f\n%f", &number1, &number2);
        result = nthpower(number1, number2);
        printf("%f\n", result);
    } else if (operation == 6) {
        printf("Please enter numbers\n");
        result = average();
        printf("%f\n", result);
    } else if (operation == 7) {
        printf("Please enter numbers\n");
        maxvalue();
    } else {
        printf("Please select an operation from the menu!\n");
    }

    // Recursively call the operand function to continue the program
    operand();
}

// The main function that starts the program
int main() {
    // Call the operand function to display the menu and perform operations
    operand();

    return 0;
}
