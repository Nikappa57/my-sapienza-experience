--- 1

select distinct codice, nome
from bambino join richiesta on codice=codiceb
where citta != 'Milano' and preferenza >= 4


--- 2

select distinct r1.codiceb
from (richiesta r1 join giocattolo g1 on r1.codiceg=g1.codice)
	join (richiesta r2 join giocattolo g2 on r2.codiceg=g2.codice)
	on r2.codiceb=r1.codiceb
where r1.preferenza = r2.preferenza
	and g1.categoria != g2.categoria

--- 3

select distinct codice, citta, (
	select count(*) 
		from richiesta r 
		where r.codiceb=codice 
			and preferenza=1)
from bambino join richiesta on codiceb=codice


--- 4

select cb, cg,
	case when max(preferenza) is null then 0 else max(preferenza) end
from (select b.codice cb, g.codice cg
		from bambino b, giocattolo g)
	left join richiesta on codiceb=cb and codiceg=cg
group by cb, cg

--- 5

select cg, avg(preferenza)
from (
	select distinct codice cg 
		from giocattolo
	except
	select codiceg
		from richiesta join bambino on codiceb=codice
		where citta = 'Firenze') v
	left join richiesta on cg=codiceg
group by cg;
--- 1

select distinct codice, nome
from bambino join richiesta on codice=codiceb
where citta != 'Milano' and preferenza >= 4


--- 2

select distinct r1.codiceb
from (richiesta r1 join giocattolo g1 on r1.codiceg=g1.codice)
	join (richiesta r2 join giocattolo g2 on r2.codiceg=g2.codice)
		on r2.codiceb=r1.codiceb
		where r1.preferenza = r2.preferenza
			and g1.categoria != g2.categoria

			--- 3

select distinct codice, citta, (
		select count(*) 
				from richiesta r 
						where r.codiceb=codice 
									and preferenza=1)
								from bambino join richiesta on codiceb=codice


								--- 4

select cb, cg,
case when max(preferenza) is null then 0 else max(preferenza) end
	from (select b.codice cb, g.codice cg
				from bambino b, giocattolo g)
				left join richiesta on codiceb=cb and codiceg=cg
				group by cb, cg

				--- 5

select cg, avg(preferenza)
from (
		select distinct codice cg 
				from giocattolo
					except
						select codiceg
								from richiesta join bambino on codiceb=codice
										where citta = 'Firenze') v
										left join richiesta on cg=codiceg
										group by cg;

