#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;
  char  *str3;

  i = 0;
  j = 0;
  str3 = malloc(sizeof(str3) * (strlen(dest) + strlen(src) + 1));
  while (dest[i] != '\0')
    {
      str3[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    str3[i++] = src[j++];
  str3[i] = '\0';
  return (str3);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;
  int   j;
  char  k;

  i = 0;
  j = 0;
  while (s1[i] != 0 && s2[j] != 0)
    {
      if (s1[i] == s2[j])
        {
          i = i + 1;
          j = j + 1;
        }
      if (s1[i] != s2[j])
	{
	  k = s1[i] - s2[j];
	  return (k);
	}
    }
  return (0);
}

char	man(int a)
{
  if (a == 1)
    printf("Usage [-c] : blih repository create [nom du dépot]\n");
  else if (a == 2)
    printf("Usage [-d] : blih repository delete [nom du dépot]\n");
  else if (a == 3)
    printf("Usage [-s] : blih repository setacl [nom du dépot] [utilisateur] [acl]\n");
  else if (a == 4)
    printf("Usage [-g] : blih repository getacl [nom du dépot]\n");
  else if (a == 5)
    {
      printf("Usage [-m] : Option master :\n");
      printf("[nom du dépot] [utilisateur pour acl] [acl]\n");
      printf("/!\\ Attention, changer votre login ligne 158\n");
    }
  else if (a == 6)
    printf("Usage [-u] : git clone [votre login]@git.epitech.eu:/[login du clone]/[nom du dépot]\n");
  else if (a == 7)
    printf("Usage [-l] : blih repository list\n");
  else
    {
      printf("\n\t\t\e[31m\e[4m\e[40mMan pour Blih_Master®\e[39m\e[24m\e[49m\n\n");
      printf("\nUsage : /home/login/blih_master [options] commande ...\n\n");
      printf("Options globales :\n");
      printf("\t-c : blih repository create [nom du dépot]\n");
      printf("\t-d : blih repository delete [nom du dépot]\n");
      printf("\t-s : blih repository setacl [nom du dépot] [utilisateur] [acl]\n");
      printf("\t-g : blih repository getacl [nom du dépot]\n");
      printf("\t-l : blih repository list\n");
      printf("\t-u : git clone [votre login]@git.epitech.eu:/[login du clone/[nom du dépot]\n");
      printf("\t-m : Option master :\n");
      printf("\t[nom du dépot] [utilisateur pour acl] [acl]\n");
      printf("\t/!\\ Attention, changer votre login ligne 158\n");
    }
  exit(0);
}

char	flags(char **argv, int ac)
{
  char	*buff;

  if ((my_strcmp("-c", argv[1])) == 0)
    {
      if (ac != 3)
	man(1);
      buff = malloc(98765);
      buff = my_strcat("python3 ~/./.blih.py repository create ", argv[2]);  //Changer chemin d'accès si besoin
      system(buff);
      free(buff);
      exit(0);
    }
  else if (my_strcmp("-d", argv[1]) == 0)
    {
      if (ac != 3)
	man(2);
      buff = malloc(98765);
      buff = my_strcat("python3 ~/./.blih.py repository delete ", argv[2]);  //Changer chemin d'accès si besoin
      system(buff);
      free(buff);
      exit(0);
    }
  else if (my_strcmp("-s", argv[1]) == 0)
    {
      if (ac != 5)
	man(3);
      buff = malloc(98765);
      buff = my_strcat("python3 ~/./.blih.py repository setacl ", argv[2]);  //Changer chemin d'accès si besoin
      buff = my_strcat(buff, " ");
      buff = my_strcat(buff, argv[3]);
      buff = my_strcat(buff, " ");
      buff = my_strcat(buff, argv[4]);
      system(buff);
      free(buff);
      exit(0);
    }
  else if (my_strcmp("-g", argv[1]) == 0)
    {
      if (ac != 3)
	man(4);
      buff = malloc(98765);
      buff = my_strcat("python3 ~/./.blih.py repository getacl ", argv[2]);  //Changer chemin d'accès si besoin
      system(buff);
      free(buff);
      exit(0);
    }
  else if (my_strcmp("-m", argv[1]) == 0)
    {
      if (ac != 5)
	man(5);
      buff = malloc(98765);
      buff = my_strcat("python3 ~/./.blih.py repository create ", argv[2]);  //Changer chemin d'accès si besoin
      system(buff);
      buff = my_strcat("python3 ~/./.blih.py repository setacl ", argv[2]);  //Changer chemin d'accès si besoin
      buff = my_strcat(buff, " ");
      buff = my_strcat(buff, argv[3]);
      buff = my_strcat(buff, " ");
      buff = my_strcat(buff, argv[4]);
      system(buff);
      buff = my_strcat("git clone login@git.epitech.eu:/login/", argv[2]);  //Changer votre login
      system(buff);
      free(buff);
      exit(0);
    }
  else if (my_strcmp("-u", argv[1]) == 0)
    {
      if (ac != 5)
	man(6);
      buff = malloc(98765);
      buff = my_strcat("git clone ", argv[2]);
      buff = my_strcat(buff, "@git.epitech.eu:/");
      buff = my_strcat(buff, argv[3]);
      buff = my_strcat(buff, "/");
      buff = my_strcat(buff, argv[4]);
      system(buff);
      free(buff);
      exit(0);
    }
  else if (my_strcmp("-l", argv[1]) == 0)
    {
      if (ac != 2)
	man(7);
      buff = malloc(98765);
      buff = "python3 ~/./.blih.py repository list";  //Changer chemin d'accès si besoin
      system(buff);
      exit(0);
    }
  else if (my_strcmp("-h", argv[1]) == 0)
    man(0);
  else
    man(0);
}

int	main(int ac, char **argv)
{
  char	*buff;

  if (ac == 1)
    {
      man(0);
      exit(0);
    }
  flags(argv, ac);
}
