open System
//Zadanie1
Console.WriteLine("\n Zadanie1\n")
let nPierwszych (n:int) : List<int>= 
    [1..n]
Console.WriteLine("Podaj liczbe n do stworzenia listy. Nie może być mniejsza niż 1.\n")
let (zad1_n:int) = int(Console.ReadLine())
if zad1_n > 0 then
    let (zad1_a:List<int>) = nPierwszych zad1_n
    Console.WriteLine($"Lista składająca się z {zad1_n} elementów:\n{zad1_a}")
else
    Console.WriteLine($"Bledna liczba.\n")

//Zadanie2
let zad2 (min:int) (max:int) (krok:int) : List<int> = 
    [min..krok..max]
Console.WriteLine("\nZadanie2\n")
Console.WriteLine("Podaj minimalna wartosc w liscie. Nie może być mniejsza niż 1.\n")
let (zad2_min:int) = int(Console.ReadLine())
Console.WriteLine("Podaj maksymalna wartosc w liscie. Nie może być mniejsza niz minimalna.\n")
let (zad2_max:int) = int(Console.ReadLine())
Console.WriteLine("Podaj krok w liscie. Nie może być mniejsza niż 1.\n")
let (zad2_krok:int) = int(Console.ReadLine())
if zad2_min > 0 then
    if zad2_max > zad2_min then
        if zad2_krok > 0 then
            let (zad2_lista:List<int>) = zad2 zad2_min zad2_max zad2_krok
            Console.WriteLine($"Lista: \n{zad2_lista}")
        else
            printfn"\nKrok jest mniejszy niz 1."
    else
        printfn"\nNieprawidlowa wartosc"
else
    printfn"\nNieprawidlowa wartosc"

//Zadanie3
let zad3_funkcja (zad3_n:int) (zad3_a:int) = 
    if zad3_a < zad3_n && zad3_a > 0 then 
        let (zad3_list:List<int>) = [1..zad3_n]
        printfn "Wartosc w tablicy = %i " (zad3_list.Item(zad3_a-1))
    else 
        Console.WriteLine("Nieprawidlowy indeks listy.\n")
Console.WriteLine("\nZadanie3\n")
Console.WriteLine("Podaj ile liczb ma byc w liscie\n")
let (zad3_n:int) = int(Console.ReadLine())
Console.WriteLine("Podaj ktory element chcesz wyswietlic z listy\n")
let (zad3_a:int) = int(Console.ReadLine())
zad3_funkcja zad3_n (zad3_a-1)


//Zadanie4
let zad4_funkcja (zad4_n:int) (zad4_a:int) = 
    let x = [1..zad4_n]
    let mutable xx = 0
    for i in x do 
        if zad4_a = i then
            xx <- 1
    if xx = 0 then
        printfn"Nie znaleziono elementu\n"
    else 
        printfn"Znaleziono element"
Console.WriteLine("\nZadanie4\n")
Console.WriteLine("Podaj ile liczb ma byc w liscie\n")
let (zad4_n:int) = int(Console.ReadLine())
Console.WriteLine("Podaj wartosc ktora chcesz sprawdzic czy jest w liscie\n")
let (zad4_a:int) = int(Console.ReadLine())
zad4_funkcja zad4_n zad4_a
//Zadanie5
type Zad6_unia =
    | Index of int
    | Brak
let zad5_funkcja (zad5_list:List<int>) (zad5_a:int) : (Zad6_unia)=
    let mutable (x:Zad6_unia) = Brak
    let mutable (j:int) = 0
    for i in zad5_list do
        Console.WriteLine($"{i}\n")
        if i = zad5_a then 
            x <- Index(int(j))
        j <- j+1
    x    
Console.WriteLine("\nZadanie5\n")
let zad5_list:List<int> = [1..2..200]
Console.WriteLine("Podaj wartosc ktora chcesz sprawdzic czy jest w liscie\n")
let (zad5_a:int) = int(Console.ReadLine())
let zad5_czyJest:Zad6_unia = zad5_funkcja zad5_list zad5_a
match zad5_czyJest with
| Index x -> Console.WriteLine($"Index został znaleziony na indexie o wartosci: { x }")
| _ ->  Console.WriteLine($"Nie znaleziono indeksu z ta wartoscia")
//Zadanie6
let zad6_funkcja (zad6_list:List<int>) (zad6_a:int) : List<int> = 
    List.take zad6_a zad6_list @ List.skip (zad6_a + 1) zad6_list
Console.WriteLine("\nZadanie6\n")
let (zad6_list:List<int>) = [1..3..20]
Console.WriteLine("Podaj indeks ktory chcesz usunac z listy\n")
let (zad6_a:int) = int(Console.ReadLine())
if zad6_a > (-1) && zad6_a > zad6_list.Length - 1 then
    let (zad6_wynik:List<int>) = zad6_funkcja zad6_list zad6_a
    Console.WriteLine($"Lista po usunieciu: {zad6_wynik}")
else 
    Console.WriteLine("Nie znaleziono indeksu.")
//Zadanie7
let zad7_funkcja (zad6_list:List<int>) : float = 
    let mutable (dlugosc:int) = 0
    let mutable (suma:int) = 0 
    for i in zad6_list do
        dlugosc <- dlugosc+1
        suma <- suma+i
    let mutable (srednia:float) = float(suma)/float(dlugosc)
    srednia
Console.WriteLine("\nZadanie7\n")
let (zad7_wynik:float) = zad7_funkcja zad6_list
Console.WriteLine($"Wynik sredniej z listy wynosi {zad7_wynik}")

