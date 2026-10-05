int scoreOfParentheses(char* s) {
   char stk[30];
   int top = -1,score_count_sum = 0;
   for(int i=0;i<strlen(s);i++)
   {
    if(s[i] == '(')
    {
        stk[++top] = s[i];
    }
    int count = 0,score = 0;
   while(s[i] == ')' && top != -1)
   {
    top--;
    count += 1;
    if(count == 1)
    {
        score = 1;
    }
    else
    {
        score = 2*score;
    }
   }
   score_count_sum += score;
   count =0;
   score = 0;
   }
   return score_count_sum;
}
