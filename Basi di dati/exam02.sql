--- 1

select distinct g.codice, cittanascita
from giornalista g
	join firma f on f.codice=g.codice
where anno >= 2000;

--- 2

select distinct f1.nome
from firma f1 join firma f2 
	on f1.nome=f2.nome 
		and f1.codice=f2.codice
		and f1.anno=f2.anno
where f1.mese + 1 = f2.mese;

--- 3

select g.codice, sum(articoli)
from giornalista g
	join firma f on f.codice=g.codice
	join testata t on (t.nome=f.nome and g.cittanascita = t.citta)

--- 4

select nome from testata
except
select f.nome
	from firma f join giornalista g on f.codice = g.codice
		where g.orientamento != 'sinistra'

--- 5

with vista as (select t.nome, f.codice, f.anno, sum(articoli) a
	from testata t join firma f on t.nome=f.nome
	where f.codice=t.direttore
	group by t.nome, f.codice, f.anno)
select v1.nome, v1.anno
from vista v1
where v1.a = (select max(a) from vista v2 where v2.nome=v1.nome);


