DROP TABLE Zawodnicy CASCADE CONSTRAINTS;


--Zadanie 1
CREATE TABLE Zawodnicy(
    id_zawodnika NUMBER CONSTRAINT id_primary PRIMARY KEY NOT NULL,
    nazwisko VARCHAR2(50) CONSTRAINT nazwisko_nn NOT NULL,
    imiona VARCHAR2(50) CONSTRAINT imiona_nn NOT NULL,
    data_ur DATE DEFAULT TO_DATE('01.01.2007','DD.MM.YYYY') CONSTRAINT data_ur_nn NOT NULL CONSTRAINT data_ur_chk check(data_ur < TO_DATE('02.01.2007','DD.MM.YYYY')),
    wzrost NUMBER CONSTRAINT wzrost_nn NOT NULL CONSTRAINT wzrost_chk check(wzrost BETWEEN 150 AND 210),
    waga NUMBER(5,2) CONSTRAINT waga_nn NOT NULL CONSTRAINT waga_chk check(waga BETWEEN 50 AND 101),
    pozycja VARCHAR2(20) DEFAULT NULL CONSTRAINT pozycja_chk check( pozycja IN ('bramkarz','obronca','napastnik','pomocnik',NULL)),
    klub VARCHAR(100) DEFAULT 'Wolny Zawodnik' ,
    liczba_minut NUMBER DEFAULT 0  CONSTRAINT minuty_chk check(liczba_minut>=0),
    placa NUMBER(30,2) DEFAULT 0.00  
);



PARTITION BY LIST(pozycja)
    SUBPARTITION BY RANGE(wzrost)(
        PARTITION defensywa VALUES('bramkarz','obronca')(
            SUBPARTITION def_niscy VALUES LESS THAN(182),
            SUBPARTITION def_wysocy VALUES LESS THAN(maxvalue)       
        ),
        PARTITION ofensywa VALUES('napastnik','pomocnik')(
            SUBPARTITION ofe_niscy VALUES LESS THAN(178),
            SUBPARTITION ofe_wysocy VALUES LESS THAN(maxvalue)        
        ),
        PARTITION uniwersalni VALUES(DEFAULT)(
            SUBPARTITION uni_niscy VALUES LESS THAN(180),
            SUBPARTITION uni_wysocy VALUES LESS THAN(maxvalue)       
        )
);

DESC Zawodnicy;

SELECT * FROM Zawodnicy;

SELECT * FROM all_constraints WHERE table_name = 'Zawodnicy';

SELECT * FROM all_constraints WHERE owner LIKE 'MATART22';

select * from v$OPTION;

UPDATE v$OPTION SET Partitioning =  'True';

select * from v$version;

select from v$version;*


