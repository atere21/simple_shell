#include shell.h

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;

if (buf[j] == '|' && buf[j + 1] == '|')
{
= 0;
fo->cmd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
= 0;
fo->cmd_buf_type = CMD_AND;
}
else if (buf[j] == ';') /* found end of this command */
{
= 0; /* replace semicolon with null */
fo->cmd_buf_type = CMD_CHAIN;
}
else
 (0);
*p = j;
return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;

if (info->cmd_buf_type == CMD_AND)
{
(info->status)
= 0;
= len;
(info->cmd_buf_type == CMD_OR)
{
= 0;
= len;
= j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
ode = node_starts_with(info->alias, info->argv[0], '=');
 (0);
fo->argv[0]);
= _strchr(node->str, '=');
 (0);
= _strdup(p + 1);
 (0);
fo->argv[0] = p;
}
return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
int i = 0;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
tinue;

g(&(info->argv[i]),
vert_number(info->status, 10, 0)));
tinue;
g(&(info->argv[i]),
vert_number(getpid(), 10, 0)));
tinue;
ode = node_starts_with(info->env, &info->argv[i][1], '=');
(node)
g(&(info->argv[i]),
ode->str, '=') + 1));
tinue;
g(&info->argv[i], _strdup());

}
return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
