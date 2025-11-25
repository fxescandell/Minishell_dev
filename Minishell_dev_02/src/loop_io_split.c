#include "loop_io.h"
#include "minishell.h"


static int  is_unquoted_semicolon(const char *s, int pos)
{
    int i;
    int in_single;
    int in_double;
    
    i = 0;
    in_single = 0;
    in_double = 0;
    while (i < pos)
    {
        if (s[i] == '\'' && !in_double)
            in_single = !in_single;
        else if (s[i] == '"' && !in_single)
            in_double = !in_single;
        else if (s[i] == '\\' && s[i + 1] != '\0')
            i++;
        i++;
    }
    return (s[pos] == ';' && !in_single && !in_double);
}

static int  count_semicolons(const char *line)
{
    int     count;
    int     i;

    count = 1;
    i = 0;
    while (line[i])
    {
        if (is_unquoted_semicolon(line, i))
            count++;
        i++;
    }
    return (count);
}

static void fill_segments(char **result, const char *line)
{
    int i;
    int start;
    int j;

    i = 0;
    start = 0;
    j = 0;
    while(line[i])
    {
        if(is_unquoted_semicolon(line, i))
        {
            result[j++] = ft_substr(line, start, i - start);
            start = i + 1;
        }
        i++;
    }
    result[j++] = ft_substr(line, start, i - start);
    result[j] = NULL;
}

char    **split_by_semmicolon(const char *line)
{
    char    **result;
    int     count;

    count = count_semicolons(line);
    result = (char **)safe_malloc(sizeof(char *) * (count + 1));
    fill_segments(result, line);
    return(result);
}
