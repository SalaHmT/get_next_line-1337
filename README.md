# get_next_line-42-
get_next_line 42 project..


—————————————————————————————————————————————————————————————————————————————————————————————
GET_NEXT_LINE.C          :->
—————————————————————————————————————————————————————————————————————————————————————————————
1 : The function *get_line : prototype is : static char *get_line(char *backup);
2 : The function *get_backup : prototype is : static char *get_backup(char *backup);
3 : The function *read_line : prototype is : static char *read_line(char *backup, int fd);
4 : The function *get_next_line : prototype is : char    *get_next_line(int fd);
—————————————————————————————————————————————————————————————————————————————————————————————
GET_NEXT_LINE_UTILS.C   :->
—————————————————————————————————————————————————————————————————————————————————————————————
1 : The function ft_index : prototype is : int ft_index(const char *s, char c);
2 : The function ft_strlen : prototype is : unsigned int    ft_strlen(const char *str);
3 : The function *ft_strdup : prototype is : char    *ft_strdup(const char *s1);
4 : The function *ft_strjoin : prototype is : char    *ft_strjoin(char *s1, char const *s2);
—————————————————————————————————————————————————————————————————————————————————————————————
GET_NEXT_LINE_BONUS.C    :->
—————————————————————————————————————————————————————————————————————————————————————————————
1 - 2 - 3 : The same as GET_NEXT_LINE.C JUST LITTLE CHANGE IN THE FUNCTION *get_next_line.c
4 : The function *get_next_line : prototype is : char    *get_next_line(int fd) and this time 
The variable char : (*backup[10240]) is now get multiple line at the same time ;
 —————————————————————————————————————————————————————————————————————————————————————————————
GET_NEXT_LINE_UTILS_BONUS.C   :->
——————————————————————————————————————————————————————————————————————————————————————————————
1 - 2 - 3 -4 : The same as GET_NEXT_LINE_UTILS.C ….
——————————————————————————————————————————————————————————————————————————————————————————————
