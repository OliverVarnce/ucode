unsigned long mx_hex_to_nbr(const char *hex) {
    int i = 0;
    long res = 0;
    long k;
    long pow;
    int len = 0;

    while(hex[len])
        len++;
    len--;

    while(hex[i])
    {
        pow = 1;

        if (hex[i] > 47 && hex[i] < 58)
            k = hex[i] - 48;   
        else if (hex[i] > 96 && hex[i] < 123) 
            k = hex[i] - 97 + 10;
        else if (hex[i] > 64 && hex[i] < 91)
            k = hex[i] - 65 + 10;
        
        for(int i = 1; i <= len; i++)
            pow *= 16;

        res += k * pow;

        len--;
        i++;
    }

    return res;
}
