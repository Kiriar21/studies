--Zadanie 1

DROP TABLE Produkty CASCADE CONSTRAINTS;
--Zadanie 1
CREATE TABLE Produkty(
    id_produktu NUMBER(4) CONSTRAINT id_uni NOT NULL UNIQUE CONSTRAINT id_chk check(LENGTH(id_produktu)=4),
    nazwa VARCHAR2(40) CONSTRAINT nazwa_nn NOT NULL,
    stan NUMBER(6,2) CONSTRAINT stan_chk check(stan < 9999.99),
    cena NUMBER(8,2) DEFAULT 1.23
);

AlTER TABLE Produkty ADD (wartosc NUMBER as (stan*cena) );

SELECT * FROM Produkty;

DESC Produkty;


--Zadanie 2
DROP TABLE Kasjerzy CASCADE CONSTRAINTS;

CREATE TABLE Kasjerzy(
    id_kasjera NUMBER(5) CONSTRAINT id_pk PRIMARY KEY,
    nazwisko VARCHAR2(20),
    data_zatrudnienia DATE CONSTRAINT date_nn NOT NULL,
    placa NUMBER(7, 2)
);
DESC Kasjerzy;

--Zadanie 3
DROP TABLE Transakcje CASCADE CONSTRAINTS;

CREATE TABLE Transakcje(
  id_transakcji NUMBER(8) CONSTRAINT id_pk1 PRIMARY KEY CONSTRAINT id_chk1 check(id_transakcji <= 99999999),
  id_produktu NUMBER(4) CONSTRAINT idp_nn NOT NULL CONSTRAINT idp_chk check(LENGTH(id_produktu)=4),
  id_sprzedawcy NUMBER(5) CONSTRAINT ids_nn  NOT NULL,
  miara NUMBER(6, 2) DEFAULT 1,
  czas_transakcji TIMESTAMP(9),
  CONSTRAINT fk_id_prod FOREIGN KEY (id_produktu) REFERENCES Produkty(id_produktu),
  CONSTRAINT fk_id_sprz FOREIGN KEY (id_sprzedawcy) REFERENCES Kasjerzy(id_kasjera)
);
DESC Transakcje;