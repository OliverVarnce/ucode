int mx_sqrt(int x) {
    for(int i = 0; i <= x / 2; i++) {    
        if(i * i == x )    {
            x = i;
            return  x;
        }
         
    }            
    x = 0;
    return x;
}