//Zadanie8
let zad8_funkcja (tablica:string[]) (separator:string) :String = 
   String.concat separator tablica
Console.WriteLine("\nZadanie8\n")
let (zad8_tab:string[]) = [|"kokos ";"kokosowy ";"z ";"mleczkiem ";"kokosowym ";"<3"|]
let (zad8_result:String) = zad8_funkcja zad8_tab ""
Console.WriteLine($"Wynik funkcji z zadania 8 {zad8_result}")
//Zadanie9
let zad9_dlugosci (lista: list<string>) : list<int> =
    List.map (fun x -> String.length x) lista
Console.WriteLine("\nZadanie9\n")
let (zad9_tab:list<string>) = ["kokos ";"kokosowy ";"z ";"mleczkiem ";"kokosowym ";"<3"]
let (zad9_result:List<int>) = zad9_dlugosci zad9_tab
Console.WriteLine($"Lista:{zad9_tab}\nNowa lista intow z listy stringow: {zad9_result}\n")
//Zadanie10
let zad10_funkcja (lista:list<string>) =
    let najkrotszy = List.minBy (fun x -> String.length x) lista
    let najdluzszy = List.maxBy (fun x -> String.length x) lista
    (najkrotszy, najdluzszy)
Console.WriteLine("\nZadanie10\n")
let zad10_result = zad10_funkcja zad9_tab
Console.WriteLine($"Najktorszy wyraz: {fst zad10_result} a najdluzszy wyraz: {snd zad10_result}")
//Zadanie12
let zad12_funkcja (zad12_lista:List<string>) : List<string> =
    zad12_lista |> List.fold (fun acc x -> x::acc) []
Console.WriteLine("\nZadanie12\n")
let (zad12_tab:list<string>) = ["kokos ";"kokosowy ";"z ";"mleczkiem ";"kokosowym ";"<3"]
let (zad12_result:List<string>) = zad12_funkcja zad12_tab
Console.WriteLine($"Lista:{zad12_tab}\nNowa lista intow z listy stringow: {zad12_result}\n")

//Zadanie14
let zad14_funkcja (zad14_lista1:List<int>) (zad14_lista2:List<int>) : List<Boolean> =
    if zad14_lista1.Length <> zad14_lista2.Length then
        raise(System.ArgumentException("Listy nie sa tej samej dlugosci"))
    let (result:List<Boolean>) =  List.map2 (fun x y -> x > y) zad14_lista1 zad14_lista2
    result
Console.WriteLine("\nZadanie14\n")
let (zad14_lista1:List<int>) = [1;2;3;4;5]
let (zad14_lista2:List<int>) = [0;45;3;1;1]

try
    let zad14_result = zad14_funkcja zad14_lista1 zad14_lista2
    Console.WriteLine($"Wynik funkcji dla listy: {zad14_lista1} i listy {zad14_lista2}\n{zad14_result}")
with
    | ex -> printfn "%s" ex.Message
//Zadanie16
type rosn_malej = 
    | ASC 
    | DESC

let czyposrto (zad16_lista:list<'a>) (jak: rosn_malej) = 
    let mutable licznik  = 0
    let (posortowana:List<'a>) =
        match jak with
        | ASC -> zad16_lista |> List.sort
        | DESC -> zad16_lista |> List.sortByDescending id 
    for i in 0..(zad16_lista.Length)-1 do
        if zad16_lista.Item(i) = posortowana.Item(i) then
            licznik <- licznik+1
    if licznik = zad16_lista.Length then
        printfn "Lista %A jest posortowana" zad16_lista
    else
        printfn "Lista %A nie jest posortowana" zad16_lista
Console.WriteLine("\nZadanie16\n")
czyposrto [1;2;3;4;5] DESC
czyposrto [1;2;3;4;5] ASC

//Zadanie18
type 'a StackNode = // wezel
    { Value: 'a // wartosc z wezlu
      Next: 'a StackNode option // wskazuje kolejny wezle na stosie
    }  

type 'a Stack = // stos
    {
        mutable Head: 'a StackNode option  // wskazuje na wierzcholek stosu
    }

let push (stack: 'a Stack) (value: 'a) = // wstawienie na stos
    let newNode = { Value = value; Next = stack.Head } // wstawia wartosc na stos i ustawia nowy wezel od glowy
    stack.Head <- Some newNode // tutaj glowa jest ustawiona na nowy wezel

let pop (stack: 'a Stack) = // zdejmuje element ze stosu
    match stack.Head with 
    | Some node ->  // jezeli stos nie pusty
        stack.Head <- node.Next // ustawia glowe na kolejny wezel
        Some node.Value // zwraca wartosc ze stosu 
    | None -> None // jak pusty stos to nic nie robi


//Zadanie19
type ('k, 'v) KeyValuePair =
    { Key: 'k
      Value: 'v }

type ('k, 'v) Map =
    { mutable Head: ('k, 'v) KeyValuePair StackNode option }

let add (map: ('k, 'v) Map) (key: 'k) (value: 'v) =
    let newNode = { Value = { Key = key; Value = value }; Next = map.Head }
    map.Head <- Some newNode

let find (map: ('k, 'v) Map) (key: 'k) =
    let rec findKey (node: ('k, 'v) KeyValuePair StackNode option) =
        match node with
        | Some n when n.Value.Key = key -> Some n.Value.Value
        | Some n -> findKey n.Next
        | None -> None
    findKey map.Head
//Zadanie20

//Zadanie21

//Zadanie22

//Zadanie23

//Zadanie30

