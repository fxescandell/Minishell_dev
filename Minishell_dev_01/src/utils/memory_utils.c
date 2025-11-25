#include "minishell.h"

void  *safe_malloc(size_t size)
{
   void	*ptr;

   ptr = malloc(size);
   if (!ptr)
   {
      ft_putstr_fd("MSX: malloc: allocation failed\n", 2);
      exit(EXIT_FAILURE);
   }
   return (ptr);
}

void  free_string_array(char **array)
{
   int   i;

   if (!array)
      return ;
   i = 0;
   while(array[i])
   {
      printf("Liberando: %s\n", array[i]);
      free(array[i]);
      i++;
   }
   free(array);
}

