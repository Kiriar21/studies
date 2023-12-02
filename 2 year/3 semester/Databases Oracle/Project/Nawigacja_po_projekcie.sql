--INFORMATYKA STOPIEN 2
CREATE TABLE inf2   AS
SELECT upr.nr_indeksu,upr.srednia,upr.kierunek, upr.stopien, ROW_NUMBER() OVER (ORDER BY srednia DESC) as ranking, ROW_NUMBER() OVER (ORDER BY srednia DESC) as miejsce 
FROM Uprawnieni upr
WHERE upr.kierunek = 'INFORMATYKA' AND upr.stopien = 2 
ORDER BY upr.srednia DESC;
UPDATE inf2 i1 SET i1.ranking =
    CASE
        WHEN i1.srednia = (SELECT i2.srednia FROM inf2 i2 WHERE i2.ranking = i1.ranking-1 ) THEN (SELECT MIN(i3.ranking) FROM inf2 i3 WHERE i3.srednia = i1.srednia)
        ELSE i1.ranking
    END;

SELECT granica_do FROM ramy_placowe WHERE kierunek LIKE 'INFORMATYKA' AND stopien=2 and poziom=4;
--Zaaktualizowanie w razie potrzeby przedzialow do wyplaty stypendium
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM inf2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.miejsce=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM inf2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END;
--Usuniecie niepotrzebnych osob z tabeli stypendystow
DELETE inf2 i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);

























--Tabela 
SELECT * FROM Uprawnieni;
SELECT * FROM srodki order by 1,2;
SELECT * FROM ramy_placowe;

SELECT * FROM mat_stos_iti ;


SELECT * FROM inf2;
--Liczba Osob uprawnionych do stypendium
SELECT COUNT(*) liczba_uprawionych FROM Uprawnieni;
--Polecenie do usuniecia tabeli

SELECT * FROM inf1;
--Zapytanie pokazuja ile pieniedzy przeznaczymy na stypendia
SELECT r1.kierunek, r1.stopien, SUM(r1.kwota*r1.ile_osob) kwota_przeznaczona , ( SELECT s1.kwota_calkowita FROM srodki s1 WHERE s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien ) kwota_max,( SELECT s1.kwota_calkowita FROM srodki s1 WHERE s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien ) - SUM(r1.kwota*r1.ile_osob) status  FROM ramy_placowe r1  GROUP BY r1.kierunek, r1.stopien;

DROP TABLE Uprawnieni CASCADE CONSTRAINTS;
DROP TABLE srodki CASCADE CONSTRAINTS;
DROP TABLE ramy_placowe CASCADE CONSTRAINTS;
DROP TABLE inf1 CASCADE CONSTRAINTS;
DROP TABLE inf2 CASCADE CONSTRAINTS;
DROP TABLE mat_stos_iti CASCADE CONSTRAINTS;
DROP TABLE mech1 CASCADE CONSTRAINTS;
DROP TABLE mech2 CASCADE CONSTRAINTS;
DROP TABLE mibm1 CASCADE CONSTRAINTS;
DROP TABLE mibm2 CASCADE CONSTRAINTS;
--Zalozenie 1
-- Dane z tabel do wykorzystania:

-- Tabela Studentów
SELECT s.* FROM Studenci s;
--Tabela Ocen
SELECT o.* FROM Oceny o;
--Tabela przedmiotów
SELECT p.* FROM Przedmioty p;

--Zlaczenie wszystkich danych 
SELECT * FROM Studenci s JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu;

--Zlaczenie ocen i przedmiotow
SELECT * FROM Oceny o JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu;

--Zlaczenie studentow i ocen
SELECT * FROM Studenci s JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu;

--Zlaczenie studentow i przedmiotow
SELECT * FROM Studenci s JOIN Przedmioty p ON s.kierunek=p.id_kierunku;


SELECT COUNT(*) FROM Studenci WHERE stopien = 2 AND kierunek like 'INFORMATYKA' AND rok < 2;



UPDATE srodki s1 
SET r1.granica_do = 
    CASE
        WHEN r1.liczba_upr > 19 THEN CEIL((r1.zakres/100)*r1.liczba_upr)
        WHEN (r1.liczba_upr BETWEEN 5 AND 10 AND r1.poziom IN(1,2)) OR  (r1.liczba_upr BETWEEN 11 AND 14 AND r1.poziom IN(1,2,3)) OR (r1.liczba_upr < 5 AND r1.poziom =1 ) OR (r1.liczba_upr BETWEEN 15 AND 19)  THEN r1.poziom
        ELSE 0
    END
