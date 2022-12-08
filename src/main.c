#include "../include/include.h"

unsigned int	starter_env(char *s)
{
	unsigned int	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

t_env *get_env(char **env)
{
    int i = 0;
    t_env *list = NULL;
    list = malloc(sizeof(t_env)* 100);
   
   while (env[i])
    {
        list[i].name = ft_strsub(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		printf("starter_env(env[i]) == %d\n", starter_env(env[i]));
		printf("ft_strlen(env[i] == %d\n", ft_strlen(env[i]));
		printf(" ft_strchr(env[i], '=') - env[i]) = %ld\n",   env[i] - ft_strchr(env[i], '='));
        list[i].content =  ft_strsub(env[i], starter_env(env[i]), ft_strlen(env[i] - starter_env(env[i])));
		i++;
    }
    return (list);
}

t_list *lexer(t_list *str)
{
    t_list *list;
    t_list *tmp = malloc(sizeof(t_list) * 100);
    char **tab;
	char *tp = (char *)str->content;
    int i = 0;
    tab = ft_strsplit(tp, ' ');
    while (tab[i])
    {
        list = ft_lstnew(tab[i]);
        list->next = tmp;
        tmp = list;
        i++;
    }
	printf("TAB VA SUIVRE---->\n");
	afftab(tab);
    afflist(list, "Lexer");
    return (list);
}


int main(int ac, char **av, char **env)
{
    t_env *list;
	t_list	*history = NULL;
    t_list *str = NULL;
	history = ft_lstnew(NULL);
    list = get_env(env);
    (void)ac;
    (void)av;
	int	i = 0;

	while (list[i].name)
	{
		printf("Env[i] -- >%s\n", list[i].content);
		i++;
	}
    while (42)
	{
		printf("0\n");
	 	ft_putstr("minishell>");
        str = ft_lstnew(get_next_line(0));
		printf("1\n");
		ft_lstadd(&history, str);
		afflist(history, "History");
		// printf("history->content = %s\n", history->content);
		// *history = (*history)->next;
        //printf("La commande que tu tape = %s\n", str);
		printf("je vois avant lexer\n");
        lexer(str);
	}
    return (0);
}