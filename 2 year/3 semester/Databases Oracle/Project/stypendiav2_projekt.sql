--Aby Projekt zadzialal wystarczy zaznaczyc caly kod i wykonac 
--Na poczatek tworzenie tabeli z osobami ktore moga dostac stypendium 
--****************************** Kazdy obszar dydaktyczny jest przepisywany z tabel ******************************
CREATE TABLE Uprawnieni AS  
(
    SELECT s.nr_indeksu, (SELECT s3.stopien FROM Studenci s3 WHERE s3.nr_indeksu = s.nr_indeksu) stopien,
    (SELECT MAX(p2.semestr) FROM Oceny o2 JOIN Przedmioty p2 ON o2.id_przedmiotu=p2.id_przedmiotu WHERE o2.nr_indeksu=s.nr_indeksu GROUP BY o2.nr_indeksu) semestr,
    (SELECT s4.kierunek FROM Studenci s4 WHERE s4.nr_indeksu = s.nr_indeksu) kierunek
    FROM Studenci s JOIN przedmioty p ON s.kierunek=p.id_kierunku
    WHERE s.nr_indeksu 
    IN(
    --Znalezienie osob, ktore NADAL SIE UCZA - ich ostatnio wpisany semestr rozni sie od maksymalnego na danym kierunku na danym stopniu
            SELECT DISTINCT s.nr_indeksu 
            FROM Studenci s 
            JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu 
            JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu
            WHERE s.tryb like 'STACJONARNY'
            GROUP BY s.nr_indeksu, s.stopien, p.id_kierunku
            HAVING MAX(p.semestr) < 
            (
                SELECT MAX(p1.semestr)  
                FROM Przedmioty p1
                WHERE p1.id_kierunku = p.id_kierunku AND p1.stopien=s.stopien
                GROUP BY p1.id_kierunku
            )
    --Wyciagamy czesc wspolna z powyzszego zapytania i z czescia ponizej - na poczatek znajdujemy osoby ktore nigdy nie mialy zadnej 2 w ocenach
        INTERSECT 
            (
                (
                    SELECT DISTINCT(x1.indeksy) 
                    FROM 
                    (
                        SELECT s.nr_indeksu indeksy 
                        FROM Studenci s 
                        JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu
                        WHERE 
                            (
                                SELECT MIN(ox.ocena) 
                                FROM Oceny ox
                                WHERE ox.nr_indeksu = s.nr_indeksu
                            )> 2 
                        GROUP BY s.nr_indeksu
                    ) x1
                -- Laczymy z osobami, ktore mialy dwojke ale ja poprawily na pozytywna ocene                
                UNION
                    SELECT DISTINCT w1.nr_indeksu 
                    FROM
                    (
                        SELECT ox.nr_indeksu, MAX(ox.ocena) max_ocena, MIN(ox.ocena) min_ocena
                        FROM Oceny ox
                        GROUP BY ox.nr_indeksu, ox.id_przedmiotu
                    ) w1
                    WHERE w1.max_ocena > w1.min_ocena AND w1.min_ocena=2
                )
            --Odejmujemy osoby, ktore maja na koncie pusta kolumne oceny czyli NULL            
            MINUS
                SELECT DISTINCT ox12.nr_indeksu 
                FROM Oceny ox12
                WHERE ox12.ocena is null 
                GROUP BY ox12.nr_indeksu, ox12.id_przedmiotu
            )
    --Na koniec dodajemy warunek, ze tylko osoby w trybie stacjonarnym nas interesuja         
    ) AND s.tryb LIKE 'STACJONARNY' GROUP BY s.nr_indeksu 
);
--Dodanie kolumny Srednia do Uprawnionych
ALTER TABLE Uprawnieni ADD
(
    srednia NUMBER(4,3) DEFAULT 2.000 CONSTRAINT sr_up1 NOT NULL CONSTRAINT sr_up2 check(srednia>=2.000 AND srednia <=5.000),
    ranking NUMBER
);
--Aktualizacja srednich wazonych studentow, ktorzy moga dostac stypendium
UPDATE Uprawnieni u SET u.srednia = (
        SELECT ROUND(SUM(o3.ocena*p3.ects)/SUM(p3.ects),3) 
        FROM Oceny o3 
        JOIN Przedmioty p3 ON o3.id_przedmiotu=p3.id_przedmiotu 
        WHERE o3.nr_indeksu = u.nr_indeksu  AND p3.semestr = u.semestr and u.stopien = p3.stopien 
        GROUP BY u.nr_indeksu
    );
