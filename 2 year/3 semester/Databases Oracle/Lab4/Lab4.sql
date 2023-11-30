--Lab4
--Zadanie 1
SELECT * 
FROM Pojazdy p 
JOIN Wlasciciele w 
ON p.id_wlasciciela = w.id_wlasciciela
WHERE EXTRACT(YEAR FROM data_produkcji) = 2018
ORDER BY data_produkcji;

--Zadanie 2
SELECT nr_rejestracyjny, marka, modell, data_produkcji, id_wlasciciela, wlasciciel, w.data_up, data_up-data_produkcji as dni, EXTRACT(YEAR FROM data_up) - EXTRACT(YEAR FROM data_produkcji) as Lata
FROM Pojazdy p
JOIN Wlasciciele w
USING (id_wlasciciela)
WHERE (p.data_produkcji < w.data_up) AND w.status_wlasciciela = 'osoba_fizyczna'
ORDER BY 8 DESC, 9 DESC;

--Zadanie 3
SELECT p.nr_akt, p.nazwisko, p.placa, s.placa_min, s.placa_max 
FROM Pracownicy p 
JOIN Stanowiska s ON p.stanowisko = s.stanowisko
WHERE p.placa > s.placa_max OR p.placa < s.placa_min;

--Zadanie 4
SELECT s.nr_indeksu, s.nazwisko, o.ocena, o.id_przedmiotu, p.nazwa, o.data_wystawienia
FROM Studenci s JOIN Oceny o ON s.nr_indeksu=o.nr_indeksu
JOIN Przedmioty p ON p.id_przedmiotu=o.id_przedmiotu
WHERE o.ocena = 5 AND p.egzamin='T' AND o.data_wystawienia >= (sysdate-(INTERVAL '1' YEAR))
ORDER BY s.nr_indeksu, o.data_wystawienia;

--Zadamoe 5
SELECT TO_CHAR(czas,'DD-MM-YYYY') as "Dzien Polowu", nazwisko, imiona, REPLACE(g.nazwa,'NULL','Brak polowu'), l.nazwa as Lowisko, r.waga, r.dlugosc
FROM Rejestry r
JOIN Wedkarze w ON r.id_wedkarza=w.id_wedkarza
JOIN Gatunki g ON r.id_gatunku=g.id_gatunku
JOIN Lowiska l ON r.id_lowiska =l.id_lowiska
WHERE TO_DATE(TO_CHAR(czas,'DD-MM-YYYY'),'DD-MM-YYYY') >= TO_DATE(TO_CHAR(sysdate - INTERVAL '2' YEAR,'DD-MM-YYYY'),'DD-MM-YYYY')
ORDER BY czas ASC;

--Zadanie 6
SELECT *
FROM Licencje j
JOIN Wedkarze w ON j.id_wedkarza=w.id_wedkarza
WHERE rodzaj = 'podstawowa' AND SUBSTR(id_okregu,1,3) = 'PZW' AND ROK = EXTRACT(YEAR FROM sysdate); 

--Zadanie 7
SELECT  w.id_wedkarza, l.id_okregu, l.id_licencji, l.od_dnia "Poczatek", l.do_dnia "Koniec" , TO_NUMBER(TO_DATE(do_dnia,'DD-MM')-TO_DATE(od_dnia,'DD-MM')) as "Liczba Dni", TO_NUMBER(TO_DATE(do_dnia,'DD-MM')-TO_DATE(od_dnia,'DD-MM'))*o.dzienna_oplata as "Koszt Licencji"
FROM licencje l
JOIN Oplaty o ON o.id_okregu=l.id_okregu
JOIN Wedkarze w ON l.id_wedkarza=w.id_wedkarza
WHERE l.rok = 2020;

--Zadanie 8
SELECT p.nr_akt, p.nazwisko, d.id_dzialu, d.nazwa ,s.stanowisko
FROM Pracownicy p
FULL JOIN Dzialy d 
ON p.id_dzialu=d.id_dzialu
FULL JOIN Stanowiska s 
ON p.stanowisko = s.stanowisko;

--Zadanie 9
SELECT p1.id_dzialu, p1.nr_akt||' '||p1.nazwisko||' zarabia '||p1.placa as Pracownik1 , p2.id_dzialu, p2.nr_akt||' '||p2.nazwisko||' zarabia '||p2.placa as Pracownik2
FROM Pracownicy p1
INNER JOIN Pracownicy p2
ON (p1.id_dzialu = 20 AND p2.id_dzialu=30);

