#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*nb_to_bitmask(int n, int length)
{
  char	*str;
  int	i;

  i = 0;
  str = malloc(sizeof(*str) * (length + 1));
  if (str == NULL)
    {
      perror("malloc:");
      return (NULL);
    }
  while (i < length)
    {
      str[length - i - 1] = ((n & (1 << i)) >> i) + 48;
      i++;
    }
  str[length] = 0;
  return (str);
}

int	main(void)
{
  int	a;
  char	*str;

  a = 1;
  if ((str = nb_to_bitmask(a, 8)) == NULL)
    {
      return (EXIT_FAILURE);
    }
  printf("%s\n", str);      
  return (EXIT_SUCCESS);
}