--Zadanie 1 - insertowanie 
INSERT INTO Zawodnicy VALUES (1001, 'Nowak', 'Piotr', To_date('10-01-1992', 'DD-MM-YYYY'), 192, 81.5, 'bramkarz', 'Warta Czestochowa', 360, 8000);
INSERT INTO Zawodnicy VALUES (1002, 'Kowalski', 'Adam', To_date('15-04-1994', 'DD-MM-YYYY'), 194, 83, 'bramkarz', 'Odra Wroclaw', 270, 7000);
INSERT INTO Zawodnicy VALUES (1003, 'Polak', 'Dariusz', To_date('11-06-2000', 'DD-MM-YYYY'), 189, 79.5, 'bramkarz', 'Wisla Warszawa', 450, 10000);
INSERT INTO Zawodnicy VALUES (1004, 'Malinowski', 'Adrian', To_date('21-11-1989', 'DD-MM-YYYY'), 190, 85, 'obronca', 'Warta Czestochowa', 300, 6000);
INSERT INTO Zawodnicy VALUES (1005, 'Czech', 'Piotr', To_date('04-12-1991', 'DD-MM-YYYY'), 187, 83, 'obronca', 'Odra Wroclaw', 200, 5200);
INSERT INTO Zawodnicy VALUES (1006, 'Podolski', 'Krystian', To_date('26-02-1999', 'DD-MM-YYYY'), 186, 89, 'obronca', 'Wisla Warszawa', 350, 7000);
INSERT INTO Zawodnicy VALUES (1007, 'Oleksy', 'Robert', To_date('12-08-1998', 'DD-MM-YYYY'), 185, 85, 'obronca', NULL, NULL, NULL);
INSERT INTO Zawodnicy VALUES (1008, 'Grzyb', 'Krzysztof', To_date('17-09-1997', 'DD-MM-YYYY'), 173, 75, 'pomocnik', 'Warta Czestochowa', 400, 6400);
INSERT INTO Zawodnicy VALUES (1009, 'Kwasek', 'Artur', To_date('30-10-1993', 'DD-MM-YYYY'), 180, 75, 'pomocnik', 'Odra Wroclaw', 370, 6600);
INSERT INTO Zawodnicy VALUES (1010, 'Kukla', 'Kamil', To_date('01-02-1995', 'DD-MM-YYYY'), 179, 75, 'pomocnik', 'Wisla Warszawa', 250, 6000);
INSERT INTO Zawodnicy (id_zawodnika, nazwisko, imiona, data_ur, wzrost, waga, pozycja) VALUES (1011, 'Drozd', 'Adam', To_date('19-03-1997', 'DD-MM-YYYY'), 182, 77, 'pomocnik');
INSERT INTO Zawodnicy VALUES (1012, 'Jankowski', 'Marek', To_date('23-09-2001', 'DD-MM-YYYY'), 185, 80, 'napastnik', 'Warta Czestochowa', 60, 4000);
INSERT INTO Zawodnicy VALUES (1013, 'Knysak', 'Fabian', To_date('10-10-1996', 'DD-MM-YYYY'), 175, 73, 'napastnik', 'Odra Wroclaw', 250, 8000);
INSERT INTO Zawodnicy VALUES (1014, 'Tyrek', 'Tomasz', To_date('31-01-2000', 'DD-MM-YYYY'), 179, 74, 'napastnik', 'Wisla Warszawa', 200, 12000);
INSERT INTO Zawodnicy VALUES (1015, 'Zachara', 'Mateusz', To_date('09-09-2002', 'DD-MM-YYYY'), 181, 73, 'napastnik', NULL, NULL, NULL);
INSERT INTO Zawodnicy VALUES (1016, 'Jaskola', 'Milosz', To_date('13-09-1999', 'DD-MM-YYYY'), 187, 81, 'napastnik', 'Warta Czestochowa', 160, 4600);
INSERT INTO Zawodnicy VALUES (1017, 'Knus', 'Franciszek', To_date('10-03-1986', 'DD-MM-YYYY'), 177, 71, 'napastnik', 'Odra Wroclaw', NULL, 7400);
INSERT INTO Zawodnicy VALUES (1018, 'Toborek', 'Tomasz', To_date('31-03-1999', 'DD-MM-YYYY'), 183, 72, 'napastnik', 'Wisla Warszawa', 230, 12400);
INSERT INTO Zawodnicy VALUES (1019, 'Zasepa', 'Michal', To_date('19-09-2003', 'DD-MM-YYYY'), 180, 76, 'napastnik', NULL, NULL, NULL);
INSERT INTO Zawodnicy VALUES (1020, 'Borel', 'Jan', To_date('11-02-2004', 'DD-MM-YYYY'), 179, 75, 'pomocnik', 'Warta Czestochowa', NULL, NULL);
INSERT INTO Zawodnicy VALUES (1021, 'Czok', 'Damian', To_date('28-08-1997', 'DD-MM-YYYY'), 190, 82, 'obronca', 'Odra Wroclaw', NULL, NULL);
INSERT INTO Zawodnicy VALUES (1022, 'Bak', 'Michal', To_date('18-10-2005', 'DD-MM-YYYY'), 176, 67, NULL, 'Odra Wroclaw', 5, 3500);
INSERT INTO Zawodnicy VALUES (1023, 'Kosmala', 'Adam', To_date('22-01-2006', 'DD-MM-YYYY'), 181 , 69, NULL, NULL, NULL, NULL);



SELECT * FROM Zawodnicy;


--Zadanie 2

INSERT INTO Zawodnicy VALUES (1001, 'Czok1', 'Damian1', To_date('28-08-1997', 'DD-MM-YYYY'), 190, 82, 'obronca', 'Odra Wroclaw', NULL, NULL);
INSERT INTO Zawodnicy VALUES (1024, 'Bak', 'Michal', To_date('18-10-2005', 'DD-MM-YYYY'), 300, 67, NULL, 'Odra Wroclaw', 5, 3500);
INSERT INTO Zawodnicy VALUES (1025, 'Kosmala', 'Adam', To_date('22-01-2006', 'DD-MM-YYYY'), 181 , 1169, NULL, NULL, NULL, NULL);


