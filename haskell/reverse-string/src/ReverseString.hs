module ReverseString (reverseString) where

reverseString :: String -> String
reverseString = reverseWithAcc ""
  where
    reverseWithAcc s [] = s
    reverseWithAcc s (c : cs) = reverseWithAcc (c : s) cs