--Tworzenie tabeli srodki, ktora zawiera informacje ile pieniedzy dany kierunek i stopien ma na przydzielenie stypendium
CREATE TABLE srodki   AS 
(
    SELECT s.kierunek, s.stopien FROM Studenci s GROUP BY s.kierunek, s.stopien
);
--Modyfikacja srodkow na dodatkowe zabezpieczenia
ALTER TABLE srodki ADD
(
    kwota_stud NUMBER(4) DEFAULT 0 CONSTRAINT sr_nn NOT NULL CONSTRAINT sr_chk check(kwota_stud>=0),
    kwota_calkowita NUMBER(6) DEFAULT 0 CONSTRAINT sr_nn1 NOT NULL CONSTRAINT sr_chk1 check(kwota_calkowita>=0),
    wartosc_x NUMBER(10,5) DEFAULT 0 CONSTRAINT sr_nn2 NOT NULL CONSTRAINT sr_chk2 check(wartosc_x>=0)
);
--Wpisanie wartosci podanych w prezentacji do tablicy 
--****************************** Modyfikacja kwot przyznanych na jednego studenta ******************************
UPDATE srodki s SET s.kwota_stud = 120 WHERE s.stopien = 1 AND s.kierunek LIKE 'INFORMATYKA';
UPDATE srodki s SET s.kwota_stud = 100 WHERE s.stopien = 2 AND s.kierunek LIKE 'INFORMATYKA';
UPDATE srodki s SET s.kwota_stud = 90 WHERE s.stopien = 1 AND s.kierunek LIKE 'MATEMATYKA_STOSOWANA_I_TECHNOLOGIE_INFORMATYCZNE';
UPDATE srodki s SET s.kwota_stud = 110 WHERE s.stopien = 1 AND s.kierunek LIKE 'MECHANIKA_I_BUDOWA_MASZYN';
UPDATE srodki s SET s.kwota_stud = 100 WHERE s.stopien = 2 AND s.kierunek LIKE 'MECHANIKA_I_BUDOWA_MASZYN';
UPDATE srodki s SET s.kwota_stud = 120 WHERE s.stopien = 1 AND s.kierunek LIKE 'MECHATRONIKA';
UPDATE srodki s SET s.kwota_stud = 90 WHERE s.stopien = 2 AND s.kierunek LIKE 'MECHATRONIKA';
--Modyfikacja tabeli srodkow, aby okreslic budzet jaki Uczelnia dostanie od Panstwa na stypendia dla studentow
UPDATE srodki s1 SET s1.kwota_calkowita = s1.kwota_stud * (SELECT COUNT(*)  FROM Studenci s WHERE s.nr_indeksu IN(
SELECT DISTINCT s.nr_indeksu 
            FROM Studenci s 
            JOIN Oceny o ON o.nr_indeksu=s.nr_indeksu 
            JOIN Przedmioty p ON o.id_przedmiotu=p.id_przedmiotu
            GROUP BY s.nr_indeksu, s.stopien, p.id_kierunku
            HAVING MAX(p.semestr) < 
            (
                SELECT MAX(p1.semestr)  
                FROM Przedmioty p1
                WHERE p1.id_kierunku = p.id_kierunku AND p1.stopien=s.stopien
                GROUP BY p1.id_kierunku
            )
) AND s.kierunek = s1.kierunek AND s.stopien=s1.stopien );
--Tworzenie tabeli pomocniczej dla okreslenia pozostalych warunkow z zadania, miedzy innymi zakresy dla ilu osob przydzielimy stypendia
--****************************** Mozliwosc edycji wartosci zakresow poszczegolnych przedzialow ******************************
CREATE TABLE ramy_placowe    AS 
(
        SELECT s.kierunek, s.stopien, 1 poziom, 
        (
            SELECT COUNT(*) 
            FROM Uprawnieni r2 
            WHERE s.kierunek=r2.kierunek AND s.stopien=r2.stopien
        )as liczba_upr,
        2 zakres, 0 kwota, 1 granica_od, 1 granica_do 
        FROM Studenci s 
        GROUP BY s.kierunek, s.stopien
    UNION 
        SELECT s.kierunek, s.stopien, 2 poziom,
        (
            SELECT COUNT(*) 
            FROM Uprawnieni r2 
            WHERE s.kierunek=r2.kierunek AND s.stopien=r2.stopien
        )as liczba_upr,
        5 zakres, 0 kwota, 1 granica_od, 1 granica_do 
        FROM Studenci s 
        GROUP BY s.kierunek, s.stopien
    UNION 
        SELECT s.kierunek, s.stopien, 3 poziom,
        (
            SELECT COUNT(*) 
            FROM Uprawnieni r2 
            WHERE s.kierunek=r2.kierunek AND s.stopien=r2.stopien
        )as liczba_upr,
        10 zakres, 0 kwota, 1 granica_od, 1 granica_do
        FROM Studenci s 
        GROUP BY s.kierunek, s.stopien
    UNION
        SELECT s.kierunek, s.stopien, 4 poziom,
        (
            SELECT COUNT(*) 
            FROM Uprawnieni r2 
            WHERE s.kierunek=r2.kierunek AND s.stopien=r2.stopien
        )as liczba_upr,
        20 zakres, 0 kwota, 1 granica_od, 1 granica_do
        FROM Studenci s 
        GROUP BY s.kierunek, s.stopien
);
--Dodanie ogranicznia dla kwoty na studenta w danym zakresie
ALTER TABLE ramy_placowe MODIFY (kwota CONSTRAINT rp_chk check(kwota>=0 AND kwota IS NOT NULL));
ALTER TABLE ramy_placowe MODIFY (liczba_upr CONSTRAINT rp_chk2 check(liczba_upr>=0 AND liczba_upr IS NOT NULL));
ALTER TABLE ramy_placowe MODIFY (zakres CONSTRAINT rp_chk3 check(zakres>=0 AND zakres IS NOT NULL));
ALTER TABLE ramy_placowe MODIFY (granica_od CONSTRAINT rp_chk4 check(granica_od>=0 AND granica_od IS NOT NULL ));
ALTER TABLE ramy_placowe MODIFY (granica_do CONSTRAINT rp_chk5 check(granica_do>=0 AND granica_do IS NOT NULL ));
ALTER TABLE ramy_placowe ADD (mnoznik NUMBER(4,3) DEFAULT 1 CONSTRAINT rp_chk6 check(mnoznik>=0 AND mnoznik IS NOT NULL));
ALTER TABLE ramy_placowe ADD (ile_osob NUMBER(4) DEFAULT 1 CONSTRAINT rp_chk7 check(ile_osob>=0 AND ile_osob IS NOT NULL));
-- Wyznaczenie granicy gornej
UPDATE ramy_placowe r1 SET r1.granica_do = CEIL((r1.zakres/100)*r1.liczba_upr);
-- Wyznaczenie granicy dolnej
UPDATE ramy_placowe r1 SET r1.granica_od = 
    CASE
        WHEN  r1.poziom = 1 THEN 1
        WHEN  r1.poziom > 1 THEN 1+(SELECT r2.granica_do FROM ramy_placowe r2 WHERE r1.kierunek=r2.kierunek AND r1.stopien=r2.stopien AND r2.poziom=r1.poziom-1)
    END;
