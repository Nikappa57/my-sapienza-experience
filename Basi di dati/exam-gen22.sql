--- 1

select distinct lavoratore
from partecipa join attivita on codiceattivita=codice
where durata > 10

--- 2

select progetto, count(distinct lavoratore)
from partecipa join attivita on codiceattivita=codice
group by progetto

--- 3

select lavoratore, avg(distinct nattivita)
from partecipa 
	join attivita on codice=codiceattivita
	join (select progetto p, count(*) nattivita
		from attivita
		group by progetto) on progetto=p
group by lavoratore

--- 4

select distinct lavoratore, progetto, case when c is null then 0 else c end
from (select * from partecipa, attivita) v1
	left join
	(select p.lavoratore l, a.progetto p, sum(durata) c
		from partecipa p join attivita a on p.codiceattivita=a.codice
		group by p.lavoratore, a.progetto) v2
	on v1.lavoratore=l and v1.progetto=p;

--- or

select distinct p1.lavoratore, a1.progetto,
	(select case when sum(a2.durata) is null then 0 else sum(a2.durata) end
		from partecipa p2 join attivita a2 on p2.codiceattivita=a2.codice
		where p2.lavoratore=p1.lavoratore and a2.progetto=a1.progetto) 
from partecipa p1, attivita a1

--- 5

select distinct p1.lavoratore
from attivita a1
	join partecipa p1 on codiceattivita=codice
group by p1.lavoratore, a1.progetto
having count(distinct codice) = 
	(select count(distinct a2.codice) from attivita a2 where a2.progetto=a1.progetto)