--Zadanie 3
select * from zawodnicy partition(ofensywa);
select * from zawodnicy subpartition(ofe_niscy);
DELETE * FROM zawodnicy subpartition (ofe_niscy);
delete from zawodnicy where data_ur > sysdate - interval '21' year(2);
delete from zawodnicy;
select * from zawodnicy;
rollback;
select * from zawodnicy;
DROP TABLE Zawodnicy CASCADE CONSTRAINTS;
rollback;
select * from zawodnicy;
--Tworzenie od nowa 

--Zadanie 4
UPDATE Zawodnicy SET klub='Wolny Zawodnik' WHERE klub is null;
UPDATE Zawodnicy SET liczba_minut=0 WHERE liczba_minut is null;
UPDATE Zawodnicy SET placa=0 WHERE placa is null;


SELECT * FROM Zawodnicy;

--Zadanie 5

UPDATE Zawodnicy SET liczba_minut=liczba_minut+ CASE
    WHEN liczba_minut>100 THEN 90
    WHEN liczba_minut<1 THEN 15
    ELSE 45
END WHERE klub LIKE 'Warta Czestochowa' OR klub LIKE 'Odra Wroclaw';

SELECT * FROM Zawodnicy  WHERE klub LIKE 'Warta Czestochowa' OR klub LIKE 'Odra Wroclaw';

--Zadanie 6
SELECT * FROM Zawodnicy;
SELECT klub,MAX(liczba_minut) FROM Zawodnicy GROUP BY klub;
SELECT klub, MIN(liczba_minut) FROM Zawodnicy GROUP BY klub;

SELECT * FROM Zawodnicy WHERE klub LIKE 'Wolny Zawodnik';

UPDATE Zawodnicy z2 SET placa=placa+(placa*0.25) WHERE id_zawodnika=
( SELECT id_zawodnika FROM Zawodnicy  z1 WHERE z2.id_zawodnika = z1.id_zawodnika AND
(klub, liczba_minut) =
(SELECT klub,MAX(liczba_minut) FROM Zawodnicy WHERE z1.klub = klub GROUP BY klub)
);

UPDATE Zawodnicy z2 SET placa=placa-(placa*0.1) WHERE id_zawodnika=
( SELECT id_zawodnika FROM Zawodnicy  z1 WHERE z2.id_zawodnika = z1.id_zawodnika AND
(klub, liczba_minut) =
(SELECT klub,MIN(liczba_minut) FROM Zawodnicy WHERE z1.klub = klub GROUP BY klub)
);


UPDATE Zawodnicy z2 SET placa=placa+(placa*0.25) WHERE (klub,liczba_minut)=(SELECT klub,MAX(liczba_minut) FROM Zawodnicy WHERE z2.klub=klub GROUP BY klub);
UPDATE Zawodnicy z2 SET placa=placa-(placa*0.1) WHERE (klub,liczba_minut)=(SELECT klub,MIN(liczba_minut) FROM Zawodnicy WHERE z2.klub=klub GROUP BY klub);


--Zadanie 7
UPDATE ZAWODNICY SET klub =( SELECT klub  FROM Zawodnicy z2 WHERE (SELECT COUNT(*) FROM Zawodnicy WHERE z2.klub=klub ) = (SELECT MIN(COUNT(*)) FROM Zawodnicy WHERE klub NOT LIKE 'Wolny Zawodnik' GROUP BY klub) AND ROWNUM = 1 GROUP BY klub), placa = NVL(placa,4321) WHERE klub LIKE 'Wolny Zawodnik';


--Zadanie 8
UPDATE Zawodnicy SET klub='Warta Czestochowa', placa=placa+4567 WHERE id_zawodnika=(SELECT id_zawodnika FROM Zawodnicy z1 WHERE klub LIKE 'Odra Wroclaw' AND data_ur=(SELECT MAX(data_ur) FROM Zawodnicy WHERE klub=z1.klub ));

--Zadanie 9

--Zadanie 10


UPDATE Zawodnicy SET klub='Wolny Zawodnik',placa=0 WHERE id_zawodnika = (SELECT id_zawodnika FROM (SELECT * FROM Zawodnicy WHERE data_ur = (SELECT MIN(data_ur) FROM Zawodnicy)) zaw1
WHERE liczba_minut<(SELECT MAX(liczba_minut) FROM Zawodnicy WHERE klub=zaw1.klub));
 
SELECT * FROM Zawodnicy WHERE data_ur = (SELECT MIN(data_ur) FROM Zawodnicy);

--Zadanie 11

--Zadanie 12
DROP TABLE Zawodnicy CASCADE CONSTRAINTS;   