--Ustawienie mnoznika dla kazdego zakresu
--****************************** Mozliwosc edycji wartosci procentowej dla danych przedzialow, na ten moment jest to 30% ******************************
UPDATE ramy_placowe r1 SET r1.mnoznik =  POWER(1.3,4-r1.poziom);
--Wyznaczenie ilosci osob ktore dostana stypendium za dany zakres
Update ramy_placowe r1 SET ile_osob = CASE
    WHEN r1.poziom = 1 THEN r1.granica_do
    WHEN r1.granica_do - (SELECT r2.granica_do FROM ramy_placowe r2 WHERE r1.kierunek=r2.kierunek AND r1.stopien=r2.stopien AND r2.poziom=r1.poziom-1) < 1 THEN 0  
    ELSE r1.granica_do - (SELECT r2.granica_do FROM ramy_placowe r2 WHERE r1.kierunek=r2.kierunek AND r1.stopien=r2.stopien AND r2.poziom=r1.poziom-1)        
END;
--Aktualizacja wartosci x'a dla kazdego zakresu 
UPDATE srodki s1 SET s1.wartosc_x =(SELECT  TRUNC((s1.kwota_calkowita/SUM((r1.ile_osob*r1.mnoznik))),2) as x FROM ramy_placowe r1 WHERE s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien GROUP BY r1.kierunek, r1.stopien);
--Aktualizacja kwoty wyplacanej z danego zakresu
UPDATE ramy_placowe r1 SET r1.kwota = TRUNC(r1.mnoznik*( SELECT wartosc_x FROM srodki s1 WHERE  s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien),2);
--**********************************************************Tworzenie tabel pomocniczych do listy stypendium**********************************************************
--INFORMATYKA STOPIEN 1
CREATE TABLE inf1   AS
SELECT upr.nr_indeksu,upr.srednia,upr.kierunek, upr.stopien, ROW_NUMBER() OVER (ORDER BY srednia DESC) as ranking, ROW_NUMBER() OVER (ORDER BY srednia DESC) as miejsce 
FROM Uprawnieni upr
WHERE upr.kierunek = 'INFORMATYKA' AND upr.stopien = 1 
ORDER BY upr.srednia DESC;
--Sprawdzenie czy ranking zgadza sie z miejscem i wyznaczonym przedzialem
UPDATE inf1 i1 SET i1.ranking =
    CASE
        WHEN i1.srednia = (SELECT i2.srednia FROM inf1 i2 WHERE i2.ranking = i1.ranking-1 ) THEN (SELECT MIN(i3.ranking) FROM inf1 i3 WHERE i3.srednia = i1.srednia)
        ELSE i1.ranking
    END;
