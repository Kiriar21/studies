--Zadanie 1

SELECT nazwisko,stanowisko, (placa + NVL(dod_funkcyjny,0) + (placa*dod_staz/100) - NVL(koszt_ubezpieczenia,0))  AS "Pensja", ABS(6626.95-(placa + NVL(dod_funkcyjny,0) + (placa*dod_staz/100) - NVL(koszt_ubezpieczenia,0)))  AS "Odchylenie", ROUND(ABS(6626.95-(placa + NVL(dod_funkcyjny,0) + (placa*dod_staz/100) - NVL(koszt_ubezpieczenia,0))),1) as "Round do 0.1", TRUNC(ABS(6626.95-(placa + NVL(dod_funkcyjny,0) + (placa*dod_staz/100) - NVL(koszt_ubezpieczenia,0))),-2) as "Trunc do 100-ek"  FROM PRACOWNICY WHERE data_zwol IS NULL ORDER BY 3;
--Zadanie 2
SELECT nazwisko, stanowisko, (placa*0.12)+placa "Pensja netto", ROUND((placa*0.12)+placa,-2)  as "Pensja zaokraglona", ROUND((placa*0.12)+placa,-2)-TRUNC((placa*0.12)+placa,-2) as "Roznica Round-Trunc"
FROM Pracownicy;
--Zadanie 3
SELECT ROUND(AVG(pojemnosc)/1000,1) as "Srednia Pojemnosc" 
FROM Pojazdy
WHERE to_char(data_produkcji,'CC') = 20;
--Zadanie 4
SELECT POWER((log(123,5)+ln(sqrt(1234)))/(Power(1234,1/3)+12),3) as wynik FROM Dual;
--Zadanie 5
SELECT LEAST(sqrt(119), POWER(2.2,3), POWER(1234,1/3), LOG(1030,2)) as "Najmniejsza wartosc", GREATEST(sqrt(119), POWER(2.2,3), POWER(1234,1/3), LOG(1030,2)) as "Najwieksza wartosc" FROM Dual;
SELECT LN(119),POWER(2.2,3),POWER(1234,1/3), LOG(1030,2) FROM Dual;
--Zadanie 6
SELECT INTERVAL '+101-11' YEAR(3) TO MONTH as "Przedzial 101 lat 11 miesiecy", INTERVAL '25 3:5:36.6' DAY(2) TO SECOND as "25 dni 3h 5m 36s", CONCAT(INTERVAL '101-11' YEAR(3) TO MONTH, INTERVAL '-25 3:5:36.6' DAY(2) TO SECOND)as razem FROM Dual;
--Zadanie 7
SELECT TO_CHAR(sysdate, 'YYYY-MM-DD HH:MM:SS') as terazniejszosc, 
TO_CHAR(sysdate - INTERVAL '54321' DAY(5),'YYYY-MM-DD HH:MM:SS') as przeszlosc,
TO_CHAR(sysdate + INTERVAL '54321' DAY(5), 'YYYY-MM-DD HH:MM:SS') as przyszosc
FROM Dual;
--Zadanie 8
SELECT TO_CHAR(sysdate, 'YYYY-MM-DD HH:MM:SS') as terazniejszosc,
TO_CHAR(sysdate - INTERVAL '567 8:9:0.0' DAY(3) TO SECOND, 'YYYY-MM-DD HH:MM:SS') as przeszlosc,
TO_CHAR(sysdate + INTERVAL '129-11' YEAR(3) TO MONTH, 'YYYY-MM-DD HH:MM:SS') as przyszosc
FROM Dual;
--Zadanie 9
SELECT TIMESTAMP '2018-12-11 19:07:00' - TIMESTAMP '2015-02-15 22:04:19',
(TIMESTAMP '2018-12-11 19:07:00' - TIMESTAMP '2015-02-15 22:04:19') YEAR TO MONTH 
FROM Dual;
--Zadanie 10
SELECT EXTRACT(YEAR FROM SYSDATE) as Rok,
EXTRACT(MONTH FROM SYSDATE) as Miesiac,
EXTRACT(DAY FROM SYSDATE) as Dzien,
EXTRACT(HOUR FROM SYSTIMESTAMP) as Godzina,
EXTRACT(MINUTE FROM SYSTIMESTAMP) as Minuta,
EXTRACT(SECOND FROM SYSTIMESTAMP) as Sekunda
FROM Dual;
--Zadanie 11
SELECT * 
FROM Studenci
WHERE TO_CHAR(data_urodzenia, 'MM-DD') = TO_CHAR(sysdate, 'MM-DD') ;
Zadanie 12
SELECT ADD_MONTHS(sysdate,123) ||' week '|| TO_CHAR(ADD_MONTHS(sysdate,123),'WW') as "Date for 123 months",
LAST_DAY(ADD_MONTHS(sysdate,123))||' '|| TO_CHAR(LAST_DAY(ADD_MONTHS(sysdate,123)),'DAY') as "Last Day for 123 months"
FROM Dual;
--Zadanie 13
SELECT sysdate as aktulanie,
ROUND(sysdate,'MONTH') as miesiecy,
TRUNC(sysdate,'YEAR') as lat,
trunc(sysdate,'CC') as wiekow
FROM Dual;
--Zadanie 14
SELECT ROUND(AVG(EXTRACT(YEAR FROM SYSDATE)-(TO_NUMBER(TO_CHAR(data_produkcji, 'YYYY'))))) as "Sredni wiek" FROM Pojazdy
WHERE TO_NUMBER(TO_CHAR(data_produkcji, 'Q')) IN(1,3) AND MOD(TO_NUMBER(TO_CHAR(data_produkcji, 'YYYY')),2) != 0 ;
--Zadanie 15
SELECT COUNT(*) as "Liczba Pracowników",
ROUND(AVG(placa),2) as "?rednia placa",
ROUND(AVG(TRUNC(MONTHS_BETWEEN(sysdate, data_zatr)))) as "?redni sta? w miesiacach"
FROM Pracownicy
WHERE data_zatr >= sysdate -  INTERVAL '10' YEAR AND data_zatr <= sysdate AND data_zwol IS NULL ;
--Zadanie 16
SELECT imiona, nazwisko, data_urodzenia, TRUNC(MONTHS_BETWEEN(sysdate, data_urodzenia)/12) as "Pelne lata" ,TO_NUMBER(TO_CHAR(sysdate,'YYYY')) - TO_NUMBER(TO_CHAR(data_urodzenia,'YYYY')) as "wg rocznika"
FROM Studenci
WHERE imiona LIKE 'M%'
ORDER BY data_urodzenia;
--Zadanie 17
SELECT CAST(CONCAT('987','654') AS NUMBER) as "Liczba pierwsza",
CAST('123456' AS NUMBER) as "Liczba Druga",
CAST(CONCAT('987','654') AS NUMBER) - CAST('123456' AS NUMBER) as "Ró?nica"
FROM Dual;
--Zadanie 18
SELECT TO_CHAR(TO_CHAR(sysdate,'CC'),'RN') as wiek,
TRIM(TO_CHAR(TO_CHAR(sysdate,'YYYY'),'RN'))||'-'||TRIM(TO_CHAR(TO_CHAR(sysdate,'MM'),'RN'))||'-'||TRIM(TO_CHAR(TO_CHAR(sysdate,'DD'),'RN')) as "aktualna data"
FROM Dual;
--Zadanie 19
SELECT TO_CHAR(TO_DATE('12-09-1683','DD-MM-YYYY'),'CC')||' wiek '|| TO_CHAR(TO_DATE('12-09-1683','DD-MM-YYYY'),'Q')||' kwartal '||
TO_CHAR(TO_DATE('12-09-1683','DD-MM-YYYY'),'MONTH')||' ' || TO_CHAR(TO_DATE('12-09-1683','DD-MM-YYYY'),'W')||' tydzien '||TO_CHAR(TO_DATE('12-09-1683','DD-MM-YYYY'),'DAY')
as "szczególy dnia 12.09.1683"
FROM Dual;
--Zadanie 20
SELECT nazwisko, imiona, data_urodzenia, TO_CHAR(data_urodzenia,'DAY') as "Dzien Tygodnia"
FROM Studenci
WHERE imiona LIKE '%a' AND
MOD(TO_NUMBER(TO_CHAR(data_urodzenia,'DD')),5)!=0 AND
TO_NUMBER(TO_CHAR(data_urodzenia,'MM')) IN (7,8) AND
TO_NUMBER(TO_CHAR(data_urodzenia,'D')) IN (6,7);
--Zadanie 21
SELECT nazwisko, stanowisko, data_zatr, data_zwol, TRUNC(MONTHS_BETWEEN(NVL(data_zwol,sysdate),data_zatr)/12)||' lat '|| TRUNC(MOD(MONTHS_BETWEEN(NVL(data_zwol,sysdate),data_zatr),12))||' miesiecy' as "pracuje juz"
FROM Pracownicy
WHERE data_zatr < sysdate
ORDER BY TRUNC(MONTHS_BETWEEN(NVL(data_zwol,sysdate),data_zatr)/12) DESC, TRUNC(MOD(MONTHS_BETWEEN(NVL(data_zwol,sysdate),data_zatr),12)) DESC, nazwisko ASC;
--Zadanie21 Jedrek
SELECT Stanowisko, nazwisko, data_zatr, data_zwol,
EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM data_zatr) || ' lat '||
ABS(EXTRACT(MONTH FROM SYSDATE)-EXTRACT(MONTH FROM data_zatr)) || ' miesiecy ' as dupa
FROM Pracownicy
WHERE (data_zwol > sysdate OR data_zwol is NULL) AND data_zatr<=sysdate;
--Zadanie 22
SELECT nr_akt, nazwisko, stanowisko, data_zatr, data_zwol, placa+(pensja*dod_staz/100)+dod_funk as pensja
FROM Pracownicy
WHERE data_zatr <= '1-5-2018' AND NVL(data_zwol,sysdate) >= '31-5-2018';
--Zadanie 23
SELECT imiona, nazwisko, data_urodzenia, TO_CHAR(data_urodzenia,'Day')
FROM Studenci
WHERE data_urodzenia BETWEEN TO_DATE('13-08-1997','DD-MM-YYYY') AND TO_DATE('23-11-2001','DD-MM-YYYY') 
AND
(imiona LIKE '%a' AND TO_NUMBER(TO_CHAR(data_urodzenia,'D'))=6 AND TO_NUMBER(TO_CHAR(data_urodzenia,'DD')) BETWEEN 1 AND 7 )
OR
(imiona NOT LIKE '%a' AND TO_NUMBER(TO_CHAR(data_urodzenia,'D'))=6 AND TO_NUMBER(TO_CHAR(data_urodzenia,'DD')) BETWEEN TO_NUMBER(TO_CHAR(LAST_DAY(data_urodzenia),'DD'))-6 AND TO_NUMBER(TO_CHAR(LAST_DAY(data_urodzenia),'DD')) );
--Zadanie 24
ALTER SESSION SET NLS_DATE_FORMAT  = 'DD-MM-YYYY';
SELECT MAX(data_urodzenia) - MIN(data_urodzenia) as "Roznica Dni"
FROM Studenci
WHERE kierunek = 'INFORMATYKA' AND TO_NUMBER(TO_CHAR(data_urodzenia,'DDD')) BETWEEN TO_NUMBER(TO_CHAR(sysdate,'DDD')) - 7 AND TO_NUMBER(TO_CHAR(sysdate,'DDD')) + 7 ;
--Zadanie 25
SELECT imiona, nazwisko FROM Studenci WHERE regexp_like(imiona,'^[[:alpha:]]{5}$') AND regexp_like(nazwisko,'^Ko.+ski');
--Zadanie 26
SELECT adres, REGEXP_REPLACE(REGEXP_replace(adres, '[[:alpha:]]{3,}','ALPHA'),'[[:digit:]]{1,}','Digit') as "Zaszyfrowany Adres" FROM Studenci;
--Zadanie 27
SELECT adres FROM Studenci
WHERE regexp_like(adres,'^ul.\s[DOPT]\S{1,}\s(68|168)\s');
--Zadanie 28
SELECT adres FROM Studenci
WHERE regexp_like(adres,'^(ul.|al.)\s[[:alpha:]]{6,}\s[[:alpha:]]{6,}\s\S*\s\S*\s[[:alpha:]]{6,}\s[[:alpha:]]{6,}');