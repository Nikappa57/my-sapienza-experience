#ifndef ES12_H
# define ES12_H

#include "albero_binario.h"
#include "lista.h"

void			rimuovi_minimo(TipoAlbero *a);
void			duplica_foglie(TipoAlbero *a);
void			rimuovi_foglie_profonde(TipoAlbero *a, int n);
void			scambia_sottoalberi_simili(TipoAlbero *a);
void			limita_livello(TipoAlbero *a, int livello);
void			rimuovi_max_livello(TipoAlbero *a, int livello);
void			comprimi_sottoalberi(TipoAlbero *a);
void			sx_pari_dx_dispari(TipoAlbero *a);
TipoAlbero		albero_percorso_lungo(TipoAlbero *a);
void			scambia_uguali_livello(TipoAlbero *a, int livello);
TipoAlbero 		albero_ricerca(TipoLista l);
void			binric_rimuovi(TipoAlbero *a, int v);

int				min(int a, int b);
int				max(int a, int b);
TipoInfoAlbero	val_min(TipoAlbero a);
void			elimina_albero(TipoAlbero *a);
bool 			estFoglia(TipoAlbero a);
int				numero_nodi(TipoAlbero a);
TipoLista		init_r(T *vec, int len);
TipoAlbero		estSingolo(TipoAlbero a);
#endif