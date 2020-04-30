int is_upper_save_space(char c){
    if(c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}


#define is_upper_save_time(c) ((c) >= 'A' && (c) <= 'Z')? 1: 0
