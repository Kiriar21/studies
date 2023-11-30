--Zadanie 1
SELECT count(*) as "Liczba Studentek" from Studenci WHERE imiona LIKE '%a' AND STOPIEN = 1 AND ROK = 3 AND tryb LIKE 'STACJONARNY';
--Zadanie 2
SELECT count(*) as "Liczba Studentów" from Studenci WHERE upper(nazwisko) LIKE 'KOWALS%' OR lower(nazwisko) LIKE 'nowakowsk%';
--Zadanie 3
SELECT count(*) as "Liczba studentów" , COUNT(DISTINCT(imiona)) as "Liczba imion" from Studenci WHERE imiona LIKE 'M%' AND imiona NOT LIKE '%a';
SELECT DISTINCT(imiona) FROM Studenci WHERE imiona LIKE 'M%' AND imiona NOT LIKE '%a';  
SELECT * FROM Studenci WHERE imiona LIKE 'M%' AND imiona NOT LIKE '%a';
--Zadanie 4
SELECT CONCAT(nazwisko, CONCAT(' ',imiona)) as "Personalia Studenta" from Studenci WHERE (rok=4 AND stopien=1) OR (rok=2 AND stopien=2) ORDER BY nazwisko ASC;
SELECT * from Studenci WHERE nazwisko LIKE 'A%' ORDER BY  nazwisko ASC, imiona ASC;
--Zadanie 5
SELECT  UPPER(CONCAT(SUBSTR(imiona,1,3),SUBSTR(nazwisko,LENGTH(nazwisko)-3,3))) as "skrot" ,imiona, nazwisko from Studenci WHERE Initcap(zakres) LIKE 'Ogolny';
SELECT * from Studenci Where zakres LIKE 'Ogolny';
--Zadanie 6
SELECT COUNT(imiona) as "Liczba Studentów" from Studenci WHERE (SUBSTR(LOWER(imiona),2,1) LIKE 'r' OR SUBSTR(LOWER(imiona),2,1) LIKE 't' OR SUBSTR(LOWER(imiona),2,1) LIKE 'z') AND (SUBSTR(LOWER(imiona),LENGTH(LOWER(imiona))-1,1) LIKE 'n' OR SUBSTR(LOWER(imiona),LENGTH(LOWER(imiona))-1,1) LIKE 's' OR SUBSTR(LOWER(imiona),LENGTH(LOWER(imiona))-1,1) LIKE 'w');
--Zadanie 7
SELECT COUNT(imiona) as "Liczba Studentów" from Studenci WHERE (SUBSTR(LOWER(imiona),1,2) LIKE 'd%' OR SUBSTR(LOWER(imiona),1,2) LIKE '%d' OR SUBSTR(LOWER(imiona),1,2) LIKE 'n%' OR SUBSTR(LOWER(imiona),1,2) LIKE '%n') AND (SUBSTR(LOWER(imiona),LENGTH(imiona)-2,2) LIKE 'l%' OR SUBSTR(LOWER(imiona),LENGTH(imiona)-2,2) LIKE '%l' OR SUBSTR(LOWER(imiona),LENGTH(imiona)-2,2) LIKE 'a%' OR SUBSTR(LOWER(imiona),LENGTH(imiona)-2,2) LIKE '%a');
--Zadanie 8
SELECT imiona, nazwisko, (LENGTH(imiona) + LENGTH(nazwisko)) as "Liczba liter"  from Studenci WHERE (LENGTH(imiona) + LENGTH(nazwisko)) BETWEEN 9 AND 13  AND (LENGTH(imiona) + LENGTH(nazwisko)) NOT IN (10,12);
SELECT imiona, nazwisko, (LENGTH(imiona) + LENGTH(nazwisko)) as "Liczba liter"  from Studenci WHERE (LENGTH(imiona) + LENGTH(nazwisko)) BETWEEN 9 AND 13  AND (LENGTH(imiona) + LENGTH(nazwisko)) NOT IN (10,12) ORDER BY 3;
--Zadanie 9a
SELECT DISTINCT(Initcap(kierunek)) FROM Studenci;
--Zadanie 9b
SELECT DISTINCT(CONCAT(SUBSTR(kierunek,1,1), SUBSTR(LOWER(kierunek),2,LENGTH(kierunek)))) FROM Studenci;
--Zadanie 10
SELECT SUBSTR(nazwisko,3,LENGTH(nazwisko)) as "nazwisko bez KO", SUBSTR(imiona,1,LENGTH(imiona)-2) as "imie bez SZ",CONCAT(nazwisko,CONCAT(' ',imiona)) as "PERSONALIA" FROM Studenci WHERE nazwisko LIKE 'Ko%' AND imiona LIKE '%sz';
SELECT INITCAP(LTRIM(nazwisko,'Ko')) as Nazwisko , RTRIM(imiona,'sz') as imiona, nazwisko||' '||imiona as Personalia FROM Studenci WHERE nazwisko LIKE 'Ko%' AND imiona LIKE '%sz' ;
--Zadanie 11
SELECT nazwisko, LENGTH(nazwisko) as "Liczba Liter",  INSTR(nazwisko,'a') as "Pozycja litery a"
FROM Studenci
WHERE rok=2 AND LENGTH(nazwisko) BETWEEN 6 AND 9 AND nazwisko LIKE '%a%' ORDER BY LENGTH(nazwisko) DESC;
--Zadanie 12
SELECT * 
from Studenci
WHERE INSTR(SUBSTR(LOWER(nazwisko),1,7),'sk',1,1) !=0 AND INSTR(SUBSTR(LOWER(nazwisko),8,12),'sk',1,1) !=0 ;
--Zadanie 13
SELECT adres as "Adres przed", REPLACE(REPLACE(adres,'ul.', 'ulica'),'al.','aleja') as "Adres po"
FROM STUDENCI
WHERE SUBSTR(LOWER(adres),1,3) LIKE 'ul.' OR SUBSTR(LOWER(adres),1,3) LIKE 'al.';
--Zadanie 14
SELECT nazwisko, REPLACE(nazwisko,'Ka','Start') as "nazwisko po zmianie", imiona, RPAD(TRIM(TRAILING('a') FROM imiona),LENGTH(imiona)+2,'End')  as "imie po zmianie"
FROM Studenci
WHERE nazwisko LIKE 'Ka%' AND imiona LIKE '%a';
--Zadanie 15
SELECT RPAD(LPAD(nazwisko,LENGTH(nazwisko)+3,'*'),LENGTH(nazwisko)+7,'+') 
FROM Studenci;
--Zadanie 16
SELECT * 
FROM pojazdy 
WHERE nr_rejestracyjny LIKE 'SC %' 
AND pojemnosc BETWEEN 1000 AND 2000 AND
SUBSTR(nr_rejestracyjny,-1) IN (' ','1','2','3','4','5','6','7','8','9','0') 
AND SUBSTR(nr_rejestracyjny,-2,1) IN (' ','1','2','3','4','5','6','7','8','9','0')
AND SUBSTR(nr_rejestracyjny,-3,1) IN (' ','1','2','3','4','5','6','7','8','9','0')
AND SUBSTR(nr_rejestracyjny,-4,1) IN (' ','1','2','3','4','5','6','7','8','9','0')
AND SUBSTR(nr_rejestracyjny,-5,1) IN (' ','1','2','3','4','5','6','7','8','9','0');
--Zadanie 17
SELECT * 
FROM Pojazdy
WHERE marka LIKE 'FORD'
AND kolor LIKE 'Black Red'
AND MOD(pojemnosc,3)=0
AND pojemnosc!=0
AND MOD(pojemnosc,10)!=0;
--Zadanie 18
SELECT COUNT(*) as "Liczba Pojazdów", TRUNC(AVG(pojemnosc),2) as "Srednia pojemnosc", MIN(pojemnosc) as "Minimalna pojemno??", MAX(pojemnosc) as "Maksymalna Pojemno??"
FROM Pojazdy
WHERE kolor LIKE '% %'
AND pojemnosc NOT IN(250,500)
AND pojemnosc!=0
AND INSTR(nr_rejestracyjny,'6',1,2) != 0;
--Zadanie 19
SELECT marka, modell, typ, pojemnosc, ROUND(pojemnosc,-3) as "pojemnosc po zakragleniu", DECODE(NVL(ROUND(pojemnosc,-3),0), 0, 'nieznajomy pojazd',1000, 'maly pojazd',2000, 'sredni pojazd',3000, 'duzy pojazd') as komentarz  
FROM Pojazdy;
--Zadamoe 20
SELECT nr_rejestracyjny, modell, pojemnosc, DECODE(SUBSTR(nr_rejestracyjny,1,2),'SC', '?laskie','PO', 'Wielkopolskie', 'EL', 'Lodzkie', 'GD', 'Pomorskie', 'niezidentyfikowany') as "Województwo"
FROM Pojazdy
WHERE marka LIKE 'FORD'
AND ((pojemnosc BETWEEN 0 AND 999)
OR pojemnosc > 2500)
AND pojemnosc != 0 
AND pojemnosc IS NOT NULL;
--Zadanie 21
SELECT 'Od '||SUBSTR(MIN(czas),1,9)||' do '||SUBSTR(MAX(czas),1,9)||' odnotowano '||COUNT(*)||' zdarze? w zakresie '||COUNT(DISTINCT(id_lowiska))||' lowisk, w tym zlowiono '||COUNT(id_gatunku)||' ryb.' as "Statystyki ogólne"
FROM Rejestry;
--Zadanie 22
SELECT *
FROM Rejestry
WHERE id_gatunku IN(1,3,9,10)
AND SUBSTR(id_lowiska,1,1) LIKE 'C'
AND dlugosc BETWEEN 40 AND 60
AND mod(waga,0.1)=0;
--Zadanie 23
SELECT COUNT(id_gatunku) as "Liczba Ryb", COUNT(DISTINCT(id_wedkarza)) as "Liczba lowcow", COUNT(DISTINCT(id_lowiska)) as "Liczba lowisk", SUM(waga) as "Laczna waga", ROUND(AVG(waga),3) as "Srednia waga", ROUND(AVG(dlugosc),2) as "Srednia dlugosc"
FROM Rejestry
WHERE id_gatunku =1;
--Zadanie 24
SELECT SUBSTR(czas,1,9) as "Dzien polowu", id_gatunku, DECODE(id_gatunku, NULL, 'Brak polowu', 1, 'karp', 3 ,'leszcz', 10, 'sandacz', 17, 'ploc') as "Gatunek"
FROM Rejestry
WHERE (id_gatunku IN(1,3,10,17) OR id_gatunku IS NULL)
ORDER BY czas ASC;