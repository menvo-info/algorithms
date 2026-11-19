bool isValid(char* s) {
    char temp[10000];    
    int k = 0;            
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            temp[k] = s[i];
            k++;
        } else {
            char need;
            if (s[i] == ')') need = '(';
            else if (s[i] == ']') need = '[';
            else need = '{';

            if (k == 0 || temp[k-1] != need) return false;

            k--;
        }
    }

    if (k != 0) return false;
    return true;
}