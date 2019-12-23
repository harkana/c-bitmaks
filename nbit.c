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

int	power(int n, int f)
{
  if (f > 0)
    {
      return (n * power(n, f - 1));
    }
  return (1);
}

int	bitmask_to_nb(char *str, int length)
{
  int	n;
  int	i;

  n = i = 0;
  while (str[i])
    {
      n += ((str[i] - 48) * power(2, length - i - 1));
      i++;
    }
  return (n);
}

int	main(void)
{
  int	a;
  char	*str;
  int	nb;

  a = 53;
  if ((str = nb_to_bitmask(a, 8)) == NULL)
    {
      return (EXIT_FAILURE);
    }
  printf("%s\n", str);
  nb = bitmask_to_nb(str, 8);
  printf("nb: %d\n", nb);
  printf("2 puissance 4 : %d\n", power(2, 4));
  return (EXIT_SUCCESS);
}
