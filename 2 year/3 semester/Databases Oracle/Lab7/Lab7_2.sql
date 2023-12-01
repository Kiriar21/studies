--Zadanie 1
SELECT DISTINCT(re.id_wedkarza), imiona, nazwisko, data_ur
FROM Rejestry re
JOIN Wedkarze we
ON re.id_wedkarza = we.id_wedkarza
WHERE exists(SELECT dlugosc FROM Rejestry WHERE id_wedkarza = re.id_wedkarza AND dlugosc > 70);

--Zadanie 2
SELECT * FROM Pojazdy;

SELECT marka,modell FROM Pojazdy po
WHERE 1500 < all(SELECT pojemnosc FROM Pojazdy WHERE vin=po.vin)
AND exists (SELECT * FROM pojazdy WHERE vin=po.vin)
GROUP BY marka, modell
ORDER BY 1,2;   

--Zadanie 3
SELECT * FROM Rejestry;
SELECT * FROM Wedkarze;
SELECT * FROM Gatunki;

SELECT * FROM
Rejestry re1 JOIN Wedkarze we1 
ON re1.id_wedkarza = we1.id_wedkarza
JOIN Gatunki ga1 
ON re1.id_gatunku=ga1.id_gatunku 
WHERE exists (
SELECT count(*) FROM rejestry WHERE id_wedkarza=we1.id_wedkarza AND nazwa = 'SANDACZ' 
AND TO_NUMBER(EXTRACT(MONTH FROM czas)) BETWEEN 6 AND 9
) AND nazwa = 'SANDACZ' 
AND TO_NUMBER(EXTRACT(MONTH FROM czas)) BETWEEN 6 AND 9;
--Zadanie 6
SELECT * FROM Rejestry re1
JOIN Gatunki ga1 
ON re1.id_gatunku=ga1.id_gatunku
WHERE re1.id_gatunku = ANY (SELECT id_gatunku FROM Rejestry JOIN Gatunki USING(id_gatunku) WHERE re1.dlugosc <= ga1.wymiar)
AND exists(SELECT wymiar FROM Rejestry WHERE re1.id_gatunku=id_gatunku AND wymiar is not NULL);
--Zadanie 16
SELECT * FROM Studenci;

SELECT stopien, rok, gr_dziekan, COUNT(*) as liczba, LISTAGG(imiona||' '||nazwisko,',') WITHIN GROUP (ORDER BY nazwisko) as "Studentki w grupie" FROM Studenci
WHERE kierunek = 'INFORMATYKA' AND tryb = 'STACJONARNY' AND imiona like '%a'
GROUP BY stopien, rok, gr_dziekan, zakres;