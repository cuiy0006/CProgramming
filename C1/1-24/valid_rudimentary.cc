#include <stdio.h>

int main(){
    char c = '\0';
    char last = '\0';
    bool single_comment = false;
    bool multi_comment = false;
    bool double_quote = false;
    bool single_quote = false;
    // bool escape = false;
    int parenthese = 0;
    int bracket = 0;
    int brace = 0;

    while((c = getchar()) != EOF){
        if(single_comment){
            if(c == '\n'){
                single_comment = false;
            }
            last = c;
            continue;
        }

        if(multi_comment){
            if(last == '*' && c == '/'){
                multi_comment = false;
            }
            last = c;
            continue;
        }

        if(double_quote){
            if(c == '"' && last != '\\'){
                double_quote = false;
            }
            last = c;
            continue;
        }

        if(single_quote){
            if(c == '\'' && last != '\\'){
                single_quote = false;
            }
            last = c;
            continue;
        }

        if(c == '"'){
            double_quote = true;
        } else if(c == '\''){
            single_quote = true;
        } else if(c == '/' && last == '/'){
            single_comment = true;
        } else if(c == '*' && last == '/'){
            multi_comment = true;
        } else {
            if(c == '('){
                ++parenthese;
            } else if(c == ')'){
                --parenthese;
            } else if(c == '['){
                ++bracket;
            } else if(c == ']'){
                --bracket;
            } else if(c == '{'){
                ++brace;
            } else if(c == '}'){
                --brace;
            }
            if(parenthese < 0 || bracket < 0 || brace < 0){
                return false;
            }
        }
        last = c;
    }

    bool is_valid = !(multi_comment || single_quote || double_quote || parenthese != 0 || brace != 0 || bracket != 0);
    if(is_valid){
        printf("Valid!\n");
    } else {
        printf("Invalid!\n");
    }
}