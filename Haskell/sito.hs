sieve :: Int -> [Int] -> [Int]
sieve n ns = filter (notDivBy n) ns
      where notDivBy n k = (k `mod` n) /= 0

eratos :: [Int] -> [Int]
eratos (n:ns) = n : eratos (sieve n ns)
eratos []     = []

primes = eratos [2..]