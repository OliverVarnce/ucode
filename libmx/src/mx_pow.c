double mx_pow(double n, unsigned int pow) {
    
    double num = 1;
    if (pow == 0) {
        if (n != 0)
            return 1;
        else
            return 0;
    }
    else {
        for (unsigned int i = 0; i < pow; ++i)
            num *=n;
        return (num);
    }
}
