
    ———————————————————————————————————————————————————————————————------------------------------                  
    GET_NEXT_LINE.C          :->                                                                 
    ———————————————————————————————————————————————————————————————------------------------------             
    1 : The function *get_ln : prototype is :  char *get_ln(char *backup);
    2 : The function *get_sv_and_fr : prototype is :  char *get_sv_and_fr(char *backup);
    3 : The function *read_ln : prototype is :  char *read_ln(char *backup, int fd);
    4 : The function *get_next_line : prototype is : char    *get_next_line(int fd);   
    ———————————————————————————————————————————————————————————————------------------------------        
    GET_NEXT_LINE_UTILS.C   :->                                                                  
    ———————————————————————————————————————————————————————————————------------------------------
    1 : The function *get_ln : prototype is :  char *get_ln(char *backup);
    2 : The function *get_sv_and_fr : prototype is :  char *get_sv_and_fr(char *backup);
    3: The function ft_index : prototype is : char	*ft_strchr(char *s, int c);              
    4 : The function ft_strlen : prototype is : int    ft_strlen(const char *s);                    
    5 : The function *ft_strjoin_l : prototype is : char    *ft_strjoin_l(char *s1, char  *s2); 
    ——————————————————————————————————————————————————————————-----------------------------------             
    GET_NEXT_LINE_BONUS.C    :->                                                                  
    ——————————————————————————————————————————————————————————-----------------------------------                 
    1 - 2 - 3 : The same as GET_NEXT_LINE.C JUST LITTLE CHANGE IN THE FUNCTION *get_next_line.c    
    4 : The function *get_next_line : prototype is : char    *get_next_line(int fd) and this time   
    The variable char : (*backup[10240]) is now get multiple line at the same time with the 
    max_open ;               
    ———————————————————————————————————————————————————————————----------------------------------                 
    GET_NEXT_LINE_UTILS_BONUS.C   :->                                                              
    ———————————————————————————————————————————————————————————----------------------------------              
    1 - 2 - 3 -4 : The same as GET_NEXT_LINE_UTILS.C ….                                            
    ———————————————————————————————————————————————————————————----------------------------------               
