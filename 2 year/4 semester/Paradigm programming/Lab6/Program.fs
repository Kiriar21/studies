open System

//Zadanie 1
let rand = new Random()

let f x = 0.5 * (x ** 2.0) - 0.25 * x - 14.0

let areaMC n =
    let mutable count = 0
    for i in 1..n do
        let x = -10.0 + rand.NextDouble() * 20.0 
        let y = -20.0 + rand.NextDouble() * 60.0 
        if y < f x then count <- count + 1 
    let totalArea = 20.0 * 60.0
    let sampleArea = totalArea * float count / float n
    sampleArea

let n = 10000000  //im więcej tym dokładniej
let result = areaMC n 
printfn "Zadanie1:Pole powierzchni nad funkcją f(x) = 0.5 * (x^2) - 0.25 * x - 14 w przedziale [-10,10]: %f\n" result

//Zadanie 15
printfn"Zadanie15"

let knn (trainData: float[][]) (trainLabels: int[]) (testData: float[][]) (k: int) =
    let distances (a: float[]) (b: float[]) =
        Array.map2 (fun x y -> pown (x - y) 2) a b |> Array.sum |> sqrt

    let nearestNeighbors (testPoint: float[]) =
        let distancesAndLabels = Array.zip trainData trainLabels
                                 |> Array.map (fun (trainPoint, label) -> (distances trainPoint testPoint, label))
                                 |> Array.sortBy fst
        distancesAndLabels |> Array.take k |> Array.map snd

    testData |> Array.map (fun point -> nearestNeighbors point |> List.ofArray)

let trainData = [| [| 1.0; 1.0 |]; [| 2.0; 2.0 |]; [| 10.0; 10.0 |]; [| 11.0; 11.0 |] |]
let trainLabels = [| 0; 0; 1; 1 |]
let testData = [| [| 1.5; 1.5 |]; [| 9.0; 9.0 |] |]
let k15 = 3
let predictedLabels = knn trainData trainLabels testData k15
printfn "Wynik algorytmu k najbliższych sąsiadów: %A" predictedLabels

