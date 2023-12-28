open System
open System.Collections.Generic
open System.IO

//Zadanie 4
type Tree<'a> =
    | Leaf of 'a
    | Node of Tree<'a> * Tree<'a>

let rec listaNaDrzewo (lista:'a list) =
    match lista with
    | [] -> failwith "Pusta lista"
    | [x] -> Leaf x
    | _ ->
        let mid = lista.Length / 2
        let left = List.take mid lista
        let right = List.skip mid lista
        Node(listaNaDrzewo left, listaNaDrzewo right)
let lista = [1..2..11]
let tree = listaNaDrzewo lista
printfn "\nZadanie4: Po zmianie listy %A na drzewo: %A\n" lista tree

//Zadanie 5
type Treee<'a> =
    | Leaf
    | Node of 'a * Treee<'a> * Treee<'a>

let node x left right =
    Node(x, left, right)

let rec drzewoNaListe tree =
    match tree with
    | Node(x,l,r) -> drzewoNaListe l @ [x] @ drzewoNaListe r
    | Leaf -> []

let zad5_drzewo = Node(23, Node(31, Leaf, Leaf), Node(1, Leaf, Leaf))
printfn "\nZadanie5: Po zmianie drzewa %A na liste: %A" zad5_drzewo (drzewoNaListe zad5_drzewo) 

//Zadanie 6
let random = System.Random()
let zad6_lista = List.init 20 (fun _ -> random.Next(-10, 11))
printfn"\nZadanie6: Lista: %A" zad6_lista
Console.WriteLine($"Lista liczb dodatnich: {List.filter (fun x -> x > 0 ) zad6_lista}") 
Console.WriteLine($"Lista liczb ujemnych: {List.filter (fun x -> x < 0 ) zad6_lista}") 

//Zadanie 7
let zad7_lista = List.init 20 (fun _ -> random.Next(-10, 11))
let (zad7_suma:int) = List.sum zad7_lista
let (zad7_srednia:int) = zad7_suma/zad7_lista.Length
printfn"\nZadanie7: Srednia z listy: %A wynosi %d" zad7_lista zad7_srednia
Console.WriteLine($"Lista liczb powyzej sredniej: {List.filter (fun x -> x > zad7_srednia ) zad7_lista}") 
Console.WriteLine($"Lista liczb ponizej sredniej: {List.filter (fun x -> x < zad7_srednia ) zad7_lista}") 

//Zadanie 8
let zad8_sciezka = "zad8.txt"
let wczytane = System.IO.File.ReadAllLines zad8_sciezka |> Array.toList // zamiana tablicy na liste
let liczby_wczytane = wczytane |> List.map (fun s -> s.Split() |> Array.map Int32.Parse) // zmiana na liste bo funkcja przyjmuje tablice

let wczytane_jako_trojki : (int*int*int) list= // zrobienie krotek z 3 wartosciami
    liczby_wczytane |> List.map (fun x -> (x.[0], x.[1], x.[2]))

let dwa_rozwiazania = List.filter (fun (a, b, c) -> a <> 0 && ((b * b) - 4 * a * c) > 0) wczytane_jako_trojki
let jedno_rozwiazanie = List.filter (fun (a, b, c) -> a <> 0 && ((b * b) - 4 * a * c) = 0) wczytane_jako_trojki
let brak_rozwiazania = List.filter (fun (a, b, c) -> a <> 0 && ((b * b) - 4 * a * c) < 0) wczytane_jako_trojki
printfn "\nZadanie8: Lista dwóch rozwiązań: %A\nLista jednego rozwiązania: %A\nLista brak rozwiązań: %A\n" dwa_rozwiazania jedno_rozwiazanie brak_rozwiazania

//Zadanie 9
let sciezka_wejsciowy = "zad9.txt"
let mutable zad9_x = []
let mutable zad9_y = []
let mutable zad9_odl = []

for linia in File.ReadAllLines(sciezka_wejsciowy) do
    let lin = linia.Split(',')
    let x9 = lin.[0..0] |> Array.map float
    let y9 = lin.[1..1] |> Array.map float
    zad9_x <- List.append zad9_x ( x9|> Array.toList)
    zad9_y <- List.append zad9_y ( y9|> Array.toList)

let odlegosc_zad11 (x1:float) (y1:float) (x2:float) (y2:float) : float =
    sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))

