char* minRemoveToMakeValid(char* s) {
    int len = strlen(s);

    char* stk = (char*)malloc((len + 1) * sizeof(char));
    if (stk == NULL) return NULL;

    int top = -1;
    int count_forward = 0, count_backward = 0;

    for(int i = 0; i < len; i++)
    {
        if(isalpha(s[i]))
        {
            stk[++top] = s[i];
        }
        if(s[i] == '(')
        {
            stk[++top] = s[i];
            count_forward++;
        }
        if(s[i] == ')')
        {
            if(count_backward < count_forward)
            {
                stk[++top] = s[i];
                count_backward++;
            }
        }
    }

    stk[++top] = '\0';


    return stk;
}
