l--Lab 5
--Zadanie 1
SELECT *
FROM Studenci
WHERE kierunek='INFORMATYKA' AND data_urodzenia = (SELECT MIN(data_urodzenia) FROM Studenci WHERE kierunek='INFORMATYKA');
--Zadanie 2
SELECT * FROM Pojazdy pe
WHERE marka LIKE 'FORD' AND modell like 'MONDEO' 
AND rodzaj_paliwa like 'benzyna' 
and pojemnosc = (SELECT MAX(pojemnosc) FROM Pojazdy WHERE marka LIKE 'FORD' AND modell like 'MONDEO' AND rodzaj_paliwa like 'benzyna' )
AND
(
(SELECT TO_CHAR(data_produkcji,'DAY') FROM Pojazdy WHERE pe.vin = vin AND marka LIKE 'FORD' AND modell like 'MONDEO' AND rodzaj_paliwa like 'benzyna' ) LIKE 'TUESDAY%'
OR 
(SELECT TO_CHAR(data_produkcji,'DAY') FROM Pojazdy WHERE pe.vin = vin AND marka LIKE 'FORD' AND modell like 'MONDEO' AND rodzaj_paliwa like 'benzyna') LIKE 'THURSDAY%'
);
--Zadanie 3
SELECT nr_akt, nazwisko, imiona, stanowisko, data_zatr, CONCAT(EXTRACT(YEAR FROM SYSDATE)-EXTRACT(YEAR FROM DATA_ZATR),CONCAT('-',EXTRACT(MONTH FROM SYSDATE)-EXTRACT(MONTH FROM DATA_ZATR))) as "staz(Lata-Miesiace)"
FROM Pracownicy 
WHERE data_zatr=(SELECT MIN(data_zatr) FROM Pracownicy WHERE data_zwol is NULL OR data_zwol > sysdate) 
AND (data_zwol is NULL OR data_zwol > sysdate);

SELECT nr_akt, nazwisko, imiona, stanowisko, data_zatr, '+'||TRUNC(MONTHS_BETWEEN(sysdate, data_zatr)/12)||'-'||TRUNC(MOD((MONTHS_BETWEEN(sysdate, data_zatr)),12))  as "staz(Lata-Miesiace)"
FROM Pracownicy 
WHERE data_zatr=(SELECT MIN(data_zatr) FROM Pracownicy WHERE data_zwol is NULL OR data_zwol > sysdate) 
AND (data_zwol is NULL OR data_zwol > sysdate);

--Zadanie 4
SELECT id_dzialu, nazwa, nr_akt, nazwisko, data_zatr, data_zwol
FROM Pracownicy
JOIN Dzialy
USING(id_dzialu)
WHERE (id_dzialu,data_zatr) IN  (SELECT id_dzialu,MAX(data_zatr) FROM Pracownicy WHERE (data_zwol IS NULL OR data_zwol > sysdate) AND data_zatr <= sysdate GROUP BY id_dzialu)
ORDER BY 1 DESC;
--Zadanie 5
SELECT  to_char(czas,'YYYY') as Rok, gat.nazwa, dlugosc, to_char(czas,'DD-MM-YYYY') as "Kiedy", nazwisko, low.nazwa as "Lowisko"
FROM Rejestry rej
JOIN Wedkarze wed
USING(id_wedkarza)
JOIN Gatunki gat
USING(id_gatunku)
JOIN Lowiska low
USING(id_lowiska)
WHERE 
(id_gatunku,TO_CHAR(czas,'YYYY'), rej.dlugosc) IN (SELECT id_gatunku, TO_CHAR(czas,'YYYY'), MAX(dlugosc) FROM Rejestry WHERE id_gatunku IS NOT NULL GROUP BY id_gatunku, TO_CHAR(czas,'YYYY'))
AND id_gatunku IS NOT NULL
ORDER BY 1,3,2;
--Zadanie 6
SELECT  waga, gat.nazwa, lowiska.nazwa, nazwisko, wed.imiona, TO_CHAR(czas,'DD-MM-YYYY') as Dzien, TO_CHAR(czas,'DAY') as "Dzien Tygodnia"
FROM Rejestry rej
JOIN Wedkarze wed
USING(id_wedkarza)
JOIN Gatunki gat
USING(id_gatunku)
JOIN Lowiska
USING(id_lowiska)
WHERE waga=(SELECT MAX(WAGA) FROM Rejestry WHERE TO_CHAR(czas,'D') = 6)
OR 
waga=(SELECT MAX(WAGA) FROM Rejestry WHERE TO_CHAR(czas,'D') = 7);

