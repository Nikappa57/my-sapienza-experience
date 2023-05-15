#ifndef ES11_H
# define ES11_H

#include "albero_binario.h"
#include "lista.h"

bool	estFoglia(TipoAlbero a);
int		listLen(TipoLista l);

TipoInfoAlbero	trova_massimo(TipoAlbero a);
TipoInfoAlbero	somma_foglie(TipoAlbero a);
int				cerca_livello(TipoAlbero a, TipoInfoAlbero v);
int				conta_dispari(TipoAlbero a);
int				somma_singoli(TipoAlbero a);
TipoLista		albero_lista(TipoAlbero a);
TipoLista 		percorso_lungo(TipoAlbero a);
void			somma_sottoalbero(TipoAlbero a);
void			scambia_foglie(TipoAlbero a);
void 			max_figli_livello(TipoAlbero a, int livello);
void			scambia_foglie_livello(TipoAlbero a, int livello);
void			set_albbinric(TipoAlbero a, TipoLista l);

#endif