let punkt_x_11:float = 1.0
let punkt_y_11:float = 1.0

for i=0 to zad9_x.Length-1 do
    let tmp = [|odlegosc_zad11 zad9_x.[i] zad9_y.[i] punkt_x_11 punkt_y_11|]
    zad9_odl <- List.append zad9_odl ( tmp |> Array.toList)

let mutable zad9_result = []
for i=0 to zad9_odl.Length-1 do
    let tmp = [|zad9_x.[i],zad9_y.[i],zad9_odl.[i]|]
    zad9_result <- List.append zad9_result (tmp |> Array.toList)

let zad9_result_posortowana = zad9_result |> List.sortBy(fun (_,_,z) -> z)
let zad9_wynik = zad9_result_posortowana |> List.map (fun (x,y,z) -> sprintf "(%f,%f,%f)" x y z)

let sciezka_zapis = "rozwiazanie9.txt"
System.IO.File.WriteAllLines(sciezka_zapis, zad9_wynik)
Console.WriteLine($"\nZadanie 9: Zapisano plik wynikowy.\n")
//Zadanie 11
let sciezka11 = "iris.txt"
let mutable pierwsza = []
let mutable druga = []
let mutable trzecia = []
let mutable czwarta = []

for linia in File.ReadAllLines(sciezka11) do
    let lin = linia.Split(' ')
    
    let pierwszaZamiana = lin.[0..0] |> Array.map (fun x -> x.Replace(",", "."))
    let drugaZamiana = lin.[1..1] |> Array.map (fun x -> x.Replace(",", "."))
    let trzeciaZamiana = lin.[2..2] |> Array.map (fun x -> x.Replace(",", "."))
    let czwartaZamiana = lin.[3..3] |> Array.map (fun x -> x.Replace(",", "."))
    
    let pierwszaWartosci = pierwszaZamiana |> Array.map float
    let drugieWartosci = drugaZamiana |> Array.map float
    let trzecieWartosci = trzeciaZamiana |> Array.map float
    let czwarteWartosci = czwartaZamiana |> Array.map float
    
    pierwsza <- List.append pierwsza (pierwszaWartosci|> Array.toList)
    druga <- List.append druga (drugieWartosci|> Array.toList)
    trzecia <- List.append trzecia (trzecieWartosci|> Array.toList)
    czwarta <- List.append czwarta (czwarteWartosci|> Array.toList)

Console.WriteLine($"\nZadanie11: \nPierwsza kolumna: Max={List.maxBy( fun(x) -> x) pierwsza}, Min={List.minBy( fun(x) -> x) pierwsza}, Avg={List.averageBy( fun(x) -> x) pierwsza}")
Console.WriteLine($"Druga kolumna: Max={List.maxBy( fun(x) -> x) druga}, Min={List.minBy( fun(x) -> x) druga}, Avg={List.averageBy( fun(x) -> x) druga}")
Console.WriteLine($"Trzecia kolumna: Max={List.maxBy( fun(x) -> x) trzecia}, Min={List.minBy( fun(x) -> x) trzecia}, Avg={List.averageBy( fun(x) -> x) trzecia}")
Console.WriteLine($"Czwarta kolumna: Max={List.maxBy( fun(x) -> x) czwarta}, Min={List.minBy( fun(x) -> x) czwarta}, Avg={List.averageBy( fun(x) -> x) czwarta}")

//Zadanie 13
let rand = new System.Random()
let zad13_lista = [for i in 1..1000 -> rand.Next(-10, 10)]
Console.WriteLine($"\nZadanie13: Wylosowane liczby: {zad13_lista}")
let licznik = fun v -> (List.filter (fun i -> i = v) zad13_lista).Length
let podsumowanie = Map.ofList([for i in -10..10->(i, licznik i)])
Console.WriteLine($"Mapa wylosowanych wartości:  {podsumowanie}")