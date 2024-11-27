-- 1

select codice, nome
from giocattolo join richiesta on codice=codiceg
where categoria != 5 and preferenza <= 4

-- 2

select distinct r1.codiceg
from richiesta r1 join richiesta r2 
	on r1.codiceb=r2.codiceb and r1.codiceg=r2.codiceg
where r1.preferenza != r2.preferenza

-- 3

select codice, categoria, avg(preferenza)
from richiesta join giocattolo on codiceg=codice
group by codice, categoria

-- 4

select b.codice, p, 
	(select count(codiceg)
		from richiesta r
			join giocattolo g on codiceg=g.codice
		where codiceb=b.codice
			and categoria > 3
			and preferenza=p)
from bambino b,
	(select distinct preferenza p from richiesta)


-- 5

select c, 
	(select avg(preferenza) from richiesta where codiceb=c)
from (select codice c
		from bambino
		except
		select codiceb c from richiesta join giocattolo on codiceg=codice
			where categoria = 1)

