select targaauto, codgarage, garage.citta
from custodita join garage on codice=codgarage
where numero=1
order by targaauto

select distinct garage.citta, targa
from automobile
	join custodita on targaauto=targa
	join garage on codice=codgarage
where cilindrata>100 and numero>10

select codgarage, sum(numero)
from custodita
where numero > 0
group by codgarage

select garage.codice, sum(custodita.numero)
from garage join custodita on garage.codice = custodita.codgarage
group by garage.codice
having sum(custodita.numero) > 10 or sum(custodita.numero) is null

select targa, count(garage.codice), sum(numero)
from automobile
	join custodita on targa=targaauto
	join garage on codice=codgarage
where automobile.citta=garage.citta and numero>0
group by targa;

select codice from garage
except
select codgarage
from custodita
	join automobile on targaauto=targa
where automobile.citta='Roma'


select codice from garage
except
select codgarage
from custodita
	join automobile on targa=targaauto
	join garage on codice=codgarage
where automobile.citta!=garage.citta


select targa, g1.citta
from automobile, garage g1
where targa not in (select targaauto from custodita join garage g2 on codgarage=g2.codice
		where g2.citta=g1.citta);

select targa, count(distinct garage.citta)
from automobile 
	left join custodita on targaauto=targa
	join garage on codice=codgarage
group by targa;

select c1.targaauto, c1.codgarage
from custodita c1
where c1.numero=(select max(numero) from custodita c2 where c2.targaauto=c1.targaauto);
