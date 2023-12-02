SELECT r1.kierunek, r1.stopien, (SELECT s.kwota_calkowita/s.kwota_stud FROM srodki s WHERE s.kierunek=r1.kierunek AND s.stopien=r1.stopien) liczba_studentow,
MAX(r1.liczba_upr) liczba_stud_z_zal, MAX(r1.granica_do) liczba_stypendystow, SUM(r1.kwota*r1.ile_osob) koszt ,
    (
        SELECT s1.kwota_calkowita 
        FROM srodki s1 
        WHERE s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien 
    )budzet,
    ( 
        SELECT s1.kwota_calkowita 
        FROM srodki s1 
        WHERE s1.kierunek = r1.kierunek AND s1.stopien = r1.stopien
    ) 
    - SUM(r1.kwota*r1.ile_osob) saldo
FROM ramy_placowe r1  
GROUP BY r1.kierunek, r1.stopien
ORDER BY 1,2;
