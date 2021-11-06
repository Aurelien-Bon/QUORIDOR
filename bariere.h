#ifndef BARIERE_H_INCLUDED
#define BARIERE_H_INCLUDED
typedef struct bariere
{
	int cord_x;
	int cord_y;
	int id;
	char sens;//h,b,g,d
	int active;
}t_bariere;
struct bariere creeBariere(void);
void afficherBariere(struct bariere b);

#endif // BARIERE_H_INCLUDED