--Zadanie 10 
SELECT p1.nr_akt, p1.nazwisko||' '||p1.imiona as Przelozony, p2.przelozony as "NR Przelozonego", p2.nazwisko||' '||p2.imiona as Przelozony
FROM Pracownicy p1
LEFT JOIN Pracownicy p2
ON (p1.przelozony = p2.nr_akt);
--Zadanie 11
SELECT rok, COUNT(*) as "liczba studentow"
FROM Studenci 
WHERE kierunek = 'INFORMATYKA' AND Stopien = 1
GROUP BY rok HAVING COUNT(*) > 200;

--Zadanie 12
SELECT kierunek, stopien, rok, count(*)  as "Liczba Studentów" 
FROM Studenci
GROUP BY kierunek, stopien, rok
ORDER BY stopien DESC , rok DESC;

--Zadanie 13
SELECT kierunek, tryb, COUNT(*) as "Liczba Studentów" 
FROM Studenci
GROUP BY kierunek, tryb
HAVING COUNT(*) > 100;

--Zadanie 14
SELECT stopien, rok, gr_dziekan, TRUNC(AVG(srednia),2) as "Srednia studentek "
FROM Studenci
WHERE imiona LIKE '%a' AND kierunek = 'MATEMATYKA_STOSOWANA_I_TECHNOLOGIE_INFORMATYCZNE'
GROUP BY stopien, rok, gr_dziekan
ORDER BY rok, gr_dziekan;

--Zadanie 15
SELECT kierunek, rok, MIN(data_urodzenia) as Najmlodszy, MAX(data_urodzenia) as Najstarszy, ROUND(MONTHS_BETWEEN(MAX(data_urodzenia),MIN(data_urodzenia))) as "Liczba Miesiecy"
FROM Studenci
WHERE stopien=1 AND tryb = 'STACJONARNY'
GROUP BY kierunek, rok
HAVING TRUNC(MONTHS_BETWEEN(MAX(data_urodzenia),MIN(data_urodzenia))) > 100
ORDER BY 5 DESC;

--Zadanie 16
SELECT EXTRACT(YEAR FROM czas) as Rok, TO_CHAR(czas,'DAY') as "Dzien tygodnia", COUNT(*) as "Liczba Prob", COUNT(id_gatunku) as "Proby udane"
FROM Rejestry
WHERE MOD(EXTRACT(DAY FROM czas),2)=0
GROUP BY EXTRACT(YEAR FROM czas),TO_CHAR(czas,'DAY')
ORDER BY 3, 4;

--Zadanie 17
SELECT p.id_wlasciciela, w.wlasciciel, COUNT(*) as "Liczba Pojazdów", COUNT(DISTINCT(marka)) as "Liczba Marek"
FROM Pojazdy p JOIN Wlasciciele w ON (p.id_wlasciciela = w.id_wlasciciela)
GROUP BY p.id_wlasciciela, w.wlasciciel
HAVING COUNT(*) BETWEEN 7 AND 16
ORDER BY 3 DESC, 4 DESC;

--Zadanie 18
SELECT p.id_dzialu, d.nazwa, count(*) as "Liczba pracowinikow", ROUND(AVG(placa)) as "Srednia Placa" 
FROM Pracownicy p 
LEFT JOIN Dzialy d 
ON p.id_dzialu=d.id_dzialu
WHERE p.data_zwol is NULL
GROUP BY p.id_dzialu, d.nazwa 
ORDER BY 4 DESC;

--Zadanie 19
SELECT REGEXP_SUBSTR(d.adres, '\s[[:alpha:]]{1,}$') as Lokalizacja, COUNT(*) as "Liczba Pracownikow", COUNT(koszt_ubezpieczenia) as "Liczba ubezpieczonych",
SUM(p.placa+ (p.placa*p.dod_staz/100) + NVL(dod_funkcyjny,0) ) as "Koszty pracownicze"
FROM Pracownicy p 
LEFT JOIN Dzialy d
ON p.id_dzialu = d.id_dzialu
GROUP BY REGEXP_SUBSTR(d.adres, '\s[[:alpha:]]{1,}$')
ORDER BY 4 DESC;