--Zadanie 7
SELECT kierunek, tryb, nr_indeksu, nazwisko, srednia 
FROM Studenci
WHERE rok=2 and stopien=1
AND (kierunek,tryb,srednia)  IN (SELECT kierunek,tryb,MIN(srednia) FROM Studenci WHERE rok=2 and stopien=1 GROUP BY kierunek , tryb )
ORDER BY 5;

--Zadanie 8
SELECT kierunek, srednia, nazwisko, imiona, nr_indeksu, stopien, rok, tryb
FROM Studenci st
WHERE srednia=(SELECT MAX(srednia) FROM Studenci WHERE imiona LIKE '%a' AND kierunek=st.kierunek )
OR
srednia=(SELECT MAX(srednia) FROM Studenci WHERE imiona NOT LIKE '%a' AND kierunek=st.kierunek )
AND imiona LIKE '%a'
ORDER BY 1,2 DESC,8;

--Zadanie 9
SELECT id_wlasciciela, wlasciciel, adres, COUNT(*) as "Liczba_Pojazdów"
FROM Pojazdy
JOIN Wlasciciele
USING(id_wlasciciela)
WHERE typ='MOTOCYKL' OR typ='SAM_OSOBOWY' 
GROUP BY id_wlasciciela, wlasciciel, adres
HAVING COUNT(*)=(SELECT MAX(COUNT(*)) FROM pojazdy WHERE typ='MOTOCYKL' OR typ='SAM_OSOBOWY' GROUP BY id_wlasciciela) 
ORDER BY 4 DESC;


--Zadanie 10
SELECT po.id_wlasciciela, wlasciciel, adres, COUNT(*) as "Liczba_Pojazdów",(SELECT MAX(COUNT(*)) FROM pojazdy WHERE typ='SAM_OSOBOWY' AND id_wlasciciela=po.id_wlasciciela GROUP BY id_wlasciciela) as "Liczba samochodow",(SELECT NVL(MAX(COUNT(*)),0) FROM pojazdy WHERE typ='MOTOCYKL' AND id_wlasciciela=po.id_wlasciciela GROUP BY id_wlasciciela) as "Liczba motocykli"
FROM Pojazdy po 
JOIN Wlasciciele wl
--USING(id_wlasciciela)
ON po.id_wlasciciela=wl.id_wlasciciela
WHERE typ='MOTOCYKL' OR typ='SAM_OSOBOWY' 
GROUP BY po.id_wlasciciela, wlasciciel, adres
HAVING COUNT(*)=(SELECT MAX(COUNT(*)) FROM pojazdy WHERE typ='MOTOCYKL' OR typ='SAM_OSOBOWY' GROUP BY id_wlasciciela) 
ORDER BY 4 DESC;


