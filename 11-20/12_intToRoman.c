static const char roma_hundreds[] = { 'C', 'D', 'M' };
static const char roma_tens[] = { 'X', 'L', 'C' };
static const char roma_single[] = { 'I', 'V', 'X' };

void add_roma_symbol(char *p, int *index, char symbol, int times)
{
    int i;
    
    for (i = 0; i < times; i++) {
        p[*index] = symbol;
        (*index)++;
    }
}

void parse_digit_thousands(char *p, int *index, int digit)
{
    add_roma_symbol(p, index, 'M', digit);
}

void parse_digit(char *p, int *index, int digit, char *roma)
{
    if (0 == digit) {
        return;
    }

    if (digit < 4) {
        add_roma_symbol(p, index, roma[0], digit);
    }
    else if (4 == digit) {
        add_roma_symbol(p, index, roma[0], 1);
        add_roma_symbol(p, index, roma[1], 1);
    }
    else if (5 == digit) {
        add_roma_symbol(p, index, roma[1], 1);
    }
    else if (9 == digit) {
        add_roma_symbol(p, index, roma[0], 1);
        add_roma_symbol(p, index, roma[2], 1);
    }
    else {
        add_roma_symbol(p, index, roma[1], 1);
        add_roma_symbol(p, index, roma[0], digit-5);
    }
}

char * intToRoman(int num){
    int data[4] = {0};
    int i;
    int temp = num;
    int index = 0;
    char *p;

    if (num < 1 || num > 3999) {
        return NULL;
    }

    for (i = 0; i < 4; i++) {
        data[3-i] = temp % 10;
        temp      = temp / 10;
    }

    p = malloc(30);
    if (NULL == p) {
        return NULL;
    }

    // thousands digit
    parse_digit_thousands(p, &index, data[0]);

    // hundreds digit
    parse_digit(p, &index, data[1], roma_hundreds);

    // tens digit
    parse_digit(p, &index, data[2], roma_tens);

    // single digit
    parse_digit(p, &index, data[3], roma_single);

    p[index] = '\0';

    return p;
}