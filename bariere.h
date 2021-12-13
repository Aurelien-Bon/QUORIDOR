#ifndef BARIERE_H_INCLUDED
#define BARIERE_H_INCLUDED
typedef struct bariere
{
	int cord_x1;
	int cord_y1;
	int cord_x2;
	int cord_y2;
	int id;
	char sens;//h,b,g,d
	int active;
}t_bariere;
struct bariere creeBariere(void);
void afficherBariereText(struct bariere b);
void Color(int couleurDuTexte,int couleurDeFond);

#endif // BARIERE_H_INCLUDED