--Zadanie 11
SELECT  stu.nr_indeksu, stu.nazwisko, stu.imiona, stu.kierunek, stu.rok ,COUNT(ocena) as "Liczba ocen 5"
FROM Studenci stu
JOIN oceny oce
ON stu.nr_indeksu = oce.nr_indeksu
WHERE oce.ocena=5
GROUP BY stu.nr_indeksu, stu.nazwisko, stu.imiona, stu.kierunek, stu.rok 
HAVING COUNT(ocena) = (SELECT MAX(COUNT(OCENA)) FROM Studenci JOIN Oceny ON studenci.nr_indeksu=oceny.nr_indeksu WHERE oceny.ocena=5 GROUP BY studenci.nr_indeksu);
--Zadanie 12
SELECT studenci.nr_indeksu, studenci.nazwisko, studenci.imiona, studenci.kierunek, studenci.rok, oce.ocena, COUNT(ocena) as "Liczba Ocen"
FROM Studenci
JOIN Oceny oce
ON Studenci.nr_indeksu = oce.nr_indeksu
GROUP BY studenci.nr_indeksu, studenci.nazwisko, studenci.imiona, studenci.kierunek, studenci.rok, oce.ocena
HAVING COUNT(OCENA)=(SELECT MAX(COUNT(OCENA)) 
FROM Studenci JOIN Oceny ON studenci.nr_indeksu=oceny.nr_indeksu 
WHERE ocena= oce.ocena
GROUP BY studenci.nr_indeksu, oceny.ocena)
ORDER BY 7 DESC;
--Zadanie 13 BEZ nieudanego polowu
SELECT  gat.nazwa, TO_CHAR(czas,'DD-MM-YYYY') as "Ostatni Polow", sysdate-czas as "Liczba Dni", wed.id_wedkarza, wed.nazwisko as "Nazwisko Wedkarza", lowi.nazwa as "Nazwa Lowiska"
FROM Rejestry rej
JOIN Wedkarze wed
ON rej.id_wedkarza=wed.id_wedkarza
JOIN Gatunki gat
ON gat.id_gatunku=rej.id_gatunku
JOIN Lowiska lowi
ON lowi.id_lowiska=rej.id_lowiska
WHERE (gat.nazwa,czas) = (SELECT gatunki.nazwa, MAX(czas) FROM Gatunki JOIN Rejestry ON gatunki.id_gatunku = rejestry.id_gatunku WHERE rejestry.id_gatunku=rej.id_gatunku GROUP BY gatunki.nazwa, rejestry.id_gatunku);

--Zadanie 14 DODANE TYLKO SORTOWANIE, BEZ ZADNYCH NOWYCH REKORDOW
SELECT  gat.nazwa, TO_CHAR(czas,'DD-MM-YYYY') as "Ostatni Polow", sysdate-czas as "Liczba Dni", wed.id_wedkarza, wed.nazwisko as "Nazwisko Wedkarza", lowi.nazwa as "Nazwa Lowiska"
FROM Rejestry rej
JOIN Wedkarze wed
ON rej.id_wedkarza=wed.id_wedkarza
JOIN Gatunki gat
ON gat.id_gatunku=rej.id_gatunku
JOIN Lowiska lowi
ON lowi.id_lowiska=rej.id_lowiska
WHERE (gat.nazwa,czas) = (SELECT gatunki.nazwa, MAX(czas) FROM Gatunki JOIN Rejestry ON gatunki.id_gatunku = rejestry.id_gatunku WHERE rejestry.id_gatunku=rej.id_gatunku is NULL GROUP BY gatunki.nazwa, rejestry.id_gatunku)
ORDER BY 3 DESC;


--Zadanie 15
SELECT dzialy.id_dzialu, dzialy.nazwa, pracownicy.nr_akt, pracownicy.nazwisko, pracownicy.data_zatr, pracownicy.data_zwol
FROM Pracownicy
JOIN Dzialy
ON pracownicy.id_dzialu = dzialy.id_dzialu
WHERE data_zatr < sysdate AND (data_zwol is NULL OR data_zwol > sysdate)
AND 
(pracownicy.id_dzialu, pracownicy.data_zatr) IN
(SELECT id_dzialu, MAX(data_zatr) FROM Pracownicy WHERE data_zatr < sysdate AND (data_zwol is NULL OR data_zwol > sysdate) GROUP BY id_dzialu)
OR
(pracownicy.id_dzialu, pracownicy.data_zatr) IN
(SELECT id_dzialu, MIN(data_zatr) FROM Pracownicy WHERE data_zatr < sysdate AND (data_zwol is NULL OR data_zwol > sysdate) GROUP BY id_dzialu);
--Zadanie 16 
SELECT typ, marka, modell, COUNT(*) as Liczebnosc
FROM pojazdy poj
GROUP BY typ, marka, modell
HAVING COUNT(*) = (SELECT MAX(COUNT(*)) FROM Pojazdy WHERE typ=poj.typ GROUP BY typ,marka, modell );

--Zadanie 17
--POMIJAM

--Zadanie 18 - bez podzialu na lata
SELECT  TO_CHAR(czas,'DD-MM-YYYY HH:MM'), rej.id_wedkarza, wed.nazwisko, gat.nazwa, lowi.nazwa, rej.dlugosc, ROUND((SELECT AVG(dlugosc) FROM Rejestry WHERE id_gatunku=rej.id_gatunku  ),1) as "Srednia Dlugosc"
FROM Rejestry rej
JOIN Wedkarze wed
ON rej.id_wedkarza=wed.id_wedkarza
JOIN Gatunki gat
ON gat.id_gatunku=rej.id_gatunku
JOIN Lowiska lowi
ON lowi.id_lowiska=rej.id_lowiska
WHERE rej.dlugosc > (SELECT AVG(dlugosc) FROM Rejestry WHERE id_gatunku=rej.id_gatunku );