--Zaaktualizowanie w razie potrzeby przedzialow do wyplaty stypendium
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM inf1 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM inf1 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END WHERE r1.poziom=4;
--Usuniecie niepotrzebnych osob z tabeli stypendystow
DELETE inf1 i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);
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
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM inf2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM inf2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END WHERE r1.poziom=4;
DELETE inf2 i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);
--MATEMATYKA_STOSOWANA_I_TECHNOLOGIE_INFORMATYCZNE
CREATE TABLE mat_stos_iti   AS
SELECT upr.nr_indeksu,upr.srednia,upr.kierunek, upr.stopien, ROW_NUMBER() OVER (ORDER BY srednia DESC) as ranking, ROW_NUMBER() OVER (ORDER BY srednia DESC) as miejsce 
FROM Uprawnieni upr
WHERE upr.kierunek = 'MATEMATYKA_STOSOWANA_I_TECHNOLOGIE_INFORMATYCZNE' AND upr.stopien = 1 
ORDER BY upr.srednia DESC;
UPDATE mat_stos_iti i1 SET i1.ranking =
    CASE
        WHEN i1.srednia = (SELECT i2.srednia FROM mat_stos_iti i2 WHERE i2.ranking = i1.ranking-1 ) THEN (SELECT MIN(i3.ranking) FROM mat_stos_iti i3 WHERE i3.srednia = i1.srednia)
        ELSE i1.ranking
    END;
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM mat_stos_iti i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM mat_stos_iti i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END WHERE r1.poziom=4;
DELETE mat_stos_iti i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);
--MECHANIKA_I_BUDOWA_MASZYN STOPIEN 1
CREATE TABLE mibm1   AS
SELECT upr.nr_indeksu,upr.srednia,upr.kierunek, upr.stopien, ROW_NUMBER() OVER (ORDER BY srednia DESC) as ranking, ROW_NUMBER() OVER (ORDER BY srednia DESC) as miejsce 
FROM Uprawnieni upr
WHERE upr.kierunek = 'MECHANIKA_I_BUDOWA_MASZYN' AND upr.stopien = 1 
ORDER BY upr.srednia DESC;
UPDATE mibm1 i1 SET i1.ranking =
    CASE
        WHEN i1.srednia = (SELECT i2.srednia FROM mibm1 i2 WHERE i2.ranking = i1.ranking-1 ) THEN (SELECT MIN(i3.ranking) FROM mibm1 i3 WHERE i3.srednia = i1.srednia)
        ELSE i1.ranking
    END;
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM mibm1 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM mibm1 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END WHERE r1.poziom=4;
DELETE mibm1 i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);
--MECHANIKA_I_BUDOWA_MASZYN STOPIEN 2
CREATE TABLE mibm2   AS
SELECT upr.nr_indeksu,upr.srednia,upr.kierunek, upr.stopien, ROW_NUMBER() OVER (ORDER BY srednia DESC) as ranking, ROW_NUMBER() OVER (ORDER BY srednia DESC) as miejsce 
FROM Uprawnieni upr
WHERE upr.kierunek = 'MECHANIKA_I_BUDOWA_MASZYN' AND upr.stopien = 2 
ORDER BY upr.srednia DESC;
UPDATE mibm2 i1 SET i1.ranking =
    CASE
        WHEN i1.srednia = (SELECT i2.srednia FROM mibm2 i2 WHERE i2.ranking = i1.ranking-1 ) THEN (SELECT MIN(i3.ranking) FROM mibm2 i3 WHERE i3.srednia = i1.srednia)
        ELSE i1.ranking
    END;
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM mibm2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM mibm2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END WHERE r1.poziom=4;
DELETE mibm2 i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);
--MECHATRONIKA STOPIEN 1
CREATE TABLE mech1   AS
SELECT upr.nr_indeksu,upr.srednia,upr.kierunek, upr.stopien, ROW_NUMBER() OVER (ORDER BY srednia DESC) as ranking, ROW_NUMBER() OVER (ORDER BY srednia DESC) as miejsce 
FROM Uprawnieni upr
WHERE upr.kierunek = 'MECHATRONIKA' AND upr.stopien = 1 
ORDER BY upr.srednia DESC;
UPDATE mech1 i1 SET i1.ranking =
    CASE
        WHEN i1.srednia = (SELECT i2.srednia FROM mech1 i2 WHERE i2.ranking = i1.ranking-1 ) THEN (SELECT MIN(i3.ranking) FROM mech1 i3 WHERE i3.srednia = i1.srednia)
        ELSE i1.ranking
    END;
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM mech1 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM mech1 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END WHERE r1.poziom=4;
DELETE mech1 i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);
--MECHATRONIKA STOPIEN 2
CREATE TABLE mech2   AS
SELECT upr.nr_indeksu,upr.srednia,upr.kierunek, upr.stopien, ROW_NUMBER() OVER (ORDER BY srednia DESC) as ranking, ROW_NUMBER() OVER (ORDER BY srednia DESC) as miejsce 
FROM Uprawnieni upr
WHERE upr.kierunek = 'MECHATRONIKA' AND upr.stopien = 2 
ORDER BY upr.srednia DESC;
UPDATE mech2 i1 SET i1.ranking =
    CASE
        WHEN i1.srednia = (SELECT i2.srednia FROM mech2 i2 WHERE i2.ranking = i1.ranking-1 ) THEN (SELECT MIN(i3.ranking) FROM mech2 i3 WHERE i3.srednia = i1.srednia)
        ELSE i1.ranking
    END;
