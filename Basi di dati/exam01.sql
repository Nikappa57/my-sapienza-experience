select r.codice, r.giorno, r.valore
from rilevazione r
	join centralina c on r.codice=c.codice
	join citta on id=citta
where nome = 'Milano' and c.tipo != 1 and r.valore > 100;

select c.codice, regione, avg(valore)
from centralina c
	join citta on citta=id
	left join rilevazione r on r.codice=c.codice
group by c.codice, regione;

select distinct r1.codice
from rilevazione r1 join rilevazione r2 on r1.codice=r2.codice
where r1.giorno = r2.giorno + 1 and r1.valore = r2.valore;

select codice from centralina
except
select codice from rilevazione
where giorno > 90

select regione
from rilevazione r
	join centralina c on r.codice=c.codice
	join citta on id=citta
group by regione
having avg(valore) < (select avg(valore) from rilevazione);
