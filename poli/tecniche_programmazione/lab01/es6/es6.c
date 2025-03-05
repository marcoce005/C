#include <stdio.h>
#include <math.h>

float calculate(char oper, float n1, float n2)
{
    float ans;

    switch (oper)
    {
    case '+':
        ans = n1 + n2;
        break;

    case '-':
        ans = n1 - n2;
        break;

    case '*':
        ans = n1 * n2;
        break;

    case '/':
        ans = n1 / n2;
        break;

    default:
        printf("\nWrong operation.");
        return NAN;
        break;
    }
    return ans;
}

int main(void)
{
    FILE *operation, *output;

    operation = fopen("./operation.txt", "r");
    output = fopen("./output.txt", "w");

    char oper, str[50];
    float val1, val2, ans;

    while (!feof(operation))
    {
        fgets(str, 50, operation);
        sscanf(str, "%c %f %f", &oper, &val1, &val2);

        ans = calculate(oper, val1, val2);

        if (isnan(ans))
        {
            fclose(output);
            fclose(operation);
            return -1;
        }

        fprintf(output, "%c %.2f\n", oper, calculate(oper, val1, val2));
    }

    fclose(output);
    fclose(operation);

    return 0;
}