UPDATE ramy_placowe r1 SET r1.granica_do = 
CASE
    WHEN r1.granica_do != (SELECT MAX(i1.miejsce) FROM mech2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do ) THEN (SELECT MAX(i1.miejsce) FROM mech2 i1 WHERE i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND i1.ranking=r1.granica_do )
    ELSE r1.granica_do
END WHERE r1.poziom=4;
DELETE mech2 i1 WHERE i1.miejsce > (SELECT r1.granica_do FROM ramy_placowe r1 WHERE r1.kierunek=i1.kierunek AND r1.stopien = i1.stopien AND r1.poziom = 4);
--Aktualizacja granic poczatkowych 
UPDATE ramy_placowe r1 SET r1.granica_od = 
    CASE
        WHEN  r1.poziom = 1 THEN 1
        WHEN  r1.poziom > 1 THEN 1+(SELECT r2.granica_do FROM ramy_placowe r2 WHERE r1.kierunek=r2.kierunek AND r1.stopien=r2.stopien AND r2.poziom=r1.poziom-1)
    END;
--Dodanie specjalnych kolumn w poszczegolnych tabelach pomocniczych 
ALTER TABLE inf1 ADD kwota NUMBER ADD poziom NUMBER;
ALTER TABLE inf2 ADD kwota NUMBER ADD poziom NUMBER;
ALTER TABLE mat_stos_iti ADD kwota NUMBER ADD poziom NUMBER;
ALTER TABLE mech1 ADD kwota NUMBER ADD poziom NUMBER;
ALTER TABLE mech2 ADD kwota NUMBER ADD poziom NUMBER;
ALTER TABLE mibm1 ADD kwota NUMBER ADD poziom NUMBER;
ALTER TABLE mibm2 ADD kwota NUMBER ADD poziom NUMBER;
--Aktualizacja dodanych kolumn
UPDATE inf1 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE inf2 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mat_stos_iti i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mech1 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mech2 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mibm1 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mibm2 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
--Aktualiowanie ile osob dostanie stypendium z danego przedzialu
Update ramy_placowe r1 SET r1.ile_osob = CASE
        WHEN EXISTS(SELECT COUNT(*) FROM mat_stos_iti WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom) THEN (SELECT COUNT(*) FROM mat_stos_iti WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom)
        WHEN EXISTS(SELECT COUNT(*) FROM inf1 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom) THEN (SELECT COUNT(*) FROM inf1 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom)
        WHEN EXISTS(SELECT COUNT(*) FROM inf2 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom) THEN (SELECT COUNT(*) FROM inf2 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom)
        WHEN EXISTS(SELECT COUNT(*) FROM mech1 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom) THEN (SELECT COUNT(*) FROM mech1 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom)
        WHEN EXISTS(SELECT COUNT(*) FROM mech2 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom) THEN (SELECT COUNT(*) FROM mech2 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom)
        WHEN EXISTS(SELECT COUNT(*) FROM mibm1 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom) THEN (SELECT COUNT(*) FROM mibm1 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom)
        WHEN EXISTS(SELECT COUNT(*) FROM mibm2 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom) THEN (SELECT COUNT(*) FROM mibm2 WHERE r1.kierunek = kierunek AND r1.stopien=stopien AND r1.poziom = poziom GROUP BY kierunek, stopien, poziom)       
        ELSE 0
