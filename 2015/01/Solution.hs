import System.IO

main :: IO()
main = do
    handle <- openFile "input.txt" ReadMode
    contents <- hGetContents handle
    print (findFloor contents)
    hClose handle

findFloor :: String -> Int
findFloor [] = 0
findFloor (c:cs) | c == '(' = 1 + findFloor cs
                 | otherwise = (-1) + findFloor cs