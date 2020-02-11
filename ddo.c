 int put_nbr(level)
 {
   if(level == 4)
      if(table[3] == 1)
      {
        printf("Success!");
        return -3; //success 
      }
        else 
          return 0;
   
 else // recursive
 {
     i = 0;
     while (i < 4)
     {
         if (check[i] == 0)
     {
             table[i] = i+1;
             check[i] = 1;
             if(put_nbr(level + 1) == -3)
                return -3;
             g_check[i] = 0;
         }
       i++;
     }
     return (0); /
 }
