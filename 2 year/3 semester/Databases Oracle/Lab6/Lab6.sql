--Zadanie 1
SELECT wlasciciel FROM Wlasciciele
UNION 
SELECT imiona || ' ' || nazwisko FROM Wedkarze
INTERSECT 
SELECT imiona || ' ' || nazwisko FROM Studenci;

SELECT wlasciciel FROM Wlasciciele
INTERSECT 
SELECT imiona || ' ' || nazwisko FROM Wedkarze
UNION
SELECT imiona || ' ' || nazwisko FROM Studenci;

--Zadanie 2
SELECT KOLOR FROM POJAZDY WHERE EXTRACT(YEAR FROM data_produkcji)>2000 AND typ LIKE 'SAM_OSOBOWY'
INTERSECT 
SELECT KOLOR FROM POJAZDY WHERE TRIM(TO_CHAR(data_produkcji,'day')) LIKE 'wtorek' AND typ LIKE 'SAM_CIEZAROWY'
MINUS
SELECT DISTINCT KOLOR FROM Pojazdy WHERE typ LIKE 'AUTOBUS';
--Zadanie 3
--Zadanie 4
--Zadanie 5
SELECT VIN,NR_REJESTRACYJNY, MARKA, MODELL, data_produkcji,'Swiezy Pojazd' FROM Pojazdy
WHERE MONTHS_BETWEEN(sysdate, data_produkcji) <= (4*12)
UNION
SELECT VIN,NR_REJESTRACYJNY, MARKA, MODELL, data_produkcji, 'Dobry Pojazd' FROM Pojazdy
WHERE MONTHS_BETWEEN(sysdate, data_produkcji) BETWEEN (4*12)+1 AND 12*10
UNION
SELECT VIN,NR_REJESTRACYJNY, MARKA, MODELL, data_produkcji, 'Leciwy Pojazd' FROM Pojazdy
WHERE MONTHS_BETWEEN(sysdate, data_produkcji) >(12*10);
--Zadanie 6
SELECT TO_CHAR(czas,'DD/MM/YYYY HH24:MI') AS "CZAS?", dlugosc,
CASE
    WHEN DLUGOSC < (SELECT AVG(DLUGOSC) FROM Rejestry WHERE id_gatunku=3 ) THEN 'Ponizej Sredniej'
    WHEN DLUGOSC > (SELECT AVG(DLUGOSC) FROM Rejestry WHERE id_gatunku=3 ) THEN 'Powyzej Sredniej'
    WHEN DLUGOSC = (SELECT AVG(DLUGOSC) FROM Rejestry WHERE id_gatunku=3 ) THEN 'Rownie ze srednia'
END KOMENTARZ
FROM Rejestry JOIN GATUNKI USING(id_gatunku) WHERE nazwa LIKE 'LESZCZ' ORDER BY 2;