;





CREATE TABLE INFORMATYKA_1 AS 
SELECT NR_INDEKSU,NAZWISKO,IMIONA,KIERUNEK,STOPIEN,SREDNIA_ECTS SREDNIA,ROW_NUMBER() OVER (ORDER BY SREDNIA_ECTS DESC) RANKING FROM STUDENCI_PRST WHERE STOPIEN = 1 AND KIERUNEK = 'INFORMATYKA' ORDER BY SREDNIA_ECTS;
ALTER TABLE INFORMATYKA_1 ADD KWOTA NUMBER(10,3) DEFAULT 0;

UPDATE INFORMATYKA_1 INF SET RANKING = (
SELECT 
CASE
WHEN RANK1 != 1 AND SRED = (SELECT SREDNIA FROM INFORMATYKA_1 WHERE RANKING = RANK1 - 1) THEN (SELECT MIN(RANKING) FROM INFORMATYKA_1 WHERE SREDNIA = SRED)
ELSE RANK1 END TEST
FROM(
SELECT NR_INDEKSU NR,NAZWISKO,IMIONA,KIERUNEK,STOPIEN,SREDNIA SRED,RANKING RANK1
FROM INFORMATYKA_1 WHERE INF.NR_INDEKSU = NR_INDEKSU
ORDER BY SREDNIA DESC));

DELETE INFORMATYKA_1 INF WHERE RANKING > (SELECT CEIL(LICZBA_STUD_Z_ZAL*0.2) FROM KIERUNKI_STYPENDIA WHERE ID_KIERUNKU =  INF.KIERUNEK AND STOPIEN = INF.STOPIEN);





--Zalozenie 2
--Zapytanie znajdujace maksymalny semestr na danym kierunku na danym stopniu
SELECT id_kierunku, stopien, MAX(semestr)  
FROM Przedmioty p 
GROUP BY id_kierunku, stopien;

SELECT DISTINCT MAX(semestr)  
FROM Przedmioty p 
GROUP BY id_kierunku, stopien;


--Zapytanie sprawdzajace aktualny semestr studenta

SELECT s.nr_indeksu, p.stopien, MAX(semestr) 
FROM Studenci s 
JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu 
JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu
GROUP BY s.nr_indeksu, p.stopien;

SELECT COUNT(DISTINCT s.nr_indeksu) FROM Studenci s JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu WHERE stopien = 2 ;


SELECT nr_indeksu FROM Oceny WHERE max(ocena) = 4 GROUP BY nr_indeksu;

SELECT * FROM Studenci WHERE nr_indeksu=138165;





















--Zalozenie 3

-- Numery indektow osob ktore maja brak oceny
SELECT DISTINCT nr_indeksu 
FROM Oceny 
WHERE ocena is null 
GROUP BY nr_indeksu, id_przedmiotu;
-- Numery indeksow, ktore mialy dwojke ale ja poprawily
    SELECT DISTINCT nr_indeksu 
    FROM
    (
        SELECT nr_indeksu, MAX(ocena) max_ocena, MIN(ocena) min_ocena
        FROM Oceny 
        GROUP BY nr_indeksu, id_przedmiotu
    ) w1 WHERE w1.max_ocena > w1.min_ocena AND w1.min_ocena=2;
--Studenci ktorzy nie maja zadnej dwojki 
SELECT DISTINCT(indeksy) 
FROM 
(
    SELECT s.nr_indeksu indeksy 
    FROM Studenci s 
    JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu
    WHERE 
        (
            SELECT MIN(ocena) 
            FROM Oceny 
            WHERE nr_indeksu = s.nr_indeksu 
        )> 2  
    GROUP BY s.nr_indeksu
);

--Zalozenie 3

    SELECT DISTINCT(indeksy) 
    FROM 
    (
        SELECT s.nr_indeksu indeksy 
        FROM Studenci s 
        JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu
        WHERE 
            (
                SELECT MIN(ocena) 
                FROM Oceny 
                WHERE nr_indeksu = s.nr_indeksu
            )> 2 
        GROUP BY s.nr_indeksu
    )
UNION
    SELECT DISTINCT nr_indeksu 
    FROM
    (
        SELECT nr_indeksu, MAX(ocena) max_ocena, MIN(ocena) min_ocena
        FROM Oceny 
        GROUP BY nr_indeksu, id_przedmiotu
    ) w1 WHERE w1.max_ocena > w1.min_ocena AND w1.min_ocena=2
