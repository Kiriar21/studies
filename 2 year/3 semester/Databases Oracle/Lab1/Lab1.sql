-- Zadanie 1
DESC Studenci;
--Zadanie 2
SELECT * FROM Studenci;
--Zadanie 3
SELECT imiona, nazwisko FROM Studenci;
--Zadanie 4
SELECT DISTINCT(kierunek) FROM Studenci;
--Zadanie 5
SELECT nazwisko, imiona, tryb, rok, gr_dziekan, zakres FROM Studenci WHERE kierunek='INFORMATYKA' ORDER BY rok ASC, nazwisko DESC;
--Zadanie 6
SELECT * FROM Studenci WHERE rok=3 AND Gr_dziekan=2;
--Zadanie 7
SELECT * FROM Studenci WHERE srednia is NULL;
--Zadanie 8
SELECT nazwisko, imiona, rok FROM Studenci WHERE STOPIEN=1 AND rok=2 OR rok=3 OR rok=4;
SELECT nazwisko, imiona, rok FROM Studenci WHERE STOPIEN=1 AND rok BETWEEN 2 AND 4 ;
SELECT nazwisko, imiona, rok FROM Studenci WHERE STOPIEN=1 AND rok IN(2,3,4) ;
--Zadanie 9 
SELECT imiona, nazwisko FROM Studenci WHERE ( imiona NOT LIKE 'A%') AND (imiona  LIKE '%a') ORDER BY imiona ASC, nazwisko ASC;
--Zadanie 10
SELECT imiona, nazwisko FROM Studenci WHERE imiona NOT LIKE '%a' AND nazwisko LIKE '% %' ORDER BY nazwisko DESC, imiona DESC;
--Zadanie 11
SELECT * FROM Studenci WHERE imiona IN('Adam','Konrad','Anna','Magdalena');
SELECT * FROM Studenci WHERE imiona = 'Adam' OR imiona='Anna' OR imiona = 'Konrad' OR imiona = 'Magdalena';
--Zadanie 12
SELECT * FROM Studenci WHERE nazwisko LIKE 'Kowalsk%' OR nazwisko LIKE 'Nowak'  ORDER BY data_urodzenia DESC;
--Zadanie 13
SELECT * FROM Studenci WHERE ( nazwisko LIKE '%k' OR nazwisko LIKE '%z' ) AND (imiona LIKE '_a%' OR imiona LIKE '_o%');
--Zadanie 14
SELECT imiona FROM Studenci WHERE imiona BETWEEN 'Do%' AND 'Mi%' ORDER BY imiona ASC;
SELECT imiona FROM Studenci WHERE imiona BETWEEN 'Do' AND 'Mi' ORDER BY imiona ASC;
SELECT imiona FROM Studenci WHERE imiona >='Do' AND imiona<='Mi' ORDER BY imiona ASC;
--Zadanie 15
SELECT nazwisko, (placa/20) as dniowka FROM PRACOWNICY ORDER BY 2 DESC, nazwisko ASC;
--Zadanie 16
SELECT nazwisko,nr_akt,(placa + NVL(dod_funkcyjny,0) + (placa*dod_staz/100) - NVL(koszt_ubezpieczenia,0)) AS placa FROM PRACOWNICY WHERE data_zwol IS NULL ORDER BY placa ASC;
--Zadanie 17
SELECT nazwisko,((placa + NVL(dod_funkcyjny,0) + (placa*dod_staz/100) - NVL(koszt_ubezpieczenia,0))*12) AS "Roczna Pensja" FROM PRACOWNICY WHERE data_zwol IS NULL AND (stanowisko NOT LIKE 'Dyrektor') AND (stanowisko NOT LIKE 'Prezes') ORDER BY 2;
--Zadanie 18
SELECT nazwisko||' ('||NR_AKT||') aktualnie pracuje w '||NVL(ID_DZIALU,0)||'-ym dziale na stanowisku '|| STANOWISKO || ' w firmie od '|| DATA_ZATR AS "Aktualni Pracownicy Firmy" FROM Pracownicy WHERE DATA_ZWOL IS NULL ORDER BY ID_DZIALU ASC, nazwisko ASC;
--Zadanie 19
SELECT * FROM Pojazdy WHERE (NR_REJESTRACYJNY LIKE 'SC%' AND NR_REJESTRACYJNY LIKE '%5') AND (POJEMNOSC < 1700 OR POJEMNOSC > 2000) AND (KOLOR LIKE '% %') AND (KOLOR LIKE '%r%' OR KOLOR LIKE '%R%');