--Zadanie 20
SELECT stanowisko, COUNT(*) as "Liczba Pracownikow", ROUND(AVG(p.placa)) as "Srednia Placa", MAX(p.placa) as "Najwieksza placa", MIN(p.placa) as "Najmniejsza Placa"
FROM Pracownicy p
RIGHT JOIN Stanowiska s
USING (stanowisko)
GROUP BY stanowisko
ORDER BY 2,3;
--Zadanie 21 
SELECT DECODE(r.id_gatunku,NULL,'brak',r.id_gatunku), g.nazwa, COUNT(*) as "Sztuk", SUM(NVL(r.waga,0)) as "Laczna Waga", ROUND(AVG(NVL(r.waga,0)),2) as "Srednia Waga", ROUND(AVG(NVL(r.dlugosc,0)),2) as "Srednia Dlugosc"
FROM Rejestry r
RIGHT JOIN Gatunki g
ON r.id_gatunku=g.id_gatunku
GROUP BY r.id_gatunku, g.nazwa;
--Zadanie 22
SELECT r.id_lowiska, COUNT(r.id_gatunku) as "Liczba Polowow", COUNT(NVL(r.id_gatunku,0))-COUNT(r.id_gatunku) as "Liczba Nieudanych Polowow",COUNT(DISTINCT(id_wedkarza)) as "Liczba Róznych Wedkarzy"
FROM Rejestry r
JOIN Lowiska l 
ON r.id_lowiska=l.id_lowiska
WHERE czas BETWEEN TIMESTAMP '2017-11-15 13:05:00' AND (TIMESTAMP '2017-11-15 13:05:00' + INTERVAL '2' YEAR)+INTERVAL '21 19:09:28' DAY(2) TO SECOND  
GROUP BY r.id_lowiska
HAVING COUNT(id_gatunku) >= 6 AND (COUNT(NVL(r.id_gatunku,0))-COUNT(r.id_gatunku)) >= 2 ;

--Zadanie 23
SELECT op.rok, id_okregu, COUNT(l.id_licencji) as "Liczba Licencji", COUNT(DISTINCT(l.id_wedkarza)) as "Liczba Wedkarzy"   
FROM Okregi ok
LEFT JOIN Oplaty op
USING (id_okregu)
LEFT JOIN Licencje l
USING (id_okregu)
GROUP BY op.rok,id_okregu
ORDER BY 1,2;

--Zadanie 24
SELECT nr_indeksu, nazwisko, kierunek, stopien, COUNT(NVL(ocena,0))-COUNT(ocena) as "Liczba Braków"
FROM Studenci s
JOIN Oceny o 
USING (nr_indeksu)
GROUP BY nr_indeksu, kierunek, stopien, nazwisko
HAVING COUNT(NVL(ocena,0))-COUNT(ocena) >= 2
ORDER BY 5 DESC, 2;
--Zadanie 25
SELECT id_wlasciciela, w.wlasciciel, COUNT(*) as "Liczba Pojazdów", COUNT(DISTINCT(marka)) "Liczba Marek"
FROM Pojazdy p
LEFT JOIN Wlasciciele w
USING(id_wlasciciela)
WHERE w.status_wlasciciela='osoba_fizyczna'
GROUP BY id_wlasciciela, w.wlasciciel
HAVING (COUNT(*) = 0) OR ( COUNT(*) = 3 AND COUNT(DISTINCT(marka)) = 3 ) 
ORDER BY 3, 2;
--Zadanie 26
SELECT id_przedmiotu, przedmioty.nazwa, przedmioty.id_kierunku, przedmioty.stopien, przedmioty.semestr, COUNT(*) as "Liczba Studentow", COUNT(ocena) as "Liczba zaliczen", COUNT(NVL(ocena,0)) - COUNT(ocena) as "Liczba Brakow" 
FROM Przedmioty
JOIN Oceny
USING (id_przedmiotu)
GROUP BY id_przedmiotu, przedmioty.nazwa, przedmioty.id_kierunku, przedmioty.stopien, przedmioty.semestr
HAVING COUNT(NVL(ocena,0)) - COUNT(ocena) BETWEEN 3 AND 6
ORDER BY 8 DESC, 2;

--Zadanie 27
SELECT nazwa, gatunki.rekord_waga as "Rekordowa waga", DECODE(MAX(rejestry.waga),NULL,'brak polowu', MAX(rejestry.waga)) as  "Najciezsza ryba", DECODE(TRUNC(MAX(rejestry.waga)/gatunki.rekord_waga,2),NULL,' ',ROUND(MAX(rejestry.waga)/gatunki.rekord_waga,4)*100) as "Procent Rekordu"
FROM Rejestry
RIGHT JOIN Gatunki
USING (id_gatunku)
GROUP BY nazwa, gatunki.rekord_waga
HAVING (TRUNC(MAX(rejestry.waga)/gatunki.rekord_waga,2) >= 0.25 OR TRUNC(MAX(rejestry.waga)/gatunki.rekord_waga,2) IS NULL) AND gatunki.rekord_waga IS NOT NULL;