END;
--Aktualizowanie mnoznika
Update ramy_placowe r1 SET r1.mnoznik = CASE
    WHEN r1.ile_osob = 0 THEN 0
    ELSE r1.mnoznik
END;
--Dodanie pomocniczej kolumny do obliczen mnoznika
ALTER TABLE ramy_placowe  ADD pom NUMBER;
--Aktualizacja dodanej kolumny
Update ramy_placowe r1 SET r1.pom = CASE
   WHEN r1.ile_osob > 0 THEN 1
   ELSE 0
END;
--Aktualizacja mnoznika
Update ramy_placowe r1 SET r1.mnoznik = CASE
    WHEN r1.pom = 1 THEN POWER(1.3,(SELECT SUM(r2.pom) FROM ramy_placowe r2 WHERE r1.kierunek = r2.kierunek AND r1.stopien=r2.stopien AND r2.poziom>=r1.poziom)-1)
    ELSE 0
END;
--Aktualizacja wartosci x'a dla kazdego zakresu 
UPDATE srodki s1 SET s1.wartosc_x =(SELECT  TRUNC((s1.kwota_calkowita/SUM((r1.ile_osob*r1.mnoznik))),2) as x FROM ramy_placowe r1 WHERE s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien GROUP BY r1.kierunek, r1.stopien);
--Aktualizacja kwoty wyplacanej z danego zakresu
UPDATE ramy_placowe r1 SET r1.kwota = TRUNC(r1.mnoznik*( SELECT wartosc_x FROM srodki s1 WHERE  s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien),2);
--Aktualizacja kwot jakie dostaja stypendysci
UPDATE inf1 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE inf2 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mat_stos_iti i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mech1 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mech2 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mibm1 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
UPDATE mibm2 i1 SET (i1.poziom,i1.kwota) = (SELECT r1.poziom,r1.kwota FROM ramy_placowe r1 WHERE i1.ranking BETWEEN r1.granica_od AND r1.granica_do AND i1.kierunek = r1.kierunek AND i1.stopien = r1.stopien AND r1.granica_do>=r1.granica_od);
--****************************** Wystarczy zaznaczyc caly kod i wykonac po aktualizacji danych, aby zadzialala aktualizacja / pierwsze uruchomienie ******************************

--* Kod do usuniecia wszystkich utworzonych tabel 
--DROP TABLE Uprawnieni CASCADE CONSTRAINTS;
--DROP TABLE srodki CASCADE CONSTRAINTS;
--DROP TABLE ramy_placowe CASCADE CONSTRAINTS;
--DROP TABLE inf1 CASCADE CONSTRAINTS;
--DROP TABLE inf2 CASCADE CONSTRAINTS;
--DROP TABLE mat_stos_iti CASCADE CONSTRAINTS;
--DROP TABLE mech1 CASCADE CONSTRAINTS;
--DROP TABLE mech2 CASCADE CONSTRAINTS;
--DROP TABLE mibm1 CASCADE CONSTRAINTS;
--DROP TABLE mibm2 CASCADE CONSTRAINTS;
