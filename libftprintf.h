#include <stddef.h>

int		ft_printf(const char *format, ...);

char	*ft_size_t_to_str_base(size_t num, char *radix);
char	*ft_size_t_to_str_hex(size_t num); 

char	*ft_convert_c(char c);
char	*ft_convert_d(int n);
char	*ft_convert_i(int n);
char	*ft_convert_p(void *ptr);
char	*ft_convert_percent(void);
char	*ft_convert_s(char *str);
char	*ft_convert_u(int num);
char	*ft_convert_x(int num);
char	*ft_convert_x_upper(int num);
