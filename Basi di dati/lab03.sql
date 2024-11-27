SELECT persona.nome, citta.regione from persona, citta where persona.eta >= 18

SELECT distinct citta.regione 
	from citta, persona, genia 
	where persona.nome = genia.genitore
		and persona.cittanascita = citta.nome;


select g genitore, f figlio
	from persona g, persona f, genia 
	where g.nome = genia.genitore 
		and f.nome = genia.figlio 
		and f.cittanascita = g.cittanascita;

select n.nome nonno from persona n, genia g1, genia g2 
	where n.sesso = 'M'
		and g1.genitore = n.nome
		and g1.figlio = g2.genitore;

SELECT distinct citta.regione
	from citta, persona p, genia g1, genia g2
	where p.cittanascita = citta.nome
		and p.sesso = 'M'
		and p.eta < 60
		and g1.genitore = p.nome
		and g1.figlio = g2.genitore;

select distinct g1f1.figlio as fratello1, g1f2.figlio as fratello2
	from genia g1f1, genia g2f1, genia g1f2, genia g2f2
	where g1f1.figlio = g2f1.figlio
		and g1f2.figlio = g2f2.figlio
		and g1f1.genitore = g1f2.genitore
		and g2f1.genitore = g2f2.genitore
		and g1f1.genitore != g2f1.genitore
		and g1f1.figlio < g1f2.figlio

SELECT n1.nome as nonno, n2.nome as nonna
	from persona n1, persona n2, persona p, genia gn1, genia gn2, genia gp1
	where n1.sesso = 'M' and n2.sesso = 'F' and p.sesso = 'M'
		and gn1.genitore = n1.nome and gn2.genitore = n2.nome
		and gn1.figlio = p.nome and gn2.figlio = p.nome
		and gp1.genitore = p.nome;
		