--Zadanie 19 0 niedkonczone
SELECT id_okregu,rej.id_lowiska, nazwa, (SELECT SUM(waga) FROM Rejestry WHERE id_lowiska=rej.id_lowiska  GROUP BY id_lowiska) as "Laczna Waga", ( SELECT COUNT(*) FROM Rejestry WHERE id_lowiska = rej.id_lowiska GROUP BY id_lowiska) as "Liczba Wpisow"
FROM Rejestry rej
JOIN Lowiska lowi
ON rej.id_lowiska = lowi.id_lowiska
WHERE lowi.id_okregu LIKE 'PZW%' AND
id_okregu=
(SELECT id_okregu FROM Lowiska WHERE id_okregu = lowi.id_okregu GROUP BY id_okregu);




--Zadanie 20
SELECT tryb, stopien, kierunek, rok, COUNT(*) as "Liczba Studentów"
FROM Studenci
GROUP BY ROLLUP (tryb, stopien, kierunek, rok);

--Zadanie 21
SELECT  DECODE(GROUPING_ID(tryb, stopien, kierunek, rok),0,'Na danym roku w TSK: ',1,'Na danym kierunku w TS: ',3,'W ramach danego stopnia w T: ',7,'W danym trybie: ',15,'Ogolem studiuje: ' ) as "Komentarz", tryb, stopien, kierunek, rok, COUNT(*) as "Liczba Studentów"
FROM Studenci
GROUP BY ROLLUP (tryb, stopien, kierunek, rok);

--Zadanie 22
SELECT wlasciciel, id_wlasciciela, typ, marka, count(vin) as "Liczba Pojazdow"
FROM Pojazdy
JOIN Wlasciciele
USING (id_wlasciciela)
GROUP BY CUBE((typ,marka),(typ),(marka)), ROLLUP(wlasciciel, id_wlasciciela)
HAVING COUNT(VIN) >=3;


--Zadanie 23
SELECT 
DECODE(GROUPING(lo.nazwa),1,'Wszystkie Lowiska',lo.nazwa) as "Lowisko",
DECODE(GROUPING(ga.nazwa),1,'Razem',ga.nazwa) as "Gatunek",
COUNT(id_gatunku) as "Liczebnosc",
SUM(re.waga) as "Laczna waga",
COUNT(DISTINCT(re.id_wedkarza)) as "Liczba roznych wedkarzy"
FROM Rejestry re
JOIN Lowiska lo 
USING (id_lowiska)
JOIN Gatunki ga
USING (id_gatunku)
GROUP BY GROUPING SETS ( (lo.nazwa, ga.nazwa),(lo.nazwa),(ga.nazwa),() ) ;

--Zadanie 24
SELECT prz.id_przedmiotu, prz.nazwa, stu.stopien, stu.rok, oce.ocena as "Ocena", count(*) as "Liczba Ocen"
FROM Studenci stu
JOIN Oceny oce
USING (nr_indeksu)
JOIN Przedmioty prz
ON (prz.id_przedmiotu=oce.id_przedmiotu)
WHERE kierunek like 'INFORMATYKA'
GROUP BY GROUPING SETS((prz.id_przedmiotu, prz.nazwa, stu.stopien, stu.rok,oce.ocena ),( stu.stopien, stu.rok ),( oce.ocena ),())
ORDER BY 1 DESC;

SELECT * FROM przedmioty;
SELECT * FROM Oceny;
SELECT * FROM Studenci;


--CZARNA LISTA - zadanie 12


SELECT kierunek,imiona,(
SELECT COUNT(*) 
FROM Studenci 
WHERE kierunek = s1.kierunek 
AND imiona = s2.imiona
) as "Liczba Stud" 
FROM (
SELECT DISTINCT(kierunek)
FROM Studenci) s1 
CROSS JOIN 
(SELECT DISTINCT(imiona)
FROM Studenci
) s2
WHERE imiona LIKE 'S%';




