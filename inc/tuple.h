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

// Tests
bool	tuple_eq(t_tuple *t1, t_tuple *t2);

// Operations
t_tuple	*tuple_add(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_subtract(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_mult(t_tuple *t, double scale);
t_tuple	*tuple_div(t_tuple *t, double scale);

// Vector
t_tuple	*vector_create(double x, double y, double z);
bool	is_vector(t_tuple *t);
double	vector_magnitude(t_tuple *v);
t_tuple	*vector_normalize(t_tuple *v);
double	vector_dot(t_tuple *v1, t_tuple *v2);
t_tuple	*vector_cross(t_tuple *v1, t_tuple *v2);

// Point
t_tuple	*point_create(double x, double y, double z);
bool	is_point(t_tuple *t);

#endif