#ifndef TUPLE_H
# define TUPLE_H

# include <stdbool.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

// Creation and destruction
t_tuple	*tuple_create(double x, double y, double z, double w);
void	tuple_destroy(t_tuple *t);	
void	tuple_set(t_tuple *tuple, double x, double y, double z, double w);

// Tests
bool	tuple_eq(t_tuple *t1, t_tuple *t2);

// Operations
void	tuple_add(t_tuple *result, t_tuple *t1, t_tuple *t2);
void	tuple_subtract(t_tuple *result, t_tuple *t1, t_tuple *t2);
void	tuple_mult(t_tuple *result, t_tuple *t, double scale);
void	tuple_div(t_tuple *result, t_tuple *t, double scale);

// Vector
void	vector_set(t_tuple *t, double x, double y, double z);
t_tuple	*vector_create(double x, double y, double z);
bool	is_vector(t_tuple *t);
double	vector_magnitude(t_tuple *v);
void	vector_normalize(t_tuple *result, t_tuple *v);
double	vector_dot(t_tuple *v1, t_tuple *v2);
void	vector_cross(t_tuple *result, t_tuple *v1, t_tuple *v2);

// Point
void	point_set(t_tuple *t, double x, double y, double z);
t_tuple	*point_create(double x, double y, double z);
bool	is_point(t_tuple *t);

#endif