MINUS
    SELECT DISTINCT nr_indeksu 
    FROM Oceny  
    WHERE ocena is null 
    GROUP BY nr_indeksu, id_przedmiotu;
















































--Zalozenie 1
-- Dane z tabel do wykorzystania:

-- Tabela Studentów
SELECT s.* FROM Studenci s;
--Tabela Ocen
SELECT o.* FROM Oceny o;
--Tabela przedmiotów
SELECT p.* FROM Przedmioty p;

--Zlaczenie wszystkich danych 
SELECT * FROM Studenci s JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu;

--Zlaczenie ocen i przedmiotow
SELECT * FROM Oceny o JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu;

--Zlaczenie studentow i ocen
SELECT * FROM Studenci s JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu;

--Zlaczenie studentow i przedmiotow
SELECT * FROM Studenci s JOIN Przedmioty p ON s.kierunek=p.id_kierunku;



SELECT nr_indeksu, MAX(semestr)
FROM Studenci s JOIN przedmioty p ON s.kierunek=p.id_kierunku
GROUP BY nr_indeksu;

 

--Zalozenie 2
--Projekt zaczynamy od wybrania studentów, którzy nie sa na ostatnim semestrze. 









SELECT DISTINCT s.nr_indeksu
        FROM Studenci s 
        JOIN Przedmioty p ON s.kierunek=p.id_kierunku
        WHERE tryb LIKE 'STACJONARNY'
        AND (s.kierunek, p.stopien, semestr) NOT IN
                    (SELECT MAX(semestr)  
                    FROM Przedmioty p 
                    GROUP BY id_kierunku, stopien)
        GROUP BY s.nr_indeksu, p.stopien, kierunek;
            

SELECT DISTINCT s.nr_indeksu FROM Studenci s 
JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu 
JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu
WHERE tryb like 'STACJONARNY'
GROUP BY s.nr_indeksu, s.stopien, p.id_kierunku
HAVING MAX(semestr) < 
(
    SELECT MAX(semestr)  
    FROM Przedmioty p1
    WHERE p1.id_kierunku = p.id_kierunku AND p1.stopien=s.stopien
    GROUP BY p1.id_kierunku
);

SELECT * FROM Oceny o JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu WHERE nr_indeksu = 139338;






--Studenci ktorzy sie jeszcze ucza, czyli nie maja wpisane max semestru 

SELECT * 
FROM Studenci 
WHERE nr_indeksu 
IN(
    SELECT DISTINCT s.nr_indeksu
    FROM Studenci s 
    JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu 
    JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu
    WHERE tryb LIKE 'STACJONARNY'
    GROUP BY s.nr_indeksu, p.stopien
    HAVING MAX(semestr) 
        NOT IN(
                SELECT DISTINCT MAX(semestr)  
                FROM Przedmioty p 
                GROUP BY id_kierunku, stopien
        )
);



--Zalozenie 3

    SELECT DISTINCT(indeksy) 
    FROM 
    (
        SELECT s.nr_indeksu indeksy 
        FROM Studenci s 
        JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu
        WHERE 
            (
                SELECT MIN(ocena) 
                FROM Oceny 
                WHERE nr_indeksu = s.nr_indeksu
            )> 2 
        GROUP BY s.nr_indeksu
    )
UNION
    SELECT DISTINCT nr_indeksu 
    FROM
    (
        SELECT nr_indeksu, MAX(ocena) max_ocena, MIN(ocena) min_ocena
        FROM Oceny 
        GROUP BY nr_indeksu, id_przedmiotu
    ) w1 WHERE w1.max_ocena > w1.min_ocena AND w1.min_ocena=2 
MINUS
    SELECT DISTINCT nr_indeksu 
    FROM Oceny  
    WHERE ocena is null 
    GROUP BY nr_indeksu, id_przedmiotu;































--BRUDNOPIS 
--
--INSERT INTO Studenci values (333333, 'test', 'test', to_date('09-02-2002', 'dd-mm-yyyy'), 'ul. Polna 280 97-532 Lazow', 'MECHANIKA_I_BUDOWA_MASZYN', 'NIESTACJONARNY', 1, 1, 'OGOLNY', 5, 3.95);
--
--DELETE FROM Studenci WHERE nr_indeksu = 333333;
--DELETE FROM Oceny WHERE nr_indeksu = 333333;
--INSERT INTO Oceny values (59312, 333333, 'MIBM_1_1', 5, to_date('14-01-2023', 'dd-mm-yyyy') );
--
--SELECT * FROM Oceny WHERE nr_indeksu=333333;
